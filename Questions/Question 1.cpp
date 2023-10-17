#include <iostream>
#include <string>
using namespace std;


// a - z === 97 - 122
char shiftChar(char c, int shift){
    char result; // Variable to contain shifted character
    if (!isupper(c) && isalpha(c)){ // Ensures c is not uppercase and is an alphabetic character
        result = char(int(c + ((shift % 26) + 26) - 97) % 26 + 97);
    }
    else{
        result = c;
    }

    return result;
}


// Line 10 ensures the shift value is within the valid alphabet range (shift % 26), adds 26 to ensure the shift value is positive, subtracts 97 to ensure
// that 'a' (ASCII 97) is the zero reference point. It is modded by 26 again to ensure it is within valid alphabet range, and then 97 is added to bring it 
// back to the lowercase ASCII values 97 - 122, and then finally casted to char.
