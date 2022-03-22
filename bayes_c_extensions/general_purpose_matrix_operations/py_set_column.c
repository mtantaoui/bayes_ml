#include "../utils.h"
#include "Python.h"
#include "general_purpose_functions.h"
#include "numpy/arrayobject.h"

PyObject* py_set_column(PyObject* self, PyObject* args)
{
    PyArrayObject *py_matrix_in, *py_vector_in, *py_matrix_out, *py_vector_out;
    double **c_matrix_out, *c_vector_out;
    int nrows, col;

    import_array();

    // parse args
    if (!PyArg_ParseTuple(args, "O!O!i", &PyArray_Type, &py_matrix_in,
            &PyArray_Type, &py_vector_in, &col)) {
        // Check to make sure input isn't zero dimensional!
        if ((PyArray_DIMS(py_matrix_in) == NULL) || (PyArray_STRIDES(py_matrix_in) == NULL)) {
            PyErr_Format(PyExc_TypeError, "Matrix Input is zero-dimensional.");
            return NULL;
        }
        if ((PyArray_DIMS(py_vector_in) == NULL) || (PyArray_STRIDES(py_vector_in) == NULL)) {
            PyErr_Format(PyExc_TypeError, "Vector Input is zero-dimensional.");
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
    nrows = py_matrix_in->dimensions[0];

    py_matrix_out = (PyArrayObject*)PyArray_SimpleNewFromData(
        2, PyArray_DIMS(py_matrix_in), NPY_DOUBLE, py_matrix_in->data);
    py_vector_out = (PyArrayObject*)PyArray_SimpleNewFromData(
        1, PyArray_DIMS(py_vector_in), NPY_DOUBLE, py_vector_in->data);

    c_matrix_out = pymatrix_to_Carrayptrs(py_matrix_out);
    c_vector_out = pyvector_to_Carrayptrs(py_vector_out);

    set_column(c_matrix_out, c_vector_out, col, nrows);

    free_Carrayptrs(c_matrix_out);
    // free(c_vector_out);

    return PyArray_Return(py_matrix_out);
}