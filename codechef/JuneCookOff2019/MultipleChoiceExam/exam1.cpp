#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int calc_marks(int n,char s[],char u[]){
	int marks = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == u[i])
			marks++;
		else{
			if(s[i] != 'N'){
				i+=1;
				continue;
			}
		}
	}
	return marks;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char s[n];
		char u[n];
		cin>>u;
		cin>>s;

		cout<<calc_marks(n,s,u)<<endl;
	}
}