#include<iostream>
using namespace std;

class Shop{
    string itemNAME[100];
    int itemID[100];
    int itemPRICE[100];
    int counter;
    public:
        void getcount(void){
            counter = 0;
        }
        void getitem(void);
        void Dispalyprice(void);
};

void Shop :: getitem(void){
    cout << "Enter Name of the product : ";
    getline(cin >> ws, itemNAME[counter]);
    cout << "Enter itemID : ";
    cin >> itemID[counter];
    cout << "Enter price of the selected item : ";
    cin >> itemPRICE[counter];
    counter ++ ;
}

void Shop :: Dispalyprice(void){
    for(int i = 0; i <= counter; i++){
        cout << i+1 << ".Your Item : "<< itemNAME[i] << "-" << itemID[i] << " costs : " << itemPRICE[i] << endl;
    }
    
}

int main(){
    Shop dukaan;
    dukaan.getcount();
    dukaan.getitem();
    dukaan.getitem();
    dukaan.getitem();
    dukaan.Dispalyprice();
}