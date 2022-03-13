// #define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "Python.h"
#include "general_purpose_matrix_operations/py_copy_matrix.h"

#include "numpy/arrayobject.h"

/* Module method table */
static PyMethodDef BayesMethods[] = {
    {"copy_matrix", py_copy_matrix, METH_VARARGS, "Copy a Matrix"},
    {NULL, NULL, 0, NULL}};

/* Module structure */
static struct PyModuleDef bayesmodule = {
    PyModuleDef_HEAD_INIT,
    "bayes_ml",                                         /* name of module */
    "A module based on probabilistic machine learning", /* Doc string (may be NULL) */
    -1,                                                 /* Size of per-interpreter state or -1 */
    BayesMethods                                        /* Method table */
};

/* Module initialization function */
PyMODINIT_FUNC PyInit_bayes_ml(void)
{
    import_array();
    return PyModule_Create(&bayesmodule);
}