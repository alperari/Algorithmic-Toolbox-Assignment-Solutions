#include <iostream>
#include <vector>

using std::vector;





int merge(vector<int>& arr, int l, int m, int r)
{
    int inversion_num = 0;
    
    int n1 = m - l+1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {

            inversion_num += n1 - i;

            arr[k] = R[j];
            j++;
        }
        k++;
    }


    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        
        arr[k] = R[j];
        j++;
        k++;
    }
    return inversion_num;
}

long long get_number_of_inversions(vector<int>& a, int left, int right) {
    long long* number_of_inversions = new long long(0);
    if (right <= left)
        return *number_of_inversions;


    int ave = (left + right) / 2;

    *number_of_inversions += get_number_of_inversions(a, left, ave);
    *number_of_inversions += get_number_of_inversions(a, ave+1, right);
    *number_of_inversions += merge(a,left,ave, right);
    //write your code here
    return *number_of_inversions;
}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  
  std::cout << get_number_of_inversions(a, 0, a.size()-1) << '\n';
  
 
}
