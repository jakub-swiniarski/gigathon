# Memory
## Cel gry
Gra polega na odnalezieniu wszystkich par kart o tych samych symbolach. Gra jest dwuosobowa.

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
./memory
```
Windows
```shell
cmake .
cmake --build .
.\memory.exe
```

## Instrukcja gry
Na początku program poprosi nas o podanie rozmiaru planszy. Należy podać parę dodatnich liczb, których iloczyn jest liczbą parzystą, np.:
```shell
4 4
```
Pierwsza liczba oznacza szerokość, a druga - wysokość. <br>
Następnie gracze na zmianę podają współrzędne kart, które chcą sprawdzić. Współrzędne karty podaje się w taki sam sposób, jak rozmiar planszy.
```shell
1 2
```
Pierwsza liczba oznacza współrzędną x, a druga - współrzędną y. Karta w lewym górnym rogu planszy ma współrzędne (0, 0). Karta (1, 2) została oznaczona literą "O":
```shell
####
####
#O##
####
```
Wygrywa gracz, który znajdzie najwięcej par kart.
