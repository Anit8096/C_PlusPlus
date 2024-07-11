#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable {
private:
    static const int HashGroups = 10;
    list<pair<int, string>> Table[HashGroups];
  
public:
    bool isEmpty();
    int HashFunction(int key);
    void InsertItem(int key, string value);
    void DeleateItem(int key);
    string Search(int key);
    void PrintTable();
};

bool HashTable::isEmpty() {
    int sum = 0;
    for (int i = 0; i < HashGroups; i++) {
        sum += Table[i].size();
    }
    if (sum != 0) {
        return false;
    }
    return true; 
}

int HashTable::HashFunction(int key){
    return key % HashGroups;
}

void HashTable::InsertItem (int key, string value) {
    int HashValue = HashFunction(key);
    auto& Cell = Table[HashValue];
    auto btIr = begin(Cell);
    bool KeyExists = false;
    for (; btIr != end(Cell); btIr++) {
        if (btIr->first == key) {
            KeyExists = true;
            btIr->second = value;
            cout<<"[WARNING] Key exists. Value replaced."<<endl;
            break;   
        }
    }

    if (!KeyExists) {
        Cell.emplace_back(key, value);
    }

    return;
}

void HashTable::DeleateItem(int key) {
    int HashValue = HashFunction(key);
    auto& Cell = Table[HashValue];
    auto btIr = begin(Cell);
    bool KeyExists = false;
    for (; btIr != end(Cell); btIr++) {
        if (btIr->first == key) {
            KeyExists = true;
            btIr = Cell.erase(btIr);
            cout<<"[INFO] Pair Removed."<<endl;
            break;   
        }
    }

    if (!KeyExists) {
        cout<<"[WARNING] Key not found. Pair not removed."<<endl;
    }
    
    return;
}

void HashTable::PrintTable() {
    for (int i{}; i < HashGroups; i++) {
        if (Table[i].size() == 0) continue;

        auto bItr = Table[i].begin();
        for ( ; bItr != Table[i].end(); bItr++) {
            cout<<"[INFO] Key : "<<bItr->first<<" Value : "<<bItr->second<<endl;
        }
    }
    return;
}

int main() {
    HashTable HT;

    if (HT.isEmpty()) {
        cout<<"Correct answer, good job !"<<endl;
    } else {
        cout<<"Something's wrong"<<endl;
    }

    HT.InsertItem(562, "Ani");
    HT.InsertItem(231, "Anu");
    HT.InsertItem(223, "Papaji");
    HT.InsertItem(435, "Mummy");
    HT.InsertItem(774, "Rohan_Bhaiya");
    HT.InsertItem(326, "Riya_didi");
    HT.InsertItem(987, "Tejasv_Bhaiya");
    HT.InsertItem(478, "Sona_Didi");
    HT.InsertItem(999, "Navya");
    HT.InsertItem(231, "Naina");

    HT.PrintTable();

    HT.DeleateItem(871);
    HT.DeleateItem(800);



    if (HT.isEmpty()) {
        cout<<"Something's wrong"<<endl;
    } else {
        cout<<"Correct answer, good job !"<<endl;
    }

    return 0;
}