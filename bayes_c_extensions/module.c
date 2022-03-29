// #define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "Python.h"
#include "arithmetic_matrix_operations/arithmetic_operations_pyfunctions.h"
#include "general_purpose_matrix_operations/general_purpose_pyfunctions.h"
#include "numpy/arrayobject.h"
#include <stdint.h>

/* Module method table */
static PyMethodDef BayesMethods[] = {
    { "copy_matrix", py_copy_matrix, METH_VARARGS, "Copy a Matrix" },
    { "get_row", py_get_row, METH_VARARGS, "Get a matrix row" },
    { "get_column", py_get_column, METH_VARARGS, "Get a matrix column" },
    { "set_row", py_set_row, METH_VARARGS, "Set a matrix row" },
    { "set_column", py_set_column, METH_VARARGS, "Set a matrix column" },
    { "get_diagonal", py_get_diagonal, METH_VARARGS, "Get a matrix diagonal" },
    { "set_diagonal", py_set_diagonal, METH_VARARGS, "Set a matrix diagonal" },
    { "set_diagonal_to_scalar", py_set_diagonal_to_scalar, METH_VARARGS, "Set a matrix diagonal to scalar" },
    { "transpose_matrix", py_transpose_matrix, METH_VARARGS, "Transpose a matrix" },
    { "transpose_square_matrix", py_transpose_square_matrix, METH_VARARGS, "Transpose a square matrix" },
    { "add_matrix", py_add_matrices, METH_VARARGS, "Add two matrices" },

    { NULL, NULL, 0, NULL }
};

/* Module structure */
static struct PyModuleDef bayesmodule = {
    PyModuleDef_HEAD_INIT, "bayes_ml", /* name of module */
    "A module based on probabilistic machine learning", /* Doc string (may be
                                                           NULL) */
    -1, /* Size of per-interpreter state or -1 */
    BayesMethods /* Method table */
};

/* Module initialization function */
PyMODINIT_FUNC PyInit_bayes_ml(void)
{
    import_array();
    return PyModule_Create(&bayesmodule);
}