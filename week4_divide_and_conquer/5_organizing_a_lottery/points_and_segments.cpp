#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


int IterativeBinarySearch_Starts(vector<int>& starts, int num)
{
    //SMALLER OR EQUAL
    int left = 0;
    int right = starts.size() - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (starts[mid] == num)
        {
            while (mid+1 < starts.size() && starts[mid+1] == num)
            {
                mid++;
            }
            break;
        }
        else if (starts[mid] > num)
        {
            //ignore right half
            right = mid-1;
        }
        else
        {
            left = mid + 1;
        }
    }
    while (mid >=0 && starts[mid] > num)
        mid--;


    
    return mid;

}
int IterativeBinarySearch_Ends(vector<int>& ends, int num)
{
    int left = 0;
    int right = ends.size() - 1;
    int mid = 0;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (ends[mid] == num)
        {
            while (mid - 1 >= 0 && ends[mid - 1] == num)
            {
                mid--;
            }
            break;
        }
        else if(ends[mid]<num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }


    while (mid <ends.size() && ends[mid] < num)
        mid++;

    
    return mid-1;
}

vector<int> fast_count_segments(vector<int>& starts, vector<int>& ends, vector<int>& points) {
  vector<int> cnt(points.size());
  //write your code here
  for (int i = 0;i < points.size();i++)
  {
      //std::cout << "for " << points[i] << "    " << IterativeBinarySearch_Starts(starts, points[i]) << " " << IterativeBinarySearch_Ends(ends, points[i]) << std::endl;
      cnt[i] = -IterativeBinarySearch_Ends(ends, points[i]) + IterativeBinarySearch_Starts(starts, points[i]);
  }




  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n);
  vector<int> ends(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> starts[i] >> ends[i];
  }

  std::sort(starts.begin(), starts.end());
  std::sort(ends.begin(), ends.end());

  
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  /*std::cout << "[";
  for (int i = 0; i < starts.size(); i++)
  {
      std::cout << starts[i] << " ";
  }
  std::cout << " ]\n";

  std::cout << "[";
  for (int i = 0; i < ends.size(); i++)
  {
      std::cout << ends[i] << " ";
  }
  std::cout << " ]\n";
*/
  
  
  
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}



/*
5 1
3 8
1 15
12 14
4 6
0 1
11
*/