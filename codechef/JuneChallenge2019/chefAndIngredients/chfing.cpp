#include <bits/stdc++.h>
#include <iostream>
using namespace std;
	
unsigned long long int findAnswer(unsigned long long int n, unsigned long long int k){
		unsigned long long int a = k-1;
		unsigned long long int d = n-1;
		unsigned long long int no = ceil(a/(long double)d);//long double can store upto 12 bytes of data
		unsigned long long int l = (2*a - (no-1)*d);
		if(no%2==0)
			no = no/2;
		else
			l = l/2; 
			
		return ((no%1000000007)*(l%1000000007))%1000000007;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		unsigned long long int n,k;
		cin>>n>>k;
		cout<<findAnswer(n,k)<<endl;
	}
	return 0;
}