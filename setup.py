from distutils.core import setup, Extension
import numpy as np
import os 

def get_c_modules():
    c_extensions = (".c")
    modules = []
    for root, dirs, files in os.walk(os.getcwd()):
        for file in files:
            if file.endswith(c_extensions):
                modules.append(root + "/" + file)
    return modules

setup(
    name="bayes_ml",
    ext_modules=[
        Extension(
            "bayes_ml",
            get_c_modules(),
            include_dirs=[np.get_include()],
        )
    ],
)
