import time

# Selection Sort Function
def selection_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        min_index = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # Swap the minimum element with the current element
        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr


# User Input
user_input = input("Enter numbers separated by spaces: ")
arr = list(map(int, user_input.split()))

# Start Time
start_time = time.perf_counter()

# Sorting
sorted_arr = selection_sort(arr)

# End Time
end_time = time.perf_counter()

# Execution Time
execution_time = end_time - start_time

# Output
print("\nSorted Array:", sorted_arr)
print("Execution Time: {:.10f} seconds".format(execution_time))

# Time Complexity
print("Best Case Time Complexity   : O(n²)")
print("Average Case Time Complexity: O(n²)")
print("Worst Case Time Complexity  : O(n²)")
print("Space Complexity            : O(1)")
