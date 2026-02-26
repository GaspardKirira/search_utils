#include <search_utils/search_utils.hpp>
#include <iostream>
#include <vector>
#include <cassert>

using namespace search_utils;

void test_binary_search()
{
  std::vector<int> v{1, 3, 5, 7, 9};

  auto idx = binary_search_index(v.begin(), v.end(), 5);
  assert(idx.has_value());
  assert(idx.value() == 2);

  auto missing = binary_search_index(v.begin(), v.end(), 4);
  assert(!missing.has_value());
}

void test_bounds()
{
  std::vector<int> v{1, 2, 2, 2, 4, 6};

  std::size_t lb = lower_bound_index(v.begin(), v.end(), 2);
  std::size_t ub = upper_bound_index(v.begin(), v.end(), 2);

  assert(lb == 1);
  assert(ub == 4);
}

void test_contains()
{
  std::vector<int> v{10, 20, 30};

  assert(contains(v.begin(), v.end(), 20));
  assert(!contains(v.begin(), v.end(), 25));
}

int main()
{
  test_binary_search();
  test_bounds();
  test_contains();

  std::cout << "search_utils tests passed\n";
}
