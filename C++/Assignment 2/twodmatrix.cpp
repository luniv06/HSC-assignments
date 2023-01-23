#include <iostream>

using namespace std;

int **aloc_and_set_to_val(int num_rows, int num_cols, int element_val) {
    int **matrix = new int *[num_rows];
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = new int[num_cols];
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            matrix[i][j] = element_val;
        }
    }
    return matrix;
}

int **add_matrices(int num_rows, int num_cols, int **matrix1, int **matrix2) {
    int **matrix3 = new int *[num_rows];
    for (int i = 0; i < num_rows; i++) {
        matrix3[i] = new int[num_cols];
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix3;
}

void free_matrix(int num_rows, int num_cols, int **matrix) {
    for (int i = 0; i < num_rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void print_matrix(int num_rows, int num_cols, int **matrix) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int num_rows, num_cols;
    cout << "Enter no. of rows: ";
    cin >> num_rows;
    cout << "\nEnter no. of columns: ";
    cin >> num_cols;

    int **matrix1 = aloc_and_set_to_val(num_rows, num_cols, 1);
    int **matrix2 = aloc_and_set_to_val(num_rows, num_cols, 4);
    int **matrix3 = add_matrices(num_rows, num_cols, matrix1, matrix2);
    cout << "Matrix 1: " << endl;
    print_matrix(num_rows, num_cols, matrix1);
    cout << "\nMatrix 2: " << endl;
    print_matrix(num_rows, num_cols, matrix2);
    cout << "\nMatrix 1 + Matrix 2 = " << endl;
    print_matrix(num_rows, num_cols, matrix3);
    free_matrix(num_rows, num_cols, matrix1);
    free_matrix(num_rows, num_cols, matrix2);
    free_matrix(num_rows, num_cols, matrix3);
    return 0;
}