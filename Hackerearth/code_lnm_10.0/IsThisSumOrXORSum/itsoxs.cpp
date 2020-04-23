#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long int power(int x,int y){
	long long int res = 1;
	long long int a = x;
	while(y>0){
		if(y&1)
			res = res*a;
		y = y>>1;
		a = a*a;
	}
	return res; 
}

long long int findnab(long long int n){
	int count = 0;
	int r = 0;
	while(n){
		r = n%2;
		if(!r)
			count++;
		n=n/2;
	}
	
	return power(3,count);	
}

int main(){

	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		cout<<findnab(n)<<endl;
	}
	return 0;
}