#include<iostream>
using namespace std;
#define INF 99999
#define num 4

void floyd_warshall(int A[][num]){
  int i,j,k;
  for(k = 0;k<num;k++){
    for(i= 0;i<num;i++){
      for(j=0;j<num;j++){
        if(A[i][j] > (A[i][k] + A[k][j]) && A[k][j]!= INF && A[i][k] != INF){
          A[i][j] = A[i][k] + A[k][j];
        }
      }
    }
  }
}

int main(){
  int i,j,no_of_vertices;
  cout<<"Enter the value 99999 wherever infinity is present "<<endl<<endl;   
  cout<<"Enter the your matrix : "<<" ";
  int M[num][num];
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      cin>>M[i][j];
    }
    cout<<endl; 
  }    
  cout<<"Your matrix is : "<<endl;
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      if (M[i][j] == INF){
          cout<<"INF"<<"   ";
      } else {
          cout<< M[i][j]<<"     ";
      }
    }
    cout<<endl;  
  }                      
  floyd_warshall(M);
  cout<<endl<<endl;
  cout<<"The Distance matrix is : "<<endl;
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
        if (M[i][j] == INF){
            cout<<"INF"<<"   ";
        } else{
            cout<< M[i][j]<<"    ";
        }
    }
    cout<<endl;
  }
  return(0);
}    