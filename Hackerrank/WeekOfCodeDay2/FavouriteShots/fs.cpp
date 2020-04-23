#include<bits/stdc++.h>
#include<iostream>
#define ll long long int
using namespace std;

//d<a
int calculateLeftShots(ll d, ll a[], int l, int r,int n){
	if(l>r){
		if(l == 0)
			return n;
		else
			return 0;
	}
	int mid = (l+r)/2;
	if(a[mid]<=d && a[mid+1]>d)
		return (n-(mid+1));
	if(a[mid]<d)
		return calculateLeftShots(d,a,mid+1,r,n);
	if(a[mid]>d)
		return calculateLeftShots(d,a,l,mid-1,n);

}

//c>b
int calculateRightShots(ll c, ll b[], int l, int r,int n){//to how many shots does it lie on right to
	int mid = (l+r)/2;
	if(l>r){
		if(l == 0)
			return 0;
		else
			return n;
	}
	// cout<<"calculated mid: "<<mid<<endl;
	if(b[mid]>=c && b[mid-1]<c){
		// cout<<"mid to be returned : "<<mid<<endl;
		return mid;//return actual no. of elements at the left
	}
	if(b[mid]<c)
		return calculateRightShots(c,b,mid+1,r,n);
	if(b[mid]>c)
		return calculateRightShots(c,b,l,mid-1,n);
}

ll calculateTotalStrength(ll a[],ll b[], ll c[], ll d[], int n,int m){
	ll sum = 0;
	for(int i=0;i<m;i++){
		int lefts = calculateLeftShots(d[i],a,0,n-1,n);
		int rights = calculateRightShots(c[i],b,0,n-1,n);
		// cout<<"lefts : "<<lefts<<endl;
		// cout<<"rights : "<<rights<<endl;
		sum += (n-(lefts + rights));
	}

	return sum;
}


int main(){
	int n,m;
	cin>>n>>m;
	ll a[n];
	ll b[n];
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	ll c[m];
	ll d[m];
	for(int i=0;i<m;i++)
		cin>>c[i]>>d[i];

	cout<<calculateTotalStrength(a,b,c,d,n,m);
	// cout<<calculateLeftShots(6,a,0,n-1,n);
}