#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    getchar();
    for(;t>0;t--){
        string s;
        getline(cin, s);
        int n=s.length();
        cout<<n<<endl;
        bool flag=false;
        for(int i=0;i<n-2;i++){
            if((i-1==-1 && i+3==n)||(s[i-1]==' ' && i+3==n)||(s[i-1]=' ' && s[i+3]==' ')||(i-1==-1 && s[i+3]==' ')){
                if(s[i]=='n' && s[i+1]=='o' && s[i+2]=='t'){
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Real Fancy"<<endl;
        else
            cout<<"regularly fancy"<<endl;
    }     
    return 0;
}