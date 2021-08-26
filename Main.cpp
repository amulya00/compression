#include <bits/stdc++.h>
using namespace std;

#include "Compress.h"
#include "BitBuffer.h"

int main()
{
    BitBuffer b;
    b.add('a');
    b.add('b');
    b.add(4,2);
    b.print();
}