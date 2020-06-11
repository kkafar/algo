from random import random

def bubble_sort(arr):
    a = len(arr)
    while a > 0:
        for i in range(0, a - 1):
            if arr[i] >= arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        a -= 1

def bin_search(arr, key):
    p = 0
    q = len(arr) - 1
    while p <= q:
        mid = (p + q) // 2
        if arr[mid] == key: return mid
        elif arr[mid] > key: q = mid - 1
        else: p = mid + 1
        
    return -1
    
def bin_search_rec(arr, key, p, q):
    if p <= q:
        mid = (p + q) // 2
        if key > arr[mid]: return bin_search_rec(arr, key, mid + 1, q)
        elif key < arr[mid]: return bin_search_rec(arr, key, p, mid - 1)
        else: return mid
    
    return -1


if __name__ == '__main__':
    arr = []
    for i in range(9):
        arr.append(int(random() * 1000))
    
    bubble_sort(arr)
    print("arr: ", arr)
    for i in range(9):
        print(bin_search(arr, arr[i]), end=" ")
        print(bin_search_rec(arr, arr[i], 0, len(arr) - 1))
