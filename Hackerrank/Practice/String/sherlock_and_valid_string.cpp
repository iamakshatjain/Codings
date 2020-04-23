#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s)
{
    string yes = "YES";
    string no = "NO";
    unordered_map<char, int> smap;
    unordered_map<int, int> nmap;

    for (int i = 0; i < s.size(); i++)
    {
        int ele = s[i];
        int prev_freq = smap[ele];
        int curr_freq = prev_freq + 1;
        smap[ele] += 1;
        if (prev_freq > 0)
        {
            nmap[prev_freq] -= 1;
        }
        nmap[curr_freq] += 1;
    }

    vector<int> freqs;
    vector<int> nos;
    for (auto i : nmap)
    {
        if (i.second > 0)
        {
            freqs.push_back(i.second);
            nos.push_back(i.first);
        }
    }

    if (freqs.size() == 1)
        return yes;

    if (freqs.size() > 2)
        return no;

    if (freqs.size() == 2)
    {
        int l;
        int r;
        int lf;
        int rf;
        if (nos[0] > nos[1])
        {
            l = nos[1];
            lf = freqs[1];
            r = nos[0];
            rf = freqs[0];
        }
        else
        {
            l = nos[0];
            lf = freqs[0];
            r = nos[1];
            rf = freqs[1];
        }

        if ((r - l == 1) && (rf == 1))
            return yes;
        if ((lf == 1 && l == 1))
            return yes;
    }

    return no;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
