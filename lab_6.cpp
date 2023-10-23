//Author: Tatum Morris
//ID: 3062485
//Date: 10/19/2023
//Assignment: Lab 6: Matrix Manipulation


#include <iostream>
#include <fstream>
#include <ostream>

const int maxSize = 100;

void readMatrix(int matrixA[maxSize][maxSize], int matrixB[maxSize][maxSize], int &size) {
    std::ifstream file("matrix_input.txt");
    file >> size;
    std::string dummy;
    std::getline(file, dummy);
    for (int i=0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            file >> matrixA[i][j];
        }
    }
    std::getline(file, dummy);
    for (int i=0; i < size; ++i) {
        for (int j = 0; j < size; j++) {
            file >> matrixB[i][j];
        }
    }    
}



void printMatrix(int matrix[maxSize][maxSize], int size) {
    for (int i = 0; i < size; ++i){
        for(int j=0; j< size; ++j) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
}

void sumMatrix(int matrixA[maxSize][maxSize],int matrixB[maxSize][maxSize], int result[maxSize][maxSize], int size) {
    printf("Matrix Sum (A + B):\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    printMatrix(result, size);
}

void productMatrix(int matrixA[maxSize][maxSize],int matrixB[maxSize][maxSize], int result[maxSize][maxSize], int size) {
    printf("Matrix Product (A * B):\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    printMatrix(result, size);
}

void differenceMatrix(int matrixA[maxSize][maxSize],int matrixB[maxSize][maxSize], int result[maxSize][maxSize], int size) {
    printf("Matrix Difference (A - B):\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
            printf("%3d", result[i][j]);
        }
        printf("\n"); 
    }
}

int main() {
    int matrixA[maxSize][maxSize], matrixB[maxSize][maxSize], result[maxSize][maxSize];
    int size;

    printf("Tatum Morris\n");
    printf("Lab 6: Matrix Manipulation\n\n");

    
    readMatrix(matrixA, matrixB, size);

    printf("Matrix A: \n");
    printMatrix(matrixA, size);
    printf("Matrix B: \n");
    printMatrix(matrixB, size);

    sumMatrix(matrixA, matrixB, result, size);
    printf("\n");
    productMatrix(matrixA, matrixB, result, size);
    printf("\n");
    differenceMatrix(matrixA, matrixB, result, size);

    return 0;
}

