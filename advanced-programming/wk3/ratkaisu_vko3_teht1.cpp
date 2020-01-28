#include <stdint.h> // uint8_t
#include <stdio.h>  // printf
#include <math.h>   // acos

#define PI 3.14159265

enum class TriangleType: uint8_t {
    // Triangle with different length sides
    Scalene = 1,
    // Triangle with two equal length sides
    Isosceles = 2,
    // Triangle with all equal length sides
    Equilateral = 4,
    // Triangle with one right angle
    Right = 8,
    // Not a triangle
    Error = 0
};

double getDoubleInput(bool zeroAllowed = true) {
    char in[16];
    double dIn = 0;

    while (1) {
        if (fgets(in, 16, stdin) == NULL) {
            printf("Invalid input, try again: ");
            continue;
        }

        dIn = strtod(in, NULL);
        if (!zeroAllowed && dIn == 0) {
            printf("Invalid input, try again: ");
            continue;
        }
        break;
    }
    return dIn;
}

bool isTriangular(double a, double b, double c) {
    // Verify the sum of 2 sides is greater than the remaining side, for all 3 lines
    if (a + b > c && a + c > b && b + c > a) {
        double angleSum = 0;
        // Law of cosines
        double angleA = acos(((b*b) + (c*c) - (a*a)) / (2 * b * c)) * 180.0 / PI;
        angleSum += angleA;
        angleA = round(angleA * 100) / 100;
        double angleB = acos(((a*a) + (c*c) - (b*b)) / (2 * a * c)) * 180.0 / PI;
        angleSum += angleB;
        angleB = round(angleB * 100) / 100;
        double angleC = acos(((a*a) + (b*b) - (c*c)) / (2 * a * b)) * 180.0 / PI;
        angleSum += angleC;
        angleC = round(angleC * 100) / 100;

        angleSum = round(angleSum * 100) / 100;

        printf("A = %.2f \nB = %.2f \nC = %.2f \n", angleA, angleB, angleC);
        printf("Sum of angles = %.2f \n", angleSum);
        printf("Is right triangle = %s \n", (a*a)+(b*b)==(c*c)||(b*b)+(c*c)==(a*a)||(a*a)+(c*c)==(b*b) ? "true" : "false");

        return true;
    }

    return false;
}

bool isTriangular(double a, double b, double c, TriangleType& type) {
    if (isTriangular(a, b, c)) {
        // Pythagorean
        if ((a*a) + (b*b) == (c*c) || (a*a) + (c*c) == (b*b) || (b*b) + (c*c) == (a*a)) type = TriangleType::Right;
        // All sides equal
        else if (a == b && b == c) type = TriangleType::Equilateral;
        // Any two sides equal
        else if (a == b || b == c || a == c) type = TriangleType::Isosceles;
        // No sides equal
        else type = TriangleType::Scalene;

        return true;
    }

    // Not a triangle
    type = TriangleType::Error;
    return false;
}

int main() {
    double a, b, c;
    while (1) {
        printf("\nProgram will run indefinitely, terminate with Ctrl+C to quit\n\n");
        printf("Input 1st line: ");
        a = getDoubleInput(false);
        printf("Input 2nd line: ");
        b = getDoubleInput(false);
        printf("Input 3rd line: ");
        c = getDoubleInput(false);

        printf("Inputs: [%f, %f, %f]\n", a, b, c);

        TriangleType type;
        if (isTriangular(a, b, c, type)) {
            switch (type) {
                case TriangleType::Scalene:
                    printf("Lines can be made into a scalene triangle\n");
                    break;
                case TriangleType::Isosceles:
                    printf("Lines can be made into an isosceles triangle\n");
                    break;
                case TriangleType::Equilateral:
                    printf("Lines can be made into an equilateral triangle\n");
                    break;
                case TriangleType::Right:
                    printf("Lines can be made into a right triangle\n");
                    break;
                default:
                    printf("Lines can be made into a triangle, but something went wrong in checking for type\n");
                    break;
            }
        } else {
            printf("Lines cannot be made into a triangle\n");
        }
    }

    return 0;
}
