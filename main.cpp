#include <iostream>
#include <sstream>
#include "helperFuncs.hpp"
#include "Student.h"
using namespace std;

int main() {
    AVLTree tree;
    string temp;
    // get how many commands there are
    cin >> temp;
    int cmds = stoi(temp);
    cin.ignore();
    while(cmds > 0) {
        string line;
        getline(cin, line);
        istringstream in(line);

        //get the command
        string command;
        in >> command;
        

        if (command == "insert") {
            // skip to the name
            string next;
            getline(in, next, '"');
            
            string name;
            getline(in, name, '"');
            
            getline(in, next, ' ');

            //get ufid
            string ufid;
            getline(in, ufid);
            if (nameValid(name)) {
                if (UFIDValid(ufid)) {
                    tree.insert(name, ufid);
                }
            }
        } else if (command == "remove") {
            //skip until space
            string next;
            getline(in, next, ' ');

            //get ufid
            string ufid;
            getline(in, ufid);
            
            if (UFIDValid(ufid)) {
                tree.remove(ufid);
            }
        } else if (command == "search") {
            //skip until space
            string next;
            getline(in, next, ' ');
            
            string ufid;
            getline(in, ufid, '"');
            getline(in, ufid, '"');
            
            //checks whether if ufid or name
            if (!isdigit(ufid[0])) {
                string temp;
                getline(in, temp);
                ufid += temp;
            }
            // function inside checks and searches appropriately if ufid or name
            if (UFIDValid(ufid) or nameValid(ufid)) {
                tree.search(ufid);
            }
            //simple functions printing in order, preorder, post order traversals
        } else if (command == "printInorder") {
            tree.printInorder();
        } else if (command == "printPreorder") {
            tree.printPreorder();
        } else if (command == "printPostorder") {
            tree.printPostorder();
        } else if (command == "printLevelCount") {
            tree.printLevelCount();
        } else if (command == "removeInorder") {
            // skip until next space
            string next;
            getline(in, next, ' ');
            string temp;
            in >> temp;
            int n = stoi(temp);
            tree.removeInorder(n);
        } else {
            // if it doesn't match anything
            cout << "unsuccessful command" << endl;
        }
        cmds--;
    }
    return 0;
}