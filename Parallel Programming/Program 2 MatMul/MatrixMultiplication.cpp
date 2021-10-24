//By: Scout Doran
//Date: 11/27/2020

#include <iostream>
#include <iomanip>
#include <pthread.h>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::chrono;

int const n = 5; //5,100,400
int A[n][n];
int B[n][n];
int C[n][n];
int count = 0; // used in coreMulti
int counter = 0; //used in threadEachElementMulti

void* coreMulti(void* arg) 
{  
    int core = count++; 
  
    // Each thread computes 1/2th of matrix multiplication 
    for (int i = core * n / 2; i < (core + 1) * n / 2; i++)  
        for (int j = 0; j < n; j++)  
            for (int k = 0; k < n; k++)  
                C[i][j] += A[i][k] * B[k][j]; 
}

void* threadEachElementMulti(void* arg) 
{
    int numElements = n*n;
    int element = counter++; 
  
    for (int i = element * n / numElements; i < (element + 1) * n / numElements; i++){  
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){  
                C[i][j] += A[i][k] * B[k][j];
            }
        } 
    }
}

void* serialLikeMulti(void* arg) 
{  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    } 
}

void serialMulti(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void resetMatrix(){
    for (int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
        }  
    }
}

void fillMatrix(){
    //Value to be inserted into matrix
    int value = 1;

    //Fill the matrices
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            A[row][col] = value;
        }
        value++;
    }
    value = 1;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            B[row][col] = value;
            value++;
        }
        value = 1;
    }
}

//Holds the result matrix
void displayMatrixC(){
    cout << "Matrix Multiplication Result:" << endl;
    cout << "Last Cell: ";
    for (int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){ 
            if(i == n-1 && j == n-1)
                cout << "[" << C[i][j] << "]";
        }      
    }
    cout << endl;
}

int main(int argc, char* argv[]){
    fillMatrix();
    cout << endl;
    cout << n << " X " << n << " matrix" << endl;
    cout << endl;
/*******************************************************************************************/
    //Serial version of code    
    
//START CLOCK
    auto start = high_resolution_clock::now();

//Multiply Matrix A and B stored in Matrix C
    serialMulti();

//Print result matrix
    displayMatrixC();
    
//STOP CLOCK
    auto stop = high_resolution_clock::now();
    
//CALCULATE AND DISPLAY EXECUTION TIME
    auto duration = duration_cast<nanoseconds>(stop - start); 
    cout << "Time for serial code: " << duration.count() << " nanoseconds" << endl;
    cout << endl;

//Clear Matrix
    resetMatrix();
/*******************************************************************************************/
    //Serial “like”	version	of code

//START CLOCK
    start = high_resolution_clock::now();
    int numThreads = 1;
    pthread_t thread[numThreads];
    for(int i = 0; i<numThreads; i++){
        int* p;
        pthread_create(&thread[i], NULL, serialLikeMulti, (void*)(p));
    }
    
  
    // joining and waiting for all threads to complete   
    for(int i = 0; i < numThreads; i++){
        pthread_join(thread[i], NULL);
    }
    
    displayMatrixC();

//STOP CLOCK
    stop = high_resolution_clock::now();
    
//CALCULATE AND DISPLAY EXECUTION TIME
    duration = duration_cast<nanoseconds>(stop - start); 
    cout << "Time for serial like code: " << duration.count() << " nanoseconds" << endl;
    cout << endl;

//Clear Matrix
    resetMatrix();
/*******************************************************************************************/
    //Do 1-thread for each element in matrix C
    int numElements = n*n;
    pthread_t threadArray[numElements];

//START CLOCK
    start = high_resolution_clock::now();
    for (int i = 0; i < numElements; i++) {
        int* p; 
        pthread_create(&threadArray[i], NULL, threadEachElementMulti, (void*)(p));
    } 
  
    // joining and waiting for all threads to complete 
    for (int i = 0; i < numElements; i++){  
        pthread_join(threadArray[i], NULL);
    }
    displayMatrixC();

//STOP CLOCK
    stop = high_resolution_clock::now();
    
//CALCULATE AND DISPLAY EXECUTION TIME
    duration = duration_cast<nanoseconds>(stop - start); 
    cout << "Time for 1 thread for each element: " << duration.count() << " nanoseconds" << endl;
    cout << endl;

//Clear Matrix
    resetMatrix();
/*******************************************************************************************/
    //Do 1-thread (at a	time) for each core	on your	machine
    //I have 2 cores on my machine
    
//START CLOCK
    start = high_resolution_clock::now();

    // declaring 2 threads
    int MAX_THREAD = 2; 
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 2 threads, each evaluating its own part 
    for (int i = 0; i < MAX_THREAD; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, coreMulti, (void*)(p)); 
    } 
  
    // joining and waiting for all threads to complete 
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);

    //Print result matrix
    displayMatrixC();

//STOP CLOCK
    stop = high_resolution_clock::now();
    
//CALCULATE AND DISPLAY EXECUTION TIME
    duration = duration_cast<nanoseconds>(stop - start); 
    cout << "Time for 1 thread for each core: " << duration.count() << " nanoseconds" << endl;
    cout << endl;

    return 0;
}