#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the hackerlandRadioTransmitters function below.
int hackerlandRadioTransmitters(vector<int> x, int k) {
    int count = 0;
    sort(x.begin(), x.end());
    int h = x[x.size()-1];//last house
    int i=x.size()-1;//the last house
    while(h>=1){
        int min = x[i]+k-h;//for the last house
        int last_h = h;
        int last_h_i = i;

        while(i>=0){
            int temp = x[i]+k;
            if(temp >= h){
                if(temp-h<=min){//if the difference is least => the house is closest to the boundary of lighting
                    min = temp-h;
                    last_h = temp-2*k-1;
                    last_h_i = i;
                }
            }
            i--;
        }

        count++;
        if(last_h < 1 || last_h_i<0) //if there are no more houses
            break;
        else{
            int itr = last_h_i;
            bool flag = false;
            while(itr>=0){
                if(x[itr]<=last_h){
                    flag = true;
                    h = x[itr];
                    i = last_h_i;
                    break;
                }
                itr--;
            }
            if(flag == false)//to check if there is no more house to be lit
                break;
        }
    }
    return count;

}

int main(){
    int n,k;
    cin>>n>>k;
    // cout<<"n : "<<n<<endl;
    vector<int>x;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        x.push_back(temp);
    }

    cout<<hackerlandRadioTransmitters(x,k)<<endl;
}