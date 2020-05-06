# K. Kafara
class ArrQueue:
	'''
	FIFO\n
	Jako argument konstruktora przyjmuje rozmiar kolejki\n
	Dostepne metody: is_empty(), push(), pop(), front() '''
	def __init__(self, size):
		self.size = size
		self.current_size = 0
		self.queue = [0] * size
		self.beg = 0
		self.end = -1

	def is_empty(self):
		''' 
		@return True - jeżeli rozmiar kolejki wynosi 0\n
		@return False - jeżeli rozmiar kolejki != 0 '''
		if self.current_size == 0: 	
			return True
		else: 						
			return False

	def push(self, value):
		''' 
		@brief Dodaje element o kluczu @param value na koniec kolejki. \n
		@warning procedura nie sprawdza czy nie następuje nadpisanie innego elementku kolejki 
		(koniec kolejki obliczany jest modulo rozmiar_kolejki ==> nigdy nie nastąpi próba zapisu poza
		zarezerwowana pamięcią.) '''
		self.current_size += 1
		self.end = (self.end + 1) % self.size
		self.queue[self.end] = value

	def pop(self):
		'''
		@brief Usuwa pierwszy element z kolejki. '''
		self.current_size -= 1
		self.beg = (self.beg + 1) % self.size

	def front(self):
		'''
		@brief Zwraca pierwszy element z kolejki.\n
		@warning Funkcja nie sprawdza poprawności operacji (czy np. nie próbujemy ściągnąć z pustej kolejki).'''
		return self.queue[self.beg]	
