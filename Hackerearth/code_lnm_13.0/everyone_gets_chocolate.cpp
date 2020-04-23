#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool comparator(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    if (a[0] == b[0])
        return (a[1] < b[1]);
    return false;
}

int main()
{

    int n;
    int m;

    cin >> n;
    cin >> m;
    int n_covered = 0;

    long long int chocs = 0;
    vector<vector<int>> q(m);
    vector<int> f(n + 1);
    long int curr = 1;

    for (int i = 0; i < m; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        q[i].resize(2);
        if(x<=y){
            q[i][0] = x;
            q[i][1] = y;
        }
        else{
            q[i][0] = y;
            q[i][1] = x;
        }        
    }

    sort(q.begin(), q.end(), comparator);

    for(int i=0; i<n ;i++){
        f[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int x = q[i][0];
        int y = q[i][1];
        cout << "x : " << q[i][0] << " y : " << q[i][1] << endl;

        // cout<<"x:"<<x<<"y:"<<y<<endl;


        if (f[x] != 0 && f[y] != 0)
        {
            cout << "here we continue" << endl;
            cout << " fx : " << f[x] << " fy : " << f[y] << "curr : "<< curr <<  endl;
            continue;
            // n_covered+=2;
        }

        if (f[x] != 0 && f[y] == 0){
            f[y] = f[x];
            cout << "----fx : " << f[x] << " fy : " << f[y] << "current : " << curr << endl;
            chocs += f[y];
            n_covered+=1;
            // curr--;
            // cout<<"current : "<<curr<<endl;
        }
        if (f[y] != 0 && f[x] == 0){
            f[x] = f[y];
            cout << "----fy : " << f[y] << " fx : " << f[x] << "current : " << curr << endl;
            chocs += f[x];
            n_covered+=1;
            // curr--;
            // cout
        }
            

        else if(f[y] == 0 && f[x] == 0)
        {
            f[x] = curr;
            f[y] = curr;
            curr++;
            chocs += f[x];
            chocs += f[y];
            n_covered+=2;
            cout << " fx : " << f[x] << " fy : " << f[y] << "curr : " << curr << endl;
        }
        
        // cout<<"x : "<<x<<" fx : "<<f[x]<<endl;
        // cout<<"y : "<<y<<" fy : "<<f[y]<<endl;
    }

    cout<<"chocs till now : "<<chocs<<endl;
    // int total_n = curr+(n-n_covered-1);
    // chocs+=(((total_n)*(total_n+1))/2);
    // chocs-=(((curr-1)*(curr))/2);
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {   
            f[i] = chocs;
            chocs += curr;
            curr++;
            cout << "friend : "<<i<< " value : " << f[i] << " current : " << curr << endl;
        }
        // else
        // {
        //     chocs += f[i];
        // }
        // cout<<i<<" : chocs :"<<chocs<<endl;
    }

    cout << chocs << endl;
    return 0;
}