//pc
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int FindSum( int arr[], int n ){
    
    sort( arr, arr + n );
    int sum = 0;
    for( int i = n-1; i >= 0 ; i-- ){
            
            sum = abs( sum - arr[i] );
            
        }
    return sum;
    
}

int main(){
    
    int t;
    cin>>t;
    
    while( t-- ){
        
        int n;
        cin>>n;
        int arr[n];
        for( int i = 0; i < n ; i++ ){
            
            cin>>arr[i];
            
        }
        cout<<FindSum( arr, n )<<endl;
        
    }
    
    return 0;
}
