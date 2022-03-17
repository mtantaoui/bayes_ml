#include "Python.h"

#include "general_purpose_functions.h"
#include "../utils.h"

#include "numpy/arrayobject.h"

PyObject *py_get_row(PyObject *self, PyObject *args)
{
    PyArrayObject *py_matrix_in, *py_vector_out;
    int ncols, row;
    npy_intp dim[1];

    import_array();

    // printf("------  entering py_copy_matrix function     ------\n");

    // parse args
    if (!PyArg_ParseTuple(args, "O!i", &PyArray_Type, &py_matrix_in, &row))
    {
        // Check to make sure input isn't zero dimensional!
        if ((PyArray_DIMS(py_matrix_in) == NULL) || (PyArray_STRIDES(py_matrix_in) == NULL)){
            PyErr_Format(PyExc_TypeError,
                         "Input is zero-dimensional.");
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
    ncols = dim[0] = py_matrix_in->dimensions[1];

    // making a new double matrix with same dimensions
    py_vector_out = (PyArrayObject *)PyArray_SimpleNew(1, dim, NPY_DOUBLE);
    
    get_row((double *)py_vector_out->data, (double *)py_matrix_in->data, row, ncols);

    // printf("------  leaving py_copy_matrix function     ------\n");

    return PyArray_Return(py_vector_out);
}
