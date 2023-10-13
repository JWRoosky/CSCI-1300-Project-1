#include <iostream>
#include <string>
using namespace std;


// a - z === 97 - 122
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