#include <iostream>
#include <string>
#include "CommandProcessor.h"
#include "CommandExecutor.h"
using namespace std;


int main(){   
    string command;
    string* argsArray = nullptr;
    getline(cin, command);
    CommandProcessor cmdprcss(command);
    argsArray = cmdprcss.getCommandArray();
    cmdprcss.printTokens();
    CommandExecutor::executeCommand(argsArray);
    delete[] argsArray;
    argsArray = nullptr;
    return 0;
}

