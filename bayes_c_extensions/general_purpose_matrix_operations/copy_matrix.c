#include <stdio.h>

void copy_matrix(double **in, double **out, int nrows, int ncols)
{
  // printf("------  entering copy_matrix function     ------\n");
  for (int row = 0; row < nrows; row++)
  {
    for (int col = 0; col < ncols; col++)
    {
      out[row][col] = in[row][col];
      //  printf("%.2f\t", out[row][col]);
    }
    // printf("\n");
  }
  // printf("------  leaving copy_matrix function     ------\n");
}
