void set_diagonal(double** A, double v[], int nrows, int ncols)
{
    int n;

    if (nrows < ncols)
        n = nrows;
    else
        n = ncols;

    for (int i = 0; i < n; i++)
        A[i][i] = v[i];
}