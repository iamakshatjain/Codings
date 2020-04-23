#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	cin>>t;
	while(t--){
	  int N;
	  int l;
	  cin>>N;
	  cin>>l;
	    if(N%2 != 0){
            cout<<0<<endl;
            continue;
	    }
	    
	  int n = N/2;
	  int count_div = l/2;
	  int count = 1;
	  int itr = n-1;
	  count_div--;
	  while(count_div > 0){
	    count = (count*itr)%1000000007;
	    itr--;
	    count_div--;
	    
	  }
	  
	  cout<<count%1000000007<<endl;
	}
	
	
	return 0;
}


