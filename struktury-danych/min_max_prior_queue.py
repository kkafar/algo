# K. Kafara
class MaxPriorityQueue:
    '''
    @brief Kolejka priotrytetowa (MAX). Realizwana za pomocą "Pythonowej" listy. 
    @method push(obj, prior)
    @method pop()
    @method front()
    @method is_empty() '''
    class QueueElement:
        def __init__(self, obj, prior):
            self.obj = obj
            self.prior = prior

    def __init__(self):
        self.size = 0
        self.queue = []

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return 2 * i + 1

    def right(self, i):
        return 2 * i + 2

    def push(self, obj, prior):
        '''
        @brief Dodajem objekt @param obj do kolejki z priorytetem @param prior '''
        index = self.size
        # jeżeli jest wymagane poszerzenie listy
        if self.size == len(self.queue):
            self.size += 1
            self.queue.append(self.QueueElement(obj, prior))

        # jeżeli nie trzeba poszerzać listy (ponieważ usunęliśmy jakies elmenty i jest miejsce)
        else:
            self.size += 1
            self.queue[index].obj = obj
            self.queue[index].prior = prior

        while self.parent(index) >= 0 and self.queue[ self.parent(index) ].prior < prior:
            self.queue[ self.parent(index) ], self.queue[index] = self.queue[index], self.queue[ self.parent(index) ]
            index = self.parent(index)


    def print(self):
        for i in range(self.size):
            print("(obj={}, prior={})".format(self.queue[i].obj, self.queue[i].prior), end=' ')
        print()

    def is_empty(self):
        if self.size == 0: return True
        else: return False
    
    def heapify(self, i):
        largest = i
        while i < self.size:
            left = self.left(i)
            right = self.right(i)

            if left < self.size and self.queue[left].prior > self.queue[largest].prior:
                largest = left
            
            if right < self.size and self.queue[right].prior > self.queue[largest].prior:
                largest = right

            if largest != i:
                self.queue[i], self.queue[largest] = self.queue[largest], self.queue[i]
                i = largest
            
            else:
                break


    def pop(self):
        '''
        @brief Usuwa element z najwyższym priorytetem z kolejki. '''
        self.size -= 1
        self.queue[0], self.queue[self.size] = self.queue[self.size], self.queue[0]
        self.heapify(0)

    def front(self):
        '''
        @brief Zwraca element z najwyższym priorytetem z kolejki. '''
        return self.queue[0].obj


class MinPriorityQueue:
    '''
    @brief Kolejka priotrytetowa (MIN). Realizwana za pomocą "Pythonowej" listy. 
    @method push(obj, prior)
    @method pop()
    @method front()
    @method is_empty() '''
    class QueueElement:
        def __init__(self, obj, prior):
            self.obj = obj
            self.prior = prior

    def __init__(self):
        self.size = 0
        self.queue = []

    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return 2 * i + 1

    def right(self, i):
        return 2 * i + 2

    def push(self, obj, prior):
        '''
        @brief Dodajem objekt @param obj do kolejki z priorytetem @param prior '''
        index = self.size
        # jeżeli jest wymagane poszerzenie listy
        if self.size == len(self.queue):
            self.size += 1
            self.queue.append(self.QueueElement(obj, prior))

        # jeżeli nie trzeba poszerzać listy (ponieważ usunęliśmy jakies elmenty i jest miejsce)
        else:
            self.size += 1
            self.queue[index].obj = obj
            self.queue[index].prior = prior

        while self.parent(index) >= 0 and self.queue[ self.parent(index) ].prior > prior:
            self.queue[ self.parent(index) ], self.queue[index] = self.queue[index], self.queue[ self.parent(index) ]
            index = self.parent(index)


    def print(self):
        for i in range(self.size):
            print("(obj={}, prior={})".format(self.queue[i].obj, self.queue[i].prior), end=' ')
        print()

    def is_empty(self):
        if self.size == 0: return True
        else: return False
    
    def heapify(self, i):
        largest = i
        while i < self.size:
            left = self.left(i)
            right = self.right(i)

            if left < self.size and self.queue[left].prior < self.queue[largest].prior:
                largest = left
            
            if right < self.size and self.queue[right].prior < self.queue[largest].prior:
                largest = right

            if largest != i:
                self.queue[i], self.queue[largest] = self.queue[largest], self.queue[i]
                i = largest
            
            else:
                break


    def pop(self):
        '''
        @brief Usuwa element z najwyższym priorytetem z kolejki. '''
        self.size -= 1
        self.queue[0], self.queue[self.size] = self.queue[self.size], self.queue[0]
        self.heapify(0)

    def front(self):
        '''
        @brief Zwraca element z najwyższym priorytetem z kolejki. '''
        return self.queue[0].obj


if __name__ == '__main__':
    #pqueue = MaxPriorityQueue()
    pqueue = MinPriorityQueue()
    pqueue.push(3, 10)
    pqueue.push(1, 15)
    pqueue.push(-3, 0)

    pqueue.print()

    pqueue.push(-10, 20)

    pqueue.print()

    pqueue.pop()
    pqueue.pop()

    pqueue.push(50, 50)

    pqueue.print()

    pqueue.pop()

    pqueue.print()



