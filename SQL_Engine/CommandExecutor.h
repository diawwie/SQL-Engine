// CommandExecutor.h
#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <string>
#include <regex>
#include <iostream>
#include <cstring>
using namespace std;

enum CommandType {
    CREATE_TABLE,
    CREATE_INDEX,
    DROP_TABLE,
    DROP_INDEX,
    DISPLAY_TABLE,
    INSERT,
    SELECT,
    UPDATE,
    DELETE,
    UNKNOWN,
    ERROR
};

class CommandExecutor{
    private:
        CommandType identifyCommand(string* cmds) {
            if (cmds[0] == "CREATE") {
                if (cmds[1] == "TABLE") {
                    return CommandType::CREATE_TABLE;
                }
                else if (cmds[1] == "INDEX") {
                    return CommandType::CREATE_INDEX;
                }
                return CommandType::ERROR;
            }
            else if (cmds[0] == "DROP") {
                if (cmds[1] == "TABLE") {
                    return CommandType::DROP_TABLE;
                }
                else if (cmds[1] == "INDEX") {
                    return CommandType::DROP_INDEX;
                }
                return CommandType::ERROR;
            }
            else if (cmds[0] == "DISPLAY") {
                if (cmds[1] == "TABLE") {
                    return CommandType::DISPLAY_TABLE;
                }
                return CommandType::ERROR;
            }
            else if (cmds[0] == "INSERT") {
                if (cmds[1] == "INTO") {
                    return CommandType::INSERT;
                }
                return CommandType::ERROR;
            }
            else if (cmds[0] == "SELECT") {
                return CommandType::SELECT;
            }
            else if (cmds[0] == "UPDATE") {
                return CommandType::UPDATE;
            }
            else if (cmds[0] == "DELETE") {
                if (cmds[1] == "FROM") {
                    return CommandType::DELETE;
                }
                return CommandType::ERROR;
            }
            return CommandType::UNKNOWN;
        }

        void executeCommand(string* cmds) {
            CommandType type = identifyCommand(cmds);

            switch (type) {
                case CommandType::CREATE_TABLE:
                    cout << "Executing CREATE TABLE command...";
                    break;
                case CommandType::CREATE_INDEX:
                    cout << "Executing CREATE_INDEX command...";
                    break;
                case CommandType::DROP_TABLE:
                    cout << "Executing DROP TABLE command...";
                    break;
                case CommandType::DROP_INDEX:
                    cout << "Executing DROP INDEX command...";
                    break;
                case CommandType::DISPLAY_TABLE:
                    cout << "Executing DISPLAY_TABLE command...";
                    break;
                case CommandType::INSERT:
                    cout << "Executing INSERT command...";
                    break;
                case CommandType::SELECT:
                    cout << "Executing SELECT command...";
                    break;
                case CommandType::UPDATE:
                    cout << "Executing UPDATE command...";
                    break;
                case CommandType::DELETE:
                    cout << "Executing DELETE command...";
                    break;
                case CommandType::UNKNOWN:
                    cout << "Command unknown!!";
                    break;
                case CommandType::ERROR:
                    cout << "Error!!";
                    break;
            }
        }

	public:
		CommandExecutor(string* comm_arr) {
            this->executeCommand(comm_arr);
		}

        ~CommandExecutor() {

        }
};

#endif
