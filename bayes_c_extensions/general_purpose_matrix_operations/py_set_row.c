#include "Python.h"

#include "general_purpose_functions.h"
#include "../utils.h"

#include "numpy/arrayobject.h"

PyObject *py_set_row(PyObject *self, PyObject *args)
{
    PyArrayObject *py_matrix_in, *py_vector_in;
    int ncols, row;
    npy_intp dim[2];

    import_array();

    // printf("------  entering py_copy_matrix function     ------\n");

    // parse args
    if (!PyArg_ParseTuple(args, "O!O!i", &PyArray_Type, &py_matrix_in, &PyArray_Type, &py_vector_in, &row))
    {
        // Check to make sure input isn't zero dimensional!
        if ((PyArray_DIMS(py_matrix_in) == NULL) || (PyArray_STRIDES(py_matrix_in) == NULL))
        {
            PyErr_Format(PyExc_TypeError,
                         "Matrix Input is zero-dimensional.");
            return NULL;
        }
        if ((PyArray_DIMS(py_vector_in) == NULL) || (PyArray_STRIDES(py_vector_in) == NULL))
        {
            PyErr_Format(PyExc_TypeError,
                         "Vector Input is zero-dimensional.");
            return NULL;
        }
        return NULL;
    }
    
    if ((py_matrix_in == NULL) || (py_vector_in == NULL))
        return NULL;

    // check that objects are "double" types
    // no needed if python wrapper function checks before call to
    // this routine
    if (not_doublematrix(py_matrix_in) || not_doublevector(py_vector_in))
        return NULL;

    // getting matrix dimensions
    ncols = dim[0] = py_matrix_in->dimensions[1];

    set_row((double *)py_matrix_in->data, (double *)py_vector_in->data, row, ncols);

    // printf("------  leaving py_copy_matrix function     ------\n");

    return PyArray_Return(py_matrix_in);
}