/**
 * @file search_utils.hpp
 * @brief Deterministic search helpers for modern C++.
 *
 * Provides:
 *  - Binary search (exact match)
 *  - Lower bound
 *  - Upper bound
 *  - Contains helper
 *
 * All algorithms operate on sorted ranges.
 *
 * No allocations.
 * No exceptions.
 * No hidden behavior.
 */

#pragma once

#include <cstddef>
#include <iterator>
#include <optional>

namespace search_utils
{

  /**
   * @brief Performs binary search on a sorted range.
   *
   * @tparam RandomIt Random access iterator
   * @tparam T Value type
   *
   * @param first Begin iterator
   * @param last End iterator
   * @param value Value to search
   *
   * @return Index of the element if found, otherwise std::nullopt
   *
   * @complexity O(log n)
   */
  template <typename RandomIt, typename T>
  std::optional<std::size_t>
  binary_search_index(RandomIt first, RandomIt last, const T &value)
  {
    std::size_t left = 0;
    std::size_t right = static_cast<std::size_t>(std::distance(first, last));

    while (left < right)
    {
      std::size_t mid = left + (right - left) / 2;
      if (*(first + mid) < value)
      {
        left = mid + 1;
      }
      else if (*(first + mid) > value)
      {
        right = mid;
      }
      else
      {
        return mid;
      }
    }

    return std::nullopt;
  }

  /**
   * @brief Returns first position where value could be inserted without breaking order.
   *
   * @complexity O(log n)
   */
  template <typename RandomIt, typename T>
  std::size_t
  lower_bound_index(RandomIt first, RandomIt last, const T &value)
  {
    std::size_t left = 0;
    std::size_t right = static_cast<std::size_t>(std::distance(first, last));

    while (left < right)
    {
      std::size_t mid = left + (right - left) / 2;
      if (*(first + mid) < value)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }

    return left;
  }

  /**
   * @brief Returns first position after the last occurrence of value.
   *
   * @complexity O(log n)
   */
  template <typename RandomIt, typename T>
  std::size_t
  upper_bound_index(RandomIt first, RandomIt last, const T &value)
  {
    std::size_t left = 0;
    std::size_t right = static_cast<std::size_t>(std::distance(first, last));

    while (left < right)
    {
      std::size_t mid = left + (right - left) / 2;
      if (*(first + mid) <= value)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }

    return left;
  }

  /**
   * @brief Checks if value exists in sorted range.
   *
   * @complexity O(log n)
   */
  template <typename RandomIt, typename T>
  bool
  contains(RandomIt first, RandomIt last, const T &value)
  {
    return binary_search_index(first, last, value).has_value();
  }

} // namespace search_utils
