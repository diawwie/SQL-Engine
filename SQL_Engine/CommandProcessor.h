// CommandProcessor.h
#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <string>
#include <regex>
#include <iostream>
#include <cstring>
using namespace std;

class CommandProcessor {
private:
    string* commandArray = nullptr;
    string comm = "";
    int nrArgs = 0;

    string trim(const string& s) {
        return regex_replace(s, regex("^\\s+|\\s+$"), "");
    }

    string upperize(string& s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = toupper(s[i]);
        }
        return s;
    }

    string* commandTokenizer(string s) {
        s = trim(upperize(s));
        int argNum = 0;
        string* commArr = new string[20];

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                commArr[argNum] = s.substr(0, i);
                s.erase(0, i + 1);
                i = 0;
                argNum++;
            }
        }
        commArr[argNum] = s;
        this->nrArgs = argNum+1;

        return commArr;
    }

public:
    CommandProcessor(string comm) {
        this->commandArray = new string[comm.length()+1];
        this->commandArray = this->commandTokenizer(comm);
    }

    void printTokens() {
        cout << "Command tokens:" << endl;
        for (int i = 0; i < this->nrArgs && !this->commandArray[i].empty(); i++) {
            cout << i << ": " << this->commandArray[i] << endl;
        }
    }

    string* getCommandArray() {
        string* copyCommand = new string[this->nrArgs];
        for (int i = 0; i < this->nrArgs; i++) {
            copyCommand[i] = this->commandArray[i];
        }

        return copyCommand;
    }

    ~CommandProcessor() {
        delete[] this->commandArray;
        this->commandArray = nullptr;
    }
};

#endif

