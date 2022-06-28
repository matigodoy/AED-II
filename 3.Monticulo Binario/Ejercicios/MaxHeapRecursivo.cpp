#include<iostream> 
using namespace std;

bool esMaxHeap(int a[], int i, int n)
{
    
    if (i >= (n - 2) / 2)
        return true;
 

    if (a[i] >= a[2 * i + 1] && a[i] >= a[2 * i + 2] && esMaxHeap(a, 2 * i + 1, n) && esMaxHeap(a, 2 * i + 2, n))
        return true;
 
    return false;
}
 
int main()
{
    int a[] = { 94, 70, 83, 57, 4, 61, 80 };
    int n = sizeof(a) / sizeof(int);
 
     cout << (esMaxHeap(a, 0, n)? "Si": "No") << " es un Maxheap " << endl;
 
 
    return 0;
}
