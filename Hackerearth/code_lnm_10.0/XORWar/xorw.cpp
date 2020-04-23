#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int find_winner(unsigned long long int x, unsigned long long int y, unsigned long long int z){
	int na,nb;
	while(true){
		//Alice
		na = log2(y);
		y -= pow(2,na);
		if(y<z) return 1;

		//Bob
		nb = log2(x);
		x -= pow(2,nb);
		if(x<z) return 0;
	}
}

int main(){

	unsigned long long int x,y,z;
	cin>>x>>y>>z;

	int ans = find_winner(x,y,z);
	ans?cout<<"Alice":cout<<"Bob";
	cout<<endl;
	return 0;
}