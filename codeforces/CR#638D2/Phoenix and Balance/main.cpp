// WA
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int count = 0;
    	long long int diff = 0;
    	int i=1;
    	while(i+1<=n){

    		if(count == 0) diff+=(pow(2, i) - pow(2, i+1));
    		else diff+=(pow(2, i+1) - pow(2, i));

    		count+=1;
    		count%=2;
    		i+=2;
    	}
    	cout<<abs(diff)<<endl;
    }
    return 0;
}
