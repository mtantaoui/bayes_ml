void add_matrices(double *C, double *A, double *B, int nrows, int ncols) 
{
   register int i;
   register int n = nrows * ncols;

   for (i = 0; i < n; i++) C[i] = A[i] + B[i];
}