#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

class HashTable {
private:
    vector<list<pair<int, string>>> table;
    int capacity;
    int hashFunction(int key);

public:
    HashTable(int size);
    void insert(int key, const string& value);
    void remove(int key);
    string search(int key);
    void display();
};

#endif
