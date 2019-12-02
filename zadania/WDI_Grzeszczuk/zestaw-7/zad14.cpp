/*
ZESTAW 7, ZADANIE 14
14. Problem 8 Hetmanów (treść oczywista) 

treść oczywista, ale kod wymaga dokładnego komentarza
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 8;

int abs(int a)
{
    return  ((a<0) ? (-a) : (a));
}

// wypisuje szachownicę uzupełnioną hetmanami
void print(int ph[N])
{
    int szach[N][N];
    REP(i, N)
    {
        REP(j, N)
            szach[i][j] = 0;
    }
    // tam gdzie stoi hetman wstawiamy 1
    REP(i, N) 
    {
        if (ph[i] != -1)
            szach[ph[i]][i] = 1;
    }
    REP(i, N)
    {
        REP(j, N)
            cout << setw(4) << szach[i][j];
        cout << "\n";
    }
    cout << "\n\n\n";
}
void printTab(int ph[], int N)
{
    REP(i, N)
    {
        cout << setw(4) << ph[i];
    }
    cout << "\n";
}
/*
    w - nr wiersza do którego chcemy wstawiać hetmana
    ph[i] == j != -1 --> w i-tej kolumnie w wierszu j-tym stoi hetman
    ph[i] == -1 --> w i-tej kolumnie nie ma hetmana
*/
void hetman(int w, int ph[N])
{
    //cout << "het: w: " << w << "\nph: ";
    //printTab(ph, N); cout << "\n";
    // jeżeli wywołaliśmy sie na N-tym wierszu, to znaczy że na ostatnim, czyli N-1, udało nam sie wstawić hetmana ==> cała
    // tablica jest uzupełniona zgodnie z regułami zadania ==> sukces ==> wypisujemy i wychodzimy instancję wyżej 
    if (w == N)
    {
       // printTab(ph, N);
        cout << "\n";
        print(ph);
        return;
    }
    // gdy jeszcze jakiś wiersz jest pusty
    else
    {
        // jedziemy przez kolumny (szukamy miejsca w w-tym wierszu)
        REP(i, N)
        {
            // jeżeli w kolumnie i nie ma hetmana to oznacza że pole (w,i) nie jest atakowane w pionie ani poziomie
            // (żaden hetman nie jest w naszym wierszu, bo wywołujemy się za każdym razem o wiersz niżej, czyli do wiersza pustego)
            if (ph[i] == -1)
            {
                // to zakładamy że pole nie jest atakowane
                bool empty = true;
                // i jedziemy po wszystkich kolumnach żeby sprawdzić czy pole (w,i) nie jest atakowane po przekątnej
                // pamiętając o fakcie, że jeżeli jakiś hetman jest na szachownicy to może być tylko nad nami!!
                REP(j, N)
                {
                    //cout << "j: " << j << " ";
                    /*
                        ph[j] != -1 <--> jeżeli w kolumnie j-tej jest hetman
                        abs(i-j) == w - ph[j] <-->:
                        1. w - ph[j] >= 0 zawsze! Ponieważ wszystkie hetmany stoją nad nami! ==> w > ph[j];
                        2. jeżeli wb różnicy współrzędnych jest jednakowa tzn. jeżeli:
                        (nr wiersza naszego hetmana, którego chcemy wstawić) - (nr wiersza potencjalnego zagrożenia) == (nr kolumny naszego hetmana) - (nr kol. zagr.)
                        czyli: w - ph[j] == i - j to znaczy że nasz hetman i "potencjalne zagrożenie" stoją na jednej przekątnej ==> nie możemy postawić hetmana 
                        na pozycji (w, i) ==> przechodzimy do kolejnego i
                    */
                    if (ph[j] != -1 and (abs(i - j) == w - ph[j]))
                    {
                        //cout << "false\n";
                        empty = false;
                        break;
                    }
                    //cout << "true\n";
                }
                if (empty)
                {
                    // jeżeli w w-tym wierszu gdzieś nam się udało postawić hetmana, to go wpisujemy do ph[];
                    ph[i] = w;
                    // i wywołujemy się rekurencyjnie na kolejnym wierszu
                    hetman(w + 1, ph);
                    //cout << "wychodze z rek!\n";
                    // jeżeli przeanalizowaliśmy wszystkie możliwości z pozycji (w,i), to odznaczamy tą pozycję, i przechodzimy do i+1, ewentualnie wychodzimy 
                    // instację wyżej
                    ph[i] = -1;
                }
            }
        }
    }
}

int main()
{
    int ph[N];
    // oznaczamy że nigdzie jeszcze nie ma hetmana
    REP(i, N) ph[i] = -1;

    hetman(0, ph);

    return 0;
}
