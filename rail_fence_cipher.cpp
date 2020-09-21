/*
    Rail fence cipher algorithm
    Author: Igor Sosnowicz
*/

#include <iostream>
#include <vector>
using namespace std;

class Container {
    vector <string> rows;
public:
    Container(unsigned int size){
        for (int i=0;i<size;i++)
            rows.push_back(string(""));
    }

    void add(char character, int rowId){
        rows.at(rowId-1) += character;
    }

    void display(){
        int size = rows.size();
        for (int i=0;i<size;i++)
           cout << rows.at(i);
    }

};

int function(int x, int storeys){

    x %= 2*storeys-2;

    if (x == 0)
        x = 2;

    if (x >= 1 && x <= storeys)
        return x;

    else if ( x > storeys && x <= 2 * storeys - 2 ){
        int difference =  x - storeys;
        return (x - 2*difference);
    }

    else
        throw new exception();
}

int main(){
    int storeys;
    string word;

    cout << "Insert the height of the fence: ";
    cin >> storeys;

    cout << "Insert the word to encode: ";
    cin >> word;

    Container encodedWord(storeys);
    int wordLength = word.length();
    for (int i=1; i<=wordLength; i++){
        int rowId = function(i, storeys);
        encodedWord.add(word[i-1], rowId);
    }

    encodedWord.display();

    return 0;
}
