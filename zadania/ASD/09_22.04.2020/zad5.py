# K. Kafara


"""
Przemyślenia: 

* Można wykorzystać algorytm Floyda-Warshalla O(V^3) a następnie przglądnąć
macierz najkrótszych ścieżek - jeżeli znaleźlibyśmy wiersz w bez żadnej nieskończoności 
to by oznaczało, że z wierzchołka w możemy dotrzeć do każdego innego. O(V^2) ==> ostatecznie O(V^3)

* Można by też V-krotnie puścić Dijkstrę lub Bellmana-Forda, ale wtedy dla grafów gęstych (E ~ V^2) 
stracilibyśmy górne ograniczenie O(V^3), choć dla grafów rzadkich (E ~ V) czas byłby lepszy. (+ korzystanie z 
reprezentacji listowej byłoby wydajniejsze dla algorytmów)

* Nie mam pojęcia czy można to zrobić lepiej. Być może nie trzeba przeprowadzać aż tyle relaksacji? 

* Puścić V razy DFSa? Jeżeli w którymś wywołaniu odwiedzimy wszytkie wierzcholki (można je zliczać) to zwracamy True
w innym przypadku False. O(V(V + E)) == O(V^2 + EV) co dla grafów gęstych daje O(V^3) 

* Całkiem prawdopodobne, że te rozwiązania nawet nie są bliskie optymalnego. """