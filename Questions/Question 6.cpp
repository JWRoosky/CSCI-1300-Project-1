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
    while (method_choice > 3 || method_choice < 1){
        cout << "Invalid encryption method" << endl;
        cin >> method_choice;
    }

    if (method_choice == 1){
        return shiftChar(c, 1);
    }
    else if (method_choice == 2){
        int shift = getMethod2ShiftAmount(key1);
        return shiftChar(c, shift);
    }
    else{
        int shift = getMethod3ShiftAmount(key1, key2);
        return shiftChar(c, shift);
    }
}

string encryptMessage(string message, int method_choice, string key1, string key2){
    string temp = "";
    if (method_choice == 1){
        for (int i = 0; i < message.size(); i++){
            temp += encryptChar(message[i], method_choice, key1, key2);
        }
    }
    else if (method_choice == 2){
        for (int i = 0; i < message.size(); i++){
            temp +=     shiftChar(message[i], getMethod2ShiftAmount(key1));
        }   
    }
    else if (method_choice == 3){
        for (int i = 0; i < message.size(); i++){
            temp += shiftChar(message[i], getMethod3ShiftAmount(key1, key2));
        }
    }
    else if(method_choice == 4){
        for (int i = 1; i <= message.size(); i++){
            if ((i%3) == 1){
                temp += encryptChar(message[i-1], 1, key1, key2);
            }
            else if ((i % 3) == 2){
                temp += encryptChar(message[i-1], 2, key1, key2);
            }
            else if ((i % 3) == 0){
                temp += encryptChar(message[i-1], 3, key1, key2);
            }
        }
    }
    else{
        cout << "Invalid encryption method" << endl;
        return message;
    }
    return temp;
}