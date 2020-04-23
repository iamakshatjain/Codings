#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b)
{
    unordered_map<char, int> mapa;
    unordered_map<char, int> mapb;

    int counta = a.size();
    int countb = b.size();
    for (int i = 0; i < a.size(); i++)
    {
        auto itr = mapa.find(a[i]);
        if (itr == mapa.end())
            mapa[a[i]] = 1;
        else
            mapa[a[i]] += 1;
    }

    for (int i = 0; i < b.size(); i++)
    {
        auto itr = mapb.find(b[i]);
        if (itr == mapb.end())
            mapb[b[i]] = 1;
        else
            mapb[b[i]] += 1;
    }

    for (int i = 0; i < b.size(); i++)
    {
        auto itr = mapa.find(b[i]);
        if (itr != mapa.end())
        {
            if (mapa[b[i]] > 0)
            {
                mapa[b[i]] -= 1;
                counta -= 1;
            }
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        auto itr = mapb.find(a[i]);
        if (itr != mapb.end())
        {
            if (mapb[a[i]] > 0)
            {
                mapb[a[i]] -= 1;
                countb -= 1;
            }
        }
    }

    return counta + countb;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
