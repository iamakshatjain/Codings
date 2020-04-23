#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int findAttendance(char arr[],int d,int nPresents){
	int minReqAtt = ceil(d*0.75);
	int maxPoss = 0;

	if(nPresents>=minReqAtt)
		return 0;

	minReqAtt-=nPresents;

	for(int i=2;i<d-2;i++){
		if((arr[i-1]=='P' || arr[i-2]=='P')&&(arr[i+1]=='P' || arr[i+2]=='P')&&(arr[i]=='A')){
			maxPoss++;
		}
		if(maxPoss>=minReqAtt)
			return minReqAtt;
	}
	
	return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int D;
		cin>>D;
		char attendanceString[D];
		int nP = 0;
		for(int i=0;i<D;i++){
			cin>>attendanceString[i];
			if(attendanceString[i]=='P'){
				nP++;
			}
		}
		// cout<<"np : "<<nP<<endl;
		cout<<findAttendance(attendanceString,D,nP)<<endl;
	}
}