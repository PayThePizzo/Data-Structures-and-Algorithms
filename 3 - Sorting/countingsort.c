#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

//fuck you
int max(int a, int b)
{
    if (min(a, b) == a)
        return b;
    return a;
}

void printarray(int *a, int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void countingsort(int *vector, int *result, int dim)
{
    int locmin, locmax, i, countlen;
    int *count;

    locmin = locmax = *vector;

    for (i = 0; i < dim; i++)
    {
        int e = vector[i];
        locmin = min(locmin, e);
        locmax = max(locmax, e);
    }

    countlen = locmax + 1;
    count = malloc(sizeof(int) * countlen);

    for (i = 0; i < countlen; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < dim; i++)
    {
        count[vector[i]]++;
    }

    for (i = 1; i < countlen; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = dim - 1; i >= 0; i--)
    {
        result[count[vector[i]]] = vector[i];
        count[vector[i]]--;
    }
}

int sorted(int *v, int dim)
{
    int s = 1, i = 1;
    for (; i < dim && s; i++)
    {
        s = s && (v[i - 1] <= v[i]);
    }

    return s;
}

void populatearray(int *a, int dim)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < dim; i++)
    {
        int n = rand();
        a[i] = n % 1024;
    }
}

int main()
{
    int *v, length, *result;
    length = 20;

    //initialization
    v = malloc(sizeof(int) * length);
    result = malloc(sizeof(int) * length);

    //spreading population
    populatearray(v, length);
    printarray(v, length);

    //sorting
    countingsort(v, result, length);
    if (!sorted(result, length))
        printf("NOT ");
    printf("SORTED\nARRAY:");
    printarray(result, length);

    return 0;
}
