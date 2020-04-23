#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int calcblocks(int a,int b,int i){
	int sum1 = 0;
	int mult = b-1-a;
	int times = i;
	sum1 = mult*times;
	return sum1;
}

int main(){

	int n;
	cin>>n;

	int arr[n]={0};
	int val=0;
	int ss=0;
	for(int i=0;i<n;i++){
		// cout<<"begining of iteration : "<<arr[i]<<" "<<val<<" "<<ss<<endl;
		cin>>arr[i];
		if(i==0)
			ss=arr[0];
		//if <
		if(arr[i]<ss){
			val+=ss-arr[i];
		}

		//if >
		else if(arr[i]>ss){
			val+=calcblocks(ss-1,arr[i],i);
			ss = arr[i];
		}

		ss++;
		// cout<<"end of iteration : "<<arr[i]<<" "<<val<<" "<<ss<<endl;
	}

	cout<<val<<endl;
	return 0;
}