#pragma once
#include <iostream>
#include <string>

using namespace std;

class appointment {
public:
    string pName;
    int priority;
    string dep;
    appointment* left = NULL;
    appointment* right = NULL;

    appointment(string name, int p, string d) {
        pName = name;
        priority = p;
        dep = d;
    }
};

class BST {
private:
    appointment* root;

    
    void displayMoreUrgent(appointment* node, int x) {
        if (node == NULL) return;
        displayMoreUrgent(node->left, x);
        if (node->priority <= x) {
            cout << "[" << node->pName << ", " << node->priority << ", " << node->dep << "]" << endl;
        }
        displayMoreUrgent(node->right, x);
    }

    
    void displayLessUrgent(appointment* node, int x) {
        if (node == NULL) return;
        displayLessUrgent(node->left, x);
        if (node->priority >= x) {
            cout << "[" << node->pName << ", " << node->priority << ", " << node->dep << "]" << endl;
        }
        displayLessUrgent(node->right, x);
    }

public:
    BST() { root = nullptr; }

    
    appointment* insert(appointment* app, string name, int p, string d) {
        if (app == nullptr)
            return new appointment(name, p, d);
        if (p > app->priority)
            app->right = insert(app->right, name, p, d);
        else 
            app->left = insert(app->left, name, p, d);
        return app;
    }

    void insert(string name, int p, string d) { root = insert(root, name, p, d); }

    void inorder(appointment* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << "[" << node->pName << ", " << node->priority << ", " << node->dep << "]" << endl;
            inorder(node->right);
        }
    }

    void inorder() { inorder(root); }

    void search(int x, appointment* current) {
        if (current == NULL) return;
        search(x, current->left);
        if (current->priority == x) {
            cout << "[" << current->pName << ", " << current->priority << ", " << current->dep << "]" << endl;
        }
        search(x, current->right);
    }

    void search(int x) { search(x, root); }

    appointment* findMin(appointment* node) {
        while (node && node->left != NULL) node = node->left;
        return node;
    }

    appointment* del(appointment* current, int x) {
        if (current == NULL) return NULL;
        if (x < current->priority) current->left = del(current->left, x);
        else if (x > current->priority) current->right = del(current->right, x);
        else {
            if (current->left == NULL && current->right == NULL) {
                delete current;
                return NULL;
            }
            else if (current->left == NULL) {
                appointment* temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == NULL) {
                appointment* temp = current->left;
                delete current;
                return temp;
            }
            else {
                appointment* temp = findMin(current->right);
                current->pName = temp->pName;
                current->priority = temp->priority;
                current->dep = temp->dep;
                current->right = del(current->right, temp->priority);
            }
        }
        return current;
    }

    bool searchExists(appointment* current, int x) {
        if (current == NULL) return false;
        if (x < current->priority) return searchExists(current->left, x);
        else if (x > current->priority) return searchExists(current->right, x);
        else return true;
    }

    void delall(int x) {
        while (searchExists(root, x)) {
            root = del(root, x);
        }
    }

    void displayMoreUrgent(int x) { displayMoreUrgent(root, x); }
    void displayLessUrgent(int x) { displayLessUrgent(root, x); }
};
