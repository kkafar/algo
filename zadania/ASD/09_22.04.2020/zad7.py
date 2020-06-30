# K. Kafara

""" 
1° Każdy wierzchołek ma być wykorzystany dokładnie raz
2° Co oznacza, że trasy są zamkniete? Trasa wyścigu ma być cyklem? 
3° Graf jest skierowany
4° Z każdego wierzchołka wychodzą co najwyżej 2 krawędzie (deg_out ≤ 2)
5° Do każdego wierzchołka wchodzą co najwyżej 2 krawędzie (deg_in ≤ 2)
Jeżeli dobrze rozumiem to pytamy, czy można ten graf skierowany podzielić na rozłączne cykle? 
(De facto podział na silne spójne składowe)
Do każdego wierzchołka musimy wejść i wyjść => sprowadzamy do do problemu wartościowania.  (~= 2CNF)

Możemy mieć 5 sytuacji:

1° deg_in == deg_out == 2
Wtedy powiedzmy, że do wierzchołka wchodzą krawędzie a i b, a wychodzą c oraz d. 
Musi być spełnialna formuła: 
(a v b) ∧ (~a v ~b) ∧ (c v d) ∧ (~c v ~d), co po równoważnym przekształceniu daje
(~a => b) ∧ (a => ~b) ∧ (~c => d) ∧ (c => ~d)           (1*)
Korzystamy z kontrapozycji:
(~a <=> b) ∧ (~c <=> d)

2° deg_in == 2, deg_out == 1
Wchodzą krawędzie a, b. Wychodzi krawędź c
(a v b) ∧ (~a v ~b) ∧ c
(~a => b) ∧ (a => ~b) ∧ c                               (2*)
(~a <=> b) ∧ c

3° deg_in == 1, deg_out == 2
Wchodzi krawędź a. Wychodzą krawędzie c i d
a ∧ (c v d) ∧ (~c v ~d)
a ∧ (~c => d) ∧ (c => ~d)                               (3*)
a ∧ (~c <=> d)

4° deg_in == 1, deg_out == 1
Wchodzi a, wychodzi c. 
Musi zachodzić
a ∧ c                                                   (4*)

5° Przypadek zbiorczy, gdy deg_in == 0 v deg_out == 0
Wtedy oczywiście zamkniętej(!!!! czyli cyklicznej?!) trasy przechodzącej przez wszystkie wierzchołki wyznaczyć sięna pewno nie da. 


Wszystkie krawędzie które są poza 2 literałowymi klauzulami (pojedyncze literały) muszą mieć wartościowanie 1 (być wykorzystane).
Zatem mamy z góry narzucone wartościowanie dla pewnego podzbioru literałów. 
 
1. Budujemy graf formuły. 
Na tym etapie sprawdzamy od razu czy nie zachodzi 5° (możemy np. dodając kolejne krawędzie zliczać dla jakiej liczby wierzchołków
zmieniliśmy stopień in/out z 0 na 1. Jeżeli wyjdzie nam liczba < liczba_wierzchołków w grafie to wiemy, że zachodzi 5° i możemy od razu udzielić odpowiedzi)
2. Dalej działamy tak jak w zadaniu 4, ponieważ wszystkie warunki dla poszczególnych wierzchołków muszą zachodzić jednocześnie ==> łączymy je koniunkjcą. (Czyli wyznaczamy silnie spójne składowe, jednocześnie sprawdzając czy w obrębie jednej silnie spójnej składowej nie znajdują się literały komplementarne. Jeżeli się takie literały znajdują ==> rozwiązanie nie istnieje).
"""
