#include "header.h"
void main()
{
    int g = 1;
    int *u = &g;
    printf(BOLDRED "\tWELCOME TO WORDLE GAME!\n" RESET BOLDGREEN "Remember to give your inputs in Small letters only!\n" RESET);
    int a, i = 0, j, r = 1, t = 0, x;
    char d[6], s[6];
    char *p;
    p = calloc(g, sizeof(char));
    srand(getpid());
    a = rand() % 5756 + 1;

    FILE *fp = fopen("words.txt", "r");
    if (fp == 0)
    {
        printf("Error in opening file!\n");
        return;
    }
    while (fgets(d, 6, fp) != NULL)
    {
        if (a == i++ / 2)
            break;
    }
    // printf("-----------%s--------------\n", d); {uncomment this to see word so that debugging is possible!}
    printf("Give your input guess:");
    fgets(s, 6, stdin);
    sleep;
    while (t < 6)
    {
        if (t != 0)
        {
            fflush(stdin);
            printf(RED "Wrong Answer! " RESET);
            printf("Tries Left = %d\n", (5 - t) + 1);
            printf("Unusable Words:" RED "[ ");
            for (x = 0; x < *u; x++)
            {
                printf("%c ", p[x]);
            }
            printf("]\n" RESET);
            printf("Enter Guess:");
            getchar();
            fgets(s, 6, stdin);
        }
        // printf("s=%s d=%s\n", s, d);
        r = comp(s, d, p, u);
        if (r == 0)
        {
            free(p);
            printf(BOLDGREEN "\nGame Won!\n" RESET);
            printf(BOLDYELLOW "Our Word was: %d) %s\n" RESET, a + 1, d);
            break;
        }
        t++;
    }
    if (r != 0)
    {
        free(p);
        printf(BOLDRED "You Lose hehe\n" RESET);
        printf(BOLDYELLOW "Our Word was: %d) %s\n" RESET, a + 1, d);
        return;
    }
}
int comp(char *s, char *l, char *p, int *u)
{
    int r = 0, i = 0, j = 0, k = 0, y = 0, b = 0, f = 0, w = 0, m = 5, n = 5, z = 0, index;
    char *e, d[6];
    strcpy(d, l);
    // printf("s=%s d=%s\n", s, d);
    if (strcmp(d, s) == 0)
    {
        for (i = 0; i < 5; i++)
        {
            green(s[i]);
        }
        return r;
    }
    char x[6];
    for (i = 0, z = 0; i < 5; i++)
    {
        if (s[i] != d[i])
        {
            x[z] = d[i];
            z++;
        }
    }
    x[z] = '\0';
    for (w = 0, k = 0, i = 0; i < m; i++)
    {
        for (w = 0, k = 0, j = 0; j < n; j++)
        {
            if (s[i] == d[j])
            {
                if (i == j)
                {
                    green(s[i]);
                    rem(s, i);
                    rem(d, j);
                    n--;
                    m--;
                    i--;
                    j--;
                    k = 1;
                    break;
                }
                else
                {
                    for (k = i; k < 5; k++)
                    {
                        if (s[k] == d[k])
                        {
                            if (s[k] == s[i] && i == k)
                            {
                                green(s[i]);
                                rem(s, i);
                                rem(d, j);
                                n--;
                                m--;
                                i--;
                                j--;
                                k = 1;
                                w = 1;
                            }
                        }
                    }
                    if (w == 0)
                        if (w == 0)
                        {
                            if (strchr(x, s[i]) != NULL)
                            {
                                e = strchr(x, s[i]);
                                index = (int)(e - x);
                                yellow(s[i]);
                                rem(x, index);
                                k = 1;
                                break;
                            }
                            else
                            {
                                red(s[i]);
                                for (y = 0; y < *u; y++)
                                {
                                    if (s[i] == p[y])
                                    {
                                        b = 1;
                                        break;
                                    }
                                }
                                if (b == 0)
                                {
                                    p = realloc(p, *u + 1);
                                    p[*u] = s[i];
                                    (*u)++;
                                }
                                k = 1;
                                break;
                            }
                        }
                }
            }
        }
        if (k == 0)
        {
            red(s[i]);
            for (y = 0; y < *u; y++)
            {
                if (s[i] == p[y])
                {
                    b = 1;
                    break;
                }
            }
            if (b == 0)
            {
                p = realloc(p, *u + 1);
                p[*u] = s[i];
                (*u)++;
            }
        }
    }
    printf("\n");
    r = strcmp(d, s);
    return r;
}
void rem(char *s, int n)
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        if (i == n)
        {
            for (j = n; j < 4; j++)
            {
                s[j] = s[j + 1];
            }
            s[j] = '\0';
            break;
        }
    }
}
void red(char c)
{
    printf(RED "%c " RESET, c);
    sleep;
    return;
}
void green(char c)
{
    printf(GREEN "%c " RESET, c);
    sleep;
    return;
}
void yellow(char c)
{
    printf(YELLOW "%c " RESET, c);
    sleep;
    return;
}
