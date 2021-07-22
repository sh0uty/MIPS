# MIPS Prozessor

Vereinfachter MIPS-Emulator mit SystemC v2.3.3 von Lukas Stolz und Luke Bocker

## Usage

> Um das Programm zu kompilieren:
```bash
make
```
***
Die ausfühbare Datei befindet sich im "bin/" Ordner mit dem Namen "MIPS".
Es muss jedoch darauf geachtet werden, dass sich die instructions.txt im selben Ordner befindet wie die ausführbare MIPS Datei.

> Um die Object files zu entfernen:
```bash
make clean
```
***
> Um die Object files und die Binary zu entfernen:
```bash
make remove
```
***
Wenn mehr als die jetzigen drei instructions in der instructions.txt hinzugefügt werden, muss nach Bedarf die for-Schleife in der main.cpp verlängert werden.
> Am besten auf:
```C++
for(int i = 0; i < (Anzahl Instructions + 1); i++)
```