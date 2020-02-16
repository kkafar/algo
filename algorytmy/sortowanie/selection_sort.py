def selection_sort(list):
    """ 
        @brief Sorts given list.\n 
        @param list - to-be-sorted list
    """
    for i in range(0, len(list)):
        min_val_i = i
        for j in range(i+1, len(list)):
            if list[j] < list[min_val_i]:
                min_val_i = j
        list[i], list[min_val_i] = list[min_val_i], list[i]

if __name__ == '__main__':
    array = [7, 6, 5, 4, 3, 9, 1]
    print(array)
    selection_sort(array)
    print(array)
