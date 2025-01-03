#include <stdio.h>
#include <stdlib.h>

int* FibonacciSeries(int n){
    int firstNum = -1, secondNum = 1, newTwo;
    
    int* array = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++){
        newTwo = firstNum+secondNum;
        array[i] = newTwo;
        firstNum = secondNum, secondNum = newTwo;
    }
    
    return array;
}
int sumSeries(int *arr,int n){
    int i,sum=0;
    for(i=0;i<n;i++){
        
        sum+=arr[i];
    }
    return sum+1;
}

int* FibonacciSeriesEvenNumbers(int* arr, int n){
    int i,size=0;
    for(i=0;i<n;i++){
        if(arr[i]%2==0) size++;
    }
    int* even = (int*)malloc(size*sizeof(int));
    int j=0;
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
            even[j++]=arr[i];
        } 
    }
    return even;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* array = FibonacciSeries(n);
    
    int sumOfFib= sumSeries(array,n);
    printf("%d",sumOfFib);

    printf("\n");
    int* even=FibonacciSeriesEvenNumbers(array,n);
    for(int i=0; i<(sizeof(even)/sizeof(even[0])); i++) printf("%d ", even[i]);
}