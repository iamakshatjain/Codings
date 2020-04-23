#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long unsigned int calculate_sum_product(long long unsigned int arr[],int n,long long unsigned int s){
	long long unsigned int sp = 0;
	long long unsigned int cs = 0;
	for(int i=0;i<n;i++){
		cs+=arr[i];
		sp+=(arr[i]*(s-cs));
		cout<<sp<<' '<<cs<<' '<<s-cs<<endl;
		// cout<<10000000000000*1000000000000<<endl;

	}
	return sp%10000000007;
}

int main(){
	int n;
	cin>>n;
	long long unsigned int arr[n] = {0};
	long long unsigned int s = 0;

	for(int i=0;i<n;i++){
		cin>>arr[i];
		s+=arr[i];
	}

	cout<<calculate_sum_product(arr,n,s)<<endl;
	return 0;
}