#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

void swap(vector<int>&a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

int partition(vector<int>&b, vector<int>&a, int l, int r){
    int pivot = a[r];
    int i = l;
    int j = l-1;
    while(i<r){
        if(a[i] <= pivot){
            j++;
            swap(a, i, j);
            swap(b, i, j);
        }
        i++;
    }
    swap(a, j+1, r);
    swap(b, j+1, r);
    return j+1;
}

void quick_sort(vector<int>&values, vector<int>&weights, int l, int r ){
    if(l>r)
        return;
    else{
        int q = partition(values, weights, l, r);
        quick_sort(values,weights ,l, q-1);
        quick_sort(values,weights, q+1, r);
    }
}

// int findMaxValueBacktrack(int T[][W+1], vector<int>values, vector<int>weights, int N, int W){
//     int val = *(T + (N-1)*N + W-1 );
// }

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
    	int N;
    	int W;
        int X;
        int Y;
    	cin>>N>>W>>X>>Y;
    	vector<int>values;
    	vector<int>weights;
    	int T[N][W+1] = {0};
    	
    	//input values
    	for(int i=0; i<N; i++){
    	    int temp;
    	    cin>>temp;
    	    weights.push_back(temp);
    	}
    	
    	//input weights
    	for(int i=0; i<N; i++){
    	    int temp;
    	    cin>>temp;
    	    values.push_back(temp);
    	}
        
    	quick_sort(values,weights,0,N-1);
        
        for(int i=0; i<N; i++){
            for(int j=1; j<W+1; j++){
                int weight = weights[i];
                int value = values[i];
                if(j < weight){
                    if(i-1>=0)
                        T[i][j] = T[i-1][j];
                    else
                        T[i][j] = 0;
                }
                else{
                    if(i-1 >= 0){
                        if(j-weight>=0)
                            T[i][j] = max(value + T[i-1][j-weight], T[i-1][j]);
                        else
                            T[i][j] = max(value, T[i-1][j]);   
                    }
                    else{
                        T[i][j] = max(value, 0);
                    }
                    
                }
            }
        }
    
    	// cout<<T[N-1][W]<<endl;
        // cout<<findMaxValueBacktrack(T, values, weights, N, W);
        int val = T[N-1][W];
        vector<int>rvalues;
        int r = N-1;
        int c = W;
        while(r>0 && c>0){
            if(r-1 >= 0 && c>=0 && T[r][c] == T[r-1][c]){
                r-=1;
                cout<<"R : "<<r<<endl;
                rvalues.push_back(values[r]);
            }
            
            else if (r-1 >= 0 && c>=0 && T[r][c] != T[r-1][c]){
                if(r < 0)
                    break;
                cout<<"R : "<<r<<endl;
                rvalues.push_back(values[r]);
                r-=1;
                c-=weights[r];
            }  
            else
                break;
        }

        for(int i=0; i<rvalues.size(); i++)
            cout<<"rvalues : "<<rvalues[i]<<' ';
        cout<<endl;
    }
	
	
	return 0;
}
