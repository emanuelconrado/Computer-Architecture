#include "conversor.hpp"

Conversor::Conversor(){

}

Conversor::~Conversor(){

}

void Conversor::ConversorToBin(string text, int type){

    if(type == 1){
        number = stoi(text);
        binary = bitset<16>(number).to_string();
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
        int j = 0;
        int auxbinary = 0;
        int count = 0;
        string result;
        stringstream stream;
        string auxresult;

        //if number

        for(int i = 0; i < binary.length()/4; i++){
            j = j + 3;
            string auxbin;
            for(int k = 0; k < 4; k++){
                if(count == 0){
                    auxbin = binary[j - k];
                    count = count + 1;
                }else{
                    auxbin = binary[j - k] + auxbin;
                }
            }

            auxbinary = stoi(auxbin);

            if(auxbinary < 1010){
                int intauxresult = 0;
                int l = 3;
                for(int a = 0; a < 4; a++){
                    if(auxbin[l] == '1'){
                        intauxresult = (pow(2,a)*1) + intauxresult;
                    }
                    l--;
                }
                stream << intauxresult;
            }

                stream >> auxresult;
                result = result + auxresult;

        }

        //if char


    }


}