#include <stdio.h>
#include <time.h>

#define SIZE 2000
#define ITERATIONS 500

int matrix[SIZE][SIZE];

int main()
{
    // 1. WARMUP: Isi matriks & picu Page Fault OS sebelum mencatat waktu
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = 1;
        }
    }

    clock_t start, end;

    // 2. Akses Baris (Row-Major) - Stride 1 (Ramah Cache)
    start = clock();
    long long sum_row = 0;
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                sum_row += matrix[i][j];
            }
        }
    }
    end = clock();
    double time_row = (double)(end - start) / CLOCKS_PER_SEC;

    // 3. Akses Kolom (Column-Major) - Stride N (Tidak Ramah Cache)
    start = clock();
    long long sum_col = 0;
    for (int iter = 0; iter < ITERATIONS; iter++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                sum_col += matrix[i][j];
            }
        }
    }
    end = clock();
    double time_col = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Akses Baris (Row-Major)   : %.4f detik (Sum: %lld)\n", time_row, sum_row);
    printf("Akses Kolom (Column-Major): %.4f detik (Sum: %lld)\n", time_col, sum_col);

    return 0;
}