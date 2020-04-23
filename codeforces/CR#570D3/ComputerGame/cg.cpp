//incorrect - not passing certain test case
#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;

ll calculate_turns(ll k,ll l,ll r,ll n,ll a,ll b){
	if(l>r){
		if(l == 0)
			return -1;
		else
			return n;
	}
	ll mid = (l+r)/2;
	ll d = a-b;
	ll val = (k-(a*mid + (n-mid)*b));
	if(val>0 && (val<=d || val<=min(a,b))){
		return mid;
	}
	if(val > d)
		return calculate_turns(k,mid+1,r,n,a,b);
	if(val <= d)
		return calculate_turns(k,l,mid-1,n,a,b);
}

int main(){

	ll t;
	cin>>t;
	while(t--){
		ll k,n,a,b;
		cin>>k>>n>>a>>b;
		cout<<calculate_turns(k,0,n,n,a,b)<<endl;
	}
	return 0;
}