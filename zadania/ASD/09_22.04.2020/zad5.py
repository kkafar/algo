# K. Kafara


"""
Rozw. (GL)
- Wykonać algorytm DFS śledząc czasy przetworzenia wierzchołków. O(V + E)
- Wykonać algorytm DFS z wierzchołka o największym czasie przetworzenia. O(V + E)
- Jeżeli uda się dowiedzić wszystkie wierzchołki to wyznaczyliśmy dobry początek. (Jest nim korzeń drugiego wywołania)

Czas: 2 * O(V + E) + O(V) == O(V + E)
                      ^ (na zerowanie pól visited w drugim przebiegu dfs'a / rezerwowanie tablicy w dfs)

Dlaczego to działa? 
Jeżeli w czasie wywołania DFS z jednego z wierzchołków natrafimy na 'dobry początek' - to w tym wywołaniu 
przeglądniemy graf do końca, ponieważ z 'dobrego początku' mamy dojście wszędzie - do każdego nieodwiedzonego jeszcze wierzchołka. 
Zatem jeżeli istnieje dobry początek, to znajduje się on w 'ostatnim' drzewie przeszukiwań DFS. 
Co więcej skoro z korzenia drzewa DFS doszliśmy do 'dobrego początku', to dobrym początkiem równie dobrze może być sam korzeń
(z założenia istnieje ścieżka 'dobry początek' -> korzeń, a przeglądając graf stwierdzamy, że istnieje korzeń -> 'dobry początek')
Korzeń ostatniego drzewa DFS ma największy czas przetworzenia (!) ==> jest to nasz kandydat na 'dobry początek'.  
Pozostaje to zweryfikować wykonując kolejne wykonanie algorytmu DFS na grafie z wytypowanego wierzchołka. Jeżeli uda nam się odwiedzić wszystkie
wierzchołki - to mammy wyznaczony 'dobry początek', wpp. takowy nie istnieje. 

O(V + E)'''
