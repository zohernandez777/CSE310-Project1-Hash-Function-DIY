#include "hash.h"  // Include the header file

// Define the Node constructor
Node::Node(string k) {
    key = k; //assigns the key value
    next = nullptr; //assigns the next pointer as null
}

// Define HashTable constructor
HashTable::HashTable(int k) {
    numSlots = k;
    data = new Node*[numSlots]; //creates memory for the array
    for(int i = 0; i < numSlots; i++){ //loop through all the slots
        data[i] = nullptr; //assign each slot with a null so there is no predetermined data val
    }
}

// Define HashTable destructor
HashTable::~HashTable() {
    for(int i = 0; i< numSlots; i++){ //loop through all slots in the table 
        Node* currentNode = data[i]; //starts with the first node of a slot
        while(currentNode){ //loop until we hit a nnull pointer 
            Node* tempVar = currentNode; //store in a temp var
            currentNode = currentNode->next; //moves to the next node
            delete tempVar; //free up space 



        }
    }
    delete[] data; //delete the array
}

//Hash function utilizing unverisla hashing 


/*NOTES: 
Universial Hasing : h(k)=((a⋅k+b)modp)mod m

Where a and b are chosen constants, p is a prime number greater than m, and k is the key

*/
int HashTable::hash_function(string text) {
// Implement your own hash function here
    int a = 3; //multiplier constant 
    int b = 5; // addition constant 
    //try and make it so the modvalue is the table size
    int p = numSlots; //value to hold table size
    
    int hashVal = 0; //intailize the hash value for now 
    
    for(int i = 0; i < text.length(); i++){ //loop through each char
        hashVal = (hashVal * a + text[i]) % p; //apply universal hashing 
    }
    hashVal = (hashVal + b) % p; //final steps of universal hashing
    
        return hashVal % numSlots; //make sure the index can be found within the table 
}

// Define insert function
void HashTable::insert(string key) {
     int index = hash_function(key); //find the hash index for a key
    Node* newNode = new Node(key); //create a node with the key value
    if(data[index] == nullptr){ //if empty, insert a new node 
        data[index] = newNode;
    } else{
        newNode->next = data[index]; //links new node to the chain
        data[index] = newNode;//update to piint to the new head
    }
}

// Define placeholder methods
void HashTable::printFiveSlots() {
    for(int i = 0; i < 5 && i < numSlots; i++){ //loop through first 5 slots 
cout << "Slot " << i << ": "; //print slot index
Node* currentNode = data[i]; //get the first node
if(currentNode == nullptr){ //if the slot is empty
    cout << endl; //print nothing 
}else{
    while(currentNode){ //iterate through the linked list 
        cout << currentNode->key << " "; //print the key inside the current node 
        currentNode = currentNode->next; //move on to the next node
    }
    cout << endl;
}
    }
}

//method to print slot lengths 
void HashTable::printLengths() { 
    for (int i = 0; i < numSlots; i++){ //loop through all slots 
        int nodeCounter = 0; //create a counter for length
        Node* currentNode = data[i]; //gets first node
        while(currentNode){ //traverse through the list
            nodeCounter++; //increment slot length
            currentNode = currentNode->next; //move onto next node 
        }
        cout << "Slot " << i << ": " << nodeCounter << endl; //print the length 
    }

}

void HashTable::printStdDev() {
    double mean = 0.0; //intailize mean 
 double variance = 0.0; //inttailize mean

 //start by finding the mean
 for(int i = 0; i < numSlots; i++){
    int nodeCounter = 0; //counter for slot length 
    Node* currentNode = data[i]; //get frist node 
    while(currentNode){ //traverse through list
        nodeCounter++; //increment length 
        currentNode = currentNode->next; //move onto next node 
    }
    mean += nodeCounter; //add the length to mean
 }
 mean = mean / static_cast<double>(numSlots); //calculate the mean


//Next, compute the variance 
 for(int i = 0; i < numSlots; i++){
    int nodeCounter = 0; //counter for length 
    Node* currentNode = data[i]; //get the first node
    while(currentNode){ //traverse through list 
        nodeCounter++; //count the nodes 
        currentNode = currentNode->next;//move to next node
    }
    variance += pow(nodeCounter - mean, 2); //calulate and add the squared difference 
 }

 variance /= numSlots; //final computation for variancec

 double standardDeviation = sqrt(variance); //compute the StdDev
 cout << standardDeviation << endl; //print out the StdDev
}