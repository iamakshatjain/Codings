#include<bits/stdc++.h>
#include<iostream>
#define ll long long int

using namespace std;

void display_sell_matrix(ll sell_matrix[],ll n){
	for(int i=0;i<n;i++){
		cout<<sell_matrix[i]<<' ';
	}
	cout<<endl;
}

ll find_optimal_flavour(ll c[],ll m){//this simply finds whatever we have in maximum quantity
	for(int i=0;i<m;i++){
		if(c[i]>0)
			return i;
	}
}

ll calculate_profit(ll n, ll m, ll c[], ll d[], ll f[], ll b[], ll s[]){
	ll profit = 0;
	for(int i=0;i<n;i++){
		if(c[d[i]-1]>0){//if we have the required flavour
			c[d[i]-1]--;
			profit+=f[i];
			s[i] = d[i];
		}
		else{
			s[i] = -1;
		}
	}

	// sort(c,c+m);
	for(int i=0;i<n;i++){
		if(s[i]==-1){
			//we need to find the required min sold flavour
			ll fl = find_optimal_flavour(c,m);
			//if we have the required flavour
			c[fl]--;
			profit+=b[i];
			s[i] = fl+1;
		}
	}

	return profit;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll c[m];
		for(int i=0;i<m;i++){
			cin>>c[i];
		}
		ll d[n];
		ll f[n];
		ll b[n];
		for(int i=0;i<n;i++){
			cin>>d[i]>>f[i]>>b[i];
		}
		ll sell_matrix[n] = {0};

		cout<<calculate_profit(n,m,c,d,f,b,sell_matrix)<<endl;
		display_sell_matrix(sell_matrix,n);

	}
}