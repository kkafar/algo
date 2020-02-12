def min_max_value(array):
	""" Jednoczesne wyszukiwanie min i max. 
		Zwraca krotkę: (min_value, max_value) """
	#######################################################
	# do algorytmu jednoczesnego wyszukiwania min i max potrzebujemy mieć parzystą ilość elementów w tablicy
	# ==> jeżeli jest nieparzysta to powielamy ostatni element. Potem go usuniemy ( w tym celu ustawiamy flagę - żeby widzieć czy usuwać)
	
	# jeszcze jest problem z reprezentowaniem nieskończonośći: roboczo zróbmy to tak:
	min_value = 100000000
	max_value = -100000000

	flag = False
	if len(array) % 2 == 1:
		array.append(array[-1])
		flag = True
	
	# iterujemy z krokiem 2
	for i in range(0, len(array), 2):
		if array[i] > array[i + 1]:
			# to array[i] jest potencjalnym kandydatem na max_value, 
			# natomiast array[i + 1] jest potencjalnym kandydatem na min_value
			if array[i] > max_value:
				max_value = array[i]
			if array[i + 1] < min_value: 
				min_value = array[i + 1]
		else:
			if array[i] < min_value:
				min_value = array[i]
			if array[i + 1] > max_value:
				max_value = array[i + 1]

	if flag == True: 
		array.pop()

	return (min_value, max_value)
	#######################################################
	

if __name__ == '__main__':
	array = [5, 3, 1, 2, 6, 7, 0, 9]
	print(array)
	print(min_max_value(array))
