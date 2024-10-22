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
Na początku program zapyta nas, czy chcemy wczytać zapisaną wcześniej grę. <br>
Jeśli wybierzemy opcję "T", program wczyta stan gry z pliku "stan_gry.txt". <br>
Jeśli jednak postanowimy rozpocząć nową grę, zostaniemy poproszeni o podanie rozmiaru planszy. Należy podać parę dodatnich liczb, których iloczyn jest liczbą parzystą, np.:
```shell
4 4
```
Pierwsza liczba oznacza szerokość, a druga - wysokość. <br>
Następnie gracze na zmianę podają współrzędne kart, które chcą sprawdzić. Współrzędne karty podaje się w taki sam sposób, jak rozmiar planszy.
```shell
2 3
```
Pierwsza liczba oznacza współrzędną x, a druga - współrzędną y. Karta w lewym górnym rogu planszy ma współrzędne (1, 1). Karta (2, 3) została oznaczona literą "O":
```shell
####
####
#O##
####
```
Po każdej turze program zapyta nas czy chcemy zapisać aktualny stan gry. Zostanie on zapisany w pliku "stan_gry.txt". <br>
Wygrywa gracz, który znajdzie najwięcej par kart.
