#ifndef HASH_H  // Include guard to avoid redefinition issues
#define HASH_H


#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct Node {
    string key;
    Node* next;

    Node(string k);
};

class HashTable {
    private:
        int numSlots;
        Node** data;
    
    public:
        HashTable(int k);        // Constructor
        ~HashTable();            // Destructor
    
        int hash_function(string text);
        void insert(string key);
        void printFiveSlots();
        void printLengths();
        void printStdDev();
    };

#endif
