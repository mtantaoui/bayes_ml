void get_diagonal(double v[], double* A, int nrows, int ncols)
{
    int i, n;

    n = (nrows < ncols) ? nrows : ncols;
    for (i = 0; i < n; A += (ncols + 1), i++)
        v[i] = *A;
}