# K. Kafara



class ArrMaxHeap:
    ''' Przyjmujemy dość niewygodnie indeksowanie od 0 (aby można było inicjalizować stos bez przepisywania 
        całej podanej tablicy)'''
    def __init__(self, size):
        self.size = size
        self.current_size = 0
        self.heap = None

    def left(self, index):
        return 2 * index + 1
    
    def right(self, index):
        return 2 * index + 2
    
    def parent(self, index):
        ''' Dla index == 0 zwraca -1 !!!! '''
        return (index - 1) // 2

    def heapify(self, index):
        left = self.left(index)
        right = self.right(index)
        largest = index
        
        if left < self.current_size and self.heap[left] > self.heap[largest]:
            largest = left
        
        if right < self.current_size and self.heap[right] > self.heap[largest]:
            largest = right
        
        if largest != index:
            self.heap[largest], self.heap[index] = self.heap[index], self.heap[largest]
            self.heapify(largest)

    def build_heap(self):
        for i in range((self.current_size - 1)// 2, -1, -1):
            self.heapify(i)

    def load_arr(self, arr):
        self.heap = arr
        self.current_size = len(arr)

    def load_from_arr(self, arr):
        self.heap = [None] * len(arr)
        for i in range(self.size):
            self.heap[i] = arr[i]
        self.current_size = len(arr)
        

    def print(self):
        print(self.heap)

class ArrMinHeap:
    def __init__(self, size):
        self.size = size
        self.current_size = 0
        self.heap = None

    def left(self, index):
        return 2 * index + 1
    
    def right(self, index):
        return 2 * index + 2
    
    def parent(self, index):
        ''' Dla index == 0 zwraca -1 !!!! '''
        return (index - 1) // 2

    def heapify(self, index):
        left = self.left(index)
        right = self.right(index)
        smallest = index
        
        if left < self.current_size and self.heap[left] < self.heap[smallest]:
            smallest = left
        
        if right < self.current_size and self.heap[right] < self.heap[smallest]:
            smallest = right
        
        if smallest != index:
            self.heap[smallest], self.heap[index] = self.heap[index], self.heap[smallest]
            self.heapify(smallest)

    def build_heap(self):
        for i in range((self.current_size - 1)// 2, -1, -1):
            self.heapify(i)

    def load_arr(self, arr):
        self.heap = arr
        self.current_size = len(arr)

    def load_from_arr(self, arr):
        self.heap = [None] * len(arr)
        for i in range(self.size):
            self.heap[i] = arr[i]
        self.current_size = len(arr)
        
    def print(self):
        print(self.heap)


if __name__ == '__main__':
    size = 10
    arr = []
    heap = ArrMaxHeap(size)
    for i in range(size):
        arr.append(int(input()))

    heap.load_arr(arr)
    heap.build_heap()

    heap.print()
    print(heap.current_size, heap.size)
    
    min_heap = ArrMinHeap(size)
    min_heap.load_arr(arr)
    min_heap.build_heap()

    heap.print()
    
    
