# K. Kafara
from math import sqrt

PI = 3.14159265359
mi0 = 4 * PI * 10**(-7)
class Point: 
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def module(self):
        return sqrt(self.x * self.x + self.y * self.y)

    def scale(self, number):
        self.x = self.x * number
        self.y = self.y * number

    def __add__(self, vec):
        return Point(self.x + vec.x, self.y + vec.y)

    def __mul__(self, vec):
        return (self.x * vec.x + self.y * vec.y)

    

if __name__ == '__main__':
    print(mi0)
    I = float(input("I == "))
    a = float(input("a == "))
    N = float(input("N == "))
    
    A = Point(-2 * a, a)
    B = Point(2 * a, a)
    C = Point(2 * a, a)
    D = Point(-2 * a, -a)

    blue_wire_pos = Point(a, 0)
    red_wire_pos = Point(-a, 0)
    
    result = 0

    # sumowanie po odcinku AB
    # i od razu CD
    iterator = (B.x - A.x) / (2*N)
    x0 = A.x
    y0 = B.y

    print(iterator)

    while x0 <= B.x:
        # odległość (x0, y0) od nniebieskiego przewodu
        tmp = Point(x0 - blue_wire_pos.x, y0 - blue_wire_pos.y)
        r_blue_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)
        
        # wartość indukcji w (x0, y0)
        B_blue_value = (mi0 * I) / (2 * PI * r_blue_value)

        # wersor dla niebieskiego przewodu
        n_blue_wersor = Point(-(y0 - blue_wire_pos.y) / r_blue_value, (x0 - blue_wire_pos.x) / r_blue_value)

        # skalujemy przez wartość indukcji, de facto dostając indukcję
        n_blue_wersor.scale(B_blue_value)

        # przypisujemy wektor
        B_blue = n_blue_wersor

        # to samo dla czerwonego
        tmp = Point(x0 - red_wire_pos.x, y0 - red_wire_pos.y)
        r_red_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)

        B_red_value = (mi0 * (-I)) / (2 * PI * r_red_value)

        n_red_wersor = Point(-(y0 - red_wire_pos.y) / r_red_value, (x0 - red_wire_pos.x) / r_red_value)

        n_red_wersor.scale(B_red_value)

        B_red = n_red_wersor

        # wektor wypadkowy indukcji
        B_res = B_blue + B_red

        dl_vec = Point(iterator, 0)

        result += B_res * dl_vec

        x0 += iterator

    # liczymy po krawędzi CD
    x0 = C.x
    y0 = C.y
    while x0 >= D.x:
        # odległość (x0, y0) od nniebieskiego przewodu
        tmp = Point(x0 - blue_wire_pos.x, y0 - blue_wire_pos.y)
        r_blue_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)
        
        # wartość indukcji w (x0, y0)
        B_blue_value = (mi0 * I) / (2 * PI * r_blue_value)
        
        # wersor dla niebieskiego przewodu
        n_blue_wersor = Point(-(y0 - blue_wire_pos.y) / r_blue_value, (x0 - blue_wire_pos.x) / r_blue_value)

        # skalujemy przez wartość indukcji, de facto dostając indukcję
        n_blue_wersor.scale(B_blue_value)

        # przypisujemy wektor
        B_blue = n_blue_wersor

        # to samo dla czerwonego
        tmp = Point(x0 - red_wire_pos.x, y0 - red_wire_pos.y)
        r_red_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)

        B_red_value = (mi0 * (-I)) / (2 * PI * r_red_value)

        n_red_wersor = Point(-(y0 - red_wire_pos.y) / r_red_value, (x0 - red_wire_pos.x) / r_red_value)

        n_red_wersor.scale(B_red_value)

        B_red = n_red_wersor

        # wektor wypadkowy indukcji
        B_res = B_blue + B_red

        dl_vec = Point(iterator, 0)

        result += B_res * dl_vec

        x0 -= iterator

    # po krawędzi BC
    x0 = B.x
    y0 = B.y
    iterator *= 2
    while y0 >= C.y:
        tmp = Point(x0 - blue_wire_pos.x, y0 - blue_wire_pos.y)
        r_blue_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)
        
        # wartość indukcji w (x0, y0)
        B_blue_value = (mi0 * I) / (2 * PI * r_blue_value)
        
        # wersor dla niebieskiego przewodu
        n_blue_wersor = Point(-(y0 - blue_wire_pos.y) / r_blue_value, (x0 - blue_wire_pos.x) / r_blue_value)

        # skalujemy przez wartość indukcji, de facto dostając indukcję
        n_blue_wersor.scale(B_blue_value)

        # przypisujemy wektor
        B_blue = n_blue_wersor

        # to samo dla czerwonego
        tmp = Point(x0 - red_wire_pos.x, y0 - red_wire_pos.y)
        r_red_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)

        B_red_value = (mi0 * (-I)) / (2 * PI * r_red_value)

        n_red_wersor = Point(-(y0 - red_wire_pos.y) / r_red_value, (x0 - red_wire_pos.x) / r_red_value)

        n_red_wersor.scale(B_red_value)

        B_red = n_red_wersor

        # wektor wypadkowy indukcji
        B_res = B_blue + B_red

        dl_vec = Point(iterator, 0)

        result += B_res * dl_vec

        y0 -= iterator

    x0 = D.x
    y0 = D.y
    while y0 <= A.y:
        tmp = Point(x0 - blue_wire_pos.x, y0 - blue_wire_pos.y)
        r_blue_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)
        
        # wartość indukcji w (x0, y0)
        B_blue_value = (mi0 * I) / (2 * PI * r_blue_value)
        
        # wersor dla niebieskiego przewodu
        n_blue_wersor = Point(-(y0 - blue_wire_pos.y) / r_blue_value, (x0 - blue_wire_pos.x) / r_blue_value)

        # skalujemy przez wartość indukcji, de facto dostając indukcję
        n_blue_wersor.scale(B_blue_value)

        # przypisujemy wektor
        B_blue = n_blue_wersor

        # to samo dla czerwonego
        tmp = Point(x0 - red_wire_pos.x, y0 - red_wire_pos.y)
        r_red_value = sqrt(tmp.x * tmp.x + tmp.y * tmp.y)

        B_red_value = (mi0 * (-I)) / (2 * PI * r_red_value)

        n_red_wersor = Point(-(y0 - red_wire_pos.y) / r_red_value, (x0 - red_wire_pos.x) / r_red_value)

        n_red_wersor.scale(B_red_value)

        B_red = n_red_wersor

        # wektor wypadkowy indukcji
        B_res = B_blue + B_red

        dl_vec = Point(iterator, 0)

        result += B_res * dl_vec

        y0 += iterator

    print(result)


