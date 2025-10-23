#include <iostream>
#include <string>
#include "CommandProcessor.h"
#include "CommandExecutor.h"
using namespace std;


int main(){   
    string command;
    getline(cin, command);
    CommandProcessor cmdprcss(command);
    CommandExecutor cmdexec(cmdprcss.getCommandArray());
    return 0;
}

