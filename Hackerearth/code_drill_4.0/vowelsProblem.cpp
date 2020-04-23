#include<bits/stdc++.h>
using namespace std;

int isVowel(char a){
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return 1;
    
    return 0;
}


int main(){
        
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        long long int count = 0;
        
        vector <int> bits(n);
        long long int sum = 0;
            
        for(int i = 0; i<n; i++){
            if(isVowel(s[i])){
                bits[i] = 1;   
                sum+=1;
            }
            
            else{
                bits[i] = 0;
            }
        }
            
        if(sum == 0 || n == 1 || n == 2){
            cout<<count<<endl;
            continue;
        }
        
        long long int right_sum = sum;
        long long int left_sum = bits[0];
        right_sum-=bits[0];
        
        for(int i=1; i<n-1; i++ ){
            right_sum-=bits[i];
            if(left_sum > 0 && right_sum > 0)
                count++;
                
            left_sum+=bits[i];
        }
        
        cout<<count<<endl;

    }
    return 0;
}