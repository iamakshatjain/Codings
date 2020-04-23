#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long int power(long long int n,long long int k,long long int p){
	long long int res = 1;

	n = n%p;

	while(k){
		if(k&1){
			res = (res*n)%p;
		}

		n=(n*n)%p;
		k = k>>1;
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int k;
		cin>>k;
		cout<<(power(2,k-1,1000000007)*10)%1000000007<<endl;
		//if we don't modulus here at the end the answer may go above the limit
	}
}