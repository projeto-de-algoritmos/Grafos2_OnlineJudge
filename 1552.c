#include <stdio.h>
#include <math.h>
#include <limits.h>

#define N 505

typedef struct s_ponto
{
    double x, y;
} ponto;

ponto pontos[N];
int vizinho[N];
double no[N];
int mstSet[N];

double grafo[N][N];

double distancia(ponto p1, ponto p2)
{
    double d1 = (p1.x - p2.x), d2 = (p1.y - p2.y);
    return sqrt(d1 * d1 + d2 * d2);
}

double minno(int n)
{
    double min;
    int i, minIndex;

    for (i = 0, min = LONG_MAX; i < n; i++)
    {
        if (!mstSet[i] && no[i] < min)
            min = no[i], minIndex = i;
    }
    return minIndex;
}

double prim(int n)
{
    int i, c, u, v;
    double sum;

    for (i = 0; i < n; i++)
        no[i] = LONG_MAX, mstSet[i] = 0;

    no[0] = 0, vizinho[0] = -1;

    for (c = 0; c < n - 1; c++)
    {
        u = minno(n);
        mstSet[u] = 1;

        for (v = 0; v < n; v++)
            if (!mstSet[v] && grafo[u][v] < no[v])
                vizinho[v] = u, no[v] = grafo[u][v];
    }

    for (i = 0, sum = 0; i < n; i++)
        sum += grafo[i][vizinho[i]];

    return sum;
}

int main(void)
{

    int c, n, i, j;

    scanf("%d", &c);

    while (c--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%lf %lf", &pontos[i].x, &pontos[i].y);

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                grafo[i][j] = (i == j ? LONG_MAX : distancia(pontos[i], pontos[j]));

        printf("%.2lf\n", prim(n) / 100);
    }

    return 0;
}