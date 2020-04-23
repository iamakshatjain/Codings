#include<bits/stdc++.h>
using namespace std;

bool divi(int temp,int val){
    return !(temp%val);
}

//if !b--a
//if  b && !a --b
//if  b && a --a

int main(){
    int t;
    cin>>t;
        for(;t>0;t--){
            int n,a,b;
            // n
            // a//for bob 
            // b//for alice
            cin>>n>>a>>b;
            int bob=a;
            int alice=b;
            int bobcount=0;
            int alicecount=0;
            int temp;
            
            for(int i=0;i<n;i++){
                cin>>temp;
                if(divi(temp,bob)){
                    bobcount++;
                }
                else if(!divi(temp,bob) && divi(temp,alice)){
                    alicecount++;
                }    
            }

            if(bobcount < alicecount){
                cout<<"ALICE"<<endl;
            }

            else if(bobcount > alicecount){
                cout<<"BOB"<<endl;
            }

            else{
                cout<<"ALICE"<<endl;
            }
        }
    return 0;
}