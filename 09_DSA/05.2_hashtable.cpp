#include "05.1_hashtable.cpp"
#include <iostream>

#include "HashTable.h"

HashTable::HashTable(int size) {
    capacity = size;
    table.resize(capacity);
}

int HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::insert(int key, const std::string& value) {
    int index = hashFunction(key);
    auto& cell = table[index];

    for (auto& pair : cell) {
        if (pair.first == key) {
            pair.second = value; 
            return;
        }
    }

    cell.emplace_back(key, value);
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    auto& cell = table[index];

    for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            cell.erase(it);
            break; 
        }
    }
}

std::string HashTable::search(int key) {
    int index = hashFunction(key);
    auto& cell = table[index];

    for (const auto& pair : cell) {
        if (pair.first == key) {
            return pair.second; 
        }
    }

    return "Key not found";  
}

void HashTable::display() {
    for (int i = 0; i < capacity; ++i) {
        std::cout << "Bucket " << i << ": ";
        for (const auto& pair : table[i]) {
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        std::cout << std::endl;
    }
}

#include "HashTable.h"

int main() {
    HashTable hashTable(10);

    hashTable.insert(1, "one");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");
    hashTable.insert(4, "four");
    hashTable.insert(15, "fifteen");

    std::cout << "Hash Table contents:\n";
    hashTable.display();

    std::cout << "Search for key 3: " << hashTable.search(3) << std::endl;
    std::cout << "Search for key 10: " << hashTable.search(10) << std::endl;

    hashTable.remove(2);
    std::cout << "Hash Table after removing key 2:\n";
    hashTable.display();

    return 0;
}
