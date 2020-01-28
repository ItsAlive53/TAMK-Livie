#ifndef __MYLIB_INCLUDED__
#define __MYLIB_INCLUDED__

std::string getString(std::istream& istream, std::string promptMessage);
char getChar(std::istream& istream, std::string promptMessage);
int getInt(std::istream& istream, std::string promptMessage);
float getFloat(std::istream& istream, std::string promptMessage);
double getDouble(std::istream& istream, std::string promptMessage);

std::vector<int> getRandomNumbers(int amount, int min, int max, bool unique = false);
std::vector<int> getUniqueRandomNumbers(int amount, int min, int max);

std::vector<int> sortVectorInt(std::vector<int> vec);

#endif // #ifndef __MYLIB_INCLUDED__
