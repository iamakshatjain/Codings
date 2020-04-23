#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int count_dig(int n){
    int count = 0;
    while(n>0){        
        n = n/10;
        count++;
    }   
    return count;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        int ref = n;
        int comp = 0;
        int count=1;
        for(int i=0; i<n; i++){
            if(i+1 < n && s[i] == s[i+1]){
                if(i+1 == n-1)
                    i++;
                count++;
            }
            else{
                comp+=1;
                int cdig = count_dig(count);
                // cout<<"digit count : "<<cdig<<endl;
                comp+=cdig;
                count=1;
                // cout<<"comp : "<<comp<<endl;
            }
        }
        // cout<<"count left : "<<count<<endl;
        if(count > 1){
            comp+=1;
            int cdig = count_dig(count);
            comp+=cdig;
            count = 1;
            // cout<<comp<<endl;
        }
        // cout<<comp<<endl;
        if(comp<ref){
            // cout<<comp<<endl;
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    
}
