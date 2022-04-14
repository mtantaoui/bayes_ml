import bayes_ml
import numpy as np
from rich import print

a = np.array(range(1, 101), dtype=np.float64).reshape(10, 10)
v = np.zeros(10, dtype=np.float64)

print("Copy Matrix:")
print(bayes_ml.copy_matrix(a))

print("Transpose Matrix:")
print(bayes_ml.transpose_matrix(a))

# print("Transpose Square Matrix:")
# print(bayes_ml.transpose_square_matrix(a))

print("Get Matrix Row:")
print(bayes_ml.get_row(a, 3))

print('Get Column:')
print(bayes_ml.get_column(a, 3))

print("Set Column:")
print(bayes_ml.set_column(a, a[0], 4))

print("Set Row")
print(bayes_ml.set_row(a, a[0], 4))

print("Get Diagonal:")
print(bayes_ml.get_diagonal(a))

print("Set Diagonal")
print(bayes_ml.set_diagonal(a, v))

print("Set Diagonal")
print(bayes_ml.set_diagonal(a, (v+9) * 100))

print("Set Diagonal to Scalar")
print(bayes_ml.set_diagonal_to_scalar(a, np.float64(-999)))

print("Add Matrices")
print(bayes_ml.add_matrices(a, -2*a))

print("Substract Matrices")
print(bayes_ml.substract_matrices(a, a))

print('Multiply matrix by scalar')
print(bayes_ml.multiply_matrix_by_scalar(a, np.float64(0.5)))

print("Divide Matrix by scalar")
print(bayes_ml.divide_matrix_by_scalar(a, np.float64(2)))


