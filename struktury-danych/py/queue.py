class Queue:
    ''' Kolejka. Dostępne metody:\n
    is_empty()\n
    push(element)\n
    pop()\n
    front()\n
    print()\n '''

    class QueueElement:
        def __init__(self, value = None, next_el = None, prev_el = None):
            self.value = value
            self.next = next_el
            self.prev = prev_el


    def __init__(self):
        self.head = self.QueueElement()
        self.tail = self.QueueElement()
        self.size = 0


    def push(self, element):
        ''' Dodaje element na początek kolejki ''' 
        if self.size == 0:
            new_el = self.QueueElement(element)
            self.head.next = new_el
            self.tail.prev = new_el

        else:
            new_el = self.QueueElement(element, None, self.tail.prev)
            self.tail.prev.next = new_el
            self.tail.prev = new_el

        self.size += 1



    def is_empty(self):
        ''' Zwraca True jeżeli kolejka jest pusta, False wpp. '''
        if self.size == 0:
            return True
        else:
            return False


    def pop(self):
        ''' Usuwa pierwszy element z kolejki. Należy upewnić się, że nie następuje usuwanie z pustej kolejki ''' 
        del_el = self.head.next
        if self.size == 1:
            self.head.next = None
            self.tail.prev = None
            del del_el

        else:
            self.head.next = self.head.next.next
            del del_el
    
        self.size -= 1


    def front(self):
        ''' Zwraca pierwszy element z kolejki. Jeżeli kolejka jest pusta to zwraca None '''
        if self.head.next is None:
            return None
        else:
            return self.head.next.value

    def print(self):
        print('Queue size: {}'.format(self.size), end=' ')
        print('[ ', end='')
        
        aux = self.head.next
        while aux is not None:
            print(aux.value, end=' ')
            aux = aux.next

        print(']')
    