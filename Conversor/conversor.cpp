#include "conversor.hpp"

Conversor::Conversor(){

}

Conversor::~Conversor(){

}

void Conversor::ConversorToBin(string text, int type){

    auxtext = text;

    if(type == 1){
        number = stoi(text);
        binary = bitset<16>(number).to_string();
        binary = binary.substr(binary.find('1'));
        
    }

    if(type == 2){
        int textlength = text.length() * 4;
        string result = "2000";
        string bin;
        int count = 0;
        int ramainder = 0;
        for(int i = 0; i < text.length(); i++){

            //if number
            if(text[i] >= '0' && text[i] <= '9'){
                ramainder = text[i] - '0';
                for(int j = 3; j >= 0; j--){
                    if(ramainder % 2 != 0){
                        result[j] = '1';
                    }else{
                        result[j] = '0';
                    }
                    ramainder = ramainder/2;
                } 
                if(count == 0){
                    bin = result;
                }else{
                    bin = bin + result;
                }
                count = count + 1;
            }

            //if char;
            if(text[i] >= 65 && text[i] <= 70){
                int intchar = text[i];
                switch (intchar)
                {
                case 65:
                    result = "1010";
                    break;
                case 66:
                    result = "1011";
                    break;
                case 67:
                    result = "1100";
                    break;
                case 68:
                    result = "1101";
                    break;
                case 69:
                    result = "1110";
                    break;
                default:
                    result = "1111";
                    break;
                }

                if(count == 0){
                    bin = result;
                }else{
                    bin = bin + result;
                }

                count = count + 1;
            }
        }
        binary = bin;
    }

    if(type == 3){
        binary = text;
        if(binary.length()%4 != 0){
            binary = '0' + binary;
        }
    }

    if(type == 4){
        int aux = text.length() - 1;
        int auxbinary = 0;
        for(int i = aux; i >= 0; i--){
            number =  text[i] - '0';
            binary = bitset<3>(number).to_string() + binary;

        }
        cout << binary << endl;
    }
}

void Conversor::Conver(int type){

    //Decimal

    if(type == 1){
        int j = binary.length() - 1;
        int result = 0;
        for(int i = 0; i < binary.length(); i++){
            if(binary[j] == '1'){
                result = (pow(2,i) * 1) + result;
            };
            j--;
        }
        cout << result << endl;
    }

    //Hexadecimal

    if(type == 2){
        int j = 3;
        int auxbinary = 0;
        int count = 0;
        string result;
        string auxresult;

        while(binary.length() % 4 != 0){
            binary = '0' + binary;
        }

        for(int i = 0; i < binary.length()/4; i++){
            string auxbin;
            for(int k = 0; k < 4; k++){
                if(count == 0){
                    auxbin = binary[j - k];
                    count = count + 1;
                }else{
                    auxbin = binary[j - k] + auxbin;
                }
            }
            j = j + 4;

            auxbinary = stoi(auxbin);

            if(auxbinary < 1010){
                int intauxresult = 0;
                stringstream stream;
                int l = 3;
                for(int a = 0; a < 4; a++){
                    if(auxbin[l] == '1'){
                        intauxresult = (pow(2,a)*1) + intauxresult;
                    }
                    l--;
                }
                stream << intauxresult;
                stream >> auxresult;

            }else{
                switch (auxbinary)
                {
                case 1010:
                    auxresult = 'A';
                    break;
                case 1011:
                    auxresult = 'B';
                    break;
                case 1100:
                    auxresult = 'C';
                    break;
                case 1101:
                    auxresult = 'D';
                    break;
                case 1110:
                    auxresult = 'E';
                    break;
                default:
                    auxresult = 'F';
                    break;
                }
            }
                result = result + auxresult;
        }

            cout << result << endl;

    }

    if(type == 3){
        string auxbinary;
        auxbinary = binary.substr(binary.find('1'));
        cout << auxbinary << endl;
    }

    if(type == 4){
        ConversorToOctal(auxtext);
    }
}

void Conversor::ConversorToOctal(string text){
    int j = 0;
    int count = 0;
    string result;
    string auxresult;
    while (binary.length() % 3 != 0)
    {
        binary = '0' + binary;
    }

    for(int i = 0; i < binary.length()/3; i++){
        string auxbinary;
        for(int k = 0; k < 3; k++){
            if(count == 0){
                auxbinary = binary[j + k];
                count++;
            }else{
                auxbinary = auxbinary + binary[j + k];
            }
        }

    j = j + 3;
    int intauxresult = 0;
    stringstream stream;
    int l = 2;
        for(int a = 0; a < 3; a++){
            if(auxbinary[l] == '1'){
                intauxresult = (pow(2,a)*1) + intauxresult;
            }
            l--;
        }
        stream << intauxresult;
        stream >> auxresult;

        result = result + auxresult;
    }

    cout << result << endl;
}