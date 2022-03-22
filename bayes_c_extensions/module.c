// #define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "Python.h"
#include "general_purpose_matrix_operations/general_purpose_pyfunctions.h"

#include "numpy/arrayobject.h"

/* Module method table */
static PyMethodDef BayesMethods[] = {
    {"copy_matrix", py_copy_matrix, METH_VARARGS, "Copy a Matrix"},
    {"get_row", py_get_row, METH_VARARGS, "Get a matrix row"},
    {"get_column", py_get_column, METH_VARARGS, "Get a matrix column"},
    {"set_row", py_set_row, METH_VARARGS, "Set a matrix row"},
    {"set_column", py_set_column, METH_VARARGS, "Set a matrix column"},
    {NULL, NULL, 0, NULL}};

/* Module structure */
static struct PyModuleDef bayesmodule = {
    PyModuleDef_HEAD_INIT, "bayes_ml",                  /* name of module */
    "A module based on probabilistic machine learning", /* Doc string (may be
                                                           NULL) */
    -1,          /* Size of per-interpreter state or -1 */
    BayesMethods /* Method table */
};

/* Module initialization function */
PyMODINIT_FUNC PyInit_bayes_ml(void) {
  import_array();
  return PyModule_Create(&bayesmodule);
}