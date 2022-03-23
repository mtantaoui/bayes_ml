void transpose_square_matrix(double* A, int n)
{
    double *pA, *pAt;
    double temp;
    int i, j;

    for (i = 0; i < n; A += n + 1, i++) {
        pA = A + 1;
        pAt = A + n;
        for (j = i + 1; j < n; pA++, pAt += n, j++) {
            temp = *pAt;
            *pAt = *pA;
            *pA = temp;
        }
    }
}