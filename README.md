# Algorithms [![C++ Logo](/utilities/images/cpp_logo.png "C++ Logo")](https://isocpp.org/get-started)

## This repository contains

- [Sorting algorithm](#sorting-algorithm)
  - [Exchange Sort](#exchange-sort) 
    - [Bubble Sort](#bubble-sort-algorithm) -> [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/bubble_sort.cc)
    - [Optimized Bubble Sort](#optimized-bubble-sort-algorithm) -> [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/optimized_bubble_sort.cc)
    - [Cocktail Shaker Sort](#cocktail-shaker-sort-algorithm) -> [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/cocktail_shaker_sort.cc)
    - [Odd Even Sort](#odd-even-sort-algorithm) -> [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/odd_even_sort.cc)

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
  - Integer sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/bubble_sort.cc#L29)
  - String sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/bubble_sort.cc#L54)

**What is this?**

Bubble sort, aka sinking sort is a basic algorithm for arranging a string of numbers or other elements in the correct order. This sorting algorithm is comparison-based algorithm in which each pair of adjacent elements is compared and the elements are swapped if they are not in order. The algorithm then repeats this process until it can run through the entire string or other elements and find no two elements that need to be swapped. This algorithm is not suitable for large data sets as its average and worst case complexity are of Ο(n<sup>2</sub>) where n is the number of items.

**In general**, Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. Therefore, it is called a bubble sort.

**How Bubble Sort Works?**

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
  - Integer sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/optimized_bubble_sort.cc#L29)
  - String sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/optimized_bubble_sort.cc#L60)

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
  - Integer sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/cocktail_shaker_sort.cc#L29)
  - String sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/cocktail_shaker_sort.cc#L94)

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

### Odd Even Sort Algorithm

- Code snippets
  - Integer sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/odd_even_sort.cc#L29)
  - String sort - [:page_facing_up: :link:](sorting_algorithms/exchange_sorts/odd_even_sort.cc#L68)

**What is it?**

This is basically a variation of bubble-sort. This algorithm is divided into two phases- Odd and Even Phase. The algorithm runs until the array elements are sorted and in each iteration two phases occurs- Odd and Even Phases.
In the odd phase, we perform a bubble sort on odd indexed elements and in the even phase, we perform a bubble sort on even indexed elements.

**How Odd Even Sort works?**

1. It compares two adjacent numbers and switches them, if the first number is greater than the second number to get an ascending order list.
2. The opposite case applies for a descending order series.
3. Odd-Even transposition sort operates in two phases − odd phase and even phase.
4. In both the phases, processes exchange numbers with their adjacent number in the right.

Now we should look into some practical aspects of cocktails shaker sort.

**Pseudocode**

```pascal
procedure ODD-EVEN_PAR (n) 

begin 
   id := process's label 
	
   for i := 1 to n do 
   begin 
	
      if i is odd and id is odd then 
         compare-exchange_min(id + 1); 
      else 
         compare-exchange_max(id - 1);
			
      if i is even and id is even then 
         compare-exchange_min(id + 1); 
      else 
         compare-exchange_max(id - 1);
			
   end for
	
end ODD-EVEN_PAR
```

**Time and Space** complexity for the Cocktail Shaker Sort algorithm

- **Worst** Case Time Complexity **[ Big-O ]**: **O(n<sup>2</sup>)**
- **Best** Case Time Complexity **[Big-omega]**: **O(n)**
- **Average** Time Complexity **[Big-theta]**: **O(n<sup>2</sup>)**
- **Space** Complexity: **O(1)**

---
