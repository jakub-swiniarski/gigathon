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
Program wczytuje animację z pliku "animacja.txt". Plik powinien zawierać opis animacji w następującym formacie:
```shell
<szerokość klatki> <wysokość klatki> <ilość klatek>
<zawartość n-tej klatki>
<kolory n-tej klatki>
```
Kolory są zdefiniowane za pomocą cyfr w następujący sposób:
```shell
1 - czarny
2 - czerwony
3 - zielony
4 - żółty
5 - niebieski
6 - magenta
7 - cyjan
8 - biały
```
