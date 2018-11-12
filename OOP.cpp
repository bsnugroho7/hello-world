#include<iostream>
int num1,num2;
class coba{
    public:
    void add(int num1,int num2){
        std::cout<<num1+num2<<std::endl;
    }
    void substract(int num1,int num2){
        std::cout<<num1-num2<<std::endl;
    }
    void muncul(){
        std::cout<<"Hai Kamu Jomblo\n";
    }
};
coba jombs;

int main(){
int pilih;
    std::cout<<"Pilih Operasi : \n";
    std::cout<<"1. Penjumlahan \n"<<"2. Pengurangan\n"<<"3. Tulisan\n"<<"Pilih :";
    std::cin>>pilih;
switch(pilih){
    case 1: std::cout<<"Masukkan bilangan 1 : ";std::cin>>num1;
            std::cout<<"Masukkan bilangan 2 : ";std::cin>>num2;
            jombs.add(num1,num2);
            break;
    case 2: std::cout<<"Masukkan bilangan 1 : ";std::cin>>num1;
            std::cout<<"Masukkan bilangan 2 : ";std::cin>>num2;
            jombs.substract(num1,num2);
            break;
    case 3: jombs.muncul();
            break;
}
return 0;
}

// Jomblo jombs;
// jombs.add(1,2); // 3
// jombs.substract(3,4); // -1
// jombs.show() // hai aku jomblo