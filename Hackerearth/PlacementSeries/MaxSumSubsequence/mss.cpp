#include<bits/stdc++.h>
#include<iostream>
#define ull unsigned long long int

using namespace std;

ull calculateMaxSum(int arr[],int n){
	//we considered the first element here
	ull incl = arr[0];
	ull excl = 0;
	ull excl_new = 0;//this would act as the one temp variable

	for(int i=1;i<n;i++){
		excl_new = max(incl,excl);
		incl = excl+arr[i];
		excl = excl_new;
	}

	return max(excl,incl);
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<calculateMaxSum(arr,n)<<endl;
	return 0;
}