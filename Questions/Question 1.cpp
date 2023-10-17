#include <iostream>
#include <string>
using namespace std;


// a - z === 97 - 122
char shiftChar(char c, int shift){
    char result; // Variable to contain shifted character
    if (!isupper(c) && isalpha(c)){ // Ensures c is not uppercase and is an alphabetic character
        result = char(int(c + ((shift % 26) +26) - 97) % 26 + 97);
    }
    else{
        result = c;
    }

    return result;
}
