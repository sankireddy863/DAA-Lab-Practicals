import time

# Merge Function
def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Add remaining elements
    result.extend(left[i:])
    result.extend(right[j:])

    return result


# Merge Sort Function
def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2

    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    return merge(left, right)


# User Input
user_input = input("Enter numbers separated by spaces: ")
arr = list(map(int, user_input.split()))

# Start Time
start_time = time.perf_counter()

# Sorting
sorted_arr = merge_sort(arr)

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
print("Worst Case Time Complexity  : O(n log n)")
print("Space Complexity            : O(n)")
