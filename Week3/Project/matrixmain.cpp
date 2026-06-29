#include <iostream>

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total){
    std::cout << "\nPrint2DArray started.\n";

    if (matrix_local_rows_total != 2 && matrix_local_rows_total != 3){
        std::cout << "Invalid dimensions. Only 2x3 or 3x3 arrays allowed.\n";
        std::cout << "Print2DArray finished.\n";
        return;
    }

    // Time Complexity: O(rows * columns)
    // Because the nested loops visit every element once.
    for (int i = 0; i < matrix_local_rows_total; i++){
        for (int j = 0; j < 3; j++){
            std::cout << matrix_local[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Print2DArray finished.\n";
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total)
{
    std::cout << "\nMatrixAddition started.\n";

    if (matrix_one_rows_total != matrix_two_rows_total ||
        (matrix_one_rows_total != 2 && matrix_one_rows_total != 3)){
        std::cout << "Invalid dimensions for matrix addition.\n";
        std::cout << "MatrixAddition finished.\n";
        return;
    }

    int result[3][3];

    // Time Complexity: O(rows * columns)
    // Because every matching element from both matrices is added once.
    for (int i = 0; i < matrix_one_rows_total; i++){
        for (int j = 0; j < 3; j++){
            result[i][j] = matrix_one[i][j] + matrix_two[i][j];
        }
    }

    Print2DArray(result, matrix_one_rows_total);

    std::cout << "MatrixAddition finished.\n";
}

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
    std::cout << "\nTransposeMatrix started.\n";

    if (matrix_local_rows_total != 2 && matrix_local_rows_total != 3){
        std::cout << "Invalid dimensions.\n";
        std::cout << "TransposeMatrix finished.\n";
        return;
    }

    // Time Complexity: O(rows * columns)
    // Because every element is printed once in swapped order.
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < matrix_local_rows_total; i++){
            std::cout << matrix_local[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "TransposeMatrix finished.\n";
}

void Determinant(const int matrix_local[][3], const int size){
    std::cout << "\nDeterminant started.\n";

    if (size != 2 && size != 3){
        std::cout << "Invalid dimensions. Only 2x2 or 3x3 determinant allowed.\n";
        std::cout << "Determinant finished.\n";
        return;
    }

    int determinant = 0;

    if (size == 2){
        // Time Complexity: O(1)
        determinant = (matrix_local[0][0] * matrix_local[1][1]) -
                      (matrix_local[0][1] * matrix_local[1][0]);
    }
    else {
        // Time Complexity: O(1)
        determinant =
            matrix_local[0][0] * ((matrix_local[1][1] * matrix_local[2][2]) - (matrix_local[1][2] * matrix_local[2][1]))
          - matrix_local[0][1] * ((matrix_local[1][0] * matrix_local[2][2]) - (matrix_local[1][2] * matrix_local[2][0]))
          + matrix_local[0][2] * ((matrix_local[1][0] * matrix_local[2][1]) - (matrix_local[1][1] * matrix_local[2][0]));
    }

    std::cout << "Determinant: " << determinant << std::endl;
    std::cout << "Determinant finished.\n";
}

void SearchValue(const int matrix_local[][3], const int rows, const int target){
    std::cout << "\nSearchValue started.\n";

    if (rows != 2 && rows != 3){
        std::cout << "Invalid dimensions.\n";
        std::cout << "SearchValue finished.\n";
        return;
    }

    bool found = false;

    // Time Complexity: O(rows * columns)
    // Worst case, the loop checks every element.
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < 3; j++){
            if (matrix_local[i][j] == target){
                std::cout << "Found " << target << " at row " << i << ", col " << j << std::endl;
                found = true;
            }
        }
    }

    if (!found){
        std::cout << target << " was not found.\n";
    }

    std::cout << "SearchValue finished.\n";
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3],
                    const int rows_a, const int cols_a,
                    const int rows_b, const int cols_b){

    std::cout << "\nMatrixMultiplication started.\n";

    if ((rows_a != 2 && rows_a != 3) || (rows_b != 2 && rows_b != 3) ||
        (cols_a != 2 && cols_a != 3) || (cols_b != 2 && cols_b != 3) ||
        cols_a != rows_b){
        std::cout << "Invalid dimensions for multiplication.\n";
        std::cout << "MatrixMultiplication finished.\n";
        return;
    }

    int result[3][3] = {0};

    // Time Complexity: O(rows_a * cols_b * cols_a)
    // Three nested loops: row of A, column of B, and inner multiplication.
    for (int i = 0; i < rows_a; i++){
        for (int j = 0; j < cols_b; j++){
            for (int k = 0; k < cols_a; k++){
                result[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    for (int i = 0; i < rows_a; i++){
        for (int j = 0; j < cols_b; j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "MatrixMultiplication finished.\n";
}