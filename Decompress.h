using byte = unsigned char ;
constexpr std::size_t BITS_PER_BYTE = std::numeric_limits<byte>::digits ;
using bits_in_byte = std::bitset<BITS_PER_BYTE> ;

int convert(int cur, int size, string &s)
{
    int ans = 0;
    assert((size - 1 + cur) < (int)s.size());
    assert((size - 1 + cur) >= 0);
    for (int i = size - 1; i >= 0; --i)
    {
        ans = ((ans << 1) | (s[cur + i] == '1'));
    }
    return ans;
}

string decompress()
{
    // int size;
    // unique_ptr<char> data;
    // ifstream fin("compressed.bin", ios::in | ios::binary | ios::ate);
    // if(fin.is_open()){
    //     size = fin.tellg();
    //     data = unique_ptr<char>(new char[size]);
    //     fin.seekg(0, ios::beg);
    //     fin.read(data.get(), size);
    //     fin.close();
    // }else{
    //     throw runtime_error("Could not open file");
    // }

    std::ifstream t("sample.txt");
    std::string sr((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());

    string s;
    for(int i=0;i<sr.length();i++){
        s += bits_in_byte( byte(sr[i])).to_string();
    }
    


    int n = s.size();
    string ans = "";
    // 0
    int i = 0;
    while (i < n)
    {
        if (s[i] == '0')
        {
            int ascii = convert(i + 1, 8, s);
            ans += (char)(ascii);
            i += 1;
            i += 8;
        }
        else
        {
            int jump = convert(i + 1, 12, s);
            int len = convert(i + 1 + 12, 6, s);
            int cur = (int)ans.size();
            for (int j = 0; j < len; ++j)
            {
                // assert((cur - jump + j - 1) >= 0);
                ans += (ans[cur - jump + j]);
            }
            i += 1;
            i += 12;
            i += 6;
        }
    }
    return ans;
}

// 0 10000110 0 01000110 1 010000000000001000
// 0 10000110 0 01000110 1 010000000000001000
// 0 a 0 b

// dsfsafsdfsfa

// 0 00100110 0 11001110 0 01100110 0 11001110
// 0 10000110 1 011000000000, 110000 1 100100000000, 110000 0 10000110

// dsfsafsdfsfa
// 0 00100110 0 11001110 0 01100110 0 11001110 0 10000110 1 011000000000 110000 1 100100000000 110000 0 10000110
//     d          s           f         s            a