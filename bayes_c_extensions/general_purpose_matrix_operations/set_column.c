void set_column(double **A, double v[], int col, int nrows) {
  int i;
  for (i = 0; i < nrows; i++)
    A[i][col] = v[i];
}