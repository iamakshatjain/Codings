#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int max_sum = INT_MIN;

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            int a = arr[i][j];
            // cout<<"i,j : "<<i<<','<<j<<' ';
            int b = arr[i][j+1];
            int c = arr[i][j+2];
            int d = arr[i+1][j+1];
            int e = arr[i+2][j];
            int f = arr[i+2][j+1];
            int g = arr[i+2][j+2];

            int sum = a+b+c+d+e+f+g;
            // cout<<sum<<endl;
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
