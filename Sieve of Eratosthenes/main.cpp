#include <bits/stdc++.h>
using namespace std;


void sieveOfEratosthenes(int n){
    vector<bool> isPrime(n+1, true);

    for(int i=2; i * i <= n; i++){
        if(isPrime[i]){
            for(int j=i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    
    cout << "Prime numbers up to " << n << " are: ";
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}