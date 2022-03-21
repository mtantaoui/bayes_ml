extern void copy_matrix(double **in, double **out, int nrows, int ncols);
extern void get_row(double v[], double *A, int row, int ncols);
extern void get_column(double v[], double *A, int col, int nrows, int ncols);
extern void set_row(double **A, double v[], int row, int ncols);
extern void set_column(double **A, double v[], int col, int nrows);
