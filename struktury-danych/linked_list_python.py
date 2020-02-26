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
        @method print(self)\n
        @method sort(self, beg, end)\n
        @method pop_front(self)\n
        @method pop_back(self)\n
        @method insert(self, key)
        @method copy(self)
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


    def insert(self, key):
        """
            Inserts element in to the sorted list\n
            @param key -  value to insert
        """
        if self.first == None:
            self.first = Node()
            self.first.val = key
            self.last = self.first

        else:
            elem = self.first
            sen = Node()
            sen.val = key
            self.last.next = sen
            
            while key > elem.next.val:
                elem = elem.next
            
            if elem == self.last:
                return
            
            elif elem == self.first:
                self.last.next = None
                sen.next = self.first
                self.first = sen

            else:
                self.last.next = None
                sen.next = elem.next
                elem.next = sen


    def print(self):
        """
            Prints whole list in format: val0->val1->…->valn->None + new_line
        """
        if self.first == None: print("{ }")
        else:
            print("{ ", end="")
            elem = self.first
            while elem != None:
                # wiem, że można to zrobić dobrze :O 
                if elem.next != None:
                    print(elem.val, end=", ")
                    elem = elem.next
                else:
                    print(elem.val, end=" }\n")
                    elem = elem.next



    def pop_front(self):
        """
            Removes first element from the list\n
        """
        if self.first == None: return
        
        else:
            tmp = self.first
            self.first = self.first.next
            del tmp
    

    def pop_back(self):
        """
            Removes last element from the list
        """
        if self.first == None: None
        
        elif self.first == self.last:
            tmp = self.first
            self.first, self.last = None, None
            del tmp
        
        else:
            elem = self.first
            
            while elem.next != self.last:
                elem = elem.next
            
            elem.next = None
            tmp = self.last
            self.last = elem
            del tmp
        

    def copy(self):
        copied = LinkedList()
        tmp = self.first
        while tmp != None:
            copied.push_back(tmp.val)
            tmp = tmp.next
        return copied

    # MERGE SORT
    ######################################
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
            Sorts list in ascending order using merge sort algorithm\n
            @param beg - first elem. of the to-be-sorted list (or first elem. of the fragment of the to-be-sorted-list)\n
            @param end - last elem of the to-be-sorted list (or last elem. of the fragment of the to-be-sorted list)
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
    ######################################
