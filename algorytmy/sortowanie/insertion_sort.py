def insertion_sort(array):
    """ Sorts the given list """
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and key < array[j]:
                array[j+1] = array[j]
                j -= 1
        array[j + 1] = key

if __name__ == '__main__':
    array = [7, 5, 3, 6, 2, 9]
    print(array)
    insertion_sort(array)
    print(array)
