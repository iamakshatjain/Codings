#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool twoDistinct(int a, int b){
	int freq_arr[10] = {0};
	int count = 0;
	if(!a || !b){
		count++;
	}
	while(a){
		freq_arr[a%10]++;
		a = a/10; 
	}
	while(b){
		freq_arr[b%10]++;
		b = b/10; 
	}

	
	for(int i=0;i<10;i++){
		if(freq_arr[i]!=0)
			count++;
	}

	// cout<<"distinct-count : "<<count<<endl;
	if(count==2){
		cout<<"-------------"<<endl;
		return true;

	}
	else
		return false;
}

int main(){

	int k;
	cin>>k;
	double p = pow(10,k);
	int power = ceil(p);
	int count = 0;
	for(int i=0;i<=power-1;i++){
		cout<<i<<' '<<power-i-1<<endl;
		if(twoDistinct(i,power-i-1))
			count++;
	}

	cout<<"count ::"<<count<<endl;
	return 0;
}