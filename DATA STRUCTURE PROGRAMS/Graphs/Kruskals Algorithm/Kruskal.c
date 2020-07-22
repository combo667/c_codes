#include <stdio.h>
#define I 32767

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

int edges[3][9] = {

    {1, 1, 2, 2, 3, 7, 7, 6, 5},
    {2, 6, 3, 7, 4, 5, 4, 5, 4},
    {25, 5, 12, 10, 8, 18, 14, 20, 16}

};

int included[9] = {0};

void Union(int u, int v)
{
    if (set[u] < set[v])
    {

        set[u] = set[u] + set[v];
        set[v] = u;
    }
    else
    {
        set[v] = set[v] + set[u];
        set[u] = v;
    }
}

int find(int u)
{
    int x = u;

    while (set[x] > 0)
    {
        x = set[x];
    }

    return x;
}

int KruskalsAlgo()
{
    int n = 7, e = 9;
    int min = 0;
    int i = 0, j, k = 0, u = 0, v = 0;
    int t[2][n - 1];

    while (i < n - 1)
    {
        min = I;

        for (j = 0; j < e; ++j)
        {
            if (included[j] != 1)
            {
                if (edges[2][j] < min)
                {
                    min = edges[2][j];
                    k = j;
                    u = edges[0][k], v = edges[1][k];
                }
            }
        }

        if (find(u) != find(v))
        {
            t[0][i] = u, t[1][i] = v;
            Union(find(u), find(v));
            ++i;
        }
        included[k] = 1;
    }

    for (u = 0; u < n - 1; ++u)
    {
        printf("(%d,%d)\n", t[0][u], t[1][u]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    printf("Here is the result of Kruskals ALgorithm!\n");
    KruskalsAlgo();
    printf("\n");
    return 0;
}
