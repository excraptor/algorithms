#include <iostream>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;

vector<int> b_bin;

void bin(int b) {
    if(b > 1){
        bin(b>>1);
    }
    b_bin.push_back((b & 1));
}

int modular(int a, int b, int n) {
    bin(b);
    int d = 1;
    for(int i : b_bin) {
        d = (d*d)%n;
        if(i == 1) {
            d = d*a%n;
        }
        cout << i << ".: " << d << " ";
    }
    cout << endl;
    return d;
}

int main() {
    modular(11, 13, 19);
    return 0;
}