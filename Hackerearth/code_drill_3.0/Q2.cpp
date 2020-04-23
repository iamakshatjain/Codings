#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n];

	int stack[n]={0};
	int top=-1;

	int key=1;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int j=0;
	for(j=0;j<n;j++){

		if(arr[j]==key){
			key++;
		}
		else if(key==stack[top]){
			key++;
			top--;
			--j;
			continue;
		}
		else{
			if(top+1!=n)
				stack[++top] = arr[j];
		}
		// cout<<j<<" "<<key<<" "<<stack[top]<<endl;
	}
	//when j is ended and stack can fulfill(descending order)
	while(stack[top]==key && j==n && top!=-1)
	{
		key++;
		top--;
	}

	// cout<<key<<endl;
	if(key==n+1){
		cout<<"Happy"<<endl;
	}
	else{
		cout<<"Sad"<<endl;
	}

	return 0;
}