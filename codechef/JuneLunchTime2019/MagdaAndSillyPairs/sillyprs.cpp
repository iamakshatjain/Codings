#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;

void swap(ll arr[],ll i,ll j){
	ll temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return;
}

ll find_max_average(ll a[],ll b[],ll n){
	ll avg = 0;
	ll even_count_a = 0;
	ll even_count_b = 0;
	for(ll i=0;i<n;i++){
		if(a[i]%2==0){
			swap(a,i,even_count_a);
			even_count_a++;
		}

		if(b[i]%2==0){
			swap(b,i,even_count_b);
			even_count_b++;
		}
	}

	for(ll i=0;i<n;i++){
		avg+=((a[i]+b[i])/2);
	}

	return avg;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n] = {0};
		ll b[n] = {0};
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		for(ll i=0;i<n;i++){
			cin>>b[i];
		}

		cout<<find_max_average(a,b,n)<<endl;
	}
	return 0;
}