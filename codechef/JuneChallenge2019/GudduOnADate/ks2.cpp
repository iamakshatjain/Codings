#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sum_of_digits(int n){
	int s = 0;
	while(n){
		s+=n%10;
		n=n/10;
	}
	return s;
}

int findr(unsigned long long int n){
	return 10 - sum_of_digits(n)%10;
}

unsigned long long int find_nth_round_number(unsigned long long int n){
	return 10*n + findr(n);
}

int main(){

	int t;
	cin>>t;
	while(t--){
		unsigned long long int n;
		cin>>n;
		cout<<find_nth_round_number(n)<<endl;
	}
	return 0;
}