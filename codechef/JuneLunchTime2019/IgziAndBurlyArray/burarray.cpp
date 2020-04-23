//incorrect
#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;

ll s = 0;
map<int,int>zeros;
vector<int> v;

ll find_max(ll l,ll r){
	ll max = 0;
	while(r>=l){
		if(zeros[r]!=1){
			max = r;
			return max;
		}

		r--;
	}
	
	return max;
	
}

void evaluate_query_1(int y,int n){
	zeros[y+s] = 1;
	v.push_back(y+s);
}

void evaluate_query_2(int p,int q,int n){
	ll l = p+s;
	ll r = q+s;
	ll max = find_max(l,r);
	cout<<max<<endl;
	s += max;
	s = s%n;
}

int main(){

	int T;
	cin>>T;
	while(T--){
		ll n,q;
		s = 0;
		for(int i=0;i<v.size();i++){
			zeros[v[i]] = 0;
			v[i] = 0;
		}
		cin>>n>>q;
		for(int i=0;i<q;i++){
			int t;
			ll y,p,q;
			cin>>t;
			if(t==1){
				cin>>y;
			}
			else{
				cin>>p>>q;
			}

			if(t==1)
				evaluate_query_1(y,n);
			else
				evaluate_query_2(p,q,n);
		}
	}
	return 0;
}