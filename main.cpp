#include <iostream>

#include "assignment/insertion_sort.hpp"

#include "assignment/partitioning.hpp"

#include "assignment/heap_sort.hpp"

#include "assignment/partitioning.hpp"
#include "assignment/quick_sort.hpp"

#include "assignment/merging.hpp"
#include "assignment/merge_sort.hpp"

using namespace std;
using namespace assignment;

int main() {
  int res = median_of_three({5, 2, 10, 24, 25}, 0, 4);
  cout << res << " ";



  //  InsertionSort search_algo;
//  int res = linear_search({1, 3, 5, 7, 9, 2, 2, 4}, 5);
//  cout << res << "\n";
//  int res_2 = binary_search({1, 3, 5, 7, 9, 2, 2, 4}, 5);
//  cout << res_2 << "\n";
//  cout << middle_of(0, 1) << "\n";

//  auto res = merge({1, 5, 3, 7, 8, 2, 8, 10}, 0, 3, 7, {});


  //  std::vector<int> arr = {-39, -79};
  //
  //  InsertionSort sort;
  //  sort.Sort(arr);

  return 0;
}
