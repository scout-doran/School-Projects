//By: Scout Doran
//Date: 11/10/2020
#include <iostream>
#include <iomanip>
#include <time.h>
#include <pthread.h>

using namespace std;

void *threadFunction(void *args){
    //cout << "This is the thread" << endl;
}

int main()
{
    //number of threads
    int t = 1; 
    //array of threads
    pthread_t threadArray[100000];
    clock_t start, end;
    float avg;

//1 thread
    //creating
    start = clock(); //start clock
    for(int i = 0; i < t; i++){
        pthread_create(&threadArray[i], NULL, threadFunction, NULL); //why do we pass the array by reference and why don't we pass the function like this &threadFunction(args)???
    } 
    end = clock(); //end clock
    long durationForCreate = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for creating " << t << " thread(s) is : " << durationForCreate << " nanoseconds" <<endl;
        
    //deleting 
    start = clock();
    for(int i = 0; i < t; i++){
        pthread_join(threadArray[i],NULL); 
    }
    end = clock();
        
    long durationForDelete = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for deleting " << t << " thread(s) is : " << durationForDelete << " nanoseconds" << endl;
        
    //totalTimeTemp holds the total time for a specific amount of threads (i.e 1, 10, 100,...)
    signed int totalTime = durationForCreate + durationForDelete;
    //avg holds the average time it took per thread
    avg = totalTime / t;
    cout << "Average time per thread: " << avg << " nanoseconds" << endl;
    cout << endl;

//10 threads
    t = 10;
    //creating
    start = clock(); //start clock
    for(int i = 0; i < t; i++){
        pthread_create(&threadArray[i], NULL, threadFunction, NULL); //why do we pass the array by reference and why don't we pass the function like this &threadFunction(args)???
    } 
    end = clock(); //end clock
    durationForCreate = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for creating " << t << " thread(s) is : " << durationForCreate << " nanoseconds" <<endl;
        
    //deleting 
    start = clock();
    for(int i = 0; i < t; i++){
        pthread_join(threadArray[i],NULL); 
    }
    end = clock();
        
    durationForDelete = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for deleting " << t << " thread(s) is : " << durationForDelete << " nanoseconds" << endl;
        
    //totalTimeTemp holds the total time for a specific amount of threads (i.e 1, 10, 100,...)
    totalTime = durationForCreate + durationForDelete;
    //avg holds the average time it took per thread
    avg = totalTime / t;
    cout << "Average time per thread: " << avg << " nanoseconds" << endl;
    cout << endl;

//100 threads
    t = 100;
    //creating
    start = clock(); //start clock
    for(int i = 0; i < t; i++){
        pthread_create(&threadArray[i], NULL, threadFunction, NULL); //why do we pass the array by reference and why don't we pass the function like this &threadFunction(args)???
    } 
    end = clock(); //end clock
    durationForCreate = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for creating " << t << " thread(s) is : " << durationForCreate << " nanoseconds" <<endl;
        
    //deleting 
    start = clock();
    for(int i = 0; i < t; i++){
        pthread_join(threadArray[i],NULL); 
    }
    end = clock();
        
    durationForDelete = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for deleting " << t << " thread(s) is : " << durationForDelete << " nanoseconds" << endl;
        
    //totalTimeTemp holds the total time for a specific amount of threads (i.e 1, 10, 100,...)
    totalTime = durationForCreate + durationForDelete;
    //avg holds the average time it took per thread
    avg = totalTime / t;
    cout << "Average time per thread: " << avg << " nanoseconds" << endl; 
    cout << endl;

//1000 threads
    t = 1000;
    //creating
    start = clock(); //start clock
    for(int i = 0; i < t; i++){
        pthread_create(&threadArray[i], NULL, threadFunction, NULL); //why do we pass the array by reference and why don't we pass the function like this &threadFunction(args)???
    } 
    end = clock(); //end clock
    durationForCreate = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for creating " << t << " thread(s) is : " << durationForCreate << " nanoseconds" <<endl;
        
    //deleting 
    start = clock();
    for(int i = 0; i < t; i++){
        pthread_join(threadArray[i],NULL); 
    }
    end = clock();
        
    durationForDelete = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for deleting " << t << " thread(s) is : " << durationForDelete << " nanoseconds" << endl;
        
    //totalTimeTemp holds the total time for a specific amount of threads (i.e 1, 10, 100,...)
    totalTime = durationForCreate + durationForDelete;
    //avg holds the average time it took per thread
    avg = totalTime / t;
    cout << "Average time per thread: " << avg << " nanoseconds" << endl;
    cout << endl;

//10000 threads
    t = 10000;
    //creating
    start = clock(); //start clock
    for(int i = 0; i < t; i++){
        pthread_create(&threadArray[i], NULL, threadFunction, NULL); //why do we pass the array by reference and why don't we pass the function like this &threadFunction(args)???
    } 
    end = clock(); //end clock
    durationForCreate = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for creating " << t << " thread(s) is : " << durationForCreate << " nanoseconds" <<endl;
        
    //deleting 
    start = clock();
    for(int i = 0; i < t; i++){
        pthread_join(threadArray[i],NULL); 
    }
    end = clock();
        
    durationForDelete = (double(end-start) / CLOCKS_PER_SEC) * 1000000000;
    cout << "Execution time for deleting " << t << " thread(s) is : " << durationForDelete << " nanoseconds" << endl;
        
    //totalTimeTemp holds the total time for a specific amount of threads (i.e 1, 10, 100,...)
    totalTime = durationForCreate + durationForDelete;
    //avg holds the average time it took per thread
    avg = totalTime / t;
    cout << "Average time per thread: " << avg << " nanoseconds" <<endl;
    cout << endl;

    return 0;
}
