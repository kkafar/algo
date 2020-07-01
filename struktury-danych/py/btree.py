class BTree:
    """ B-Drzewo. Dostępne metody: """
    class BTNode:
        def __init__(self):
            self.key_list = []
            self.subtree_list = []
            self.parent = None

    def __init__(self, t = 200):
        self.master = self.BTNode()
        self.t = t


    def minimum(self):
        """ Zwraca minimalny element w drzewie lub None, jeżeli drzewo jest puste. """
        
        # Ustawiamy się na wartownika
        node = self.master
        # Idziemy w lewo dopóki są jakieś poddrzewa. 
        while len(node.subtree_list) > 0:
            # Przechodzimy na obiekt będący korzeniem skrajnego lewego poddrzewa    
            node = node.subtree_list[0]

        # Jeżeli nie jesteśmy na wartowniku ==> drzewo nie jest puste, możemy coś zwrócić
        if node != self.master:
            return node.key_list[0]
        
        else:
            return None


    def maximum(self):
        """ Zwraca element maksymalny w drzewie lub None, jeżeli drzewo jest puste """

        # Ustawiamy się na wartownika
        node = self.master
        # Idziemy w prawo dopóki nie jesteśmy liściem (są jakieś poddrzewa)
        while len(node.subtree_list) > 0:
            # Przechodzimy na obiek będący korzeniem skrajnego prawego poddrzewa
            node = node.subtree_list[len(node.subtree_list) - 1]

        # Jeżeli nie jesteśmy na wartowniku ==> drzewo nie jest puste, możemy coś zwrócić
        if node != self.master:
            return node.key_list[len(node.key_list) - 1]

        else:
            return None