#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
  
// function to heapify the tree
void heapify(vector<int> &arr, int n, int root)
{
   // build heapify
    int Largest=root;
    int l=root*2+1; int r=root*2+2;
    if (l<n && arr[l]>arr[Largest]) {
        Largest=l;
    }
    if (r<n && arr[r]>arr[Largest]) {
        Largest=r;
    }
    if (Largest!=root) {
        int temp=arr[Largest];
        arr[Largest]=arr[root];
        arr[root]=temp;
        heapify(arr,n,Largest);
    }
}
  
// implementing heap sort
void heapSort(vector<int> &arr, int n)
{
   // build heap
    for (int i=(n-1)/2;i>=0;i--) {
        heapify(arr,n,i);
    }
  
   // extracting elements from heap one by one
    for (int i=n-1;i>0;i--) {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}
  
/* print contents of array */
void displayArray(vector<int> arr, int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    // Get User Inputs as a line.
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> heap_arr;
    int num;
    while (ss >> num) {
        heap_arr.push_back(num);
    }

    // Main Part.
    int n = heap_arr.size();
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
    
    heapSort(heap_arr, n);
    
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}