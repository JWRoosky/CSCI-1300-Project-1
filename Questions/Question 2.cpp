#include <iostream>
#include <string>
using namespace std;

int getMethod2ShiftAmount(string key){
    int vowels = 0; // counter variable
    for (int i = 0; i < key.size(); i++){
        if (key[i] == 'a' || key[i] == 'e' || key[i] == 'i' || key[i] == 'o' || key[i] == 'u' || key[i] == 'y'){
            vowels++; // increments the counter for each vowel in the key.
        }
    }
    int shift = (vowels + key.size()) % 26; // calculates the shift value based on the parameters of the problem

    return shift; // returns the shift value.
}
