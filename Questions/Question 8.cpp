// CSCI 1300 Fall 2023
// Author: Jack Rueschhoff
// TA: Anush Kumar Venkatesh
// Question 1
#include <iostream>
#include <string>
using namespace std;

bool containsDigits(string message){
    for (int i = 0; i < message.size(); i++){
        if (isdigit(message[i])){
            return true;
        }
    }
    return false;
}

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

char decryptChar(char c, int method_choice, string key1, string key2){
    if (method_choice == 1){
        return shiftChar(c, -1);
    }
    else if (method_choice == 2){
        return shiftChar(c, (-1 * getMethod2ShiftAmount(key1)));
    }
    else if (method_choice == 3){
        return shiftChar(c, (-1 * getMethod3ShiftAmount(key1, key2)));
    }
    else{
        cout << "Invalid decryption type " << endl;
        return c;
    }
}

string decryptMessage(string message, int method_choice, string key1, string key2){
    string temp = "";
    if (method_choice == 1){
        for (int i = 0; i < message.size(); i++){
            temp += decryptChar(message[i], method_choice, key1, key2);
        }
    }
    else if (method_choice == 2){
        for (int i = 0; i < message.size(); i++){
            temp += decryptChar(message[i], method_choice, key1, key2);
        }
    }
    else if (method_choice == 3){
        for (int i = 0; i < message.size(); i++){
            temp += decryptChar(message[i], method_choice, key1, key2);
        }
    }
    else if (method_choice == 4){
        for (int i = 1; i <= message.size(); i++){
            if ((i % 3) == 1){
                temp += decryptChar(message[i - 1], 1, key1, key2);
            }
            else if ((i % 3) == 2){
                temp += decryptChar(message[i - 1], 2, key1, key2);
            }
            else if ((i % 3) == 0){
                temp += decryptChar(message[i - 1], 3, key1, key2);
            }
        }
    }
    else{
        cout << "Invalid decryption method" << endl;
        return message;
    }
    return temp;
}

int main(){
    bool program_running = true;
    bool set_key_1 = false;
    bool set_key_2 = false;
    bool set_encryption_method;
    int menu_choice;
    int method_choice;
    string key1 = "";
    string key2 = "";
    string message;

    while (program_running == true){
        
        cout << "Please input 1-6 followed by enter to navigate the menu: " << endl;
        cout << "1. Set Encryption Key 1" << endl;
        cout << "2. Set Encryption Key 2" << endl;
        cout << "3. Select Encryption Method" << endl;
        cout << "4. Encrypt Message" << endl;
        cout << "5. Decrypt Message" << endl;
        cout << "6. Exit Program " << endl;

        cin >> menu_choice;
        cin.clear();
        cin.ignore(1000000000, '\n');
        if (menu_choice > 6 || menu_choice < 1){
            do {
                cout << "Invalid input" << endl;
                cin >> menu_choice;
                cin.clear();
                cin.ignore(100000000, '\n');
            }while(menu_choice > 6 || menu_choice < 1);
            
        }
        if (menu_choice == 1){
            do {
                cout << "Enter key:" << endl;
                getline(cin, key1);
                if (key1.size() < 1){
                    cout << "Invalid key" << endl;
                }
            }while(key1.size() < 1);
            cout << "Successfully set encryption key1 to " << key1 << endl;
            set_key_1 = true;
        }   

        else if (menu_choice == 2){
            do {
                cout << "Enter key: " << endl;
                getline(cin, key2);
                if (key2.size() < 1){
                    cout << "Invalid key" << endl;
                }
            }while(key2.size() < 1);
            cout << "Successfully set encryption key2 to " << key2<< endl;
            set_key_2 = true;
        }

        else if (menu_choice == 3){
            cout << "Please input 1-4 to decide encryption technique." << endl;
            cout << "1. Method1 only (shift by 1)" << endl;
            cout << "2. Method2 only (shift by first key)" << endl;
            cout << "3. Method3 only (shift by both keys)" << endl;
            cout << "4. Mix of Method1, Method2, Method3" << endl;
            do {
                cin >> method_choice;
                if(method_choice < 1 || method_choice > 4){
                    cout << "Invalid encryption choice"<< endl;
                    cin.clear();
                    cin.ignore(10000000, '\n');
                }
            }while(method_choice < 1 || method_choice > 4);
            cout << "Successfully set encryption type to " << method_choice<< endl;
            set_encryption_method = true;
        }

        else if (menu_choice == 4){
            if (set_encryption_method && set_key_1 && set_key_2){
                cout << "Enter your message to encrypt: " << endl;
                getline(cin, message);
                cout << encryptMessage(message, method_choice, key1, key2) << endl;
            }
            else{
                cout << "You cannot do this until you set both keys and choose an encryption method"<< endl;
            }
        }
        
        else if (menu_choice == 5){
            if (set_encryption_method && set_key_1 && set_key_2){
                cout << "Enter your message to decrypt: " << endl;
                getline(cin, message);
                cout << decryptMessage(message, method_choice, key1, key2) << endl;
            }
            else{
                cout << "You cannot do this until you set both keys and choose an encryption method"<< endl;
            }
        }

        else if (menu_choice == 6){
            cout << "Goodbye." << endl;
            return 0;
        }
    }
    return 1;
}