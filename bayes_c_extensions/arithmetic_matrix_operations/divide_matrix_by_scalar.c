void divide_matrix_by_scalar(double** matrix_in, double** matrix_out, double scalar, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            matrix_out[i][j] = matrix_in[i][j] / scalar;
        }
    }
}