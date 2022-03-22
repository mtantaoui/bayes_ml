#include <stdio.h>

void copy_matrix(double** in, double** out, int nrows, int ncols)
{
    for (int row = 0; row < nrows; row++) {
        for (int col = 0; col < ncols; col++) {
            out[row][col] = in[row][col];
        }
    }
}
