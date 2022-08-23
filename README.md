# Algorithms [![C++ Logo](/utilities/images/C++_Logo_x36.png "C++ Logo")](https://isocpp.org/get-started)

## This repository contains

- [Sorting algorithm](#sorting-algorithm)
  - [Bubble sort](#bubble-sort)

---

## Sorting algorithm

### Bubble sort

- Code snippets
  - Integer sort - [&#128279;](shorting_algorithms/bubble_sort.cpp#L20)
  - String sort - [&#128279;](shorting_algorithms/bubble_sort.cpp#L45)

**What is this?**

Bubble sort, aka sinking sort is a basic algorithm for arranging a string of numbers or other elements in the correct order. This sorting algorithm is comparison-based algorithm in which each pair of adjacent elements is compared and the elements are swapped if they are not in order. The algorithm then repeats this process until it can run through the entire string or other elements and find no two elements that need to be swapped. This algorithm is not suitable for large data sets as its average and worst case complexity are of Ο(n<sup>2</sub>) where n is the number of items.

**In general**, Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. Therefore, it is called a bubble sort.

**How Bubble Sort Works?**

> *In short*

Suppose we are trying to sort the elements in ascending order.

1. First Iteration (Compare and Swap)
    1. Starting from the first index, compare the first and the second elements.
    2. If the first element is greater than the second element, they are swapped.
    3. Now, compare the second and the third elements. Swap them if they are not in order.
    4. The above process goes on until the last element.
2. Remaining Iteration

   The same process goes on for the remaining iterations.
   After each iteration, the largest element among the unsorted elements is placed at the end.
   In each iteration, the comparison takes place up to the last unsorted element.
   The array is sorted when all the unsorted elements are placed at their correct positions.

> *In details*

To demonstrate lets take an unordered array of number with 5 elements

```cpp
int array[10] = { 5, 10, 7, 9, 2}
```

Let's close look to the elements of the array

|   index   | 0   | 1   | 2   | 3   | 4   |
|:---------:|-----|-----|-----|-----|-----|
| **value** | 5   | 10  | 7   | 11  | 2   |

Bubble sort starts with very first two elements, comparing them to check which one is greater.

|   index   | 0              | 1               | 2   | 3   | 4   |
|:---------:|----------------|-----------------|-----|-----|-----|
| **value** | <mark>5</mark> | <mark>10</mark> | 7   | 11  | 2   |

In this case, value <mark>10</mark> is greater <mark>5</mark>, so it is already in sorted locations. Next, we compare <mark>10</mark> with <mark>7</mark>.

|   index   | 0   | 1               | 2              | 3   | 4   |
|:---------:|-----|-----------------|----------------|-----|-----|
| **value** | 5   | <mark>10</mark> | <mark>7</mark> | 11  | 2   |

We find that <mark>7</mark> is smaller than <mark>10</mark> and these two values must be swapped :arrows_counterclockwise:

|   index   | 0   | 1               | 2              | 3   | 4   |
|:---------:|-----|-----------------|----------------|-----|-----|
| **value** | 5   | <mark>10</mark> | <mark>7</mark> | 11  | 2   |

The new array should look like this −

|   index   | 0   | 1   | 2    | 3   | 4   |
|:---------:|-----|-----|------|-----|-----|
| **value** | 5   | _7_ | _10_ | 11  | 2   |

Next we compare <mark>10</mark> and <mark>11</mark>. We find that both are in already sorted positions.

|   index   | 0   | 1   | 2               | 3               | 4   |
|:---------:|-----|-----|-----------------|-----------------|-----|
| **value** | 5   | 7   | <mark>10</mark> | <mark>11</mark> | 2   |

Then we move to the next two values, <mark>11</mark> and <mark>2</mark>.

|   index   | 0   | 1   | 2   | 3               | 4              |
|:---------:|-----|-----|-----|-----------------|----------------|
| **value** | 5   | 7   | 10  | <mark>11</mark> | <mark>2</mark> |

We know then that <mark>2</mark> is smaller <mark>11</mark>. Hence, they are not sorted.

|   index   | 0   | 1   | 2   | 3               | 4              |
|:---------:|-----|-----|-----|-----------------|----------------|
| **value** | 5   | 7   | 10  | <mark>11</mark> | <mark>2</mark> |

We swap these values. We find that we have reached the end of the array. After one iteration, the array should look like this −

|   index   | 0   | 1   | 2   | 3   | 4               |
|:---------:|-----|-----|-----|-----|-----------------|
| **value** | 5   | 7   | 10  | 2   | <mark>11</mark> |

To be precise, we are now showing how an array should look like after each iteration. After the second iteration, it should look like this −

|   index   | 0   | 1   | 2   | 3               | 4               |
|:---------:|-----|-----|-----|-----------------|-----------------|
| **value** | 5   | 7   | 2   | <mark>10</mark> | <mark>11</mark> |

Notice that after each iteration, at least one value moves at the end.

|   index   | 0   | 1   | 2              | 3               | 4               |
|:---------:|-----|-----|----------------|-----------------|-----------------|
| **value** | 5   | 2   | <mark>7</mark> | <mark>10</mark> | <mark>11</mark> |

And when there's no swap required, bubble sorts learns that an array is completely sorted.

|   index   | 0              | 1              | 2              | 3               | 4               |
|:---------:|----------------|----------------|----------------|-----------------|-----------------|
| **value** | <mark>2</mark> | <mark>5</mark> | <mark>7</mark> | <mark>10</mark> | <mark>11</mark> |

Now we should look into some practical aspects of bubble sort.

**Algorithm**

We assume list is an array of n elements. We further assume that swap function swaps the values of the given array elements.

```dsa
begin BubbleSort(list)

   for all elements of list
      if list[i] > list[i+1]
         swap(list[i], list[i+1])
      end if
   end for

   return list

end BubbleSort
```

**Pseudocode**

In pseudocode the algorithm can be expressed as **(0-based array)**:

```pascal
procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        swapped := false
        for i := 1 to n-1 inclusive do
            /* if this pair is out of order */
            if A[i-1] > A[i] then
                /* swap them and remember something changed */
                swap(A[i-1], A[i])
                swapped := true
            end if
        end for
    until not swapped
end procedure
```

**Time and Space** complexity for the Bubble Sort algorithm

- **Worst** Case Time Complexity **[ Big-O ]**: **O(n<sup>2</sup>)**
- **Best** Case Time Complexity **[Big-omega]**: **O(n)**
- **Average** Time Complexity **[Big-theta]**: **O(n<sup>2</sup>)**
- **Space** Complexity: **O(1)**

---
