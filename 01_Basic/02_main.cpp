#include<iostream>

int a = 5;

void func(){
    std:: cout << a << std :: endl;
}

int main(int argc, char const *argv[]){
    int a = 10;
    std :: cout << a << std :: endl;
    func();
    return 0;
}
