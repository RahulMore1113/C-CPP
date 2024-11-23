import numpy as np

# Function to add two matrices
def add_matrices(A, B):
    return np.add(A, B)

# Function to subtract two matrices
def subtract_matrices(A, B):
    return np.subtract(A, B)

# Function to multiply two matrices
def multiply_matrices(A, B):
    return np.dot(A, B)

# Function to transpose a matrix
def transpose_matrix(A):
    return np.transpose(A)

# Main function to test the operations
def main():
    # Example matrices
    A = np.array([[1, 2, 3],
                  [4, 5, 6],
                  [7, 8, 9]])

    B = np.array([[9, 8, 7],
                  [6, 5, 4],
                  [3, 2, 1]])

    print("Matrix A:")
    print(A)

    print("\nMatrix B:")
    print(B)

    # a) Addition of two matrices
    result_add = add_matrices(A, B)
    print("\nAddition of A and B:")
    print(result_add)

    # b) Subtraction of two matrices
    result_sub = subtract_matrices(A, B)
    print("\nSubtraction of A and B:")
    print(result_sub)

    # c) Multiplication of two matrices
    result_mul = multiply_matrices(A, B)
    print("\nMultiplication of A and B:")
    print(result_mul)

    # d) Transpose of matrix A
    result_transpose_A = transpose_matrix(A)
    print("\nTranspose of A:")
    print(result_transpose_A)

if __name__ == "__main__":
    main()
