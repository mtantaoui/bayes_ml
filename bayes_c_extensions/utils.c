#include "numpy/arrayobject.h"

void free_Carrayptrs(double** v)
{
    // printf("------  entering free_Carrayptrs function     ------\n");
    free((char*)v);
    // printf("------  leaving free_Carrayptrs function     ------\n");
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
    // printf("------  entering not_doublematrix function     ------\n");

    if (mat->descr->type_num != NPY_DOUBLE || mat->nd != 2) {
        PyErr_SetString(PyExc_ValueError, "In not_doublematrix: array must be of "
                                          "type Float and 2 dimensional (n x m).");
        // printf("------  leaving not_doublematrix function with error ------\n");
        return 1;
    }
    // printf("------  leaving not_doublematrix function     ------\n");

    return 0;
}

double** ptrvector(long n)
{
    double** v;
    v = (double**)malloc((size_t)(n * sizeof(double)));
    // printf("------  entering ptrvector function     ------\n");
    if (!v) {
        printf("In **ptrvector. Allocation of memory for double array failed.");
        exit(0);
    }
    // printf("------  leaving ptrvector function     ------\n");

    return v;
}

double* pyvector_to_Carrayptrs(PyArrayObject* arrayin)
{
    // int n;
    // double *vector;

    // n = arrayin->dimensions[0];
    return (double*)arrayin->data; /* pointer to arrayin data as double */
}

double** pymatrix_to_Carrayptrs(PyArrayObject* arrayin)
{
    double **c, *a;
    int i;
    npy_intp n, m;

    // printf("------  entering pymatrix_to_Carrayptrs function     ------\n");

    n = arrayin->dimensions[0];
    m = arrayin->dimensions[1];
    c = ptrvector(n);
    a = (double*)arrayin->data; /* pointer to arrayin data as double */
    for (i = 0; i < n; i++) {
        c[i] = a + i * m;
    }

    // printf("------  leaving pymatrix_to_Carrayptrs function     ------\n");

    return c;
}