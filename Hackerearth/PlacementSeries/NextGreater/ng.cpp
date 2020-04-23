#include<stdio.h>
#include<iostream>

using namespace std;

void print_next_greater(int arr[],int n){
	int greater[n] = {0};
	int top = -1;
	int ng[n] = {0};
	ng[n-1] = -1;
	int max = arr[n-1];
	greater[++top] = arr[n-1];
	for(int i=n-2;i>=0;i--){
		if(arr[i]>=max){
			ng[i] = -1;
			max = arr[i];
			if(greater[top] != arr[i])
				greater[++top] = arr[i];
		}
		else{
			while(top>=0){
				if(greater[top] > arr[i]){
					ng[i] = greater[top];
					break;
				}
				top--;
			}
			greater[++top] = arr[i];
		}
	}

	for(int i=0;i<n;i++){
		cout<<ng[i]<<' ';
	}
	cout<<endl;
}


int main(){

	int n;
	cin>>n;
	int arr[n] = {0};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	print_next_greater(arr,n);
	return 0;
}