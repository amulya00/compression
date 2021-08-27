#include <bits/stdc++.h>
using namespace std;

#include "Compress.h"
#include "Decompress.h"

int main(int argc, char *argv[])
{
    // string filename, mode;
    // if(argc == 3){
    //     mode = argv[1];
    //     filename = argv[2];
    // }
    // int size;
    // char* data;
    // ifstream fin("sample.txt", ios::in | ios::ate);
    // if(fin.is_open()){
    //     size = fin.tellg();
    //     cout<<size<<endl;
    //     data = (new char[size]);
    //     fin.seekg(0, ios::beg);
    //     fin.read(data , size);
    //     fin.close();
    // }else{
    //     throw runtime_error("Could not open file");
    // }

    std::ifstream t("sample.txt");
    std::string s((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());

    compress(s);
    // string ans = compress(s);
    //     cout << ans << "\n";
    cout << decompress() << "\n";
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     string s;
    //     cin >> s;
    //     
    // }
    return 0;
}
