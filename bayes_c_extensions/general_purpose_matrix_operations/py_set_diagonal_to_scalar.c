#include "../utils.h"
#include "Python.h"
#include "general_purpose_functions.h"
#include "numpy/arrayobject.h"

PyObject* py_set_diagonal_to_scalar(PyObject* self, PyObject* args)
{
    PyArrayObject *py_matrix_in, *py_matrix_out;
    double **c_matrix_out, scalar;
    int nrows, ncols;

    import_array();

    // parse args
    if (!PyArg_ParseTuple(args, "O!d", &PyArray_Type, &py_matrix_in, &scalar)) {
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
    nrows = py_matrix_in->dimensions[0];
    ncols = py_matrix_in->dimensions[1];

    py_matrix_out = (PyArrayObject*)PyArray_SimpleNewFromData(
        2, PyArray_DIMS(py_matrix_in), NPY_DOUBLE, py_matrix_in->data);

    c_matrix_out = pymatrix_to_Carrayptrs(py_matrix_out);

    set_diagonal_to_scalar(c_matrix_out, scalar, nrows, ncols);

    free_Carrayptrs(c_matrix_out);
    // free(c_vector_out);

    return PyArray_Return(py_matrix_out);
}