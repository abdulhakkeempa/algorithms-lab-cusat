#include <iostream>
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
	int array[] = {56,98,100,23,25,101};
	int length = sizeof(array)/sizeof(array[0]);
    quickSort(array,0,length-1);
    printArray(array,length);
}