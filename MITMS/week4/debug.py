def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) / 2
    left = merge_sort(arr[0:mid])
    right = merge_sort(arr[mid:-1])
    return merge(left, right)

def merge(left, right):
    result = []
    i = 0
    j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i = i + 1
        else:
            result.append(right[i])
            j = j + 1
    result.append(left)
    result.append(right)
    return result

if __name__ == "__main__":
    print(merge_sort([[3, 1, 4, 1, 5, 9, 2, 6]]))