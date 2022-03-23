#include "../utils.h"
#include "Python.h"
#include "general_purpose_functions.h"
#include "numpy/arrayobject.h"

PyObject* py_transpose_matrix(PyObject* self, PyObject* args)
{
    PyArrayObject *py_matrix_in, *py_matrix_out;
    int nrows, ncols;
    npy_intp dim[2];

    import_array();

    // parse args
    if (!PyArg_ParseTuple(args, "O!", &PyArray_Type, &py_matrix_in)) {
        // Check to make sure input isn't zero dimensional!
        if ((PyArray_DIMS(py_matrix_in) == NULL) || (PyArray_STRIDES(py_matrix_in) == NULL)) {
            PyErr_Format(PyExc_TypeError, "Matrix Input is zero-dimensional.");
            return NULL;
        }

        return NULL;
    }

    if (py_matrix_in == NULL)
        return NULL;

    // check that objects are "double" types
    // no needed if python wrapper function checks before call to
    // this routine
    if (not_doublematrix(py_matrix_in))
        return NULL;

    // getting matrix dimensions
    // setting dim for matrix transpose dimensions
    nrows = dim[1] = py_matrix_in->dimensions[0];
    ncols = dim[0] = py_matrix_in->dimensions[1];

    py_matrix_out = (PyArrayObject*)PyArray_Zeros(2, dim, PyArray_DESCR(py_matrix_in), 0);

    transpose_matrix((double*)py_matrix_out->data, (double*)py_matrix_in->data, nrows, ncols);

    return PyArray_Return(py_matrix_out);
}