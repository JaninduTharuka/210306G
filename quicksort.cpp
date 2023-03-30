#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Recursive Method.
void quicksort_R(int A[],int begin,int end) {
    if (begin<end) {
        int pivot = A[end];
        int i = begin-1;
        int temp;
        for (int j=begin;j<=end;j++) {
            if (A[j]<=pivot) {
                i++;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        quicksort_R(A,begin,i-1);
        quicksort_R(A,i+1,end);
    }
}

// Iterative Method.
void quicksort_I(int A[], int begin, int end) {
    int stack[end - begin + 1];
    int top = -1;
    stack[++top] = begin;
    stack[++top] = end;
    while (top >= 0) {
        end = stack[top--];
        begin = stack[top--];
        int pivot = A[end];
        int i = begin - 1;
        int temp;
        for (int j = begin; j <= end; j++) {
            if (A[j] <= pivot) {
                i++;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        if (i + 1 < end) {
            stack[++top] = i + 1;
            stack[++top] = end;
        }
        if (begin < i - 1) {
            stack[++top] = begin;
            stack[++top] = i - 1;
        }
    }
}


int main() {
    for (int L=500;L<=5000;L+=500) {
        cout << "Array size is "<<L<<endl;
        int c[L];
        for (int x=0;x<L;x++) {
            c[x]=rand()%(3*L);
        }

        // Recursive Quick Sort.....
        int a[L];
        for (int i=0;i<L;i++) {
            a[i] = c[i];
        }
        auto begin1 = high_resolution_clock::now();
        quicksort_R(a,0,L-1);
        auto end1 = high_resolution_clock::now();
        auto time1 = duration_cast<microseconds>(end1-begin1);
        cout<<"Recursive Time = "<<time1.count()<<" microseconds"<<endl;


        // Iterative Quick Sort.....
        int b[L];
        for (int i=0;i<L;i++) {
            b[i] = c[i];
        }
        auto begin2 = high_resolution_clock::now();
        quicksort_I(b,0,L-1);
        auto end2 = high_resolution_clock::now();
        auto time2 = duration_cast<microseconds>(end2-begin2);
        cout<<"Iterative Time = "<<time2.count()<<" microseconds"<<endl;
              
    }
    return 0;
}