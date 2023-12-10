#include "conversor.hpp"

int main(){

    Conversor conversor;
    string text = "";
    int type = 0;

    char l = 'F';

    cout << "Qual será o tipo de entrada? " << endl;
    cout << "1 - decimal?" << endl;
    cout << "2 - hexadecimal" << endl;
    cout << "3 - binário" << endl;
    cout << "4 - octal" << endl;
    cin >> type;

    cout << "Digite o número: ";
    cin >> text;

    conversor.ConversorToBin(text, type);

    cout << "Deseja converter para: " << endl;
    cout << "1 - decimal?" << endl;
    cout << "2 - hexadecimal" << endl;
    cout << "3 - binário" << endl;
    cout << "4 - octal" << endl;
    cin >> type;

    conversor.Conver(type);

    return 0;
}