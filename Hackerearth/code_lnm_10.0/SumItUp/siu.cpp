#include <bits/stdc++.h>
#include <iostream>
using namespace std;

map<unsigned long long int,map<unsigned long long int,unsigned long long int>>vect;//this removed stack overflow error
// long long unsigned int power(long long unsigned int b, long long unsigned int r){
// 	long long unsigned int ans = 1;
// 	for(int i=0;i<r;i++){
// 		ans %= 1000000007;
// 		ans*=b;
// 		ans %= 1000000007;
// 	}
// 	return ans;
// }

long long unsigned int power(long long unsigned int x, long long unsigned int y, long long unsigned int p) 
{ 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

unsigned long long int finda(unsigned long long int i){
	if(i==1)
		return 1;
	return power(2,i-2,1000000007)*(i+1);
}

unsigned long long int findVal(unsigned long long int r, unsigned long long int c){
	if(vect[r][c]!=0)
		return vect[r][c];

	unsigned long long int a = finda(r);
	unsigned long long int d = power(2,r-1,1000000007);
	return a+(c-r)*d;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		unsigned long long int n,r,c;
		cin>>n>>r>>c;
		if(c<r){			
			cout<<-1<<endl;
		}
		else{
			vect[r][c] = findVal(r,c);
			cout<<vect[r][c]%1000000007<<endl;
		}
	}
	return 0;
}