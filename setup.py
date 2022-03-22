from distutils.core import setup, Extension
import numpy as np

setup(
    name="bayes_ml",
    ext_modules=[
        Extension(
            "bayes_ml",
            [
                "bayes_c_extensions/module.c",
                "bayes_c_extensions/utils.c",
                "bayes_c_extensions/general_purpose_matrix_operations/copy_matrix.c",
                "bayes_c_extensions/general_purpose_matrix_operations/py_copy_matrix.c",
                "bayes_c_extensions/general_purpose_matrix_operations/get_row.c",
                "bayes_c_extensions/general_purpose_matrix_operations/py_get_row.c",
                "bayes_c_extensions/general_purpose_matrix_operations/get_column.c",
                "bayes_c_extensions/general_purpose_matrix_operations/py_get_column.c",
                "bayes_c_extensions/general_purpose_matrix_operations/set_row.c",
                "bayes_c_extensions/general_purpose_matrix_operations/py_set_row.c",
                "bayes_c_extensions/general_purpose_matrix_operations/set_column.c",
                "bayes_c_extensions/general_purpose_matrix_operations/py_set_column.c",
                "bayes_c_extensions/general_purpose_matrix_operations/get_diagonal.c",
                "bayes_c_extensions/general_purpose_matrix_operations/py_get_diagonal.c",

            ],
            include_dirs=[np.get_include()],
        )
    ],
)
