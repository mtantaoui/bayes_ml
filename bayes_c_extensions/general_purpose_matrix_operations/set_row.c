void set_row(double **A, double v[], int row, int ncols) {
  int j;
  for (j = 0; j < ncols; j++)
    A[row][j] = v[j];
}