//partially correct
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int arr[n] = {0};
    long long int x = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        x = x^arr[i];
    }
    
    if(n%2 == 0)
        cout<<0<<endl;
    else{
        x = x^arr[0];
        x = x^arr[n-1];
        cout<<x<<endl;
    }
        
    
}