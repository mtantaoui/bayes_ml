# include "numpy/arrayobject.h"

extern void free_Carrayptrs(double **v);
extern int not_doublematrix(PyArrayObject *mat);
extern double **ptrvector(long n);
extern double *pyvector_to_Carrayptrs(PyArrayObject *arrayin);
extern double **pymatrix_to_Carrayptrs(PyArrayObject *arrayin);