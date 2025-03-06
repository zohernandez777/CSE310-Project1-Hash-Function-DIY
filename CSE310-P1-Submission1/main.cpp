/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Alonzo Hernandez
Your team alias: silly sundevils
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    //create the hashtable 

    HashTable table(k);
    for (int i = 0; i < n; i++) {
        table.insert(texts[i]);
    }

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
        table.printFiveSlots();
    cout << "==== Printing the slot lengths ====" << endl;
        table.printLengths();
    cout << "==== Printing the standard deviation  =====" << endl;
        table.printStdDev();
    return 0;
}