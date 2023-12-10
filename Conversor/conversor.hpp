#include <iostream>
#include <string>
#include <bitset>
#include <math.h>
#include <sstream>
using namespace std;

class Conversor
{
public:
    int number;
    string auxtext;
    string binary;
    Conversor();
    ~Conversor();
    void ConversorToBin(string text, int type);
    void Conver(int type);
    void ConversorToOctal(string text);
};