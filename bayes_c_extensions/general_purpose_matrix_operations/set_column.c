void set_column(double *A, double v[], int col, int nrows, int ncols)
{
   int i;

   for (A += col, i = 0; i < nrows; A += ncols, i++) *A = v[i];
}