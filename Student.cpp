// Include necessary headers
#include "Student.h"
#include <cmath>
using namespace std;

// Constructor for AVLTree
AVLTree::AVLTree() {
    this->root = nullptr;
}

// Helper function to insert a student node
AVLTree::Student* AVLTree::insert(Student* root, const std::string& name, string id, std::ostream& os) {
    if (root == nullptr) {
        Student* temp = new Student(name, id);
        if (this->root == nullptr) {
            // If there is no root yet, set the root
            this->root = temp;
        }
        nodes++;
        os << "successful" << endl;
        return temp;
    }
    else if (root->ID > id) {
        // Recursively set the left node
        root->left = insert(root->left, name, id, os);
    }
    else if (root->ID < id) {
        // Recursively set the right node
        root->right = insert(root->right, name, id, os);
    } else if (root->ID == id) {
        os << "unsuccessful" << endl;
        return root;
    }
    // Update height throughout the stack frame
    updateHeight(root);
    if (root->bFactor == 2) {
        // Check for appropriate rotations
        if (root->left->bFactor == 1) {
            // Right rotation
            root = rotateRight(root);
        } else if (root->left->bFactor == -1) {
            // Left-right rotation
            root->left = rotateLeft(root->left);
            root =  rotateRight(root);
        }
    } else if (root->bFactor == -2) {
        if (root->right->bFactor == -1) {
            // Left rotation
            root = rotateLeft(root);
        } else if (root->right->bFactor == 1) {
            // Right-left rotation
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
}

// Helper function to update the height and balance factor of a node
void AVLTree::updateHeight(Student* root) {
    if (root) {
        // Set the height of each node
        root->height = 1 + max(root->left ? root->left->height : 0, root->right ? root->right->height : 0);
        if (root->left and root->right) {
            // If both children exist
            root->bFactor = root->left->height - root->right->height;
        } else if (!root->left and !root->right) {
            // No children exist
            root->bFactor = 0;
        } else if (root->left) {
            // If the left child exists
            root->bFactor = root->left->height;
        } else {
            // If the right child exists
            root->bFactor = -root->right->height;
        }
    }
}

// Helper function to perform a right rotation on a node
AVLTree::Student* AVLTree::rotateRight(Student* root) {
    // Set temporary variables
    Student* left = root->left;
    Student* deep = left->right;

    left->right = root;
    root->left = deep;

    // If the root of the tree is changed, make sure it updates
    if (this->root == root) {
        this->root = left;
    }

    // Update all height variables
    updateHeight(root);
    updateHeight(left);
    updateHeight(deep);

    return left;
}

// Helper function to perform a left rotation on a node
AVLTree::Student* AVLTree::rotateLeft(Student* root) {
    // Set temporary variables
    Student* right = root->right;
    Student* deep = right->left;

    right->left = root;
    root->right = deep;

    if (this->root == root) {
        this->root = right;
    }

    updateHeight(root);
    updateHeight(right);
    updateHeight(deep);

    return right;
}

// Public function to insert a student into the AVL tree
void AVLTree::insert(const std::string &name, string id, std::ostream& os) {
    // Calls the helper function
    if (nameValid(name) and UFIDValid(id)) {
        this->insert(this->root, name, id, os);
    } else {
        os << "unsuccessful" << endl;
    }
}

// Helper function to remove a student node with a given ID from the AVL tree
AVLTree::Student* AVLTree::remove(Student* root, string id, std::ostream& os) {
    // BST remove
    if (root == nullptr) {
        return nullptr;
    }
    if ((root->ID < id) and root->right) {
        root->right = remove(root->right, id);
    }
    else if ((root->ID > id) and root->left) {
        root->left = remove(root->left, id);
    } else if (root->ID == id) {
        removeFound = true;
        if (!root->left and !root->right) {
            // If the current node is a leaf
            delete root;
            nodes--;
            os << "successful" << endl;
            return nullptr;
        } else if (!root->left and root->right) {
            // If the root has a right child, delete the root and replace it with the successor
            Student* temp = root->right;
            delete root;
            nodes--;
            os << "successful" << endl;
            return temp;
        } else if (!root->right and root->left) {
            // If the root has a left child, delete the root and replace it with the predecessor
            Student* temp = root->left;
            delete root;
            nodes--;
            os << "successful" << endl;
            return temp;
        } else {
            // If both children exist
            Student* traverse = root->right;
            while (traverse->left) {
                traverse = traverse->left;
            }
            // Replace root information with successor information
            root->ID = traverse->ID;
            root->NAME = traverse->NAME;
            // Helper function to delete the successor
            if (root->right != traverse) {
                root->right = successor(root->right);
            } else {
                // Cannot go left anymore
                root->right = traverse->right;
                delete traverse;
            }
            nodes--;
            os << "successful" << endl;
            return root;
        }
    }
    // Update height of the current root
    updateHeight(root);
    return root;
}

// Helper function to find the successor of a node
AVLTree::Student* AVLTree::successor(Student* root) {
    if (!root->left) {
        Student* temp = root->right;
        delete root;
        return temp;
    }
    root->left = successor(root->left);
    return root;
}

// Public function to remove a student node with a given ID from the AVL tree
void AVLTree::remove(string id, std::ostream& os) {
    if (UFIDValid(id)) {
        remove(this->root, id, os);
        if (!removeFound) {
            os << "unsuccessful" << endl;
        } else {
            removeFound = false;
        }
    } else {
        os << "unsuccessful" << endl;
    }
}

// Helper function to search for a student node with a given ID or name
void AVLTree::search(Student* root, string id, std::ostream& os) {
    if (root == nullptr) {
        return;
    }
    if (nameValid(id)) {
        if (root->NAME == id) {
            os << root->ID << endl;
            searchFound = true;
        }
        if (root->left != nullptr) {
            search(root->left, id);
        }
        if (root->right != nullptr) {
            search(root->right, id);
        }
    } else if (UFIDValid(id)) {
        if (root->ID == id) {
            os << root->NAME << endl;
            searchFound = true;
            return;
        }
        if ((root->ID < id) and root->right) {
            search(root->right, id);
        }
        if ((root->ID > id) and root->left) {
            search(root->left, id);
        }
    }
}

// Public function to search for a student node with a given ID or name
void AVLTree::search(string id, std::ostream& os) {
    search(this->root, id, os);
    if (!searchFound) {
        os << "unsuccessful" << endl;
    }
    searchFound = false;
}

// Helper function to print the tree in inorder traversal
void AVLTree::printInorder(Student* root, string& output) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        printInorder(root->left, output);
    }
    output += root->NAME + ", ";

    if (root->right != nullptr) {
        printInorder(root->right, output);
    }
}

