def bubble_sort(array):
	""" Sortowanie babelkowe, idea:
		Porównujemy array[i] z array[i + 1], jeżeli array[i] >= array[i + 1] to zamieniamy je miejscami, i += 1. 
		W ten sposób bo każdym przebiegu przez tablicę na samym końcu znajdzie się najwiekszy element ==> 
		nie musimy przeglądać tablicy do końca (po pierwszym przebiegu na ostatnim miejscu znajduje się największy, po drugim, na przedostatniej
		pozycji znajduje sie drugi największy itd.)
	""" 
	a = len(array)
	while a > 0:
		for i in range(a - 1):
			if array[i] >= array[i + 1]:
				array[i], array[i + 1] = array[i + 1], array[i]
		a -= 1

if __name__ == '__main__':
	array = [5, 3, 1, 2, 6, 7, 0, 9]
	bubble_sort(array)
	print(array)
