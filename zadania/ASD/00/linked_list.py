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
        "Two way" linked list\n
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


if __name__ == '__main__':
    List = LinkedList()

    for i in range(10):
        List.push_front(i)

    List.print_list()
    print(List.first.val, List.last.val)

    List2 = LinkedList()

    for i in range(10):
        List2.push_back(i)

    List2.print_list()
    print(List2.first.val, List2.last.val)

    


    
