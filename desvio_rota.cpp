#include <iostream>
#include <queue>

using namespace std;

int g[1010][1010], c[1010];
queue<int> q;  // First in, first out

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        c[i] = INT32_MAX;  // Valor máximo 32
        for (int j = 0; j <= n; j++)
            g[i][j] = INT32_MAX;
    }
}

int dijkstra(int s, int d, int n)  // Algoritmo do menor caminho
{
    c[s] = 0;
    q.push(s);  // Insere um elemento no topo da pilha
    while (!q.empty())  // Verifica se a pilha tá vazia
    {
        int i = q.front();  // Acessa o primeiro elemento do vetor c
        q.pop();  // Remove o primeiro elemento do vetor c
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] != INT32_MAX && c[j] > c[i] + g[i][j])
            {
                c[j] = c[i] + g[i][j];
                q.push(j);  // Adiciona no topo
            }
        }
    }
    return c[d];
}

int main(void){
  
    int n, m, c, k, i, u, v, p;

    while ((cin >> n >> m >> c >> k), (n || m || c || k)) {  // Leitura
        
      init(n);
        for (i = 1; i <= m; i++){
            
          cin >> u >> v >> p;
            
          if (u >= c && v >= c)  // u e v = estrada indicando interligação entre duas cidades / c = nº de cidades da rota
                g[u][v] = g[v][u] = p;
            
          if (u >= c & v < c)
                g[u][v] = p;
            
          if (u < c && v >= c)
                g[v][u] = p;
            
          if (u < c && v < c && abs(u - v) == 1)
                g[u][v] = g[v][u] = p;
        }
        cout << dijkstra(k, c - 1, n) << endl;  // Imprime
    }

    return 0;
}
