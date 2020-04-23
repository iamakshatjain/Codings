//quesiton : https://www.hackerrank.com/challenges/ctci-merge-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long mergeAndCount(long int *arr, int l, int mid, int r)
{
    long long mg_count = 0;
    int i = l;
    int j = mid + 1;
    long int merged[r - l + 1];
    int index = 0;
    while (i <= mid && j <= r)
    {
        if (*(arr + i) > *(arr + j))
        {
            mg_count += mid - i + 1;
            merged[index] = *(arr + j);
            index++;
            j++;
        }
        else
        {
            merged[index] = *(arr + i);
            index++;
            i++;
        }
    }
    while (i <= mid)
    {
        merged[index] = *(arr + i);
        index++;
        i++;
    }
    while (j <= r)
    {
        merged[index] = *(arr + j);
        index++;
        j++;
    }

    //copy the merged back to the array
    int len = r - l + 1;
    for (int k = 0; k < len; k++)
    {
        *(arr + k + l) = merged[k];
    }

    return mg_count;
}

// Complete the countInversions function below.
long long countInversions(long int *arr, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    long long left = countInversions(arr, l, mid);
    long long right = countInversions(arr, mid + 1, r);
    long long mg = mergeAndCount(arr, l, mid, r);
    return left + right + mg;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        long int arr[n];

        for (int i = 0; i < n; i++)
        {
            long int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long long result = countInversions(arr, 0, n - 1);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
