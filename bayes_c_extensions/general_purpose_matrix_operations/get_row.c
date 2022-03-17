void get_row(double v[], double *A, int row, int ncols)
{
    int i;

    for (A += row * ncols, i = 0; i < ncols; i++)
        v[i] = *(A++);
}