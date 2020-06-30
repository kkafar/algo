# K. Kafara

''' Zakładam, że działamy na grafie z wagami jednostkowymi (nie jest sprecyzowane w zadaniu) 

Plan jest następujący: 
1. Wyznaczyć wszystkie najkrótsze ścieżki prowadzące z wierzchołka s do wierzchołka t. (nie trzeba znać konkretnie ścieżek, wystarczy
zdobyć informację które krawędzie wchodzą w ich skład)
2. Zbudować graf z wyznaczonych krawędzi. (ewentualnie oznaczyć te krawędzie i operować na wyjściowym grafie)
3. Sprawdzić czy istnieje most. 
4.1 Jeżeli most istnieje ==> jest to właśnie krawędź którą możemy zabrać i długość najkrótszej ścieżki z s do t się wydłuży. 
4.2 Jeżeli mostu nie ma ==> nie istnieje krawędź, której zabranie powoduje wydłużenie najkrótszej ścieżki z s do t. 

Trzeba też odpowiednio reagować w sytuacji kiedy ścieżka w ogóle nie istnieje. 

Budowa grafu oraz stwierdzenie istnienia mostu: O(V + E)
Problemem jest wyznaczenie wszystkich krawędzi wchodzących w skład najkrótszych ścieżek. 

Można to robić lekko zmodyfikowanym BFS'em w sposób opisany poniżej. 

d(v) <-- odległośc wierzchołka v od źródła

min_len := +∞ (oznacza długość najkrótszej ścieżki z s do t)

1. Rozpoczynamy przechodzenie w stylu BFS'a od wierzchołka s. 
Pamiętajmy o ważnej własności bfs'a: w momencie ściągnięcia dowolnego wierzchołka v z kolejki d(v) ma możliwie minimalną wartość.

2. Ściągamy wierzchołek v z kolejki. Oznaczamy go jako "odwiedzonego" ==> d(v) jest wyznaczone poprawnie.
3. Przeglądamy jego sąsiadów u: 
    3.1 Jeżeli u == t oraz d(v) < min_len:
        3.1.1   min_len := d(v) + 1
        3.1.2   Dokonujemy przejścia po krawędziach prowadzących do rodziców oznaczając kolejne krawędzie jako należące do "grafu najkrótszych ścieżek" (GNS)
                tak długo aż nie napotkamy już oznaczonej krawędzi lub wierzchołka s. 
    3.2 Jeżeli d(u) ( = d(v) + 1 ) < min_len:
        3.2.1   Ustawiamy informacje o rodzicu, odległości itd.
        3.2.2   Dodajemy u do kolejki 
4. Powtarzamy 2,3 do momentu gdy kolejka będzie pusta.

Następnie sprawdzamy (rozważając tylko te oznaczone krawędzie, czy istnieje most (w zwykły sposób, obliczając parametr low).
Jeżeli znajdziemy choć jeden most ==> możemy przerwać działanie algorytmu i odpowiedzieć na pytanie postawione w zadaniu.  '''
