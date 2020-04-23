#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t){
        char s[100];
        scanf(" %[^\n]s",s);
        bool flag=false;
        for(int i=0;s[i+2]!='\0';i++){
            if(s[i]=='n' && s[i+1]=='o' && s[i+2]=='t'){
                if((i-1==-1 && s[i+3]=='\0')||(s[i-1]==' ' && s[i+3]=='\0')||(s[i-1]=' ' && s[i+3]==' ')||(i-1==-1 && s[i+3]==' ')){
                    flag=true;
                    break;
                    }
                }

        }
        if(flag){
            cout<<"Real Fancy"<<endl;
        }
        else{
            cout<<"regularly fancy"<<endl;
        }
        t--;
    }
    
}