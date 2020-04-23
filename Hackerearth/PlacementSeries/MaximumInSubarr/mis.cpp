#include<stdio.h>
#include<iostream>

using namespace std;

int max(int arr[], int l,int r){
	int imax = l;
	for(int i=l+1;i<=r;i++){
		if(arr[i]>arr[imax])
			imax = i;
	}
	return imax;
}


void print_maximums(int arr[], int n,int k){
	int l = 0;
	int r = k-1;

	int max_index = max(arr,l,r);
	cout<<arr[max_index]<<' ';
	l++;
	r++;
	while(r<n){
		if(max_index<l){
			if(arr[r]<arr[max_index]){
				max_index = max(arr,l,r);
				cout<<arr[max_index]<<' ';
				l++;
				r++;
				continue;
			}
			
			else{
				max_index = r;
				cout<<arr[max_index]<<' ';
				l++;
				r++;
				continue;
			}
		}
		else{
			if(arr[r] < arr[max_index]){
				cout<<arr[max_index]<<' ';
				l++;
				r++;
				continue;
			}

			else{
				max_index = r;
				cout<<arr[max_index]<<' ';
				l++;
				r++;
				continue;
			}
		}
	}

	cout<<endl;
}


int main(){


	int n,k;
	cin>>n>>k;
	int arr[n] = {0};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	print_maximums(arr,n,k);
	return 0;
}