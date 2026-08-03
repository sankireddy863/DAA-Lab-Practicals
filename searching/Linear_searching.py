#  linear_search

def linear_search_all(arr, target):
    positions = []

    for i in range(len(arr)):
        if arr[i] == target:
            positions.append(i)

    return positions

# Example
arr = [5, 3, 7, 3, 9, 3]
target = 3

result = linear_search_all(arr, target)

if result:
    print("Element found at indices:", result)
else:
    print("Element not found")
