#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    int s;
    int m;
} Root;

int compare_ints(const void *a, const void *b) 
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

int compare_roots(const void *a, const void *b) 
{
    Root *ra = (Root*)a;
    Root *rb = (Root*)b;
    return ra->s - rb->s;
}

void generate_possible_roots(int c, int **possible, int *count) 
{
    int d = abs(c);
    int divisors[1000];
    int div_count = 0;

    for (int i = 1; i <= (int)sqrt(d); ++i) 
    {
        if (d % i == 0) 
        {
            divisors[div_count++] = i;
            if (i != d / i) 
            {
                divisors[div_count++] = d / i;
            }
        }
    }

    *possible = malloc(2 * div_count * sizeof(int));
    int pos_count = 0;
    for (int i = 0; i < div_count; ++i) 
    {
        (*possible)[pos_count++] = divisors[i];
        (*possible)[pos_count++] = -divisors[i];
    }

    qsort(*possible, pos_count, sizeof(int), compare_ints);

    int new_count = 0;
    for (int i = 0; i < pos_count; ++i) 
    {
        if (i == 0 || (*possible)[i] != (*possible)[i - 1]) 
        {
            (*possible)[new_count++] = (*possible)[i];
        }
    }
    *count = new_count;
}

int compute_multiplicity(int s, int a, int b, int c) 
{
    long long val = (long long)s*s*s + (long long)a*s*s + (long long)b*s + c;
    if (val != 0) return 0;

    int multiplicity = 1;
    int new_a2 = a + s;
    int new_b1 = b + s * new_a2;
    long long val_quad = (long long)s*s + (long long)new_a2*s + new_b1;
    if (val_quad == 0) 
    {
        multiplicity++;
        if (a + 3 * s == 0) 
        {
            multiplicity++;
        }
    }
    return multiplicity;
}

void generate_polynomial(int s, int m, int **coeffs, int *degree) 
{
    *degree = m;
    *coeffs = malloc((m + 1) * sizeof(int));
    switch (m) 
    {
        case 1:
            (*coeffs)[0] = 1;
            (*coeffs)[1] = -s;
            break;
        case 2:
            (*coeffs)[0] = 1;
            (*coeffs)[1] = -2 * s;
            (*coeffs)[2] = s * s;
            break;
        case 3:
            (*coeffs)[0] = 1;
            (*coeffs)[1] = -3 * s;
            (*coeffs)[2] = 3 * s * s;
            (*coeffs)[3] = -s * s * s;
            break;
        default:
            break;
    }
}

void multiply_poly(int *p1, int d1, int *p2, int d2, int **result, int *dr) 
{
    *dr = d1 + d2;
    *result = calloc((*dr + 1), sizeof(int));

    for (int i = 0; i <= d1; ++i) 
    {
        for (int j = 0; j <= d2; ++j) 
        {
            (*result)[i + j] += p1[i] * p2[j];
        }
    }
}

int main() 
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int *possible_roots;
    int num_possible;
    generate_possible_roots(c, &possible_roots, &num_possible);

    Root *roots = malloc(num_possible * sizeof(Root));
    int root_count = 0;

    for (int i = 0; i < num_possible; ++i) 
    {
        int s = possible_roots[i];
        int m = compute_multiplicity(s, a, b, c);
        if (m > 0) 
        {
            roots[root_count].s = s;
            roots[root_count].m = m;
            root_count++;
        }
    }

    free(possible_roots);

    int sum_m = 0;
    for (int i = 0; i < root_count; ++i) 
    {
        sum_m += roots[i].m;
    }

    if (sum_m != 3) 
    {
        printf("NO SOLUTION\n");
        free(roots);
        return 0;
    }

    int *product_coeffs = malloc(sizeof(int));
    product_coeffs[0] = 1;
    int product_degree = 0;

    for (int i = 0; i < root_count; ++i) 
    {
        int s = roots[i].s;
        int m = roots[i].m;

        int *poly_coeffs;
        int poly_degree;
        generate_polynomial(s, m, &poly_coeffs, &poly_degree);

        int *new_product;
        int new_degree;
        multiply_poly(product_coeffs, product_degree, poly_coeffs, poly_degree, &new_product, &new_degree);

        free(product_coeffs);
        free(poly_coeffs);

        product_coeffs = new_product;
        product_degree = new_degree;
    }

    int match = 1;
    if (product_degree != 3) 
    {
        match = 0;
    } 
    else 
    {
        int original_coeffs[] = {c, b, a, 1};
        for (int i = 0; i < 4; ++i) 
        {
            if (product_coeffs[i] != original_coeffs[i]) 
            {
                match = 0;
                break;
            }
        }
    }

    if (match) 
    {
        qsort(roots, root_count, sizeof(Root), compare_roots);
        for (int i = 0; i < root_count; ++i) 
        {
            printf("%d %d\n", roots[i].s, roots[i].m);
        }
    } 
    else 
    {
        printf("NO SOLUTION\n");
    }

    free(product_coeffs);
    free(roots);

    return 0;
}
