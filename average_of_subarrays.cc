/* 
Find the average of k (positive integer [1, nums.size()]) consecutive elements of an array. "Sliding window" technique
has been used.
Time complexity: O(n)
Space complexity: O(n)
*/ 

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<double> findSuseqAverages(size_t k, const std::vector<int>& nums) {
  std::vector<double> res(nums.size() - k + 1); // Allocate space to avoid resizing
  auto left_it = nums.begin();
  auto right_it = std::next(left_it, k);
  double curr_sum = std::accumulate(left_it, right_it, 0);

  size_t res_index = 0;
  res[res_index] = curr_sum / k;

  while (right_it != nums.end()) {
    curr_sum += *right_it - *left_it;
    res[++res_index] = curr_sum / k;
    ++right_it;
    ++left_it;
  }

  return res;
}

int main() {
  std::vector<int> nums{1, 2, 3, 4, 5};
  size_t k = 3;
  std::vector<double> averages = findSuseqAverages(k, nums);

  for (const auto& a : averages) {
    std::cout << a << " ";
  }
  std::cout << "\n\n";
}
