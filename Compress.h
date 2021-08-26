#include "HashTable.h"

pair<int, int> max_match(string &s, int idx, List *prev)
{
    int mx = 3, pos = -1;
    while (prev != NULL)
    {
        int cur_pos = prev->pos;
        int cur_idx = idx;
        while (cur_idx < (int)s.size() && s[cur_pos] == s[cur_idx])
        {
            ++cur_pos;
            ++cur_idx;
        }
        int len = (cur_idx - idx);
        if (len > mx)
        {
            mx = len;
            pos = prev->pos;
        }
        prev = prev->next;
    }
    return make_pair(idx-pos, mx);
}

void compress(string &s)
{
    HashTable ht;
    int cur = 0;
    int n = s.size();
    string ans = "";
    while (cur < n)
    {
        char a = s[cur], b = s[cur + 1];
        List *li = ht.Search(a, b);
        if (li != NULL)
        {
            pair<int, int> len = max_match(s, cur, li);
            if (len.first == -1)
            {
                ht.AddNode(a, b, cur);
                ans += s[cur];
                ++cur;
            }
            else
            {
                for (int i = 0; i < len.second; ++i)
                {
                    ht.AddNode(s[i + cur], s[i + cur + 1], i + cur);
                }
                ans += '$';
                ans += to_string(len.first);
                ans += ',';
                ans += to_string(len.second);
                ans += '$';
                cur += len.second;
            }
        }
        else
        {
            ht.AddNode(a, b, cur);
            ans += s[cur];
            ++cur;
        }
    }
    cout << ans << "\n";
}