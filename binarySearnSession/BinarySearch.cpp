// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // v sorted elements
    while (k--)
    {
        int a;
        cin >> a;

        int l = 0;
        int r = n - 1;
        bool flag = true;
        while (r >= l)
        {
            int mid = (l + r) >> 1;
            if (v[mid] == a)
            {
                cout << "YES" << endl;
                flag = false;
                break;
            }
            else if (v[mid] < a)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}