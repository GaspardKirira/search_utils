#include <search_utils/search_utils.hpp>
#include <iostream>
#include <vector>

using namespace search_utils;

void run_example()
{
  std::vector<int> data{2, 4, 6, 8, 10};

  auto result = binary_search_index(data.begin(), data.end(), 6);

  if (result.has_value())
  {
    std::cout << "Value found at index: " << result.value() << "\n";
  }
  else
  {
    std::cout << "Value not found\n";
  }
}

int main()
{
  run_example();
}
