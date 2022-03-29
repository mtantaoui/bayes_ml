void add_matrices(double** C, double** A, double** B, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            C[i][j] = A[i][j] + B[i][j];
}