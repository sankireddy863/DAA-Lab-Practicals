import time

# Insertion Sort Function
def insertion_sort(arr):
    n = len(arr)

    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

    return arr


# User Input
user_input = input("Enter numbers separated by spaces: ")
arr = list(map(int, user_input.split()))

# Check if already sorted
is_sorted = arr == sorted(arr)

# Start Time
start_time = time.perf_counter()

# Sorting
sorted_arr = insertion_sort(arr)

# End Time
end_time = time.perf_counter()

# Execution Time
execution_time = end_time - start_time

# Output
print("\nSorted Array:", sorted_arr)
print("Execution Time: {:.10f} seconds".format(execution_time))

# Time Complexity
if is_sorted:
    print("Best Case Time Complexity: O(n)")
else:
    print("Average/Worst Case Time Complexity: O(n²)")

print("Space Complexity: O(1)")
