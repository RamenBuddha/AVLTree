//
// Created by shaoy on 9/26/2023.
//

#ifndef AVL_STUDENT_H
#define AVL_STUDENT_H

#include <string>
#include <iostream>
#include "helperFuncs.hpp"

using namespace std;

class AVLTree{
    struct Student {
        string NAME = "";
        string ID = "";
        int height = 1;
        int bFactor = 0;
        Student* left = nullptr;
        Student* right = nullptr;
        Student(std::string name, string id) {
            NAME = name;
            ID = id;
        }
    };
private:
    Student* root = nullptr;
    int nodes = 0;
    int inOrder = 0;
    bool searchFound = false;
    bool removeFound = false;
    Student* insert(Student* root, const std::string& name, string id, std::ostream& os = std::cout);
    void printInorder(Student* root, string& output);
    void printPreorder(Student* root, string& output);
    void printPostorder(Student* root, string& output);
    void updateHeight(Student* root);
    void search(Student* root, string id, std::ostream& os = std::cout);
    void helper(Student* root, int n);
    Student* remove(Student* root, string id, std::ostream& os = std::cout);
    Student* rotateRight(Student* root);
    Student* rotateLeft(Student* root);
    Student* successor(Student* root);
public:
    AVLTree();
    void insert(const std::string& name, string id, std::ostream& os = std::cout);
    void remove(string id, std::ostream& os = std::cout);
    void search(string id, std::ostream& os = std::cout);
    void printInorder(std::ostream& os = std::cout);
    void printPreorder(std::ostream& os = std::cout);
    void printPostorder(std::ostream& os = std::cout);
    void printLevelCount(std::ostream& os = std::cout);
    void removeInorder(int n, std::ostream& os = std::cout);

};




#endif //AVL_STUDENT_H
