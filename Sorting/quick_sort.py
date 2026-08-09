import time

# Quick Sort Function
def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]

    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)


# User Input
user_input = input("Enter numbers separated by spaces: ")
arr = list(map(int, user_input.split()))

# Start Time
start_time = time.perf_counter()

# Sorting
sorted_arr = quick_sort(arr)

# End Time
end_time = time.perf_counter()

# Execution Time
execution_time = end_time - start_time

# Output
print("\nSorted Array:", sorted_arr)
print("Execution Time: {:.10f} seconds".format(execution_time))

# Time Complexity
print("Best Case Time Complexity   : O(n log n)")
print("Average Case Time Complexity: O(n log n)")
print("Worst Case Time Complexity  : O(n²)")
print("Space Complexity            : O(log n) (recursive stack)")
