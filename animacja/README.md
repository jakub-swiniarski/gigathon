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
