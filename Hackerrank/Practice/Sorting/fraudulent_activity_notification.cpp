#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int count = 0;
    int n = expenditure.size();
    
    int max = expenditure[0];//to not iterate till 201 elements
    vector<int>frequency(201);
    for(int i=0; i<d; i++){
        frequency[expenditure[i]]++;
        if(expenditure[i] > max)
            max = expenditure[i];
    }

    int median_value = 0;
    
    for(int i = d; i<n;i++){
        
        if(d%2 == 0){
            median_value = 0;
            int sum = 0;
            for(int j = 0; j<=max; j++){
                sum+=frequency[j];
                if(sum>=d/2){
                    median_value +=j;
                    cout<<"div:21:"<<j<<endl;
                    if(sum >= d/2 + 1)
                        median_value+=j;
                    else{
                        for(int k = j+1; k<=max; k++){
                            if(frequency[k]>0){
                                median_value+=k;
                                cout<<"div:22:"<<k<<endl;
                                break;
                            }
                        }
                    }                   
                    break;
                }
            }
        }
        else{
            int sum = 0;
            for(int j = 0; j<=max; j++){
                sum+=frequency[j];
                if(sum>=(d+1)/2){
                    cout<<j<<endl;
                    median_value = 2*j;
                    break;
                }
            }
        }
        cout<<"med:"<<median_value<<endl;
        if(expenditure[i] >= median_value)
            count++;
        
        frequency[expenditure[i-d]]-=1;
        frequency[expenditure[i]]+=1;
        if(expenditure[i] > max)
            max = expenditure[i];

    }
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
