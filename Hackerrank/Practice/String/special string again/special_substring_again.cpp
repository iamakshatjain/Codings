#include <bits/stdc++.h>

using namespace std;

long calculateCombinations(int n){
    return (n*(n+1))/2;
}

long long checkForNext(string s, int i, int n){
    char ele = s[i]; 
    i+=2;
    int k = i+n-1;
    long long int count = 0;
    for(;i<k; i++){
        if(s[i] == ele)
            count++;
    }
    return count;
}

// Complete the substrCount function below.
long long int substrCount(int n, string a) {
    int s = 0;
    int f = 0;
    // int start = -1;
    // int end = -1;
    // char ele = '*';
    // int cnt = -1;
    // long int cnt_main = -1;
    long long int count = 0;
    for(int i=0; i<n;){
        int next_ele_count = s-f+1;
        // if(i<=end && i>=start){
        //     if(cnt > 0 && a[i]==ele){
        //         cnt--;
        //     }
        //     if(i == end){
        //         count+=cnt_main-cnt;
        //         cout<<"exp : "<<cnt_main-cnt<<endl;
        //         cnt_main=-1;
        //         cnt=-1;
        //         cout<<"exp"<<endl;
        //         // if(cnt!=0){
        //         //     cnt = -1;
        //         //     cnt_main = -1;
        //         //     start = -1;
        //         //     end = -1;
        //         //     ele = '*';
        //         // }
        //         // else{
                    
        //         // }

        //     }
        // }

        if((i+1 < n) && (a[i] == a[i+1])){
            s++;
            i++;
        }
        else if((i+2 < n) && (a[i] == a[i+2])){
            long long int comb = calculateCombinations(next_ele_count); 
            count+=comb;
            cout<<"combinations : "<<comb<<endl;
            
            int count_next = checkForNext(a, i, next_ele_count); 
            count+=count_next;
            cout<<"Next avail : "<<count_next<<endl;
            // if(next_ele_count == 1){
            //     count++;
            //     cout<<"for 3 set"<<endl;
            // }else{
            //     // if((i+3 < n) && (next_ele_count > 1)){
            //         cout<<"started the count"<<endl;
            //         start = i+2;
            //         end = i+2+next_ele_count-1;
            //         ele = a[i];
            //         cnt = next_ele_count;
            //         cnt_main = next_ele_count;
            //     // }
            // }



            i++;
            f = i;
            s = i;
        }
        else{
            long long int comb = calculateCombinations(next_ele_count); 
            count+=comb;
            cout<<"combinations - else : "<<comb<<endl;
            i++;
            s = i;
            f = i;
        }
        cout<<"f : "<<f<<" s : "<<s<<endl;
    }
    if(s!=f && s!=n && f!=n){
        long long int comb = calculateCombinations(s-f+1); 
        count+=comb;
        cout<<"combinations - out : "<<comb<<endl;
        cout<<"f : "<<f<<" s : "<<s<<endl;
    }
    // if(cnt != -1 || cnt_main != -1){
    //     count+=cnt_main-cnt;
    //     cout<<"end"<<endl;
    // }
    return count;
}