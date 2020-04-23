//All correct
#include<bits/stdc++.h>
#include<iostream>
#define ull unsigned long long int

using namespace std;

ull calcGCD(ull a,ull b){
	if(a==0)
		return b;
	calcGCD(b%a,a);
}

ull findMaxGCDSum(vector<ull> v){
	int n = v.size();
	if(n==1)
		return 2*v[0];
	if(n==2)
		return v[0]+v[1];

	ull gcd = v[0];
	for(int i=0;i<n-2;i++){
		if(gcd>v[i])
			gcd = calcGCD(v[i],gcd);
		else
			gcd = calcGCD(gcd,v[i]);
	}

	ull gcd_max = calcGCD(gcd,v[n-1]); 
	ull gcd_smax = calcGCD(gcd,v[n-2]); 

	if(gcd_max + v[n-2] > gcd_smax + v[n-1])
		return gcd_max + v[n-2];
	else
		return gcd_smax + v[n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ull n;
		cin>>n;
		ull arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);

		vector<ull> v;
		//to remove duplicate elements
		for(int i=0;i<n-1;i++){
			if(arr[i] == arr[i+1])
				continue;
			v.push_back(arr[i]);
		}
		v.push_back(arr[n-1]);

		cout<<findMaxGCDSum(v)<<endl;
	}
	return 0;
}