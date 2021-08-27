#include "HashTable.h"
#include "BitBuffer.h"

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
    if (pos == -1)
        return make_pair(pos, mx);
    return make_pair(idx - pos, mx);
}

string compress(string &s)
{
    HashTable ht;
    int cur = 0;
    int n = s.size();
    BitBuffer bb;
    while (cur < n)
    {
        char a = s[cur], b = s[cur + 1];
        List *li = ht.Search(a, b);
        if (li != NULL)
        {
            pair<int, int> len = max_match(s, cur, li);
            if (len.first == -1)
            {
                // cout << s[cur] << "\n";
                ht.AddNode(a, b, cur);
                bb.add(s[cur]);
                ++cur;
            }
            else
            {
                for (int i = 0; i < len.second; ++i)
                {
                    ht.AddNode(s[i + cur], s[i + cur + 1], i + cur);
                }
                bb.add(len.first, len.second);
                cur += len.second;
            }
        }
        else
        {
            ht.AddNode(a, b, cur);
            bb.add(s[cur]);
            ++cur;
        }
    }
    return bb.print();
}

// 0 00100110 0 11001110 0 01100110 0 11001110 0 1000011 0 00110011 0 01100111 0 000100110001100110011001110001100110010000110
