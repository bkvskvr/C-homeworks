#include <stdio.h>

#define MAXN 100

int read_size(const char *prompt, int limit) {
    int v;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &v) == 1 && v >= 1 && v < limit) return v;
        printf("Error: enter an integer from 1 to %d\n", limit - 1);
        while (getchar() != '\n');
    }
}

int main(void) {
    static double a[MAXN][MAXN];
    int n = read_size("n (<100): ", MAXN);
    int m = read_size("m (<100): ", MAXN);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    int lim = n < m ? n : m;
    for (int i = 0; i < lim; i++) {
        int best = i;
        for (int j = i + 1; j < m; j++)
            if (a[i][j] > a[i][best]) best = j;
        if (best != i)
            for (int r = 0; r < n; r++) {
                double t = a[r][i]; a[r][i] = a[r][best]; a[r][best] = t;
            }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%9.3f", a[i][j]);
        printf("\n");
    }
    return 0;
}