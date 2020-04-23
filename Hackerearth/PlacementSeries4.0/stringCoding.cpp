#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string runningString(string s){
    int n = s.size();
    string res = "";
    res = res+s[0];
    // cout<<res<<endl;
    int counter = 1;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1])
            counter++;
        else{
            res = res + to_string(counter);
            res = res + s[i];
            counter=1;
            if(i == n-1)
                res = res + to_string(counter);
        }
    }
    
    if(counter!=1)
        res = res + to_string(counter);
        
    return res;
}

int main(){

    string s;
    cin>>s;
    cout<<s<<endl;
    cout<<runningString(s)<<endl;
    return 0;
}