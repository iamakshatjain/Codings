#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long int smaller(long long int n,long long int m){
	if(n>m)
		return m;
	else
		return n;
}

long long int count_balls(long long int a){
	long long int count = 0;
	while(a){
		a = a/2;
		count++;
	}
	return count;
}

int main(){
	long long int n,m;
	cin>>n>>m;
	long long int a = smaller(n,m);
	long long int cannonBalls = count_balls(a);
	cout<<cannonBalls<<endl;
	return 0;
}