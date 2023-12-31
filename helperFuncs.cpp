//
//  helperFuncs.cpp
//  AVL
//
//  Created by Eren Chang on 9/27/23.
//

#include <iostream>
#include "helperFuncs.hpp"

// check if name is valid
bool nameValid(string name) {
    if (name.length() > 20) {
        return false;
    }
    for (char c : name) {
        if (!isalpha(c) and c != ' ') {
            return false;
        }
    }
    return true;
}

// check if ufid is valid
bool UFIDValid(string ufid) {
    if (ufid.length() != 8) {
        return false;
    }
    for (char c: ufid) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
