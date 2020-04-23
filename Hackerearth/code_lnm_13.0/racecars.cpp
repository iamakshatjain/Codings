#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    int n;
    int z;
    cin>>n>>z;
    cout<<"input done"<<endl;
    cout<<n<<z;
    
    vector<int>x;
    vector<int>s;
    vector<int>t;

    int one = -1;
    int one_index = -1;
    
    int two = -1;
    int two_index = -1;
    
    int three = -1;
    int three_index = -1;
    
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }

    for(int i = 0; i<n; i++){
        cin>>s[i];
        t[i] = (x[i]-z)/s[i];
        if( i == 0 ){
            one = t[0];
            one_index = 0;   
        }
        else{
            if(one > t[i]){
                one = t[i];
                one_index = i; 
            }
        }
    }
    cout<<one_index<<endl;
    
    return 0;
}