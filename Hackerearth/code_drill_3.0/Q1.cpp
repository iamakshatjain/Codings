#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n,x,y;
	cin>>n>>x>>y;

	int flag = 1;
	int sum = 0;
	int marks[n]={0};
	
	for(int i=0;i<n;i++){
		cin>>marks[i];
		if(marks[i]<y){
			flag=0;
			break;
		}
		sum = sum+marks[i];
	}
	if(sum*100/(n*100)<x)
		flag=0;

	if(flag==0)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}