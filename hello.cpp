#include<iostream>
using namespace std;



static std::string stringToBinary(const std::string& txt) {
    std::string binary;
    for(char c: txt){
        for(int i=7;i>-1;i--){
            binary+= ((c>>i)&1)?'1':'0';       
        }
    }
    return binary;
}
int main(){
    std::string txt="hello world!!!";
    std::string binarytxt=stringToBinary(txt);
    std::cout<< binarytxt;
    return 0;
}