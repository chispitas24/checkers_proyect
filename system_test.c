/*
 * It test the efficiency of "movements" function defined in "checkers.h"
 * Compile command: gcc system_testing_movements.c -o system_test
 * Run command: ./system_test
 * @authors Naiara Alonso Montes <naiara.alonso@student.um.si>
 *          Karya Alkan          <karya.alkan@student.um.si>
 *          Athina Oikonomou     <athina.oikonomou@student.um.si>
 * @date nov-22
*/

// Libraries
#include <sys/time.h> // STANDARD LIBRARY
#include <stdio.h> // STANDARD LIBRARY

#include "checkers.c" // Library defined by the program, it contains "movement" function

// Constants
#define MAX_ITER 10000 // Fixed values
#define MAX_COORDINATES 8 // Fixed values
#define MAX_COMBINATIONS 64 // Total number of squares
#define MAX_POSITIONS 4096 // 64*64 combinations of possible/not possible movements

// Main function
int main()
{
    // Variables
    struct timeval t_0, t_1;
    unsigned int j;
    double total = 0; 
    checkersGrid CheckerBoard[SIZE][SIZE];
    initBoard(CheckerBoard);
    coordinates start, final;
    char horizontal_coordinates[MAX_COORDINATES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int vertical_coordinates[MAX_COORDINATES] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < MAX_COMBINATIONS; i++)
    {
        start.x = vertical_coordinates[i];
        start.y = horizontal_coordinates[i];
        //printf("start.x coordinate is: %d\n", start.x); ONLY TO CHECK
        //printf("start.y coordinate is: %c\n", start.y); ONLY TO CHECK
        

        for (int j = 0; j < MAX_COORDINATES; j++)
        {
            final.x = vertical_coordinates[j];
            for (int k = 0; k < MAX_COORDINATES; k++)
            {
                final.y = horizontal_coordinates[k];
                //printf("final.x coordinate is: %d\n", final.x); ONLY TO CHECK
                //printf("final.y coordinate is: %c\n", final.y); ONLY TO CHECK
                gettimeofday(&t_0, NULL); // Get initial time
                for (int l = 0; l < MAX_ITER; l++)
                {
                    movements(CheckerBoard, 'X', start, final);
                }
                gettimeofday(&t_1, NULL); // Get final time
                total += t_1.tv_sec - t_1.tv_sec + 1E-6 * (t_1.tv_usec - t_0.tv_usec);
            }
        }
    }

    // Final calculations
    total = total / MAX_POSITIONS; // Get average
    printf("The average time of execution of function \"movements\" for %d tries is %f seconds\n", MAX_ITER, total); // Print average
    
    return (0);
}