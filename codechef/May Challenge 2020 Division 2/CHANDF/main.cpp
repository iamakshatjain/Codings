// WA
#include <bits/stdc++.h>
using namespace std;

long long int findZ(long long int x, long long int y, long long int l, long long int r){
    if(x == 0) return l;

    // case 1
    long long int OR = x|y;
    if(OR >=l && OR <= r){
        return OR;
    }
    else if(OR < l){

    }
    else{
        // OR > r   

    }

    // we need to find the max number of ones elements in between l and r
    // long long int power1 = ceil(log2(y));
    // // long long int powerL = ceil(log2(l));
    // long long int power2 = ceil(log2(r));
    // long long int power = min(power1, power2);
    // long long int ans = pow(2, power)-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long int x, y, l, r;
        cin>>x>>y>>l>>r;
        long long int OR = x|y;
        cout<<OR<<endl;
    }
    return 0;
}