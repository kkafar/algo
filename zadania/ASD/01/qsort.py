from random import random


def partition(arr, p, q):
    pivot = arr[q]
    i = p - 1

    for j in range(p, q):
        if arr[j] <= pivot:
            i += 1
            arr[j], arr[i] = arr[i], arr[j]

    arr[i + 1], arr[q] = arr[q], arr[i + 1]
    return i + 1


def qsort(arr, p, q):
    if p < q:
        x = partition(arr, p, q)
        qsort(arr, p, x - 1)
        qsort(arr, x + 1, q)


if __name__ == "__main__":
    arr = [int(random() * 1000) for i in range(0, 10)]
    print(arr)
    qsort(arr, 0, len(arr) - 1)
    print(arr)
