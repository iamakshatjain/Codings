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
        int MX = 1;
        int MN = n;
        vector<int>arr;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        if(n == 1){
            cout<<1<<' '<<1<<endl;
            continue;
        }
        int count = 1;
        for(int i=0; i<n-1; i++){
            if(abs(arr[i+1]-arr[i])<=2) count+=1;
            else{
                MN = min(MN, count);
                MX = max(MX, count);
                count = 1;
            }
        }
        MN = min(MN, count);
        MX = max(MX, count);
        cout<<MN<<' '<<MX<<endl;
    }
    return 0;
}