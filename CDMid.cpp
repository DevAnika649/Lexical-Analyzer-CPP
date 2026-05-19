#include <bits/stdc++.h>
using namespace std;

bool isKeyword(const string& word) {
    return word == "int" || word == "float" || word == "double" ||
           word == "string" || word == "main" || word == "if" ||
           word == "else" || word == "return" || word == "cout";
}

bool isOperator(const string& word) {
    return word == "=" || word == "+" || word == "-" ||
           word == "/" || word == "*" || word == ">" || word == "<";
}

bool isPunctuation(const string& word) {
    return word == ";" || word == "," || word == "\"" ||
           word == "(" || word == ")" || word == "{" ||
           word == "}" || word == "[" || word == "]";
}

bool isNumberConstant(const string& word) {
    return !word.empty() && word[0] >= '0' && word[0] <= '9';
}

bool isStringConstant(const string& word) {
    return word.length() >= 2 && word.front() == '"' && word.back() == '"';
}

void classifyWord(const string& word) {
    if (isKeyword(word)) {
        cout << word << " : keyword" << endl;
    }
    else if (isOperator(word)) {
        cout << word << " : operator" << endl;
    }
    else if (isPunctuation(word)) {
        cout << word << " : punctuation" << endl;
    }
    else if (isNumberConstant(word)) {
        cout << word << " : constant" << endl;
    }
    else if (isStringConstant(word)) {
        cout << word << " : constant" << endl;
    }
    else {
        cout << word << " : identifier" << endl;
    }
}

void processLine(const string& line, int lineNumber) {
    if (line.empty()) return;

    cout << "in line : " << lineNumber << endl;

    stringstream ss(line);
    string word;

    while (ss >> word) {
        classifyWord(word);
    }

    cout << endl;
}

int main() {
    ifstream file("myfile.txt");
    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        processLine(line, lineNumber);
        lineNumber++;
    }

    file.close();
    return 0;
}
