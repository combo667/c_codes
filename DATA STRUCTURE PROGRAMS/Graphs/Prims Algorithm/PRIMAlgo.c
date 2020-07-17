#include <stdio.h>
#define I 32767

int main(int argc, char const *argv[])
{
    int n = 7, i, j, u, v, min = I, k;

    int cost[8][8] = {{I, I, I, I, I, I, I, I},
                      {I, I, 25, I, I, I, 5, I},
                      {I, 25, I, 12, I, I, I, 10},
                      {I, I, 12, I, 8, I, I, I},
                      {I, I, I, 8, I, 16, I, 14},
                      {I, I, I, I, 16, I, 20, 18},
                      {I, 5, I, I, I, 20, I, I},
                      {I, I, 10, I, 14, 18, I, I}

    };

    int near[8] = {I, I, I, I, I, I, I, I};
    int t[2][6];

    for (i = 1; i <= n; ++i)
    {
        for (j = i; j <= n; ++j)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i, v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for (i = 1; i <= n; ++i)
    {
        if (near[i] != 0)
        {
            if (cost[i][t[0][0]] < cost[i][t[1][0]])
                near[i] = t[0][0];
            else
                near[i] = t[1][0];
        }
    }

    for (i = 1; i < n - 1; ++i)
    {
        min = I;
        for (j = 1; j <= n; ++j)
        {
            if (near[j] != 0)
            {
                if (cost[j][near[j]] < min)
                {
                    min = cost[j][near[j]];
                    k = j;
                }
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; ++j)
        {
            if (near[j] != 0)
            {
                if (cost[j][k] < cost[j][near[j]])
                {
                    near[j] = k;
                }
            }
        }
    }

    for (i = 0; i < n - 1; ++i)
    {
        printf("(%d,%d)\n", t[0][i], t[1][i]);
    }
    printf("\n");

    return 0;
}

/*
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 15, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}

*/