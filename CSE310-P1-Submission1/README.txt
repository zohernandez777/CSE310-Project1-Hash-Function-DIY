Name: Alonzo Hernandez
Team Name: Silly Sundevils 


Functionality of my program: 

All of my functions for the hashtable reside inside of hash.cpp. Here I have several methods which I will list:

- Node::Node(string k) this method is the struct for creating nodes. It assigns a key value and the next node is null
- HashTable::HashTable(int k): This function is a constructor for my hashtable where we create memmroy for an array accroding to the number of slots. It loops through each slot and sets the node to null so that their is space to put in data from the text files 
- HashTable::~HashTable(): This is a deconstructor which loops through the slots, then we traverse through the list and delete each node, then we delete the allocated array to ensure dynamic memmroy
int HashTable::hash_function(string text): my hasing function utilizes universial hashing to avoid collisions, we define constants for hashing , and then iterate through each charcter updating the hash value. Then we do a second adjusment to the hash value in order to reduce more collisions 
                                            then we divide the has value by the number of sots to ensure that the value is within bounds
- void HashTable::insert(string key): The insert function adds keys to a hash table using seperat chainging. You find a hash index followed by creating a new node. We first check for an empty slot and if one is found we insert a new node. Otherwise, a collsion happened and a new noded is added to the list. The newNode has pointer set to the current head of the list, where data[index] is updated to point to a new node, making a new head.
- void HashTable::printFiveSlots(): This function loops through the slots. If a node is null, print nothing. Otherwise, traverse through the list and print out the first five slots
- void HashTable::printLengths(): This function starts by looping through the slots, and grabs the head of the list. It then traverse through the list incrementing a node counter variable, and moves onto the next node. At the end of the loop we print out the length of the list
-void HashTable::printStdDev(): In this function we calculate the standrad deviation. First we calculate the mean by travesing through the list incrementing. Then we added the inremented length of the list to the mean and divide by the number of slots to find the avergae. 
                                Next, we calcuate the varaince with a similar method implemting a counter for length, but to calulate the variance we find the differnce of the list length and mean sqaured
                                Lastly, we calculate the standard devaaiation by square rooting the varaince. And print out that value

My main function:

- the only new thing I did was create a hashTable object and loop through the tokens inserting each one into the tabel. Then I call on my methods from hash to display my values.