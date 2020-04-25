#include <bits/stdc++.h>
using namespace std;

int min(int a, int b){
	return a<b?a:b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,s;
    	cin>>n>>s;
    	int def = 101;
    	int frwd = 101;
    	vector<int>arr;
    	for(int i=0; i<n; i++){
    		int temp;
    		cin>>temp;
    		arr.push_back(temp);
    	}
    	for(int i=0; i<n; i++){
    		int temp;
    		cin>>temp;
    		if(temp == 0) def = min(def, arr[i]);
    		else frwd = min(frwd, arr[i]);
    	}
    	if(def + frwd <= 100-s) cout<<"yes"<<endl;
    	else cout<<"no"<<endl;
    }
    return 0;
}