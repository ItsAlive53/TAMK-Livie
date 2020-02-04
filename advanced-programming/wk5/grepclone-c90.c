#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <ctype.h>
#include <string.h>


/* Options */
#define INPUT_BUFFER_SIZE 4096
/* Print debug information */
/*#define DEBUG_PRINTS*/




/**
 * 
 * 
 * DON'T CHANGE PAST THIS
 * 
 * */



/* Miscellaneous options */
#define OPTS_VERSION_BIT 0x0001
#define OPTS_HELP_BIT 0x0002

/* Output control options */
#define OPTS_LINE_NUMBER_BIT 0x0004
#define OPTS_FILE_NAME_BIT 0x0008
#define OPTS_NO_FILE_NAME_BIT 0x0010
#define OPTS_NULL_AFTER_FILE_BIT 0x0020

/* Special */
#define OPTS_READ_STDIN_BIT 0x0040

/* Error flags */
#define ERR_INVALID_OPT_BIT 0x0001
#define ERR_FILE_NOT_FOUND_BIT 0x0002

/* Selection logic helpers */
#define SEL_LINE_MATCHED_BIT 0x01
/*#define SEL_FILE_MATCHED_BIT 0x02*/


const char* UNKNOWN_TEXT = "Usage: %s [OPTION]... PATTERN [FILE]...\nTry '%s --help' for more information.\n";

const char* VERSION_TEXT = "grep clone v0.1\n";

const char* HELP_TEXT = "Usage: %s [OPTION]... PATTERN [FILE]...\nSearch for PATTERN in each FILE.\nExample: %s -i 'hello world' menu.h main.c\n";
const char* HELP_TEXT_PATTERN_OPTIONS = "\nPattern selection and interpretation:\n  -i, --ignore-case         ignore case distinctions in patterns and data\n      --no-ignore-case      do not ignore case distinctions (default)\n";
const char* HELP_TEXT_MISC_OPTIONS = "\nMiscellaneous:\n  -V, --version             display version information and exit\n      --help                display this help text and exit\n";
const char* HELP_TEXT_OUTPUT_OPTIONS = "\nOutput control:\n  -n, --line-number         print line number with output lines\n  -H, --with-filename       print file name with output lines\n  -h, --no-filename         suppress the file name prefix on output\n  -Z, --null                print 0 byte after FILE name\n";
const char* HELP_TEXT_END = "\nWhen FILE is '-', read standard input. With no FILE, read '-'.\nWith fewer than two FILEs, assume -h.\nExit status is 0 if any line is selected, 1 otherwise;\nif any error occurs, the exit status is 2.\n";

void setBit(char flag, uint16_t* bitMask, uint16_t* errBitMask) {
    switch (flag) {
        case 'V':
            *bitMask |= OPTS_VERSION_BIT;
            break;
        case 'n':
            *bitMask |= OPTS_LINE_NUMBER_BIT;
            break;
        case 'H':
            *bitMask |= OPTS_FILE_NAME_BIT;
            break;
        case 'h':
            *bitMask |= OPTS_NO_FILE_NAME_BIT;
            break;
        case 'Z':
            *bitMask |= OPTS_NULL_AFTER_FILE_BIT;
            break;
        default:
            *errBitMask |= ERR_INVALID_OPT_BIT;
            break;
    }
}

