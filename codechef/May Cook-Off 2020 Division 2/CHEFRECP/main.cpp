// 0 sec
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        unordered_map<int, int> freq;
        unordered_map<int, int> pres;
        int val = arr[0];
        int count = 1;
        bool flag = true;
        for(int i=1; i<n; i++){
            if(arr[i] == val){
                if(pres[val] == 1){
                    flag = false;
                    break;
                }
                while(arr[i] == val){
                    count++;
                    i++;
                }
                i-=1;
            } else {
                if(freq[count]!=0){
                    flag = false;
                    break;
                } else {
                    pres[val] = 1;
                    freq[count] = val;
                    val = arr[i];
                    count = 1;
                }
            } 
        }
        if(flag && count!=0){
            if(freq[count]!=0){
                flag = false;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}