void set_row(double *A, double v[], int row, int ncols)
{
   A += row * ncols;
   for (; ncols > 0; ncols--) *A++ = *v++;
}