#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;

ll calculateEqualPrice(ll min,ll max,ll k,int n){
	min+=k;
	if(abs(max-min)<=k)
		return min;
	else
		return -1;
}


int main(){

	int q;
	cin>>q;
	while(q--){
		int n;
		ll k;
		cin>>n>>k;
		ll arr[n];
		ll min = 1000000000;
		ll max = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]<min)
				min = arr[i];
			if(arr[i]>max)
				max = arr[i];
		}

		cout<<calculateEqualPrice(min,max,k,n)<<endl;
	}
	return 0;
}
