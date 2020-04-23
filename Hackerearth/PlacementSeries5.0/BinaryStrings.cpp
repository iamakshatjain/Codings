//link : https://www.hackerearth.com/problem/algorithm/ankur-hates-binary-strings/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//this problem is just like bracket satisfying problem
string isBinaryString(string s){
    int counter = 0;//this basically must work like stack
    for(unsigned int i=0;i<s.size();i++){
        if(s[i] == '0'){
            if(counter == s.size())
                return "N";
            counter++;
        }
            
        if(s[i] == '1'){
            
            if(counter == 0)
                return "N";
                
            counter--;
            
        }
        
    }
    if(counter!=0)
        return "N";
    
    return "Y";
}

int main(){
    int t;
    cin>>t;
    string arr[t];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<t;i++){
        cout<<isBinaryString(arr[i])<<endl;
    }
}

