#include <iostream>
#include <math.h>
using namespace std;

unsigned int hashInput(string input){
    unsigned int numericValue = 0, alphabetSize = 'Z' - 'A' + 1, patternLength = input.length();
    for (int i = 0; i < patternLength; i++){
        numericValue += ((char)input[i] - ('A' - 1)) * pow(alphabetSize+1, i);
    }
    return numericValue;
}

int main(){
    string pattern, text;

    cout << "Provide the TEXT the algorithm is supposed to search in [block letters only]: ";
    cin >> text;
    cout << "Provide the PATTERN the algorithm is supposed to search for [block letters only]: ";
    cin >> pattern;

    unsigned int patternLength = pattern.length();
    unsigned int textLength = text.length();

    int patternValue = hashInput(pattern);
    int textSubstringValue;

    if (patternLength > textLength){
        cout << "Pattern cannot be longer than text!";
        return -1;
    }

    for (int i = 0; i < textLength - patternLength + 1; i++){
        textSubstringValue = hashInput(text.substr(i, patternLength));
        if (textSubstringValue == patternValue)
            if (text.substr(i, patternLength) == pattern)
                cout << "A match was found at " << i << ".\n";
    }


    return 0;
}
