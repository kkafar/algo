class Edge:
    def __init__(self, ver):
        self.vertex = ver
        # self.cost = c
        self.next = None
        self.prev = None


class Queue:
    def __init__(self):
        self.beg = None
        self.end = None


    def push_front(self, ver):
        new_el = Edge(ver)

        # dodajemy pierwszy element do kolejki 
        if self.beg is None and self.end is None: 
            self.beg = new_el
            self.end = new_el

        else: 
            new_el.next = self.beg
            self.beg.prev = new_el
            self.beg = new_el
    
    def push_back(self, ver):
        new_el = Edge(ver)

        # dodajemy pierwszy element do kolejki
        if self.beg is None and self.end is None: 
            self.beg = new_el
            self.end = new_el

        else:
            new_el.prev = self.end
            self.end.next = new_el
            self.end = new_el

    def is_empty(self):
        if self.beg is None:
            return True
        
        else:
            return False

    def pop_front(self):
        # zakłada że kolejka nie jest pusta!

        # gdy mamy tylko 1 element
        if self.beg == self.end:
            ver = self.beg.vertex
            #cost = self.beg.cost
            tmp = self.beg
            self.beg = self.end = None
            del tmp
            return (ver)
        
        else: 
            ver = self.beg.vertex
            #cost = self.beg.cost
            tmp = self.beg
            self.beg = self.beg.next
            self.beg.prev = None
            del tmp
            return (ver)

    def pop_back(self):
        # zakłada że kolejka nie jest pusta!

        # gdy mamy tylko 1 element
        if self.beg == self.end:
            ver = self.beg.vertex
            #cost = self.beg.cost
            tmp = self.beg
            self.beg = self.end = None
            del tmp
            return (ver)

        else:
            ver = self.end.vertex
            #cost = self.end.cost
            tmp = self.end
            self.end = self.end.prev
            self.end.next = None
            del tmp
            return (ver)


    def printq(self):
        tmp = self.beg
        while not (tmp is None):
            print("({})  ".format(tmp.vertex), end="")
            tmp = tmp.next
        # new line
        print()
