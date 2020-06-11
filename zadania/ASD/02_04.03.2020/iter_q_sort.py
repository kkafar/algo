from random import random
from Stack import Stack
from Stack import Node


def partition(arr, p, q):
    pvt = arr[q]
    i = p - 1

    for j in range(p, q, 1):
        if arr[j] <= pvt:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[q] = arr[q], arr[i + 1]

    return i + 1


def iter_qsort(arr, p, q):
    if p > q:
        return None

    task = Stack()
    # pamietac zeby sciagac zadania w odwrotnej kolejnosci!
    task.push(q)
    task.push(p)

    while not task.empty():
        l = task.pop()
        r = task.pop()
        if l < r:
            s = partition(arr, l, r)
            task.push(s-1)
            task.push(l)
            task.push(r)
            task.push(s+1)


if __name__ == "__main__":
    arr = [int(random() * 1000) for i in range(10)]
    print(arr)
    iter_qsort(arr, 0, len(arr) - 1)
    print(arr)
    
