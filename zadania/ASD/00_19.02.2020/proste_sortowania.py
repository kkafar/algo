from random import random

def bubble_sort(arr):
    a = len(arr)
    while a > 0:
        for i in range(0, a - 1):
            if arr[i] >= arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        a -= 1

def selection_sort(arr):
    """
         Each iteration we look for biggest element in array, and we swap it with
        ( len(arr) - number_of_iterations ) 
    """
    leng = len(arr)
    while leng > 0:
        max_i = 0
        for i in range(leng):
            if arr[i] > arr[max_i]: max_i = i
        arr[leng - 1], arr[max_i] = arr[max_i], arr[leng - 1]
        leng -= 1

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key: 
            arr[j + 1], arr[j] = arr[j], arr[j + 1]
            j -= 1
        arr[j + 1] = key

if __name__ == '__main__':
    arr = []
    for i in range(9):
        arr.append(int(random() * 100))

    print("arr: ", arr)

    arr2 = arr.copy()
    arr3 = arr.copy()
    arr4 = arr.copy()

    bubble_sort(arr2)
    selection_sort(arr3)
    insertion_sort(arr4)

    print("arr2", arr2)
    print("arr3", arr3)
    print("arr4", arr4)
    
