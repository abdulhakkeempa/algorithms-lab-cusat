#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int partition(int *data,int begin,int end);

void quickSort(int *data,int begin,int end){
    int loc;
    if(begin<end){
        loc = partition(data,begin,end);
        quickSort(data,begin,loc-1);
        quickSort(data,loc+1,end);
    }
}

int partition(int *data,int begin,int end){
    int pivot = data[begin];
    int lowerBound = begin;
    int upperBound = end;
    int temp;
    while(lowerBound<upperBound){
        while(data[lowerBound]<=pivot){
            lowerBound++;
        }
        while(data[upperBound]>pivot){
            upperBound--;
        }
        if(lowerBound<upperBound){
            temp = data[lowerBound];
            data[lowerBound]=data[upperBound];
            data[upperBound]=temp;
        }
    }
    temp = data[begin];
    data[begin] = data[upperBound];
    data[upperBound] = temp;
    return upperBound;
}

void printArray(int* data,int length){
	for (int var = 0; var < length; ++var) {
		cout<<data[var]<<" ";
	}
}

int main(){

   int array[20];
   srand(time(0));
   for (int i = 0; i <20;i++){
    array[i] = rand();
   }
   clock_t start, end;
   start = clock();
   int length = sizeof(array)/sizeof(array[0]);
   quickSort(array,0,length-1);
   end = clock();
   double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
   cout << "Time taken by program is : " << fixed
   << time_taken << setprecision(5);
   cout << " sec " << endl;
   cout<<endl;
   printArray(array,length);
}