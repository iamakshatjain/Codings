//partially correct
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{
    long int count = 0; //this is to be returned
    int n = arr.size();
    map<long int, vector<int>> positions;

    for (int i = 0; i < n; i++)
    { //O(n)
        auto itr = positions.find(arr[i]);
        if (itr == positions.end())
        {
            positions.insert(pair<long int, vector<int>>(arr[i], vector<int>()));
            positions[arr[i]].push_back(i);
            cout << "just entered : " << arr[i] << " " << positions[arr[i]][0] << endl;
        }
        else
        {
            itr->second.push_back(i);
            cout << "vector ele : " << i << endl;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        long long int next = arr[i] * r;
        long long int next2 = arr[i] * r * r;
        auto itr_next = positions.find(next);
        auto itr_next2 = positions.find(next2);
        if (itr_next != positions.end() && itr_next2 != positions.end())
        { //this means both the elements exist in the array

            vector<int> &f = positions[next];
            vector<int> &s = positions[next2];

            int f_index = 0; //this is the starting index for searching
            int s_index = 0;
            for (int j = 0; j < f.size(); j++)
            {
                if (f[f_index] < i)
                    f_index++;
            }
            for (int j = 0; j < s.size(); j++)
            {
                if (s[s_index] < f[f_index])
                    s_index++;
            }

            for (int j = f_index; j < f.size(); j++)
            {
                if (s[s_index] > f[j])
                {
                    count += s.size() - s_index;
                }
                else
                {
                    for (; s[s_index] < f[j]; s_index++)
                    {
                    }
                    j--;
                }
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++)
    {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
