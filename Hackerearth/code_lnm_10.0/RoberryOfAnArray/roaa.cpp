#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void findArray(long long int arr[],long long int s,int n){
	for(int i=0;i<n;i++){
		arr[i] = s^arr[i];
	}
}	

void swap(long long int arr[],int i,int j){
	int temp = arr[i];
	arr[i]  = arr[j];
	arr[j] = temp;
}

int partition(long long int arr[],int p, int r){
	long long int pivot = arr[r];
	int i = p-1;
	for(int j = i+1;j<r;j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,r,i+1);
	return i+1;
}

void sort(long long int arr[],int p,int r){//applying quick sort
	if(p>r)
		return;

	int q = partition(arr,p,r);
	sort(arr,p,q-1);
	sort(arr,q+1,r);
}

void display(long long int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	long long int arr[n];
	long long int s = 0;

	for(int i=0;i<n;i++){
		cin>>arr[i];
		s = s^arr[i];//to get the xor of all the inputs
	}

	findArray(arr,s,n);
	sort(arr,0,n-1);
	display(arr,n);

	return 0;
}