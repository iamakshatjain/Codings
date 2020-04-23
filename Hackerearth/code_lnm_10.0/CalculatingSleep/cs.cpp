#include<bits/stdc++.h>
#include<iostream>
using namespace std;

map<unsigned long long int,unsigned long long int> f;

unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int p){
	unsigned long long int res = 1;
	unsigned long long int a = x;

	a = a%p;

	while(y>0){
		if(y&1)
			res = (res*a)%p;
		y = y>>1;
		a = (a*a)%p;
	}
	return res; 
}


unsigned long long int findVal(unsigned long long int n){
	if(f[n]!=0)
		return f[n];

	f[n] = (2*findVal(n-1)%1000000007 + 3*findVal(n-2)%1000000007 + power(2,n-1,1000000007) + power(3,n-2,1000000007))%1000000007;
	return f[n];
}

int main(){

	int t;
	cin>>t;
	f[0] = 1;
	f[1] = 1;
	
	while(t--){
		unsigned long long int n;
		cin>>n;
		cout<<findVal(n)<<endl;
	}
	return 0;
}