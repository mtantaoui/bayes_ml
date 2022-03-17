
import bayes_ml
import numpy as np
from rich import print

a = np.array(range(1,101), dtype=np.float64).reshape(10, 10)
print(bayes_ml.copy_matrix(a))
print(bayes_ml.get_row(a, 3))