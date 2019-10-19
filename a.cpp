#include <bits/stdc++.h>

using namespace std;

/**************************************************************/

#define int long long
#define tie() ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,from,to) for(int i = from ; i <to ; i++)
#define mem(a , v) memset(a , v , sizeof a)
#define all(v) v.begin() , v.end()
#define pb push_back
#define ff first
#define ss second
#define mp make_pair


const int INF = 1e9 + 7;
const int sz = 1e5 + 20;
/***************************************************************/

void solve()
{
    int n;cin>>n;

    vector <pair <int,int> > vp;

    map <int , vector <pair <int,int> >  > m;
    f(i,0,n)
    {
        int l,r,v;
        cin>>l>>r>>v;
        if(m.find(v) == m.end())
        {
            vp.clear();
            vp.push_back(make_pair(l , r));
            m.insert(make_pair(v , vp));
        }
        else
            m[v].push_back(make_pair(l , r));
    }


    bool cond = true;
    map <int , vector <pair <int,int> > > :: iterator it;
    for(it = m.begin() ; it != m.end() ; ++it)
    {
        vector <pair <int,int> > x = (*it).ss;
        int n = x.size() , s = 0 , mn = INT_MAX , mx = INT_MIN;

        sort(all(x));
        if(n > 2)
        {
            f(i,0,n-2)
            {
                if(x[i+1].ff <= x[i].ss && x[i+2].ff <= x[i].ss)
                {
                    cond = false;
                    break;
                }
            }
        }
    }

    if(cond)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return;
}

int32_t main()
{
    clock_t st = clock();
    tie();
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    //clog<<(long double)((clock() - st)/CLOCKS_PER_SEC)<<endl;
    return 0;
}



/*



6
6
1 10 2
5 15 2
11 20 2
16 20 2
25 60 2
30 60 2


*/
