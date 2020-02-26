from random import random

def bubble_sort(arr):
    a = len(arr)
    while a > 0:
        for i in range(0, a - 1):
            if arr[i] >= arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        a -= 1

def interpol_search(arr, key):
    """
        Returns index of an element with key 'key'.
        If element is not found, returns -1\n
        Array must be sorted\n
        @param arr - array to look in for a element\n
        @param key - …

    """
    p = 0
    q = len(arr) - 1

    while key >= arr[p] and key <= arr[q]:
        index = ((key - arr[p]) * (q - p)) // (arr[q] - arr[p]) + p

        if key == arr[index]: return index
        elif key > arr[index]: p = index + 1
        else: q = index - 1
    
    return -1



if __name__ == '__main__':
    arr = []

    for i in range(10):
        arr.append(int(random() * 1000))
    
    print(arr)
    bubble_sort(arr)
    print(arr)

    for i in range(10): 
        print(i, interpol_search(arr, arr[i]))



    


    
