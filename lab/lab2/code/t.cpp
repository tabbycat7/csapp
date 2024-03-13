#include <bits/stdc++.h>
using namespace std;

int bitCount(int x)
{
    int m = (0x11 << 8) + 0x11;
    int m2;
    int a;
    int b;
    m = (m << 16) + m;
    m2 = 0x0f;
    m2 = (m2 << 8) + m2;
    a = x & m;
    a += (x >> 1) & m;
    a += (x >> 2) & m;
    a += (x >> 3) & m;
    a = a + (a >> 16);
    b = a & m2;
    b = b + ((a >> 4) & m2);
    return (b & 0x3f) + ((b >> 8) & 0x3f);
}

int dividePower2(int x, int n)
{
    // 注意是向0舍入
    int a = x >> 31;
    int bias = (1 << n) + (~1) + 1;
    int b = a & bias;
    return (x + b) >> n;
}

int isLessOrEqual(int x, int y)
{
    int sx = x >> 31;
    int sy = y >> 31;
    int s = x ^ y;
    int c;
    c = ~x + y + 1;
    c = c >> 31;
    return !!((~s & !c) | (s & x));
}
int main()
{
    cout << isLessOrEqual(0x80000000, 0x80000001) << endl;
}