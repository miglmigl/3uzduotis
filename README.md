# Tyrimas

Vector konteinerio atveju

|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,02 s   |  0,09 s | 0,89 s | 9,14 s |  86,96 s |
|  Failo nuskaitymo vidutinis laikas            | 0 s      |  0,02 s | 0,17 s | 1,68 s   |  17,91 s   |
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas| 0 s  |  0,02 s | 0,5 s | 0,58 s   |  7,14s   |
|  Failo išrūšiavimo vidutinis laikas           | 0 s      |  0 s    | 0,03 s | 0,39 s  |  3,13 s      |
|  Kietiakų failo spausdinimo vidutinis laikas  | 0,02 s    |  0,05 s | 0,55 s | 5,41 s  |  54,74 s  |
|  Vargšiukų failo spausdinimo vidutinis laikas | 0 s      |  0,04 s | 0,38 s | 3,75 s  |  38,6 s  |
|  *Bendrai užtrukta*                           | *0,04 s*  |  *0,22 s* | *2,07 s* | *20,95 s* |  *205.48 s* |




List konteinerio atveju

|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,02 s  |  0,09 s | 0,86 s | 8,61 s |  85,25 s |
|  Failo nuskaitymo vidutinis laikas            | 0 s     |  0,02 s | 0,18 s | 1,8 s   |  18,55 s   |
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas| 0 s |  0 s    | 0,06 s | 0,94 s   |  14,58s   |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0 s    | 0,04 s | 0,4 s  |  8,42 s      |
|  Kietiakų failo spausdinimo vidutinis laikas  | 0,02 s   |  0,05 s | 0,53 s | 5,27 s  |  55,17 s  |
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,02 s     |  0,04 s | 0,38 s | 3,72 s  |  38,57 s  |
|  *Bendrai užtrukta*                           | *0,06 s* |  *0,2 s* | *2,05 s* | *20,74 s* |  *220,54 s* |



Išvada: Iš lentelių matyti, kad naudojant list konteinerį failai buvo generuojami greičiau nei naudojant vector knteinerį. Pastebime,kad su vector konteineriu greičiau vyksta failo nuskaitymas, rūšiavimas pagal galutinį pažymį, rūšiavimas į "kietiakus" ir "vargšiukus" vyko greičiau nei su list konteineriu.


Parametrai, su kuriais buvo atlikti bandymai:
<img width="1007" alt="image" src="https://github.com/miglmigl/1uzduotis/assets/144427943/46785d58-94c8-48de-8d6c-8efab2b6dd17">
<img width="1025" alt="image" src="https://github.com/miglmigl/1uzduotis/assets/144427943/4c678d3f-07b0-434e-8cd7-bfddc782f4e1">
<img width="1036" alt="image" src="https://github.com/miglmigl/1uzduotis/assets/144427943/d80a9898-c956-4f68-b96a-735f61673c54">


