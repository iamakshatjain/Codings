#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;

int findPlayer(ll x,ll y, ll k){
	int flag = 1;//chef
	ll s = x+y+1;
	ll r = s/k;
	r = r%2;
	s = s%k;
	if(r==1)
		flag = 1;
	else 
		flag = 0;

	if(s>0){
		flag = (flag+1)%2;
	}

	return flag;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		ll x,y,k;
		cin>>x>>y>>k;
		findPlayer(x,y,k)?cout<<"Chef":cout<<"Paja";
		cout<<endl;
	}
	return 0;
}