// Public function to print the tree in inorder traversal
void AVLTree::printInorder(std::ostream& os) {
    string output;
    this->printInorder(this->root, output);
    os << output.substr(0, output.length()-2) << endl;
}

// Helper function to print the tree in preorder traversal
void AVLTree::printPreorder(Student* root, string& output) {
    if (root == nullptr) {
        return;
    }
    output += root->NAME + ", ";
    if (root->left != nullptr) {
        printPreorder(root->left, output);
    }
    if (root->right != nullptr) {
        printPreorder(root->right, output);
    }
}

// Public function to print the tree in preorder traversal
void AVLTree::printPreorder(std::ostream& os) {
    string output;
    this->printPreorder(this->root, output);
    os << output.substr(0, output.length()-2) << endl;
}

// Helper function to print the tree in postorder traversal
void AVLTree::printPostorder(Student* root, string& output) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        printPostorder(root->left, output);
    }
    if (root->right != nullptr) {
        printPostorder(root->right, output);
    }
    output += root->NAME + ", ";
}

// Public function to print the tree in postorder traversal
void AVLTree::printPostorder(std::ostream& os) {
    string output;
    this->printPostorder(this->root, output);
    os << output.substr(0, output.length()-2) << endl;
}

// Public function to print the height of the tree
void AVLTree::printLevelCount(std::ostream& os) {
    if (this->root) {
        os << this->root->height << endl;
        return;
    }
    os << 0;
}

// Public function to remove the nth node in inorder traversal
void AVLTree::removeInorder(int n, std::ostream& os ) {
    if (n > nodes) {
        os << "unsuccessful" << endl;
    } else {
        this->helper(this->root, n);
        inOrder = 0;
    }
}

// Helper function to remove the nth node in inorder traversal
void AVLTree::helper(AVLTree::Student* root, int n) {
    if (root->left) helper(root->left, n);
    if (n == inOrder) {
        this->remove(this->root, root->ID);
    }
    inOrder += 1;
    if (root->right) helper(root->right, n);
}
