#include <bits/stdc++.h>

using namespace std;

#define int long long
#define f(i,from,to) for(int i = from ; i < to ; i++)
#define all(v) v.begin(),v.end()
#define test int t;cin>>t;while(t--)
#define ff first
#define ss second

int32_t main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    test
    {
        int n,v,s = 0;cin>>n;

        map < int , pair <int,int>  > m;

        int a[n+1];

        a[0] = 0;

        for(int i = 1 ; i <= n ; i++)
        {
            cin>>v;
            a[i] = a[i-1] ^ v;
        }

        for(int i = 0; i <= n ; i++)
        {
            int x = a[i];
            if(m.find(x) == m.end())
            {
                pair <int,int> p= make_pair(i,1);
                m.insert(make_pair(x,p));
            }

            else
            {
                s+=(m[x].ss * (i-1)) - (m[x].ff);
                m[x].ff = m[x].ff + i;
                m[x].ss++;
            }
        }

        cout<<s<<endl;
    }

    return 0;
}
