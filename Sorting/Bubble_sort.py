import time

# Bubble Sort Function
def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        swapped = False

        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # If no swapping happened, array is already sorted
        if not swapped:
            break

    return arr


# User Input
user_input = input("Enter numbers separated by spaces: ")
arr = list(map(int, user_input.split()))

# Start Time
start_time = time.perf_counter()

# Sorting
sorted_arr = bubble_sort(arr)

# End Time
end_time = time.perf_counter()

# Execution Time
execution_time = end_time - start_time

# Output
print("\nSorted Array:", sorted_arr)
print("Execution Time: {:.10f} seconds".format(execution_time))

# Time Complexity
if arr == sorted(arr):
    print("Best Case Time Complexity: O(n)")
else:
    print("Average/Worst Case Time Complexity: O(n²)")

print("Space Complexity: O(1)")
