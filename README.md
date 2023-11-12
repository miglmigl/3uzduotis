# v0.1


Ši programa leidžia pasirinkti konteinerį, su kuriuo bus leidžiama programa ir apskaičiuojamas kiekvieno matuojamo veiksmo (generavimas, nuskaitymas, rūšiavimas pagal pasirinktą kriterijų, rūšiavimas į "kietiakus" (studentai, kurių galutinis balas yra didesnis už 5) ir "vargšiukus" (studentai, kurių galutinis balas yra mažesnis už 5), duomenų įrašymas į "kietiakai.txt" ir "vargsiukai.txt" failus ) laikas (ji bus pateikiamas išvesties lange kartu nurodant kiek studentų buvo nuskaityta).

Programa taip pat nuskaito arba generuoja studentų failus. Juose yra vardai, pavardės, tarpiniai namų darbų pažymiai, egzamino rezultatas. Galima ir ranka įrašyti norimą studentų skaičių, bei jų pažymius ir egzamino rezultatatą.

Pasirinkus failo nuskaitymo opciją - sugeneruojami du tekstiniai failai: "kietiakai.txt" ir "vargsiukai.txt", generavimo bei įrašymo ranka atveju - sugeneruojamas studentų tekstinis failas.






#Lyginame rūšiavimo greitį su vector ir list konteineriu pritaikant tris startegijas:



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



*Įdiegimo ir naudojimosi instukcija:*
 1. Atsisiųskite RUNMEE.bat, CMakeLists.txt, atsisiunčiame main.cpp, mylib.cpp, mylib.h ir norimus tekstinius kursiokų failus, juos visusu sudedame į aplankalą (pvz.: "cmaketest").
 2. "cmaketest" aplankale sukuriame aplankalus: "include", kuriame talpiname mylib.h, "src", kuriame talpiname main.cpp, mylib.cpp bei norimus kursiokų tekstinius failus.
 3. Atsidarome Windows PowerShell su administratoriaus privilegijomis.
 4. Komandų eilutėje pateikiame sakinį: cd "Jūsų cmaketest direktorija" (Nukopijuotike savo cmaketest kelią (path)).
 5. Užduodame komandą: cmake -S . -B .\build 
 6. Tęsiame komandų užklausas: cmake --build .\build
 7. Iš aplankalo "src" nusikopijuojame kursiokų failus į "debug" aplanką naudojant komandą: pvz. (copy src\Kursiokai10000.txt build\Debug)
 8. "cmaketest" aplankale randame naują aplankalą "build", kuriame galime paleist programą atveriant failą "v1.0.exe"
 9. Paleidę programą, pasirinkite norimus parametrus.



*Programos naudojimas paleidus:*
1. Paleiskite programą.
2. Pasirinkite kokį konteinerį naudosite programoje: "vector" (V) arba "list" (L).
3. Pasirinkite veiksmą: vesti studentus ir jų rezultatus ranka (T), generuoti studentų failo duomenis (G), nuskaityti studentų duomenis iš failo, juos suskirstyti į 'vargšiukus' ir 'kietiakaus' (F).
4.
  a) Pasirinkus įvedimą ranka:
	įveskite studnetų skaičių
	įveskite studento vardą ir pavardę
	veskite studento pažymius juos atskirinat tarpu, kai norėsite susutabdyti pažymių įvedimą paspausite "Enter" 2 kartus
	įvesite studento egzamino rezultatą
	pasirinkite pagal kokį dydį apibendrinsite studento rezultatus: medijaną (M) ar vidurkį (V)

--Sukurtas 'rezultatai.txt' failas

   b) Pasirinkus studentų failo generavimą:
	įveskite kiek studentų norite kad būtų jūsų generuojamame faile
	įveskite kiek tarpinių namų darbų pažymių norėsite sugeneruoti kieikvienam studentui

--Ekrane pateikiamas failo generavimo laikas

--Sukurtas 'Kursiokai*.txt' failas. ( Jei pirmame punktelyje įvedėte sakičių 100, failo pavadinimas bus 'kursiokai100.txt', jei 1000 - 'Kursiokai1000.txt' ir t.t.)


   c) Pasirinkus nuskaitymą iš failo:
	įveskite failo, kurį norite nuskaityti pavadinimą (formatas: pavadinimas.txt). (Ekrane bus parodytas galimų tekstinių failų sąrašas)
	pasirinkite pagal ką norėsite surūšiuoti failus 'vargsiukai.txt', 'kietiakai.txt'.

--Ekrane pateikiamas matuojamų veiksmų greitis

--Sukurti failai 'vargsiukai.txt', 'kietiakai.txt'



# Programos spartos tyrimas pagal vector arba list konteinerį:

*Lyginame programos veikimo greitį su vector ir list konteineriu:*



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





