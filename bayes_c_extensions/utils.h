# include "numpy/arrayobject.h"

extern void free_Carrayptrs(double **v);
extern int not_doublematrix(PyArrayObject *mat);
double **ptrvector(long n);
extern double **pymatrix_to_Carrayptrs(PyArrayObject *arrayin);