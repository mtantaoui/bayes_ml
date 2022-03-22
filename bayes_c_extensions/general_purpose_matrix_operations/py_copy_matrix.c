// #define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "../utils.h"
#include "Python.h"
#include "general_purpose_functions.h"
#include "numpy/arrayobject.h"

PyObject* py_copy_matrix(PyObject* self, PyObject* args)
{
    PyArrayObject *py_matrix_in, *py_matrix_out; // 2D numpy array
    double **c_matrix_in, **c_matrix_out;
    int nrows, ncols;

    import_array();

    // parse args
    if (!PyArg_ParseTuple(args, "O!", &PyArray_Type, &py_matrix_in)) {
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
    ncols = py_matrix_in->dimensions[1];

    // making a new double matrix with same dimensions
    py_matrix_out = (PyArrayObject*)PyArray_SimpleNew(
        2, PyArray_DIMS(py_matrix_in), NPY_DOUBLE);

    // change contiguous arrays into C ** arrays (memory is allocated!!)
    c_matrix_in = pymatrix_to_Carrayptrs(py_matrix_in);
    c_matrix_out = pymatrix_to_Carrayptrs(py_matrix_out);

    copy_matrix(c_matrix_in, c_matrix_out, nrows, ncols);

    free_Carrayptrs(c_matrix_in);
    free_Carrayptrs(c_matrix_out);

    return PyArray_Return(py_matrix_out);
}
