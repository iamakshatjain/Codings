#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
    	int n, k;
    	cin>>n>>k;
    	vector<int>arr;
    	for(int i=0; i<n; i++){
    		int temp;
    		cin>>temp;
    		arr.push_back(temp);
    	}
    	if(k == 1 || n == 1){
    		cout<<"yes"<<endl;
    		continue;
    	}
    	unordered_map<int, vector<int>>mp;
    	for(int i=0; i<n; i++){
    		mp[arr[i]].push_back(i);
    	}
    	bool flag = false;
    	sort(arr.begin(), arr.end());
    	for(int i=0; i<n; i++){
    		flag = false;
    		int v = arr[i]; 
    		vector<int> s = mp[v];
    		for(int j = 0; j<s.size(); j++){
    			if(s[j]!=-1 && (i - s[j])%k==0){
    				mp[v][j] = -1;
	    			flag = true;
	    			break;
	    		}
    		}
    		if(!flag) break;
    	}
    	if(flag) cout<<"yes"<<endl;
    	else cout<<"no"<<endl;

    }
    return 0;
}