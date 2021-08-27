#include <bits/stdc++.h>
using namespace std;

#include "Compress.h"
#include "Decompress.h"

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans = compress(s);
        cout << ans << "\n";
        cout << decompress(ans) << "\n";
    }
    return 0;
}