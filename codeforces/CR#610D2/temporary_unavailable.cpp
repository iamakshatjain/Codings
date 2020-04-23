#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long int findCommon(long int a, long int b, long int c, long int r){
    long int left = c - r;
    long int right = c + r;

    //no overlapping
    if(left > b || right < a)
        return 0;

    else if( a>=left && b<=right)
        return abs(a-b);
    else if( left>=a && right<=b )
        return abs(left-right);

    else if (left>=a && left<=b && b <= right)
        return abs(left - b);
    else
        return abs(a - right);
}

long int calculateUnavailability(long int a, long int b, long int c, long int r)
{
    long int common = findCommon(a, b, c, r);
    return abs(abs(a-b)-common);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long int val1;
        long int val2;
        long int c;
        long int r;
        long int a,b;
        cin>>val1>>val2>>c>>r;   
        
        if(val1>val2){
            b = val1;
            a = val2;
        }
        else
        {
            a = val1;
            b = val2;
        }
        cout<<calculateUnavailability(a,b,c,r)<<endl;
    }  
}