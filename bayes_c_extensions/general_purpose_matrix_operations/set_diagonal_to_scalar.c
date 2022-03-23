void set_diagonal_to_scalar(double** A, double x, int nrows, int ncols)
{
    int n = (nrows < ncols) ? nrows : ncols;

    for (int i = 0; i < n; i++)
        A[i][i] = x;
}