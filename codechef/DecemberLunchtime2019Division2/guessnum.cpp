//partially correct
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long double m,a;
        cin>>a>>m;
        long long int k_max = (m-1)/a;//floor here
        long long int k_min = 1;

        vector<int>arr;

        for(int k=1; k<=k_max;k++){
            if (a * k + 1 > m / 2)
            {
                k = k_max;
                // continue;
            }
            long double d = (m/(a*k + 1));
            if(d - int(d) == 0)
                arr.push_back(k*d);
        }
        cout<<arr.size()<<endl;
        for(int x : arr){
            cout<<x<<' ';
        }
        cout<<endl;
    }
    return 0;
}