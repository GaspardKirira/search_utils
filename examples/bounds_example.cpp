#include <search_utils/search_utils.hpp>
#include <iostream>
#include <vector>

using namespace search_utils;

void run_example()
{
  std::vector<int> data{1, 2, 2, 2, 5, 7};

  std::size_t lb = lower_bound_index(data.begin(), data.end(), 2);
  std::size_t ub = upper_bound_index(data.begin(), data.end(), 2);

  std::cout << "Lower bound index: " << lb << "\n";
  std::cout << "Upper bound index: " << ub << "\n";
}

int main()
{
  run_example();
}
