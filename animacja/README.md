# Animacja
## Wymagania wstępne
- Kompilator C++
- CMake <br>
Program został przetestowany na systemie Gentoo GNU/Linux przy użyciu G++ 13.3.1 i CMake 3.30.2.

## Kompilacja programu
Należy wykonać następujące polecenia w katalogu projektu: <br>
Linux
```shell
cmake .
make
./animacja
```
Windows
```shell
cmake .
cmake --build .
.\animacja.exe
```

## Instrukcja
Na początku program zapyta nas o podanie nazwy pliku animacji. Format tego pliku wygląda następująco:
```shell
<szerokość klatek> <wysokość klatek> <ilość klatek>
<nazwa katalogu zawierającego klatki animacji>
```
Następnie program uda się do katalogu zawierającego klatki animacji. Opis n-tej klatki znajduje się w pliku n.txt (0.txt - opis zerowej klatki). Każda klatka opisana za pomocą następującego formatu:
```shell
<zawartosc klatki - macierz znaków>
<kolory klatki - macierz cyfr>
```
Kolory są zdefiniowane za pomocą cyfr w następujący sposób:
```shell
0 - kolor domyślny
1 - czarny
2 - czerwony
3 - zielony
4 - żółty
5 - niebieski
6 - magenta
7 - cyjan
8 - biały
```
Przykladowy plik animacji ("animacja.txt") i katalog klatek ("klatki") znajdują się w katalogu tego projektu.
Aby zatrzymać odtwarzanie animacji, należy wcisnąć kombinację klawiszy CTRL + C;
