# v0.1

*Lyginame rūšiavimo greitį su vector ir list konteineriu pritaikant tris startegijas:*



Vector konteinerio atveju

|   Studentų sk.   |  1 strategija   |  2 startegija  | 3 strategija |
| -----------------|:---------------:|:--------------:|:------------:|
|  1 000           | 0,00037 s       |  0,00016 s     | 0,00009 s    |
|  10 000          | 0,00364 s       |  0,00159 s     | 0,00075 s    |
|  100 000         | 0,02843 s       |  0,02000 s     | 0,01286 s    |
|  1 000 000       | 0,39018 s       |  0,02000 s     | 0,20864 s    |
|  10 000 000      | 3.12862 s       |  2,71395 s     | 2,32814 s    |


List konteinerio atveju

|   Studentų sk.   |  1 strategija   |  2 startegija  | 3 strategija |
| -----------------|:---------------:|:--------------:|:------------:|
|  1 000           | 0,00034 s       |  0,00015 s     | 0,00012 s    |
|  10 000          | 0,00374 s       |  0,00198 s     | 0,00132 s    |
|  100 000         | 0,04280 s       |  0,03625 s     | 0,03338 s    |
|  1 000 000       | 0,39582 s       |  0,56714 s     | 0,41955 s    |
|  10 000 000      | 8,42034 s       |  5,85091 s     | 5,18927 s    |


Išvada: Naudojant vector konteinerį rezultatų nuskaitymas yra visapusiškai greitesnis. Pirma strategija abiejų konteinerių atvejais yra prasčiausiai optimizuota. Kuomet trečia veikia sparčiausiai.



*Įdiegimo ir naudojimosi instukcija:
 1. Atsisiųskite RUNMEE.bat, CMakeLists.txt, atsisiunčiame main.cpp, mylib.cpp, mylib.h ir norimus tekstinius kursiokų failus, juos visusu sudedame į aplankalą (pvz.: "cmaketest").
 2. "cmaketest" aplankale sukuriame aplankalus: "include", kuriame talpiname mylib.h, "src", kuriame talpiname main.cpp, mylib.cpp bei norimus kursiokų tekstinius failus.
 3. Atsidarome Windows PowerShell su administratoriaus privilegijomis.
 4. Komandų eilutėje pateikiame sakinį: cd "Jūsų cmaketest direktorija" (Nukopijuotike savo cmaketest kelią (path)).
 5. Užduodame komandą: cmake -S . -B .\build 
 6. Tęsiame komandų užklausas: cmake --build .\build
 7. Iš aplankalo "src" nusikopijuojame kursiokų failus į "debug" aplanką naudojant komandą: pvz. (copy src\Kursiokai10000.txt build\Debug)
 8. "cmaketest" aplankale randame naują aplankalą "build", kuriame galime paleist programą atveriant failą "v1.0.exe"
 9. Paleidę programą, pasirinkite norimus parametrus. 

