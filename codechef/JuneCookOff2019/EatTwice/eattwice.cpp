#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;

ll calculate_max_tastiness(ll d[],ll v[],ll max, ll dmax, ll n, ll m){
	ll max2 = 0;
	for(int i=0;i<n;i++){
		if(d[i]!=dmax && v[i]<=max && v[i]>=max2){
			max2 = v[i];
		}
	}

	return max+max2;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll d[n];
		ll v[n];
		ll max = 0;
		ll dmax = 0;
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i];
			if(v[i]>max){
				max = v[i];
				dmax = d[i];
			}
		}
		cout<<calculate_max_tastiness(d,v,max,dmax,n,m)<<endl;
	}
}