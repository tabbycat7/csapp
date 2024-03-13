#include <bits/stdc++.h>
using namespace std;

int isTmax(int x)
{
    int a = x + 1;
    int b = ~x;
    return !(a ^ b);
}
int isLessOrEqual(int x, int y)
{
    int a = y + (~x + 1);
    return !!((a >> 31) ^ 1);
}

int logicalNeg(int x)
{
    int a = x | x >> 16;
    int b = a | a >> 8;
    int c = b | b >> 4;
    int d = c | c >> 2;
    int e = d | c >> 1;
    return 2 + ~(e & 1);
}

unsigned floatScale2(unsigned uf)
{
    int exp = uf & 0x7f800000;
    int f = uf & 0x007fffff;
    if (!(exp ^ 0x7f800000))
        return uf;
    if (!exp)
    {
        if (f & 0x00400000)
        {
            exp = exp + 0x00800000;
            f = f << 1;
            uf = uf & 0xff800000 | f;
        }
        else
        {
            f = f << 1;
            uf = uf & 0xff800000 | f;
        }
    }
    else
        exp = exp + 0x00800000;
    int t = 0x807fffff;
    uf = uf & t | exp;
    return uf;
}
int floatFloat2Int(unsigned uf)
{
    unsigned int u = 0x1 << 31;
    unsigned sign = uf >> 31;
    unsigned int f = uf << 9;
    unsigned iexp = uf << 1 >> 24;
    printf("%.8X\n", iexp);
    if (iexp < 127)
        return 0;
    else if (iexp >= 158)
        return u;
    int i = 0;
    int resault = 0x1;
    while (i < iexp - 127)
    {
        unsigned k = u & uf;
        k >> 31;
        resault = (resault << 1) | k;
        i++;
    }
    if (sign)
        resault = ~resault + 1;
    return resault;
}
int getByte(int x, int n)
{
    x = (unsigned int)x;
    unsigned b = 0xff;
    n = (n << 3);
    b = b << n;
    x = (x & b);
    printf("%.8X\n", x);
    return (unsigned int)x >> n;
}
int logicalShift(int x, int n)
{
    int cp = x >> n;
    int len = 32 + ~n;
    cp = cp >> len >> 1;
    cp = cp << len << 1;
    return x ^ cp;
}
int dividePower2(int x, int n)
{
    int a = x >> 31;
    return x >> n;
}
int main()
{
    // cout << hex << logicalShift(0x80000000, 1) << endl;
    cout << dividePower2(-33, 4);
    return 0;
}
