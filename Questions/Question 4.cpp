#include <iostream>
#include <string>
using namespace std;


// a -> z == 97 -> 122
char shiftChar(char c, int shift){
    char result;
    if (!isupper(c) && isalpha(c)){
        result = char(int(c + ((shift % 26) +26) - 97) % 26 + 97);
    }
    else{
        result = c;
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

char encryptChar(char c, int method_choice, string key1, string key2){
    if (method_choice == 1){
        return shiftChar(c, 1);
    }
    else if (method_choice == 2){
        int shift = getMethod2ShiftAmount(key1);
        return shiftChar(c, shift);
    }
    else if (method_choice == 3){
        int shift = getMethod3ShiftAmount(key1, key2);
        return shiftChar(c, shift);
    }
    else{
        cout << "Invalid encryption method" << endl;
        return c;
    }
}