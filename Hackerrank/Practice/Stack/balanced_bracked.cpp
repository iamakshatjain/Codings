//hackerrank.com/challenges/balanced-brackets/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues&isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s)
{
    int n = s.size();
    char arr[n + 1];
    int top = -1;
    bool flag = true;
    for (int i = 0; i < n && flag == true; i++)
    {
        char ele = s[i];
        switch (ele)
        {
        case '(':
            arr[++top] = '(';
            break;
        case '[':
            arr[++top] = '[';
            break;
        case '{':
            arr[++top] = '{';
            break;
        case ')':
            if (top == -1 || arr[top] != '(')
            {
                flag = false;
                break;
            }
            else
            {
                top--;
                break;
            }
        case ']':
            if (top == -1 || arr[top] != '[')
            {
                flag = false;
                break;
            }
            else
            {
                top--;
                break;
            }
        case '}':
            if (top == -1 || arr[top] != '{')
            {
                flag = false;
                break;
            }
            else
            {
                top--;
                break;
            }
        default:
            flag = false;
            break;
        }
    }
    if (top != -1 || flag == false)
        return "NO";
    else
        return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
