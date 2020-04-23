//wrong
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long int calculateMaxItems(long int n, long int p, long int k, vector<long int> arr){
    if(arr[0] > p)
        return 0;
    int i = 0;
    long int count = 0;
    while(i<n){
        long int one = arr[i];
        long int two = 0;
        long int three = 0;
        long int four = 0;

        if(i+1<n)
            two = arr[i+1];
        if(i+2<n)
            three = arr[i+2]+one;
        if(i+3<n)
            four = arr[i+3]+two;

        if()
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long int n,p,k;
        cin>>n>>p>>k;
        vector<long int> arr;
        int size = n;
        while(size--){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end());
        cout<<calculateMaxItems(n,p,k,arr)<<endl;
    }
}