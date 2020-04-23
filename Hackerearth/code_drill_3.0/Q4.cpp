#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// int isSuitable(int mid,int sumarr[],int x,int l,int r){
// 	int totalSum = 0;
// 	if(l>0)
// 		totalSum = sumarr[r]-sumarr[l-1];
// 	else
// 		totalSum = sumarr[r];
// }

int isSuitable(int mid,int *arr,int n,int x){
	int s=0;
	for(int i=mid;i<n;i++){
		s+=arr[i]-arr[mid];
	}

	if(s>x)
		return 1;
	else if(s==x)
		return 0;
	else
		return -1;
}

int findBinary(int n,int x, int sumarr[],int arr[]){
	int l=0;
	int r=n-1;

	while(l<=r){
		int mid = (l+r)/2;
		// if(isSuitable(arr[mid],sumarr,x,l,r)<0)
		if(isSuitable(mid,arr,n,x)<0)
			r=mid-1;
		// else if(isSuitable(arr[mid],sumarr,x,l,r)>0)
		else if(isSuitable(mid,arr,n,x)>0)
			l=mid+1;
		else if(l==r)
			return mid;
	}
}

// void sumarray(int sumarr[],int arr[],int n){
// 	for(int i=0;i<n;i++){
//         if(i>0)
//         	sumarr[i]=sumarr[i-1]+arr[i];
//         else
//         	sumarr[0]=arr[0];
//     }
//     // return arr;
// }

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[],int p,int r){
	//here r denotes the actual ending index
	int pivot = a[r];
	int i = p-1;
	for(int j=p;j<r;j++){
		if(a[j]<=pivot){
			i++;
			swap(a+j,a+i);
		}
	}
	swap(a+i+1,a+r);
	return i+1;
}


void quick_sort(int a[],int p,int r){
	//we apply quick sort here
	if(p>r)
		return;
	else{
		int q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}

}


void display(int arr[],int n){
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
    int n,x;
    cin>>n>>x;

    int arr[n]={0};
    int sumarr[n]={0};

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quick_sort(arr,0,n-1);
    // sumarray(sumarr,arr,n);
    
    // display(arr,n);
    // display(sumarr,n);
    int i = findBinary(n,x,sumarr,arr);
    cout<<i<<endl;
    return 0;
}