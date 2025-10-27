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
    string* command_array = new string[20];
    string comm = "";

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
        int arg_num = 0;
        string* comm_arr = new string[20];

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                comm_arr[arg_num] = s.substr(0, i);
                s.erase(0, i + 1);
                i = 0;
                arg_num++;
            }
        }
        comm_arr[arg_num] = s;
        return comm_arr;
    }

public:
    CommandProcessor(string comm) {
        this->command_array = this->commandTokenizer(comm);
    }

    void printTokens() {
        cout << "Command tokens:" << endl;
        for (int i = 0; i < 20 && !this->command_array[i].empty(); i++) {
            cout << i << ": " << this->command_array[i] << endl;
        }
    }

    string* getCommandArray() {
        return this->command_array;
    }

    ~CommandProcessor() {
        delete[] this->command_array;
    }
};

#endif

