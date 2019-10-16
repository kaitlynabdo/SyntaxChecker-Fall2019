#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool delimeterMatching(string s, GenStack<char> syn, int line){
    for (int i = 0; i < s.length()-1; ++i){
        if(s[i] == '{'){ //adding the initial bracket to the stack
            syn.push(s[i]);
        }
        else if (s[i] == '('){
            syn.push(s[i]);
        }
        else if (s[i] == '['){
            syn.push(s[i]);
        }
        if(s[i] == '}' && syn.peek() != '{'){ // if pair was not completed
            cout << "Error on line " << line << ". Missing compliment to " << syn.peek() << endl;
            return false;
        }
        else if(s[i] == ']' && syn.peek() != '['){
            cout << "Error on line " << line << ". Missing compliment to " << syn.peek() << endl;
            return false;
        }
        else if(s[i] == ')' && syn.peek() != '('){
            cout << "Error on line " << line << ". Missing compliment to " << syn.peek() << endl;
            return false;
        }
        else if(s[i] == '}' && syn.peek() == '{'){ // completion of delimeter pair
            syn.pop();
        }
        else if(s[i] == ']' && syn.peek() == '['){
            syn.pop();
        }
        else if(s[i] == ')' && syn.peek() == '('){
            syn.pop();
        }
    }
    return true; // if its not false, it must be true
}

bool repeatWithNewFile(string file, GenStack<char> syn, char response){
    while(response == '0'){
        int line = 0;
        string text = " ";
        cout << "Please enter a new file path." << endl;
        cin >> file;
        ifstream infile (file);
        if(!infile.is_open()){
            cout << "File not found." << endl;
            return 0;
            while (!infile.eof()){ //rechecking the new file
                infile >> text;
                ++line; //counting lines
                if(delimeterMatching(text, syn, line) == false){ // if its false, return false
                    bool res1 = delimeterMatching(text, syn, line);
                    return false;
                }
            }
            infile.clear();
        }
        cout << "No errors were found. Would you like to find another file? Type '0' for yes and '1' for no." << endl;
        cin >> response;
    }
    return true;
}


int main(int argc, char **argv){
    GenStack<char> syntaxChecker(15);
    string filePath = "Untitled.txt";
    if (argc > 1){ // typing more than one argument, then use the imput from the command line (file name)
        filePath = argv[1];
    }
    ifstream in_file;
    in_file.open(filePath); // finding file
    if(!in_file.is_open()){
        cout << "File not found." << endl;
        return 0;
    }
    string text = " ";
    int line = 0;
    while (!in_file.eof()){
        in_file >> text;
        ++line; //counting lines
        if(delimeterMatching(text, syntaxChecker, line) == false){ // if the delimeter comes back false aka errors
            bool res = delimeterMatching(text, syntaxChecker, line); // complete method
            in_file.close();
            return 0; //terminate program
        }
    }
    in_file.clear();
    cout << "No errors were found. Would you like to find another file?" << endl;
    char response = '0';
    cout << "Type '0' to enter another file path and type '1' to exit." << endl;
    cin >> response;
    if (response == '0'){ //repeat with new file
        bool rep = repeatWithNewFile(filePath, syntaxChecker, response);
    }
    in_file.close();
    return 0;
}
