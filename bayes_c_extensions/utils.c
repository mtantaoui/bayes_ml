#include "numpy/arrayobject.h"

void free_Carrayptrs(double** v)
{
    free((char*)v);
}

int not_doublevector(PyArrayObject* vec)
{
    if (vec->descr->type_num != NPY_DOUBLE || vec->nd != 1) {
        PyErr_SetString(PyExc_ValueError, "In not_doublevector: array must be of "
                                          "type Float and 1 dimensional (n).");
        return 1;
    }
    return 0;
}

int not_doublematrix(PyArrayObject* mat)
{

    if (mat->descr->type_num != NPY_DOUBLE || mat->nd != 2) {
        PyErr_SetString(PyExc_ValueError, "In not_doublematrix: array must be of "
                                          "type Float and 2 dimensional (n x m).");
        return 1;
    }

    return 0;
}

double** ptrvector(long n)
{
    double** v;
    v = (double**)malloc((size_t)(n * sizeof(double)));
    if (!v) {
        printf("In **ptrvector. Allocation of memory for double array failed.");
        exit(0);
    }

    return v;
}

double* pyvector_to_Carrayptrs(PyArrayObject* arrayin)
{
    return (double*)arrayin->data; /* pointer to arrayin data as double */
}

double** pymatrix_to_Carrayptrs(PyArrayObject* arrayin)
{
    double **c, *a;
    int i;
    npy_intp n, m;

    n = arrayin->dimensions[0];
    m = arrayin->dimensions[1];
    c = ptrvector(n);
    a = (double*)arrayin->data; /* pointer to arrayin data as double */
    for (i = 0; i < n; i++) {
        c[i] = a + i * m;
    }

    return c;
}