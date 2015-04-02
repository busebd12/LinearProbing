#include <iostream>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <map>
#include <cstdlib>
#include <cmath>
#include "LinearProbing.h"

using namespace std;

int TABLE_SIZE; //Make TABLE_SIZE global to allow the Table Size to be taken in within main() and used in hash()

size_t hasher(const string & key);


int main()
{
	Symbol temp;
	vector<Symbol> symbols;
	string s;
    
    int t;
    int hash_key_array[TABLE_SIZE]; //array to hold hash key values
	
	ifstream file;
    file.open("symbols.txt");
    cout << "Opening file..." << endl;
    
    if(!file)
    {
    	cout << "System failed to open file.";
    }
    else
    {
    	cout << "File successfully opened" << endl;
    }

    int numOfSymbols;

    //for loop to read in the string name and the integer that follows the string name from symbols.txt
    while(file >> s)
    {
        numOfSymbols++;
        temp.setData(s);
        file >> t;
        temp.setType(t);
        symbols.push_back(temp);
    }


    cout << "What would you like the table size to be?" << endl;
    cin >> TABLE_SIZE;

    HashTable<Symbol> hashtable(TABLE_SIZE); //makes a hash table with size TABLE_SIZE
    cout << endl;


    //loop to populate the hash table that was just created above
    for(int j = 0; j < TABLE_SIZE; j++)
    {
    	temp.setData(symbols[j].getData());
        cout << temp.getData() << endl;

        temp.setType(symbols[j].getType());
        cout << temp.getType() << endl;

        cout << endl;

        hashtable.insert(temp);
    }
    hashtable.print();
}

//functon to get the correct value for hashVal
size_t hasher(const string & key)
{
	size_t hashVal = 0;

	for(char ch : key)
	{
		hashVal = 37 * hashVal + ch;
	}
	return labs(hashVal % TABLE_SIZE);
}