int main(int argc, char** argv) {
    uint16_t errFlags = 0;
    uint8_t selFlags = 0;

    uint16_t opts = 0;
    uint8_t optCount = 0;

    FILE* pFile;

    int width, patternLoc, lineNumber, fileCount;

    /* Allocate input buffer */
    char line[INPUT_BUFFER_SIZE];

    /* Used in for loops */
    int i = 0;

    if (argc <= 1) {
        fprintf(stderr, UNKNOWN_TEXT, *argv, *argv);
        return 2;
    }


    for (i = 1; i < argc; i++) {
#ifdef DEBUG_PRINTS
        printf("%s\n", argv[i]);
#endif
        if (*(argv[i]) == '-') {
            optCount++;
            
            width = strlen(argv[i]);

            if (width <= 1) {
                errFlags |= ERR_INVALID_OPT_BIT;
                break;
            }

            if (width == 2) {
                if (argv[i][1] == '-') {
                    /* Break from for loop, read rest as input */
                    break;
                }
                setBit(argv[i][1], &opts, &errFlags);

                if (errFlags) {
                    fprintf(stderr, "%s: Invalid option -- '%c'\n", *argv, argv[i][1]);
                }
            } else {
                if (argv[i][1] != '-') {
                    char* c = argv[i] + 1;
                    while (*c) {
                        setBit(*c, &opts, &errFlags);
                        if (errFlags) {
                            fprintf(stderr, "%s: Invalid option -- '%c'\n", *argv, *c);
                        }
                        c++;
                    }
                } else if (strcmp(argv[i], "--version") == 0) {
                    opts |= OPTS_VERSION_BIT;
                } else if (strcmp(argv[i], "--help") == 0) {
                    opts |= OPTS_HELP_BIT;
                } else if (strcmp(argv[i], "--line-number") == 0) {
                    opts |= OPTS_LINE_NUMBER_BIT;
                } else if (strcmp(argv[i], "--with-filename") == 0) {
                    opts |= OPTS_FILE_NAME_BIT;
                } else if (strcmp(argv[i], "--no-filename") == 0) {
                    opts |= OPTS_NO_FILE_NAME_BIT;
                } else if (strcmp(argv[i], "--null") == 0) {
                    opts |= OPTS_NULL_AFTER_FILE_BIT;
                } else {
                    errFlags |= ERR_INVALID_OPT_BIT;
                    fprintf(stderr, "%s: Invalid option -- '%s'\n", *argv, argv[i]);
                }
            }
        } else {
            break;
        }
    }

    if (opts & OPTS_VERSION_BIT) {
        printf(VERSION_TEXT);
        return 1;
    }

    if (opts & OPTS_HELP_BIT) {
        printf(HELP_TEXT, *argv, *argv);
        printf(HELP_TEXT_PATTERN_OPTIONS);
        printf(HELP_TEXT_MISC_OPTIONS);
        printf(HELP_TEXT_OUTPUT_OPTIONS);
        printf(HELP_TEXT_END);
        return 1;
    }

    if ((optCount + 1 >= argc) || errFlags) {
        fprintf(stderr, UNKNOWN_TEXT, *argv, *argv);
        return 2;
    }

#ifdef DEBUG_PRINTS
    if (opts & OPTS_VERSION_BIT) {
        printf("%s: %s flag SET\n", *argv, "OPTS_VERSION_BIT");
    }
    if (opts & OPTS_HELP_BIT) {
        printf("%s: %s flag SET\n", *argv, "OPTS_HELP_BIT");
    }
    if (opts & OPTS_LINE_NUMBER_BIT) {
        printf("%s: %s flag SET\n", *argv, "OPTS_LINE_NUMBER_BIT");
    }
    if (opts & OPTS_FILE_NAME_BIT) {
        printf("%s: %s flag SET\n", *argv, "OPTS_FILE_NAME_BIT");
    }
    if (opts & OPTS_NO_FILE_NAME_BIT) {
        printf("%s: %s flag SET\n", *argv, "OPTS_NO_FILE_NAME_BIT");
    }
    if (opts & OPTS_NULL_AFTER_FILE_BIT) {
        printf("%s: %s flag SET\n", *argv, "OPTS_NULL_AFTER_FILE_BIT");
    }
    if (opts & OPTS_READ_STDIN_BIT) {
        printf("%s: %s flag SET\n", *argv, "OPTS_READ_STDIN_BIT");
    }
    if (errFlags & ERR_INVALID_OPT_BIT) {
        printf("%s: %s flag SET\n", *argv, "ERR_INVALID_OPT_BIT");
    }
    if (errFlags & ERR_FILE_NOT_FOUND_BIT) {
        printf("%s: %s flag SET\n", *argv, "ERR_FILE_NOT_FOUND_BIT");
    }
#endif

    /* Pattern = argv[optCount + 1] */
    patternLoc = optCount + 1;

#ifdef DEBUG_PRINTS
    printf("%s: Successfully created input buffer\n", *argv);
#endif

    fileCount = argc - optCount - 2;
    
    if (optCount + 2 == argc) {
        opts |= OPTS_READ_STDIN_BIT;
    } else {
        for (i = optCount + 2; i < argc; i++) {
            selFlags = 0;

            if (strcmp(argv[i], "-") == 0) {
                opts |= OPTS_READ_STDIN_BIT;
                break;
            }

            /* Filename: argv[i] */
            pFile = fopen(argv[i], "r");

            if (pFile != NULL) {
#ifdef DEBUG_PRINTS
                printf("%s: %s: File opened successfully\n", *argv, argv[i]);
#endif

                lineNumber = 0;
                while (fgets(line, INPUT_BUFFER_SIZE, pFile) != NULL) {
                    char* c = line;
                    while (*c) {
                        if (*c == *(argv[patternLoc])) {
                            if (strncmp(argv[patternLoc], c, strlen(argv[patternLoc])) == 0) {
                                selFlags |= SEL_LINE_MATCHED_BIT;

                                /* Print selected line */
                                if ((opts & OPTS_FILE_NAME_BIT) || (fileCount > 1 && !(opts & OPTS_NO_FILE_NAME_BIT))) {
                                    printf("%s", argv[i]);
                                    if (opts & OPTS_NULL_AFTER_FILE_BIT) {
                                        printf("\\0");
                                    } else {
                                        printf(":");
                                    }
                                }
                                if (opts & OPTS_LINE_NUMBER_BIT) {
                                    printf("%i:", lineNumber);
                                }
                                printf("%s", line);
                                /* END Print selected line */
                            }
                        }
                        c++;
                    }
                    /* insert printing here */
                    lineNumber++;
                }

                fclose(pFile);
#ifdef DEBUG_PRINTS
                printf("%s: %s: File closed\n", *argv, argv[i]);
#endif
            } else {
                fprintf(stderr, "%s: %s: No such file\n", *argv, argv[i]);
            }
        }
    }

    if (opts & OPTS_READ_STDIN_BIT) {
        pFile = stdin;
        lineNumber = 0;
        while (fgets(line, INPUT_BUFFER_SIZE, pFile) != NULL) {
            char* c = line;
            while (*c) {
                if (*c == *(argv[patternLoc])) {
                    if (strncmp(argv[patternLoc], c, strlen(argv[patternLoc])) == 0) {
                        selFlags |= SEL_LINE_MATCHED_BIT;

                        /* Print selected line */
                        if ((opts & OPTS_FILE_NAME_BIT) || (fileCount > 1 && !(opts & OPTS_NO_FILE_NAME_BIT))) {
                            printf("(standard input)");
                            if (opts & OPTS_NULL_AFTER_FILE_BIT) {
                                printf("\\0");
                            } else {
                                printf(":");
                            }
                        }
                        if (opts & OPTS_LINE_NUMBER_BIT) {
                            printf("%i:", lineNumber);
                        }
                        printf("%s", line);
                        /* END Print selected line */
                    }
                }
                c++;
            }
            lineNumber++;
        }
    }

    if (errFlags) {
        return 2;
    }

    if (selFlags) {
        return 1;
    }

#ifdef DEBUG_PRINTS
    printf("%s: Got to return 0\n", *argv);
#endif
    return 0;
}
