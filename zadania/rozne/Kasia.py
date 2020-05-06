# K. Kafara

# przykładowa funkcja, można zadać dowolną, określoną na przedziale na którym
# liczyć przybliżenie całki Riemanna 
def linear_function(x):
    return 1 * x

# funkcja obliczająca przybliżenie całki Riemanna, korzystająca wprost z def. 
def definite_riemann_integral(a, b, function, n):
    # funkcja obliczająca przybliżenie całki Riemanna, korzystająca wprost z def.
    # @param a, b - krańce przedziału na którym liczymy całkę
    # @param function - funkcja podcałkowa
    # @param n - na ile odcinków równej długości dzielimy przedział [a, b] 
    sum = 0
    iterator = (b - a) / n
    while a <= b:
        sum += function(a) * iterator
        a += iterator
        # print(a)

    return sum



if __name__ == '__main__':
    print(definite_riemann_integral(0, 10, linear_function, 1000))
