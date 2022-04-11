#include "../utils.h"
#include "Python.h"
#include "arithmetic_operations.h"
#include "numpy/arrayobject.h"

PyObject* py_add_matrices(PyObject* self, PyObject* args)
{
    PyArrayObject *py_matrix_A, *py_matrix_B, *py_matrix_out;
    double **c_matrix_out, **c_matrix_A, **c_matrix_B;
    int nrows, ncols;

    import_array();

    // parse args
    if (!PyArg_ParseTuple(args, "O!O!", &PyArray_Type, &py_matrix_A,
            &PyArray_Type, &py_matrix_B)) {
        // Check to make sure input isn't zero dimensional!
        if ((PyArray_DIMS(py_matrix_A) == NULL) || (PyArray_STRIDES(py_matrix_A) == NULL)) {
            PyErr_Format(PyExc_TypeError, "Matrix Input is zero-dimensional.");
            return NULL;
        }
        if ((PyArray_DIMS(py_matrix_B) == NULL) || (PyArray_STRIDES(py_matrix_B) == NULL)) {
            PyErr_Format(PyExc_TypeError, "Matrix Input is zero-dimensional.");
            return NULL;
        }
        return NULL;
    }

    if ((py_matrix_A == NULL) || (py_matrix_B == NULL))
        return NULL;

    // check that objects are "double" types
    // no needed if python wrapper function checks before call to
    // this routine
    if (not_doublematrix(py_matrix_A) || not_doublematrix(py_matrix_B))
        return NULL;

    // getting matrix dimensions
    nrows = py_matrix_A->dimensions[0];
    ncols = py_matrix_A->dimensions[1];

    py_matrix_out = (PyArrayObject*)PyArray_SimpleNew(
        2, PyArray_DIMS(py_matrix_A), NPY_DOUBLE);

    c_matrix_A = pymatrix_to_Carrayptrs(py_matrix_A);
    c_matrix_B = pymatrix_to_Carrayptrs(py_matrix_B);
    c_matrix_out = pymatrix_to_Carrayptrs(py_matrix_out);

    add_matrices(c_matrix_out, c_matrix_A, c_matrix_B, nrows, ncols);

    free_Carrayptrs(c_matrix_A);
    free_Carrayptrs(c_matrix_B);
    free_Carrayptrs(c_matrix_out);

    return PyArray_Return(py_matrix_out);
}