#include<bits/stdc++.h>
using namespace std;

 void display(vector<int> arr,int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


int main(){
    int t;
    cin>>t;
        for(;t>0;t--){
            int n,a,b;
            // n
            // a//for bob 
            // b//for alice
            cin>>n>>a>>b;
            vector<int> arr(n);
            int flag=0;
            int c=0;
            int size=0;
            int temp;
            for(int i=0;i<n;i++){
                cin>>temp;
                if(temp%a!=0){
                    arr[c]=temp;
                    c++;
                }
            }
            if(c!=n){//to check if there was any change from the previous array
                flag++;
                size=c;
                // cout<<"after bob : ";
                // display(arr,n);
                // cout<<" size:"<<size<<endl;
            }
            
            //bob had the first chance up here
            //we do it for alice again
            if(flag==1){
                c=0;
                for(int i=0;i<size;i++){//if there are no further elements in the array bob wins.
                    int temp=arr[i]; 
                    if(temp%b!=0){
                        arr[c]=temp;
                        c++;
                    }
                }
                if(c!=size){
                    flag++;
                    size=c;
                    // cout<<"after alice : ";
                    // display(arr,n);
                    // cout<<" size:"<<size<<endl;
                }
            }
            
            //this was the chance of alice
            //again chance of bob
            if(flag==2){
                c=0;
                for(int i=0;i<size;i++){//if no further elements to be removed by bob then alice wins
                    int temp=arr[i];
                    if(temp%a!=0){
                        arr[c]=temp;
                        c++;
                    }
                } 
                if(c!=size){
                    flag++;
                    size=c;
                    // cout<<"after bob : ";
                    // display(arr,n);
                    // cout<<" size:"<<size<<endl;

                }
            }
            
            // display(arr,size);
            //if flag=1,3 --bob
            //if flag=2 --alice

            if(flag%2==0){
                cout<<"ALICE"<<endl;
            }
            else{
                cout<<"BOB"<<endl;
            }
        }
    return 0;

}
        
        