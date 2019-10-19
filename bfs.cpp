
#include <bits/stdc++.h>

using namespace std;


/********************************************/
#define tie() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,from,to) for(int i=from;i<to;++i)
#define rev(i,to,from) for(int i=to;i>from;--i)
#define mem(arr,val) memset(arr , val , sizeof arr)
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

typedef long long int ll;
const int sz = 5e4 + 30;
const int INF = 1e9 + 1;
/******************************************/

vector <vector <int> > g;
vector <bool> vis;
vector <int> level , tmp;


void bfs(int x)
{
    vis[x] = true;
    level[x] = 0;
    queue <int> q;
    q.push(x);
    tmp.pb(x);
    while(!q.empty())
    {
        int p = q.front();
        for(auto node : g[p])
        {
            if(!vis[node])
            {
                vis[node] = true;
                q.push(node);
                tmp.pb(node);
                level[node] = level[p]+1;
            }
        }
        q.pop();
    }
}

map <int,int> m;

bool mycomp(int a , int b)
{
    return m[a] < m[b];
}

void solve()
{
    int n,u,v,root = 0;cin>>n;

    g.clear();
    g.resize(n);

    vis.resize(n,false);
    level.resize(n,false);


    f(i,0,n-1)
    {
        cin>>u>>v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs(root);

    vector <int> res(n);

    f(i,0,n)
    {
        cin>>u;
        u--;
        res[i] = u;
        m.insert(mp(u,i));
    }

    int maxi = INT_MIN;
    bool cond = true;
    f(i,0,n)
    {
        if(level[res[i]] >= maxi)
            maxi = level[res[i]];
        else
        {
            cond = false;
            break;
        }
    }

    if(cond)
    {
        f(i,0,n)
        {
            sort(all(g[i]) , mycomp);
        }
        tmp.clear();
        vis.clear();
        vis.resize(n,false);
        bfs(0);
        f(i,0,n)
        {
            if(res[i] != tmp[i])
            {
                cond = false;
                break;
            }
        }
    }



    if(cond)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return;
}


int main()
{
    tie();
    int T=1;
    while(T--)
    solve();
    return 0;
}
