#include "../utils.h"
#include "Python.h"
#include "general_purpose_functions.h"
#include "numpy/arrayobject.h"

PyObject* py_get_column(PyObject* self, PyObject* args)
{
    PyArrayObject *py_matrix_in, *py_vector_out;
    int nrows, ncols, col;
    npy_intp dim[2];

    import_array();

    // parse args
    if (!PyArg_ParseTuple(args, "O!i", &PyArray_Type, &py_matrix_in, &col)) {
        // Check to make sure input isn't zero dimensional!
        if ((PyArray_DIMS(py_matrix_in) == NULL) || (PyArray_STRIDES(py_matrix_in) == NULL)) {
            PyErr_Format(PyExc_TypeError, "Input is zero-dimensional.");
            return NULL;
        }
        return NULL;
    }
    // return NULL;
    if (NULL == py_matrix_in)
        return NULL;

    // check that objects are "double" types
    // no needed if python wrapper function checks before call to
    // this routine
    if (not_doublematrix(py_matrix_in))
        return NULL;

    // getting matrix dimensions
    nrows = py_matrix_in->dimensions[0];
    ncols = dim[0] = py_matrix_in->dimensions[1];
    dim[1] = 1;

    // making a new double matrix with same dimensions
    // returning a column vector, a matrix with 1 column and n rows
    // that's why we have 2 dimensions in py_vector_out
    py_vector_out = (PyArrayObject*)PyArray_SimpleNew(2, dim, NPY_DOUBLE);

    get_column((double*)py_vector_out->data, (double*)py_matrix_in->data, col,
        nrows, ncols);

    return PyArray_Return(py_vector_out);
}
