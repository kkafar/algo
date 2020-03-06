from random import random


def merge(arr, p, q, r): 
    """ 
        Merging two sorted parts of array arr. It changes order of elem. in arr\n
        @param arr - array from which we get sub arrays to be merged\n
        @param p\n
        @param q\n
        @param r
    """
    print("merge wywolanie: {}, {}, {}".format(p, q, r))
    print("subarr: ", arr[p:(r + 1)])
    j = q + 1
    i = p
    # Raczej przerobić by to lepiej na append'a ? done
    aux_arr = []

    while i <= q and j <= r: 
        if arr[i] <= arr[j]:
            aux_arr.append(arr[i])
            i += 1
        else:
            aux_arr.append(arr[j])
            j += 1
        
    while i <= q:
        aux_arr.append(arr[i])
        i += 1
    
    while j <= r:
        aux_arr.append(arr[j])
        j += 1

    i = p
    aux = 0

    while i <= r:
        arr[i] = aux_arr[aux]
        i += 1
        aux += 1


def m_sort(arr): 
    """  """
    if len(arr) <= 1: None
    else: 
        arr_len = len(arr)
        step = 2
        # te 2 zmienne są wyjęte, żeby je widzieć poza pętlami (potrzebene na końcu)
        left = 0
        right = step - 1
        while step <= arr_len:
            left = 0
            right = step - 1

            while left < (arr_len - 1):
                merge(arr, left, (left + right) // 2, right)
                left += step
                right += step
                if right >= arr_len:
                    right = arr_len - 1    
            step *= 2
        # no brzydkie to, ale niby działa
        merge(arr, 0, (left - (step // 2) - 1), arr_len - 1)


if __name__ == "__main__":
    arr = [ int(random() * 1000) for i in range(10)]
    print(arr)
    m_sort(arr)
    print(arr)
