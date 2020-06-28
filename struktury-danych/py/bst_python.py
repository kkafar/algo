# K. Kafara
class BinarySearchTree:
    """ Implementacja drzewa binarnego wspierającego podstawowe operacje insert(…)\nfind(…)\nremove(…) """
    class BSTNode:
        def __init__(self, key = None, value = None, parent = None, left = None, right = None):
            self.key = key
            self.value = value
            self.parent = parent
            self.left = left
            self.right = right


    def __init__(self):
        # Drzewo przed jakimikolwiek operacjami jest oczywiście puste
        self.root = None


    def insert(self, key, value):
        # Wstawia do drzewa węzeł o nowym kluczu lub uaktualnia wartość odpowiedniego węzła, jeżeli taki klucz już istnieje w drzewie.
        # Zwraca 1 jeżeli wstawiono nowy węzeł
        # Zwraca 2 jeżeli uaktualniono wartość już istniejącego węzła
        node = self.root

        if node is None:
            self.root = self.BSTNode(key, value)
            return 1
        
        else:
            direction = -1
            # direction == 1, jeżeli idziemy w lewo
            # direction == 2, jeżeli idziemy w prawo

        while direction != 0:
            if key == node.key:
                node.value = value
                return 2

            elif key < node.key: # ==> idziemy w lewo
                direction = 1
                if node.left is None:
                    break
                node = node.left
            
            else:
                direction = 2
                if node.right is None:
                    break
                node = node.right

        # jeżeli jesteśmy w tym miejscu, to znaczy że klucz key nie został odnaleziony w drzewie ==> musimy utworzyć nowy węzeł
        if direction == 1:
            node.left = self.BSTNode(key, value, node)
        
        else:
            node.right = self.BSTNode(key, value, node)

        return 1
                

    def find(self, key):
        # Zwraca wartość znajdująca się pod kluczem, jeżeli takowy udało się znaleźć. 
        # None wpp
        node = self.root

        while node is not None:
            if node.key == key:
                return node.value
            
            elif key < node.key:
                node = node.left
            
            else:
                node = node.right

        return None


    def successor(self, node):
        # Zwraca odpowiedni węzeł jeżeli nastęnik istnieje albo None wpp
        if node.right is not None:
            # Wchodzimy do prawego poddrzewa
            node = node.right
            # Bierzemy możliwie najmniejszy element
            while node.left is not None:
                node = node.left

            return node

        # Jeżeli nie ma odpowiedniego poddrzewa ==> nasz następnik musi być wyżej w drzewie.
        # Idziemy w górę tak długo, aż nie wejdziemy do jakiegoś węzła jako lewe dziecko (tzn. że jego klucz jest większy od naszego)
        while node.parent is not None and node.parent.left != node:
            node = node.parent
        
        # None, jeżeli nasze drzewo składa się jedynie z korzenia, bądź nasz węzeł nie ma następnika
        return node.parent
            

    def predecessor(self, node):
        # TODO
        if node.left is not None:
            # Wchodzimy do lewego poddrzewa
            node = node.left
            # Bierzemy z niego największy węzeł o największym kluczu
            while node.right is not None:
                node = node.right

            return node

        while node.parent is not None and node.parent.right != node:
            node = node.parent

        return node.parent

    """ FUNKCJA REMOVE JEST ABSOLUTNIE DO PRZEMYŚLENIA I NAPISANIA OD POCZĄTKU TODO """
    def remove(self, key):
        # Zwraca wartość znajdującą się pod kluczem, jeżeli element został usunięty
        # None wpp
        # node = self.root
        def _remove(key, node):
            while node is not None:
                if key < node.key:      # ==> idziemy w lewo
                    node = node.left
                
                elif key > node.key:    # ==> idziemy w prawo
                    node = node.right

                else:                   # ==> znaleźliśmy odpowiedni węzeł
                    if (node.left is None) and (node.right is None):    # Jeżeli usuwany węzeł nie ma dzieci
                        if node == self.root:
                            value = self.root.value                           # Jeżeli usuwanym węzłem jest root
                            del self.root
                            self.root = None
                            return value
                        else:
                            # Jeżeli jesteśmy lewym dzieckiem 
                            if node.parent.left == node:
                                node.parent.left = None
                                value = node.value
                                del node
                                return value
                            # Jeżeli jesteśmy prawym dzieckiem 
                            else:
                                node.parent.right = None
                                value = node.value
                                del node
                                return value
                    
                    # Jeżeli usuwany węzeł ma tylko lewe dziecko
                    elif (node.left is not None) and (node.right is None):
                        # Jeżeli usuwanym węzłem jest root
                        if node == self.root:
                            self.root = node.left
                            value = node.value
                            self.root.parent = None
                            del node
                            return value
                        
                        else:
                            if node.parent.left == node:
                                node.parent.left = node.left
                                node.left.parent = node.parent
                                value = node.value
                                del node
                                return value
                            else:
                                node.parent.right = node.left
                                node.left.parent = node.parent
                                value = node.value
                                del node
                                return value
                    
                    # Jeżeli usuwany węzeł ma tylko prawe dziecko
                    elif (node.right is not None) and (node.left is None):
                        # Jeżeli usuwanym węzłem jest root
                        if node == self.root:
                            self.root = node.right
                            value = node.value
                            self.root.parent = None
                            del node
                            return value
                        
                        else:
                            if node.parent.left == node:
                                node.parent.left = node.right
                                node.right.parent = node.parent
                                value = node.value
                                del node
                                return value
                            else:
                                node.parent.right = node.right
                                node.right.parent = node.parent
                                value = node.value
                                del node
                                return value
                    
                    # Jeżeli usuwany węzeł ma dwoje dzieci
                    else:
                        succ = self.successor(node)
                        node.key = succ.key
                        value = node.value
                        node.value = succ.value
                        _remove(succ.key, succ)
                        return value

                        
            # Nie udało się znaleźć węzła o kluczu @param key
            return None

        
        return _remove(key, self.root)
        

    def print(self, node = None, depth = 0):
        if node is None: 
            return
        else:
            print("object: {} : (key={}, val={}, parent={}, dep={})  ".format(node, node.key, node.value, node.parent, depth))
            self.print(node.left, depth + 1)
            self.print(node.right, depth + 1)


if __name__ == '__main__':
    bst = BinarySearchTree()

    bst.insert(100, 100)
    bst.insert(50, 50)
    bst.insert(200, 200)
    bst.insert(25, 25)
    bst.insert(75, 75)
    bst.insert(150, 150)
    bst.insert(400, 400)

    print(bst.find(150))

    bst.print(bst.root)

    print(bst.remove(100))
    
    bst.print(bst.root)

    print(bst.remove(200))

    bst.print(bst.root)

    print(bst.remove(150))

    bst.print(bst.root)
