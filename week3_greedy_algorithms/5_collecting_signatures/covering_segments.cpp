#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::max;
using std::min;

struct Segment {
    int start;
    int end;

  bool operator < (const Segment& str) const
  {
      return (start < str.start);
  }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  
  Segment current = segments[0];
  for (int i = 0; i < segments.size(); i++)
  {
      if (current.end >= segments[i].start)
      {
          current.start = max(current.start, segments[i].start);
          current.end = min(current.end, segments[i].end);
      }
      else
      {
          points.push_back(current.end);
          current = segments[i];
      }
  }
  points.push_back(current.end);




  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  std::sort(segments.begin(), segments.end());

  /*for (size_t i = 0; i < segments.size(); ++i) {
      std::cout << segments[i].start << " " << segments[i].end << std::endl;
  }*/
  

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
