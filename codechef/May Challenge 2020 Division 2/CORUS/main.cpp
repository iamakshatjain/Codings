#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        string s;
        cin>>s;

        // create a frequency map
        unordered_map<char, int> freq;
        vector<int>arr;
        int m = -1;
        for(int i=0; i<n; i++){
            freq[s[i]]+=1;
            m = max(m, freq[s[i]]);
        }

        // create a map of count of the deleted elements in each iteration
        // since we delete elements at each stage, this runs till the frequency map is not empty
        while(m--){
            int count = 0;
            for(auto i : freq){
                if(freq[i.first] > 0){
                    count+=1;
                    freq[i.first]-=1;
                }
            }
            arr.push_back(count);
        }

        int left = n;
        // traverse all the elements
        for(int i=0; i<arr.size(); i++){
            left-=arr[i];
            arr[i] = left;
        }
        // change the map to left elements in the queue after each iteration
        // then anwser each query in O(1)
        // if the C is not in the map created, answer is zero
        while(q--){
            int c;
            cin>>c;
            if(c > arr.size()) cout<<0<<endl;
            else if(c == 0) cout<<n<<endl;
            else cout<<arr[c-1]<<endl;
        }

    }
    return 0;
}