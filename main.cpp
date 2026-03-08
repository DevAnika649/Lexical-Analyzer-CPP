#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool isKeyword(string token) {
    if(token=="int" || token=="float" || token=="if" || token=="else" || token=="for" || token=="while")
        return true;
    return false;
}

bool isNumber(string token) {
    for(int i=0;i<token.length();i++){
        if(!isdigit(token[i]))
            return false;
    }
    return true;
}

bool isIdentifier(string token) {
    if(isalpha(token[0]))
        return true;
    return false;
}

int main() {

    ifstream file("input.txt");
    string line, token;

    while(getline(file,line)) {

        stringstream ss(line);

        while(ss >> token) {

            if(isKeyword(token))
                cout << token << " -> Keyword" << endl;

            else if(isNumber(token))
                cout << token << " -> Number" << endl;

            else if(isIdentifier(token))
                cout << token << " -> Identifier" << endl;

            else
                cout << token << " -> Symbol" << endl;
        }
    }

    file.close();
}






