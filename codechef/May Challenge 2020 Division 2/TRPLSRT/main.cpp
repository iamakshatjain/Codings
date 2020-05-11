// WA
#include <bits/stdc++.h>
using namespace std;

int findIndex(int ele, vector<int>arr, int l, int r);
int findUnsorted(vector<int> sorted, vector<int>arr);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr;
        vector<int>sorted_arr;
        vector<vector<int>>chances;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
            sorted_arr.push_back(temp);
        }
        // nlogn
        cout<<"before sort"<<endl;
        sort(sorted_arr.begin(), sorted_arr.end());
        cout<<"after sort"<<endl;
        int unsorted_count = 0;
        for(int i=0; i<n; i++){
            if(arr[i] != sorted_arr[i]){
                unsorted_count+=1;
            }
        }

        bool possible = true;
        while(unsorted_count!=0){
            int ind1 = findUnsorted(sorted_arr, arr);
            int ind2 = findIndex(arr[ind1], sorted_arr, 0, sorted_arr.size());
            int ind3 = findIndex(arr[ind2], sorted_arr, 0, sorted_arr.size());
            if(ind1 == ind3){
                bool flag = false;
                for(int i=0; i<n && unsorted_count!=2; i++){
                    if(sorted_arr[i] != arr[i] && i!=ind1 && i!=ind2){
                        ind3 = i;
                        flag = true;
                        break;
                    }
                }
                if(flag == false){
                    possible = false;
                    break;
                }
            }

            int v1 = arr[ind1];
            int v2 = arr[ind2];
            int v3 = arr[ind3];
            arr[ind1] = v3;
            arr[ind2] = v1;
            arr[ind3] = v2;
            
            if(arr[ind1] == sorted_arr[ind1]){
                unsorted_count-=1;
            }

            if(arr[ind2] == sorted_arr[ind2]){
                unsorted_count-=1;
            }

            if(arr[ind3] == sorted_arr[ind3]){
                unsorted_count-=1;
            }
            
            chances.push_back({ind1, ind2, ind3});
        }

        if(chances.size()>k || !possible){
            cout<<-1<<endl;
        } else{
            cout<<chances.size()<<endl;
            for(int i = 0; i<chances.size(); i++){
                cout<<chances[i][0]+1<<' '<<chances[i][1]+1<<' '<<chances[i][2]+1<<endl;
            }
        }

    }
    return 0;
}

int findIndex(int ele, vector<int>arr, int l, int r){
    if(l > r) return -1;
    int mid = l + (r-l)/2;
    if(ele == arr[mid]) return mid;
    else if(ele < arr[mid]) return findIndex(ele, arr, l, mid-1);
    else return findIndex(ele, arr, mid+1, r);
}

int findUnsorted(vector<int> sorted, vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != sorted[i]) return i;
    }
}