//https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void findIndices(vector<int>&cost, int ele1, int ele2, int* index1, int* index2){
    int n = cost.size();
    for(int i=0; i<n; i++){
        if(cost[i] == ele1){
            *index1 = i;
        }
    }

    for(int i=0; i<n; i++){
        if(cost[i] == ele2 && i!=*index1){
            *index2 = i;
        }
    }
}

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {

    unordered_multiset<int> mp;
    int index1 = -1;
    int index2 = -1;

    int n = cost.size();
    for(int i=0; i<n; i++){
        mp.insert(cost[i]);
    }

    for(int i=0; i<n; i++){
        int element = cost[i];
        int diff = money - element;
        if(element == diff){
            if(mp.count(element) == 2){
                findIndices(cost, element, element, &index1, &index2);
            }
        }
        else if(mp.count(diff) > 0){
            findIndices(cost, element, diff, &index1, &index2);
        }
    }
    if(index2 > index1)
        cout<<index1+1<<' '<<index2+1<<endl;
    else
        cout<<index2+1<<' '<<index1+1<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
