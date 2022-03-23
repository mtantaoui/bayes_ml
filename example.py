import bayes_ml
import numpy as np
from rich import print

a = np.array(range(1, 101), dtype=np.float64).reshape(10, 10)
v = np.zeros(10, dtype=np.float64)

print(bayes_ml.copy_matrix.__name__)
print(bayes_ml.copy_matrix(a))

print(bayes_ml.get_row(a, 3))

print(bayes_ml.get_column(a, 3))

print(bayes_ml.set_column(a, a[0], 4))

print(bayes_ml.set_row(a, a[0], 4))

print(bayes_ml.get_diagonal(a))

print(bayes_ml.set_diagonal(a, v))

print(bayes_ml.set_diagonal(a, a[0]*100))

print(bayes_ml.set_diagonal_to_scalar(a, np.float64(-999)))

