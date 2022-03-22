void get_column(double v[], double *A, int col, int nrows, int ncols) {
  int i;

  for (A += col, i = 0; i < nrows; A += ncols, i++)
    v[i] = *A;
}
