# Algorithms [![C++ Logo](/utilities/images/C++_Logo_x36.png "C++ Logo")](https://isocpp.org/get-started)

## This repository contains

- [Sorting algorithm](#sorting-algorithm)
  - [Exchange Sort](#exchange-sort) 
    - [Bubble Sort](#bubble-sort-algorithm) -> [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/bubble_sort.cc)
    - [Optimized Bubble Sort](#optimized-bubble-sort-algorithm) -> [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/optimized_bubble_sort.cc)
    - [Cocktail Shaker Sort](#cocktail-shaker-sort-algorithm) -> [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/cocktail_shaker_sort.cc)

---

## Sorting algorithm

In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) that require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output.

Formally, the output of any sorting algorithm must satisfy two conditions:
- The output is in monotonic order (each element is no smaller/larger than the previous element, according to the required order).
- The output is a permutation (a reordering, yet retaining all the original elements) of the input.

For optimum efficiency, the input data should be stored in a data structure which allows random access rather than one that allows only sequential access. 

**Let's talk about some sorting algorithm**

## Exchange Sort

---

### Bubble Sort Algorithm

- Code snippets
  - Integer sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/bubble_sort.cc#L21)
  - String sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/bubble_sort.cc#L37)

**What is this?**

Bubble sort, aka sinking sort is a basic algorithm for arranging a string of numbers or other elements in the correct order. This sorting algorithm is comparison-based algorithm in which each pair of adjacent elements is compared and the elements are swapped if they are not in order. The algorithm then repeats this process until it can run through the entire string or other elements and find no two elements that need to be swapped. This algorithm is not suitable for large data sets as its average and worst case complexity are of Ο(n<sup>2</sub>) where n is the number of items.

**In general**, Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. Therefore, it is called a bubble sort.

**How Bubble Sort Works?**

**_In short_**

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

**_In details_**

To demonstrate let's take an unordered array of number with 5 elements

```cpp
int array[5] = { 5, 10, 7, 9, 2}
```

Let's close look to the elements of the array

|   index   | 0   | 1   | 2   | 3   | 4   |
|:---------:|-----|-----|-----|-----|-----|
| **value** | 5   | 10  | 7   | 11  | 2   |

Bubble sort starts with very first two elements, comparing them to check which one is greater.

|   index   | 0                  | 1                   | 2   | 3   | 4   |
|:---------:|--------------------|---------------------|-----|-----|-----|
| **value** | <mark>**5**</mark> | <mark>**10**</mark> | 7   | 11  | 2   |

In this case, value <mark>**10**</mark> is greater <mark>**5**</mark>, so it is already in sorted locations. Next, we compare <mark>**10**</mark> with <mark>**7**</mark>.

|   index   | 0   | 1                   | 2                  | 3   | 4   |
|:---------:|-----|---------------------|--------------------|-----|-----|
| **value** | 5   | <mark>**10**</mark> | <mark>**7**</mark> | 11  | 2   |

We find that <mark>**7**</mark> is smaller than <mark>**10**</mark> and these two values must be swapped :arrows_counterclockwise:

|   index   | 0   | 1                   | 2                  | 3   | 4   |
|:---------:|-----|---------------------|--------------------|-----|-----|
| **value** | 5   | <mark>**10**</mark> | <mark>**7**</mark> | 11  | 2   |

The new array should look like this −

|   index   | 0   | 1   | 2    | 3   | 4   |
|:---------:|-----|-----|------|-----|-----|
| **value** | 5   | _7_ | _10_ | 11  | 2   |

Next we compare <mark>**10**</mark> and <mark>**11**</mark>. We find that both are in already sorted positions.

|   index   | 0   | 1   | 2                   | 3                   | 4   |
|:---------:|-----|-----|---------------------|---------------------|-----|
| **value** | 5   | 7   | <mark>**10**</mark> | <mark>**11**</mark> | 2   |

Then we move to the next two values, <mark>**11**</mark> and <mark>**2**</mark>.

|   index   | 0   | 1   | 2   | 3                   | 4                  |
|:---------:|-----|-----|-----|---------------------|--------------------|
| **value** | 5   | 7   | 10  | <mark>**11**</mark> | <mark>**2**</mark> |

We know then that <mark>**2**</mark> is smaller <mark>**11**</mark>. Hence, they are not sorted.

|   index   | 0   | 1   | 2   | 3                   | 4                  |
|:---------:|-----|-----|-----|---------------------|--------------------|
| **value** | 5   | 7   | 10  | <mark>**11**</mark> | <mark>**2**</mark> |

We swap these values. We find that we have reached the end of the array. After one iteration, the array should look like this −

|   index   | 0   | 1   | 2   | 3   | 4                   |
|:---------:|-----|-----|-----|-----|---------------------|
| **value** | 5   | 7   | 10  | 2   | <mark>**11**</mark> |

To be precise, we are now showing how an array should look like after each iteration. After the second iteration, it should look like this −

|   index   | 0   | 1   | 2   | 3                   | 4                   |
|:---------:|-----|-----|-----|---------------------|---------------------|
| **value** | 5   | 7   | 2   | <mark>**10**</mark> | <mark>**11**</mark> |

Notice that after each iteration, at least one value moves at the end.

|   index   | 0   | 1   | 2                  | 3                   | 4                   |
|:---------:|-----|-----|--------------------|---------------------|---------------------|
| **value** | 5   | 2   | <mark>**7**</mark> | <mark>**10**</mark> | <mark>**11**</mark> |

And when there's no swap required, bubble sorts learns that an array is completely sorted.

|   index   | 0                  | 1                  | 2                  | 3                   | 4                   |
|:---------:|--------------------|--------------------|--------------------|---------------------|---------------------|
| **value** | <mark>**2**</mark> | <mark>**5**</mark> | <mark>**7**</mark> | <mark>**10**</mark> | <mark>**11**</mark> |

Now we should look into some practical aspects of bubble sort.

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

### Optimized Bubble Sort Algorithm

- Code snippets
  - Integer sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/optimized_bubble_sort.cc#L21)
  - String sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/optimized_bubble_sort.cc#L43)

**What is this?**

Optimized bubble sort is basically a smarter version of bubble sort algorithm. Hence the algorithm is same with a mechanism to determine whether the list/array DS is sorted or not after every iteration.

This ensures that the algorithm only runs till the array/list is sorted.

Regular bubble sort runs iterations which are equal to the size of the array irrespective of whether the array is sorted before those number of iterations or not.

In optimized bubble sort, we have a flag variable that keeps track of whether the list is completely sorted or not.

In optimized bubble sort, whenever there is a swapping in any iteration, it means that the array/list is still not sorted & hence the flag is set to FALSE.

Whenever there is no swapping in a particular iteration, the flag is set to TRUE.

At the end of every iteration, this flag variable is checked. If value is true, it means swapping happened & hence the list isn’t sorted completely so next iteration is allowed. If value is false, it means swapping never happened, hence the list is already sorted & there is no point in further iterations hence exit algorithm.

**How Optimized Bubble Sort works?**

1. Starting with the first element(index = 0), compare the current element with the next element of the array. Set flag = false
2. If the current element is greater than the next element of the array, swap them. Set flag = true
3. If the current element is less than the next element, move to the next element.
4. At end of iteration check flag, if true, continue iteration else exit iterations.
5. Repeat Step 1 till the list is sorted.

Now we should look into some practical aspects of optimized bubble sort.

**Pseudocode**

```pascal
procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        swapped := false
        for i := 1 to n - 1 inclusive do
            if A[i - 1] > A[i] then
                swap(A[i - 1], A[i])
                swapped := true
            end if
        end for
        n := n - 1
    until not swapped
end procedure
```

More Optimized 😜

```pascal
procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        newn := 0
        for i := 1 to n - 1 inclusive do
            if A[i - 1] > A[i] then
                swap(A[i - 1], A[i])
                newn := i
            end if
        end for
        n := newn
    until n ≤ 1
end procedure
```

<b>Time and Space</b> complexity for the Optimized Bubble Sort algorithm

- **Worst** Case Time Complexity **[ Big-O ]**: **O(n<sup>2</sup>)**
- **Best** Case Time Complexity **[Big-omega]**: **O(n)**
- **Average** Time Complexity **[Big-theta]**: **O(n<sup>2</sup>)**
- **Space** Complexity: **O(1)**

---

### Cocktail Shaker Sort Algorithm

- Code snippets
  - Integer sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/cocktail_shaker_sort.cc#L21)
  - String sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/cocktail_shaker_sort.cc#L77)

**What is this?**

Cocktail sort, also known as bidirectional bubble sort, cocktail shaker sort, shaker sort (which can also refer to a variant of selection sort), ripple sort, shuffle sort, or shuttle sort, is a variation of bubble sort that is both a stable sorting algorithm and a comparison sort.

The Bubble sort algorithm always traverses elements from left and moves the largest element to its correct position in the first iteration and second-largest in the second iteration and so on. Cocktail Sort traverses through a given array in both directions alternatively. Cocktail sort does not go through the unnecessary iteration making it efficient for large arrays.

Cocktail sorts break down barriers that limit bubble sorts from being efficient enough on large arrays by not allowing them to go through unnecessary iterations on one specific region (or cluster) before moving onto another section of an array.

**How Cocktail Shaker Sort works?**

1. The first stage loops through the array from left to right, just like the Bubble Sort. During the loop, adjacent items are compared and if the value on the left is greater than the value on the right, then values are swapped. At the end of the first iteration, the largest number will reside at the end of the array.
2. The second stage loops through the array in opposite direction- starting from the item just before the most recently sorted item, and moving back to the start of the array. Here also, adjacent items are compared and are swapped if required.

Now we should look into some practical aspects of cocktails shaker sort.

**Pseudocode**

```pascal
procedure cocktailShakerSort(A : list of sortable items) is
    do
        swapped := false
        for each i in 0 to length(A) − 2 do:
            if A[i] > A[i + 1] then // test whether the two elements are in the wrong order
                swap(A[i], A[i + 1]) // let the two elements change places
                swapped := true
            end if
        end for
        if not swapped then
            // we can exit the outer loop here if no swaps occurred.
            break do-while loop
        end if
        swapped := false
        for each i in length(A) − 2 to 0 do:
            if A[i] > A[i + 1] then
                swap(A[i], A[i + 1])
                swapped := true
            end if
        end for
    while swapped // if no elements have been swapped, then the list is sorted
end procedure
```

**Time and Space** complexity for the Cocktail Shaker Sort algorithm

- **Worst** Case Time Complexity **[ Big-O ]**: **O(n<sup>2</sup>)**
- **Best** Case Time Complexity **[Big-omega]**: **O(n)**
- **Average** Time Complexity **[Big-theta]**: **O(n<sup>2</sup>)**
- **Space** Complexity: **O(1)**

---
