# K. Kafara

# Liniowy algorytm wyznaczający podtablicę o maksymalnej, nieujemnej sumie
# Idea:
# Zaczynamy przechodzić tablicę (np.) od lewej strony. Przechodząc na kolejne elementy dodajemy je 
# do sumy poprzednich, przy okazji zapamiętując dotychczasową największą sumę i indeksy graniczne podtablicy. 
# Jeżeli zdarzy się tak, że wzięcie i-tego elementu tablicy spowoduje że bieżąca suma stanie się niedodatnia
# to oznacza że:
# 1. Na i-tym elemencie odnotowaliśmy spadek wartości bieżącej sumy ==> nie ma sensu rozważać go w nowym kawałku
# 2. Możemy zacząć szukać nowej maksymalnej podtablicy od indeksu i + 1 
#
# Dlaczego to działa? Skąd gwarancja, że dla podtablicy arr[1, …, i] jej maksymalna podtablica
# arr[l, …, r] zostanie wyznaczona poprawnie?
# Zaczynamy jechać od lewej. Maksymalna podtablica arr[1, …, i] = arr[1] - oczywiście ==> dodajmy pierwszy
# element do sumy. 
#   Jeżeli pierwszy element był <= 0, to rzecz jasna nie ma sensu go brać ==> zaczynamy
#   naliczanie sumy na nowo
#   Wpp suma jest normalnie powiększona i sprawdzamy czy jest większa niz dotychczas znana maksymalna 
# Bierzemy drugi element. Zwiększamy sumę. Sprawdzamy czy udało nam się ją powiększyć:
#   Jeżeli tak: to zapamiętujemy końce przedziału z maksymalną sumą orazm samą maksymalną sumę i idziemy dalej
# Następnie sprawdzamy czy nasza obecna suma nie stała się niedodatnia. 
#   Jezeli tak: to oznacza że jeżeli dalej w tablicy jest maksymalna podtablica, to na pewno nie może ona
#   zawierać aktualnie rozważanej podtablicy (bo ten by ją zaniżał).
# Teraz powstaje pytanie, dlaczego nie może zawierać fragmentu aktualnie rozważanej podtablicy?
# Fakt 1:
#   Rozważany fragment zaczyna się od liczby dodatniej (wyjaśnione wcześniej)
# Zatem jeżeli stwierdziliśmy że jego suma stała się niedodatnia, to:  
# Fakt 2: 
#   Fragment zaczynający się później ma mniejszą sumę niż cały rozważany fragment
# A gdyby go skrócić o więcej niż o 1 z lewej strony? 
# To to co zostawiamy na pewno ma sumę > 0, inaczej przerwalibyśmy ten fragment wcześniej, ==> zostawiając tracimy




def max_sub_array(arr):
    sum = 0
    max_sum = -1000000                          # symbolizuje -inf
    l = r = l_max = r_max = 0

    for i in range(len(arr)):

        sum += arr[i]

        if sum > max_sum:
            l_max = l
            r_max = i
            max_sum = sum
        
        if sum <= 0:
            l = i + 1
            r = i + 1
            sum = 0

    return (l_max, r_max, max_sum)



if __name__ == '__main__':
    arr = [-1, 2, 3, -5, 5, -5]
    print(max_sub_array(arr))

