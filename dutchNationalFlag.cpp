#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a)
{
    int c0=0,c1=0,c2=0;

    for(int x:a)
    {
        if(x==0) c0++;
        else if(x==1) c1++;
        else c2++;
    }

    int i=0;

    while(c0--) a[i++]=0;
    while(c1--) a[i++]=1;
    while(c2--) a[i++]=2;
}
//2nd
void dutchFlag(vector<int> &a)
{
    int l = 0;
    int m = 0;
    int h = a.size() - 1;

    while (m <= h)
    {
        if (a[m] == 0)
        {
            swap(a[l], a[m]);
            l++;
            m++;
        }
        else if (a[m] == 1)
        {
            m++;
        }
        else
        {
            swap(a[m], a[h]);
            h--;
        }
    }
}
