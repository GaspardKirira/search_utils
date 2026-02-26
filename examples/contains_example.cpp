#include <search_utils/search_utils.hpp>
#include <iostream>
#include <vector>

using namespace search_utils;

void run_example()
{
  std::vector<int> data{5, 10, 15, 20};

  bool exists = contains(data.begin(), data.end(), 15);
  bool missing = contains(data.begin(), data.end(), 17);

  std::cout << "15 exists: " << std::boolalpha << exists << "\n";
  std::cout << "17 exists: " << std::boolalpha << missing << "\n";
}

int main()
{
  run_example();
}
