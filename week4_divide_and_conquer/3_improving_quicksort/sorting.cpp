#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
using std::vector;
using std::swap;


/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition(vector<int>&a, int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r];

    while (true) {
       
        while (a[++i] < v);

        
        while (v < a[--j])
            if (j == l)
                break;

        if (i >= j)
            break;

        swap(a[i], a[j]);

        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }

        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }

    swap(a[i], a[r]);

   
    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}

void randomized_quicksort(vector<int>&a, int l, int r)
{
    if (r <= l)
        return;

    int i, j;
    
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);

    partition(a, l, r, i, j);

    randomized_quicksort(a, l, j);
    randomized_quicksort(a, i, r);
}



int main() {
    srand(time(NULL));

    int n;
    std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; ++i) {
      std::cin >> a[i];
  }
  randomized_quicksort(a, 0, n - 1);
  for (size_t i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;
}
