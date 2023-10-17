#include <iostream>
#include <string>
using namespace std;


// a -> z == 97 -> 122
char shiftChar(char c, int shift){
    char result;
    if (isupper(c)){
        result = char(int(c + shift - 65) % 26 + 65);
    }
    else{
        result = char(int(c + shift - 97) % 26 + 97);
    }

    return result;
}

int getMethod2ShiftAmount(string key){
    int vowels = 0;
    for (int i = 0; i < key.size(); i++){
        if (key[i] == 'a' || key[i] == 'e' || key[i] == 'i' || key[i] == 'o' || key[i] == 'u' || key[i] == 'y'){
            vowels++;
        }
    }
    int shift = (vowels + key.size()) % 26;

    return shift;
}


int getMethod3ShiftAmount(string key1, string key2){
    int counter = 0;
    for (int i = 0; i < key1.size(); i++){
        for (int j = 0; j < key2.size(); j++){
            if (key1[i] == key2[j]){
                counter++;
            }
        }
    }
    return counter % 26;
}

char decryptChar(char c, int method_choice, string key1, string key2){
    if (method_choice > 3 || method_choice < 1){
        cout << "Invalid decryption method" << endl;
        return c;
    }
    else{
        if (!isupper(c) && isalpha(c)){
            if (method_choice == 1){
                return shiftChar(c, 25); // going forward 25 is the same as going back and wrapping around 1
            }
            else if (method_choice == 2){
                int shift = getMethod2ShiftAmount(key1);
                return shiftChar(c, 26-shift); // same idea here
            }
            else{
                int shift = getMethod3ShiftAmount(key1, key2);
                return shiftChar(c, 26-shift); // same idea here
            }
        }
        else{
            return c;
        }
    }
}
