#include <stdio.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long int ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vector<vii> a;

int main(void)
{
    int N, Q, ai, s, t, t1;
    ll li;

    while (scanf("%d", &N) && N)
    {
        a.assign(N, vii());

        for (int i = 1; i < N; i++)
        {
            scanf("%d %lld", &ai, &li);
            a[i].push_back(ii(ai, li));
            a[ai].push_back(ii(i, li));
        }

        queue<ii> q;
        vector<int> p;
        vector<ll> d;

        p.assign(N, -1);
        d.assign(N, -1);
        q.push(ii(0, 0));
        p[0] = -1;
        d[0] = 0;

        while (!q.empty())
        {
            ii u = q.front();
            q.pop();

            for (int i = 0; i < a[u.first].size(); i++)
            {
                ii v = a[u.first][i];
                if (d[v.first] < 0)
                {
                    d[v.first] = d[u.first] + v.second;
                    p[v.first] = u.first;
                    q.push(v);
                }
            }
        }

        scanf("%d", &Q);

        while (Q--)
        {
            scanf("%d %d", &s, &t);
            t1 = 0;
            set<int> m;
            for (int i = s; i >= 0; i = p[i])
                m.insert(i);

            for (int i = t; i >= 0; i = p[i])
            {
                if (m.count(i))
                {
                    t1 = i;
                    break;
                }
            }

            ll ans = d[s] + d[t] - 2 * d[t1];
            printf("%lld%c", ans, Q ? ' ' : '\n');
        }
    }

    return 0;
}