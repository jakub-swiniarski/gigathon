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
Program wczytuje wstępne informacje o animacji z pliku animacja.txt. Format tego pliku wygląda następująco:
```shell
<szerokość klatki> <wysokość klatki> <ilość klatek>
<katalog zawierający klatki animacji>
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
Aby zatrzymać odtwarzanie animacji, należy wcisnąć kombinację klawiszy CTRL + C;
