#include<bits/stdc++.h>
using namespace std;

 void display(vector<int> arr,int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
            vector<long int> arr(n);
            int flag=0;
            int c=0;
            int size=0;
            long int temp;
            for(int i=0;i<n;i++){
                cin>>temp;
                if(temp%a!=0){
                    arr[c]=temp;
                    c++;
                }
            }
            //to check if there was any change from the previous array
            if(c<n){//b
                flag++;
                size=c;
                // cout<<"after bob : ";
                // display(arr,n);
                // cout<<" size:"<<size<<endl;
            }
            else{//!b
                flag=0;
                size=n;
            }
            
            //bob had the first chance up here
            //we do it for alice again
            if(flag==1){//if b
                c=0;
                for(int i=0;i<size;i++){//if there are no further elements in the array bob wins.
                    int temp=arr[i]; 
                    if(temp%b!=0){
                        arr[c]=temp;
                        c++;
                    }
                }
                if(c<size){//if a
                    flag++;//flag becomes 2
                    size=c;
                    // cout<<"after alice : ";
                    // display(arr,n);
                    // cout<<" size:"<<size<<endl;
                }
                //else flag remains one
                else{
                    flag=1;
                }
            }
            
            // display(arr,size);
            //if flag=1,3 --bob
            //if flag=2,0 --alice

            if(flag%2==0){
                cout<<"ALICE"<<endl;
            }
            else{
                cout<<"BOB"<<endl;
            }
        }
    return 0;

}
        
        