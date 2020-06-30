# K. Kafara

""" Idea: 
Korzystamy z następującej równoważności: (x => y) <=> (~x v y) 
Zatem przykład podany w treści zadania: (x v y) ∧ (~x v z) ∧ (~z v ~y)
możemy przerobić na: (~x => y) ∧ (x => z) ∧ (z => ~y)
Formuła może być spełniona <=> nie prowadzi jednocześnie implikacja z x do ~x oraz ~x do x. (Dowód?)
Zatem tworzymy graf implikacji. Wierzchołkami są literały oraz stowarzyszona informacja czy literał jest zanegowany.
Pomiędzy dwoma literałami u, v istnieje krawędź skierowana (u,v) <=> w naszej 'przerobionej' formule istnieje implikacja 
(u => v). Następnie wyznaczamy silne spójne składowe w tym grafie (np. algorytm Kosaraju ). Podczas wyznaczania silnie spójnych
składowych kontrolujemy czy w jednej silnie spójnej składowej nie natykamy się na zarówno literał jak i jego negację. Jeżeli tak
to formuła nie jest spełnialna.
Złożoność: (reprezentacja listowa)
Zbudowanie grafu (zakładam, że jest dana w postaci przyjaźniejszej niż string i nie trzeba parsować) - O(V + E)
Silnie spójne składowe i weryfikacja: O(V + E) (złożoność DFS'a)
Zatem finalnie O(V + E)"""
