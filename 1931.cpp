#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define INF 9999999

class Grafo
{
public:
    int v;
    list<pair<int, int>> *a;

    Grafo(int v)
    {
        this->v = v;
        a = new list<pair<int, int>>[v];
    }

    void addNo(int c1, int c2, int g)
    {
        a[c1].push_back(make_pair(c2, g));
    }

    int dijkstra(int s, int t)
    {
        vector<int> d, vi;
        d.assign(v, INF), vi.assign(v, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        d[s] = 0;

        pq.push(make_pair(d[s], s));

        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            int u = p.second;
            pq.pop();

            if (!vi[u])
            {
                vi[u] = 1;
                for (list<pair<int, int>>::iterator it = a[u].begin(); it != a[u].end(); it++)
                {
                    int c1 = it->first, g = it->second;

                    if (d[c1] > d[u] + g)
                    {
                        d[c1] = d[u] + g;
                        pq.push(make_pair(d[c1], c1));
                    }
                }
            }
        }

        return d[t];
    }
};

int main(void)
{
    int c, v, c1, c2, g;

    cin >> c >> v;

    Grafo g1(c), g2(c);

    for (int i = 0; i < v; i++)
    {
        cin >> c1 >> c2 >> g;
        g1.addNo(--c1, --c2, g);
        g1.addNo(c2, c1, g);
    }

    for (int i = 0; i < c; i++)
    {
        for (list<pair<int, int>>::iterator it1 = g1.a[i].begin(); it1 != g1.a[i].end(); it1++)
        {
            c1 = it1->first, g = it1->second;

            if (g1.a[c1].size())
            {
                for (list<pair<int, int>>::iterator it2 = g1.a[c1].begin(); it2 != g1.a[c1].end(); it2++)
                {
                    if (i != it2->first)
                        g2.addNo(i, it2->first, g + it2->second);
                }
            }
        }
    }

    int m = g2.dijkstra(0, c - 1);

    cout << (m == INF ? -1 : m) << endl;

    return 0;
}