#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>arr){
    for(int x : arr){
        cout<<x<<' ';
    }
    cout<<endl;
}

int minimumSwaps(vector<int> arr)
{
    int n = arr.size();
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            //swapping
            int current = arr[i];
            int temp = arr[current - 1];
            arr[current - 1] = current;
            arr[i] = temp;
            swaps++;
            i--;
        }
    }
    return swaps;
}

int main(){
    int n;
    cin>>n;
    vector <int> vect(n);
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        vect[i] = temp;
    }
    cout<<minimumSwaps(vect)<<endl;
    return 0;
}