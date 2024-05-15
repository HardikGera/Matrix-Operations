#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Seed the random number generator
    srand(time(NULL));

    // Check for valid number of arguments
    if (argc < 6 || argc > 7)
    {
        printf("Usage: %s nrows_A ncols_A nrows_B ncols_B <operation> [print]\n", argv[0]);
        return 1;
    }

    // Get matrix dimensions from arguments
    int N1 = atoi(argv[1]);
    int M1 = atoi(argv[2]);
    int N2 = atoi(argv[3]);
    int M2 = atoi(argv[4]);

    // Generate random matrices A and B
    double A[N1][M1], B[N2][M2];
    generateMatrix(N1, M1, A);
    generateMatrix(N2, M2, B);

    // Determine operation based on argument
    char *operation = argv[5];
    if (strcmp(operation, "add") == 0)
    {
        double result[N1][M1];
        addMatrices(N1, M1, A, N2, M2, B, result);

        // Print matrices A, B, and result (if requested)
        if (argc == 7 && strcmp(argv[6], "print") == 0)
        {
            printf("Matrix A:\n");
            printMatrix(N1, M1, A);
            printf("\n"); // New line after Matrix A
            printf("Matrix B:\n");
            printMatrix(N2, M2, B);
            printf("\n"); // New line after Matrix B
            printf("Result of Addition:\n");
            printMatrix(N1, M1, result);
        }
    }
    else if (strcmp(operation, "subtract") == 0)
    {
        double result[N1][M1];
        subtractMatrices(N1, M1, A, N2, M2, B, result);

        // Print matrices A, B, and result (if requested)
        if (argc == 7 && strcmp(argv[6], "print") == 0)
        {
            printf("Matrix A:\n");
            printMatrix(N1, M1, A);
            printf("\n"); // New line after Matrix A
            printf("Matrix B:\n");
            printMatrix(N2, M2, B);
            printf("\n"); // New line after Matrix B
            printf("Result of Subtraction:\n");
            printMatrix(N1, M1, result);
        }
    }
    else if (strcmp(operation, "multiply") == 0)
    {
        double result[N1][M2]; // Result will have dimensions N1 x M2
        multiplyMatrices(N1, M1, A, N2, M2, B, result);

        // Print matrices A, B, and result (if requested)
        if (argc == 7 && strcmp(argv[6], "print") == 0)
        {
            printf("Matrix A:\n");
            printMatrix(N1, M1, A);
            printf("\n"); // New line after Matrix A
            printf("Matrix B:\n");
            printMatrix(N2, M2, B);
            printf("\n"); // New line after Matrix B
            printf("Result of Multiplication:\n");
            printMatrix(N1, M2, result); // Print with adjusted dimensions
        }
    }
    else if (strcmp(operation, "solve") == 0)
    {
        double x[N1][M2]; // Assuming solution vector x has same dimensions as B
        solveLinearSystem(N1, M1, A, N2, M2, B, x);

        // Print matrices A, B, and solution vector x (if requested)
        if (argc == 7 && strcmp(argv[6], "print") == 0)
        {
            printf("Matrix A:\n");
            printMatrix(N1, M1, A);
            printf("\n"); // New line after Matrix A
            printf("Matrix B:\n");
            printMatrix(N2, M2, B);
            printf("\n"); // New line after Matrix B
            printf("Result of x=B/A:\n");
            printMatrix(N1, M2, x); // Print with adjusted dimensions
        }
    }
    else
    {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}
