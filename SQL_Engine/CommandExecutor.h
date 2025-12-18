// CommandExecutor.h
#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <string>
#include <regex>
#include <iostream>
#include <cstring>
using namespace std;

enum class CommandType {
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
        static CommandType identifyCommand(string* cmds) {
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
    public:
      static void executeCommand(string* cmds) {
            CommandType type = identifyCommand(cmds);
            int i;
            switch (type) {
                case CommandType::CREATE_TABLE:
                    cout << "Executing CREATE TABLE command...";
                    break;
                case CommandType::CREATE_INDEX:
                    cout << "Executing CREATE_INDEX command...";
                    break;
                case CommandType::DROP_TABLE:
                    cout << "Executing DROP TABLE command...";
                    dropTable(cmds[i]);//to add table no?
                    break;
                case CommandType::DROP_INDEX:
                    cout << "Executing DROP INDEX command...";
                    break;
                case CommandType::DISPLAY_TABLE:
                    cout << "Executing DISPLAY_TABLE command...";
                    displayTable(cmds[i]);//[2]
                    break;
                case CommandType::INSERT:
                    cout << "Executing INSERT command...";
                    insertInto(cmds[2], cmds[4]);//add i or not? not sure yet. i'll look into it
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
//drop tbale, display table and insert
void dropTable(string tableName)
{
    string fileName = tableName + ".txt";
    if (remove(fileName.c_str()) == 0) 
    {
        cout << "Table '" << tableName << "' has been deleted.\n";
    }
    else {
        cout << "Table '" << tableName << "' does not exist.\n";
    }
}
void displayTable(string tableName) 
{
    string fileName = tableName + ".txt";
    ifstream fin(fileName);

    if (!fin) {
        cout << "Table '" << tableName << "' does not exist.\n";
        return;
    }
    cout << "Table "<< tableName << " contents:\n";
    string line;
    while (getline(fin, line)) 
    {
        cout << line << "\n";
    }
    fin.close();
}

void insertInto(string tableName, string valuesRaw) 
{
    string fileName = tableName + ".txt";
    ofstream fout(fileName, ios::app);
    if (!fout) {
        cout << "Table " << tableName << " does not exist.\n";
        return;
    }
    if (valuesRaw.front() == '(' && valuesRaw.back() == ')') 
    {
        valuesRaw = valuesRaw.substr(1, valuesRaw.size() - 2);
    }
    fout << valuesRaw << "\n";
    fout.close();
    cout << "Insertion into table "<< tableName<<" done.\n";
}

