# implementacja funkcji scalającej bez wartownika (bo w pythonie nie ma defacto "MAX_INT'a")
def merge(list, lbeg, lend, rend):
    """ """
    rbeg = lend+1
    list_len = rend - lbeg + 1
    left_list = []
    right_list = []
    l_iter = 0
    r_iter = 0
    # przepisanie tablic
    for i in range(lbeg, lend+1):
        left_list.append(list[i])
    for i in range (lend+1, rend+1):
        right_list.append(list[i])
    
    while l_iter < len(left_list) and r_iter < len(right_list):
        if left_list[l_iter] < right_list[r_iter]:
            list[lbeg] = left_list[l_iter]
            l_iter += 1
        else: 
            list[lbeg] = right_list[r_iter]
            r_iter += 1
        lbeg += 1

    while l_iter < len(left_list):
        list[lbeg] = left_list[l_iter]
        lbeg += 1
        l_iter += 1

    while r_iter < len(right_list):
        list[lbeg] = right_list[r_iter]
        lbeg += 1
        r_iter += 1

def merge_sort(list, beg, end):
    if beg < end:
        mid = (beg + end) // 2
        merge_sort(list, beg, mid)
        merge_sort(list, mid + 1, end)
        merge(list, beg, mid, end)            




if __name__ == '__main__':
    array = [7, 5, 3, 6, 2, 9]
    print(array)
    merge_sort(array, 0, len(array) - 1)
    print(array)
