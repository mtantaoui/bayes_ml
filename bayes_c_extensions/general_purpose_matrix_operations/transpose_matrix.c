void transpose_matrix(double* At, double* A, int nrows, int ncols)
{
    double* pA;
    double* pAt;
    int i, j;

    for (i = 0; i < nrows; At += 1, A += ncols, i++) {
        pAt = At;
        pA = A;
        for (j = 0; j < ncols; pAt += nrows, j++)
            *pAt = pA[j];
    }
}