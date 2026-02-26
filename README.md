# search_utils

Deterministic search helpers for modern C++.

`search_utils` provides minimal, explicit binary search utilities for
sorted ranges without relying on `<algorithm>`{=html} wrappers.

Header-only. Zero dependencies.

## Download

https://vixcpp.com/registry/pkg/gaspardkirira/search_utils

## Why search_utils?

Using `std::lower_bound` or `std::binary_search` is convenient, but
sometimes you need:

-   Index-based results instead of iterators
-   Explicit control over the search loop
-   Educational or competitive-programming clarity
-   Deterministic implementation without abstraction layers

This library provides:

-   `binary_search_index`
-   `lower_bound_index`
-   `upper_bound_index`
-   `contains`

No allocations\
No exceptions\
No hidden behavior

No wrappers around `<algorithm>`.\
No implicit projections.\
No policy objects.

Just explicit **O(log n)** search primitives.

## Installation

### Using Vix Registry

``` bash
vix add gaspardkirira/search_utils
vix deps
```

### Manual

``` bash
git clone https://github.com/GaspardKirira/search_utils.git
```

Add the `include/` directory to your project.

## Dependency

C++17 or newer is required (for `std::optional`).

No external dependencies.

## Quick Examples

### Binary Search (Index)

``` cpp
#include <search_utils/search_utils.hpp>
#include <vector>
#include <iostream>

int main()
{
  std::vector<int> data{1, 3, 5, 7, 9};

  auto result =
    search_utils::binary_search_index(
      data.begin(),
      data.end(),
      5);

  if (result.has_value())
  {
    std::cout << "Found at index "
              << result.value()
              << "\n";
  }
}
```

### Lower / Upper Bound

``` cpp
#include <search_utils/search_utils.hpp>
#include <vector>
#include <iostream>

int main()
{
  std::vector<int> data{1, 2, 2, 2, 4};

  std::size_t lb =
    search_utils::lower_bound_index(
      data.begin(),
      data.end(),
      2);

  std::size_t ub =
    search_utils::upper_bound_index(
      data.begin(),
      data.end(),
      2);

  std::cout << "range: ["
            << lb
            << ", "
            << ub
            << ")\n";
}
```

### Contains

``` cpp
#include <search_utils/search_utils.hpp>
#include <vector>
#include <iostream>

int main()
{
  std::vector<int> data{10, 20, 30};

  bool ok =
    search_utils::contains(
      data.begin(),
      data.end(),
      20);

  std::cout << std::boolalpha
            << ok
            << "\n";
}
```

## API Overview

``` cpp
search_utils::binary_search_index(first, last, value);
search_utils::lower_bound_index(first, last, value);
search_utils::upper_bound_index(first, last, value);
search_utils::contains(first, last, value);
```

All functions:

-   Require sorted ranges
-   Operate in **O(log n)**
-   Use random-access iterators

## Design Principles

-   Deterministic implementation
-   No STL algorithm wrappers
-   No allocation
-   No exceptions
-   Index-based results
-   Clear complexity guarantees

This module is intentionally small.

If you need:

-   Projections
-   Custom comparators
-   Ranges support
-   Policy-based search

Build those on top.

## Tests

Run:

``` bash
vix build
vix tests
```

Tests verify:

-   Correct index computation
-   Boundaries handling
-   Missing values
-   Duplicate ranges

## License

MIT License
Copyright (c) Gaspard Kirira

