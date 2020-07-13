#include <stdio.h>
#include <limits.h>
#define I 32767

void PrimAlgorithm(int[8][8]);
void printArray(int[2][6], int);

int main(int argc, char const *argv[])
{
    int cost[8][8] = {

        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 15, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}

    };

    PrimAlgorithm(cost);

    return 0;
}

void PrimAlgorithm(int cost[8][8])
{
    int n = 7;

    int near[8] = {I, I, I, I, I, I, I, I};

    int t[2][6];
    int i, j, k, u, v, min = I;

    for (i = 1; i <= n; ++i)
    {
        for (j = i; j <= n; ++j)
        {
            if (cost[i][j]<min)
            {
                min = cost[i][j];
                u = i, v = j;
            }
        }
    }

    near[u] = near[v] = 0;
    t[0][0] = u;
    t[1][0] = v;

    for (i = 1; i <= n; ++i)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
            {
                near[i] = u;
            }
            else
                near[i] = v;
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

        t[0][i] = k, t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; ++j)
        {
            if (near[j] != 0)
            {
                if (cost[j][k] < cost[j][near[j]])
                    near[j] = k;
            }
        }
    }

    printArray(t, n);
}

void printArray(int Array[2][6], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("(%d,%d), ", Array[0][i], Array[1][i]);
    }
    printf("\n");
}
