#include <bits/stdc++.h>
#include <iostream>
#define INF 2147483647;
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        long int n;
        long int total = 0;
        cin>>n;
        long int min = INF;
        for(int i=0; i<n; i++){
            long int temp;
            cin >> temp;
            if (temp < min)
                min = temp;
            total += min;
        }
        cout<<total<<endl;
    }
    return 0;
}