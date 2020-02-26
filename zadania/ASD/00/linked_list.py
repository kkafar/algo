from random import random


class Node:
    """
        Represents singular node in LinkedList\n
        @attribute val - value in node\n
        @attribute next - I don't know what it actually is in Python language, some kind of pointer to next node in list          
    """
    def __init__(self):
        """
            Sets class attributes to None
        """
        self.val = None
        self.next = None

class LinkedList:
    """
        "One way" linked list\n
        @attribute first - first object in the list\n
        @attribute last - last object in the list\n\n
        @method push_front(self, key)\n
        @method push_back(self, key)\n
        @method prin_list(self)
    """
    def __init__(self):
        """
            Sets class attributes to None
        """
        self.first = None
        self.last = None

    def push_front(self, key):
        """
            Inserts new Node in front of the list\n
            @param key - value to be inserted
        """
        if self.first == None:
            self.first = Node()
            self.first.val = key
            self.last = self.first
        
        else: 
            new_node = Node()
            new_node.val = key
            new_node.next = self.first
            self.first = new_node

    def push_back(self, key):
        """
            Inserts new node in the end of the list\n
            @param key - value to be inserted
        """
        if self.last == None:
            self.last = Node()
            self.last.val = key
            self.first = self.last
        
        else:
            new_node = Node()
            new_node.val = key
            self.last.next = new_node
            self.last = new_node

    def print_list(self):
        """
            Prints whole list in format: val0->val1->…->valn->None + new_line
        """
        elem = self.first
        while elem != None:
            print(elem.val, end="->")
            elem = elem.next
        print("None")

    def merge(self, l_beg, l_end, r_end):
        aux_list = LinkedList()
        left = l_beg
        right = l_end.next
        
        while left != l_end.next and right != r_end.next:
            if left.val <= right.val: 
                aux_list.push_back(left.val)
                left = left.next
            else:
                aux_list.push_back(right.val)
                right = right.next

        while left != l_end.next:
            aux_list.push_back(left.val)
            left = left.next
        
        while right != r_end.next:
            aux_list.push_back(right.val)
            right = right.next
            
        left = l_beg
        aux = aux_list.first
        while left != r_end.next:
            left.val = aux.val
            left = left.next
            aux = aux.next


    def sort(self, beg, end):
        """
            Sorts list in ascending order using merge sort algorithm
        """
        if beg != end:
            # Jak wyznaczyć "środek" tego przedziału [beg, end]????
            # Albo jak to robić inaczej po prostu, bo wyznaczanie środka w ten sposób 
            # to jest wręcz złe rozwiązanie
            it = beg
            count = 0

            while it != end:
                it = it.next
                count += 1
            
            count = count // 2
            new_count = 0
            it = beg
           
            while new_count < count:
                it = it.next
                new_count += 1
            ##############################################
            self.sort(beg, it)
            self.sort(it.next, end)

            self.merge(beg, it, end)


if __name__ == '__main__':
    List = LinkedList()

    for i in range(10):
        List.push_front(int(random() * 100))

    List.print_list()
    # print(List.first.val, List.last.val)
    
    List.sort(List.first, List.last)
    List.print_list()

    


    
