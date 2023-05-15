#include <stdio.h>
#include <stdlib.h>

struct s_borda {
    
    int v, w;  // par de roteadores conectados
    int p;  // preço do cabo
} typedef borda;

borda g[205];
int p[65];

int compara(const void *a, const void *b) {
    
    return ((borda *)a)->p - ((borda *)b)->p;
}

int parent(int I) {
    
    if (I == p[I])
        return I;
    return parent(p[I]);
}

int kruskal(int C) {
    
    int I, custo, v, w;

    for (I = 0, custo = 0; I < C; I++) {
        
        v = parent(g[I].v);
        w = parent(g[I].w);

        if (v != w) {
            
            p[v] = p[w];
            custo += g[I].p;
        }
    }
    return custo;
}


int main(void) {

    int R, C; // R = quantidade de roteadores / C = quantidade de cabos
    int I;  // 

    scanf("%d %d", &R, &C);

    for (I = 0; I < C; I++) {
        
        scanf("%d %d %d", &g[I].v, &g[I].w, &g[I].p);
    }

    qsort(g, C, sizeof(borda), compara);  // ordena as entradas
    for (I = 1; I <= R; I++)
        p[I] = I;

    printf("%d\n", kruskal(C));

    return 0;
}