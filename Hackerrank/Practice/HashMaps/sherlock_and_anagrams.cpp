#include <bits/stdc++.h>

using namespace std;

int findAnagrams(string arr[], int n)
{
    int count = 0;
    int rep = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            rep += 1;
        }
        else
        {
            count += (rep * (rep - 1)) / 2;
            rep = 1;
        }
    }
    if (rep != 1)
    {
        count += (rep * (rep - 1)) / 2;
    }
    return count;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s)
{
    int count = 0;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        string arr[n - i];
        int index = 0;
        for (int j = 0; j < n - i; j++)
        {
            string temp = s.substr(j, i + 1);
            sort(temp.begin(), temp.end());
            arr[index++] = temp;
        }
        sort(arr, arr + n - i);
        count += findAnagrams(arr, n - i);
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
