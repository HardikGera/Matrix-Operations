// CODE: include necessary library(s)

#include "functions.h"
#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()
#include <math.h>

// Function to generate a random matrix with values between -10 and 10
void generateMatrix(int rows, int cols, double matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = (double)rand() / (double)(RAND_MAX) * 20 - 10; // Generate random number and adjust to range
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, double matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%f ", matrix[i][j]); // Print with 2 decimal places
        }
        printf("\n");
    }
}

// Function to add two matrices with compatible dimensions
void addMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1])
{
    if (N1 != N2 || M1 != M2)
    {
        printf("Error: Matrices have incompatible dimensions for addition.\n");
        exit(1);
    }

    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M1; j++)
        {
            result[i][j] = A[i][j] + B[i][j]; // Add corresponding elements
        }
    }
}

// Function to subtract two matrices with compatible dimensions
void subtractMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M1])
{
    if (N1 != N2 || M1 != M2)
    {
        printf("Error: Matrices have incompatible dimensions for subtraction.\n");
        exit(1);
    }

    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M1; j++)
        {
            result[i][j] = A[i][j] - B[i][j]; // Subtract corresponding elements
        }
    }
}

// Function to multiply two matrices with compatible dimensions (A x B)
void multiplyMatrices(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double result[N1][M2])
{
    if (M1 != N2)
    {
        printf("Error: Matrices have incompatible dimensions for multiplication.\n");
        exit(1);
    }

    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < M1; k++)
            {
                result[i][j] += A[i][k] * B[k][j]; // Perform element-wise multiplication and summation
            }
        }
    }
}
// Function to solve a linear system of equations (Ax = b) using Gaussian elimination with back substitution

void solveLinearSystem(int N1, int M1, double A[N1][M1], int N2, int M2, double B[N2][M2], double x[N1][M2])
{
    if (N1 != N2 || M2 != 1)
    {
        printf("Error: Matrices have incompatible dimensions for solving the linear system.\n");
        exit(1);
    }
    double aug[N1][M1 + 1];

    // Create augmented matrix
    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M1 + 1; j++)
        {
            if (j == M1)
            {
                aug[i][j] = B[i][0];
            }
            else
            {
                aug[i][j] = A[i][j];
            }
        }
    }

    // Perform Gaussian elimination (forward elimination)
    for (int i = 0; i < N1 - 1; i++)
    {
        for (int j = i + 1; j < N1; j++)
        {
            double r = aug[i][i] / aug[j][i];
            for (int k = 0; k < M1 + 1; k++)
            {
                aug[j][k] = aug[i][k] - r * aug[j][k];
            }
        }
    }

    // Perform back substitution
    x[N1 - 1][0] = aug[N1 - 1][M1] / aug[N1 - 1][N1 - 1];
    for (int i = N1 - 2; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < N1; j++)
        {
            sum += aug[i][j] * x[j][0];
        }
        x[i][0] = (aug[i][M1] - sum) / aug[i][i];
    }
}

// sources
// https://github.com/ckoreli/universal-ppm-image-filter
// https://www.numerade.com/ask/question/write-a-c-program-which-a-take-number-of-column-and-rows-of-two-matrices-from-userb-take-elements-of-two-matrices-93122/

// CODE: do the same for subtractMatrices, multiplyMatrices, and solveLinearSystem functions
