#include <pthread.h>
#include <iostream>
#include <chrono>

using namespace std;

int x = 0, y = 0, z = 0;

int sudoku[9][9] = {
    {7, 9, 2, 1, 5, 4, 3, 8, 6},
    {6, 4, 3, 8, 2, 7, 1, 5, 9},
    {8, 5, 1, 3, 9, 6, 7, 2, 4},
    {2, 6, 5, 9, 7, 3, 8, 4, 1},
    {4, 8, 9, 5, 6, 1, 2, 7, 3},
    {3, 1, 7, 4, 8, 2, 9, 6, 5},
    {1, 3, 6, 7, 4, 8, 5, 9, 2},
    {9, 7, 4, 2, 1, 5, 6, 3, 8},
    {5, 2, 8, 6, 3, 9, 4, 1, 7}};


/*Checking values in a row*/
void *checkRows(void *param)
{
    int sum =  0;
    for (int i = 0; i < 9; i++){
        sum =0;
        for(int j = 0; j < 9; j++){
            sum += sudoku[i][j];
        }
        if (sum != 45){
                x = 1;
                break;
            }
    }
    return NULL;
}


void *checkColumns(void *param)
{
    int sum =  0;
    for (int i = 0; i < 9; i++){
        sum = 0;
        for(int j = 0; j < 9; j++){
            sum += sudoku[j][i];
        }
        if (sum != 45){
                y = 1;
                break;
            }
    }
 
    return NULL;
}


void *checkSubGrids(void *param)
{
    int sum = 0;
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            sum = 0;
            for (int k = i; k < i + 3; k++)
            {
                for (int l = j; l < j + 3; l++)
                {
                    sum += sudoku[k][l];
                }
                               
            }
            if (sum != 45){
                z = 1;
                break;
            }
        }
       
    }
    return NULL;
}


int main()
{


    pthread_t tid1, tid2, tid3;

    

    auto started = chrono::steady_clock::now();

    pthread_create(&tid1, NULL, checkRows, NULL);
    pthread_create(&tid2, NULL, checkColumns, NULL);
    pthread_create(&tid3, NULL, checkSubGrids, NULL);


   
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

  
    auto finished = chrono::steady_clock::now();

    
    if (x == 1 || y == 1 || z == 1)
    {
        cout << "Invalid Solution, please try again" << endl;
    }
    else
    {	
        cout << "The given solution is valid.\n" << endl;
    };


    cout << chrono::duration_cast<chrono::nanoseconds>(finished-started).count() << endl;

    return 0;
}

