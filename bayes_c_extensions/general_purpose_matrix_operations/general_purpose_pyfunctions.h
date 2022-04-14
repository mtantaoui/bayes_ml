#include "Python.h"

extern PyObject* py_copy_matrix(PyObject* self, PyObject* args);
extern PyObject* py_get_row(PyObject* self, PyObject* args);
extern PyObject* py_get_column(PyObject* self, PyObject* args);
extern PyObject* py_set_row(PyObject* self, PyObject* args);
extern PyObject* py_set_column(PyObject* self, PyObject* args);
extern PyObject* py_get_diagonal(PyObject* self, PyObject* args);
extern PyObject* py_set_diagonal(PyObject* self, PyObject* args);
extern PyObject* py_set_diagonal_to_scalar(PyObject* self, PyObject* args);
extern PyObject* py_transpose_matrix(PyObject* self, PyObject* args);
extern PyObject* py_transpose_square_matrix(PyObject* self, PyObject* args);
