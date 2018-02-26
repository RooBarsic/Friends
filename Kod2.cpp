#include <iostream>
using namespace std;
int main ()
{
    long long p, n, i, j, s = 0, t, r, h;
    cin>>p>>n;
    t = n;
    for(t = n; t >=2; t --)
    {
        s = 0;
        for(i = 2; i <= p; i++)
        {
            r = n/i;
            for(j = 1; j <= r; j ++)
            {
                h = i * j;
                if(h == t)
                    s++;
            }
        }
        if(s == 0)
        {
            cout<<t;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
