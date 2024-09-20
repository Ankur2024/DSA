#include <bits/stdc++.h>
using namespace std;

string decToBin(int k){
    string res = "";
    while(k != 0){
        if(k % 2 == 1){
            res = '1' + res;
        }else{
            res = '0' + res;
        }
        k /= 2;
    }
    return res;
}


int binToDec(string x){
    int len = x.length();
    int res = 0;
    for(int i=len-1;i>=0;i--){
        if(x[i] == '1'){
            res += pow(2, len-i-1);
        }
    }
    return res;
}

string oneComplement(string bin){
    string res = "";
    for(int i=0;i<bin.length();i++){
        if(bin[i] == '1'){
            res += '0';
        } else{
            res += '1';
        }
    }
    return res;
}

string twoComplement(string bin){
    string oneComp = oneComplement(bin);
    int sum = binToDec(oneComp) + 1;
    return decToBin(sum);
}
int main(){
    string bin = decToBin(23);
    cout << "Binary: " << bin << endl;
    int dec = binToDec(bin);
    cout << "Decimal: " << dec << endl;
    cout << "One's Compliment: "<< oneComplement(bin) << endl; 
    cout << "Two's Compliment: "<< twoComplement(bin) << endl; 
    return 0;
}