
# v3.0
**Šioje dalyje sukurtas programos diegimo failą - setup.exe.**
<br />
Instrukcija:
1. Atsisiųskite "Release katalogą".
2. Savo kompiuteryje atsidarykite atsisiųstąjį katalogą.
3. Atidarykite dokumentą: "setup.exe".
4. Iššokus lentelėms, kuriose yra prašoma daryti pokyčius jūsų kompiuteryje, leiskite.
5. Iššoks lentelė leidžianti pasirinkti failo direktoriją. Automatiškai bus siūloma: C:\Program Files (x86)\VU\Vardenis-Pavardenis\ . Jei norite, kad failo direktorija būtų kita, spustelkite mygtuką "Browse" ir pasirinkite norimą direktoriją.
6. Iššoks lentelė klausianti ar tikrai norite instaliuoti programą. Sutikite.
7. Užsidarius visiems iššokusiems langams, kompiuteryje suraskite vietą, kurioje pasirinkote talpinti projektą (automatiškai buvo nustatyta: C:\Program Files (x86)\VU\Vardenis-Pavardenis\), programą taip pat galite paleisti spustelėję ir ant programos failo esančio jūsų darbalaukyje.
8. Atidarykite katlogą Vardenis-Pavardenis.
9. Atidarykite failą "v1.5.exe".
10. Jūsų bus paprašyta administratoriaus teisių, sutikite. (Jos reikalingos, kad programai būtų leidžiama kurti failus ir katalogus jūsų kompiuteryje).
11. Programa pradės veikti, pasirinkite norimus parametrus.


<br />

# v2.0
**Šioje dalyje sukurta dokumentaciją panaudojant Doxygen.**
<br />
Doxygen dokumentacija yra prieinama atsisiuntus ir atvėrus htmpl.rar katalogą, jame paspaudus failą "index.html":
<img width="533" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/3b536704-f7b3-4d87-91c7-6533f412f840">

Tada atsivers pagrindinis dokumentacijos puslapis.

<br />

**Taip pat sukurtas cmake CMakeLists.txt skirtas įdiegimui**


 *Įdiegimo ir naudojimosi instukcija:*
 
 1. Atsisiųskite CMake programą.
 2. Atsisiųskite RUNMEE.bat, CMakeLists.txt, katalogą "src" ir "include", juos visusu sudedame į aplankalą (pvz.: "cmaketest").
 3. Atsidarome Windows PowerShell su administratoriaus privilegijomis.
 4. Komandų eilutėje pateikiame sakinį: cd "Jūsų cmaketest direktorija" (Nukopijuotike savo cmaketest kelią (path)).
 5. Užduodame komandą: cmake -S . -B .\build 
 6. Tęsiame komandų užklausas: cmake --build .\build
 7. Iš aplankalo "src" nusikopijuojame kursiokų failus į "debug" aplanką naudojant komandą: pvz. (copy src\Kursiokai10000.txt build\Debug)
 8. Uždarome konsolės langą
 9. Kompiuteryje randame "cmaketest" aplankalą, jame randame naują aplankalą "build", kuriame galime paleisti programą atveriant failą "v1.0.exe"
 10. Paleidę programą, pasirinkite norimus parametrus.




<br /><br />

# v1.5
**Šioje dalyje vietoj vienos klasės Studentas buvo sukurtos dvi: bazinė (abstrakti) klasė - Zmogus, skirta bendrai aprašyti žmogų ir jos išvestinė (derived) klasė - Studentas.**
<br />
 _Realizuota abstrakti klasė Zmogus, jos objektų kūrimas negalimas:_
<img width="448" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/26d76639-39d3-42cd-9bc5-bc32b2ad01cd">
<img width="1091" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/3486fbd2-a71b-45a8-8418-1d85d56d9b40">

<img width="856" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/8578b10a-268e-40f4-bc23-64f119b9effc">
<img width="1081" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/88bb2978-44d5-48bb-8004-1ce9563a139c">

Matome, kad kai leidžiant programą pasirenkame Zmogaus klasės objekto kūrimo opciją, zmogaus objektas nėra sukuriamas, nes, kaip rodo kaidų sąrašas apačioje: abstrakčios klasės objekto negalime sukurti. Tačiau matome, kad Studento klasės objektą vistiek galime sukurti.
<br />
_Studento klasė išvestinė (derived) iš Zmogaus ir palaiko 1.2 versijoje realizuotą trejų metodų taisyklę:_
<img width="1044" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/8ac104db-a4cc-425d-a50e-ecbc3f22c6a2">
<img width="996" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/364498e2-cc35-4577-8b88-f6a44313964e">
<img width="850" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/2e05f1a6-6d36-431f-80d9-53c726879212">

Matome, kad Studento klasė dabar yra išvestinė Zmogaus klasė, todėl atitinkamai buvo pakeistas Copy constructor, Copy asignment operator. Paleidus programą stebime Rule of three veikimą.







<br /><br />
<br />
# v1.2
**Šioje dalyje buvo sukurti įvesties ir išvesties operatoriai Studento klasei:**
<img width="590" alt="image" src="https://github.com/miglmigl/v1.1/assets/144427943/15fbe296-8297-429c-9e6f-3a373136c9bd">

Tai supaprastina duomenų įvedimui ir išvedimui skirtą kodą:
(Vietoj atskiro pavardės ir vardo įvedimo (pvz.: temp.setVar; temp.setPav) yra naudojamas įvesties persidengimo operatorius, kuris vardą ir pavardę įveda naudojant komandą: cin >> temp. Tokiu principu veikia ir iįvedimo persidengimo operatorius)


<img width="471" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/ed5d7d9d-5a38-4771-984a-d81a31dd9b96">
<img width="348" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/a1274986-0dcb-48f7-8d3c-e69fb8eb6840">
<img width="503" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/fd22d5ae-0e69-4f57-ac22-c20cddf831a7">
<img width="699" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/3221f503-45e8-479f-a588-85e1db1b1a94">
<img width="875" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/c746de9f-53ae-4928-a15f-6a52175e74ad">





<br /><br />
<br />
**Taip pat įgyvendinta "Rule of three":**

<img width="395" alt="image" src="https://github.com/miglmigl/v1.1/assets/144427943/538d5f6a-2273-4848-8876-c184ab88243d">




Programoje pasirinkus R varinatą, pateikaima "Rule of three" demonstracija:
<img width="854" alt="image" src="https://github.com/miglmigl/2uzduotis/assets/144427943/be16e65d-2c67-4767-a106-8acd88351ab5">

Ekrane išvedami studentams priskirti egzamino rezultatai, bei copy, copy priskyrimo operatorių ir destruktoriaus suveikimą patvirtinantys sakiniai. 



<br /><br />
<br />


# v1.1


Šioje versijoje iš struct Studentas buvo sukurta class Studentas. Visos funkcijos buvo pakeistos, kad veiktų kartu su klase.
Programa nuskaito, generuoja, leidžia įrašyti studentus/ jų failus.


# Laiko tyrimas su struct ir class Studentas vector konteinerio atveju:

Naudojant struct Studentas:

|                                                   |  100000  | 1000000 | 
| ------------------------------------------------- |:--------:|:-------:|
|  Failo generavimo laikas                          |   0,31 s | 3,04 s  |  
|  Failo nuskaitymo vidutinis laikas                |   0,09 s | 0,93 s  |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|   0,02 s | 0,32 s  |  
|  Failo išrūšiavimo vidutinis laikas               |   0,02 s | 0,22 s  |  
|  Kietiakų failo spausdinimo vidutinis laikas      |   0,2  s | 2,07 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |   0,14 s | 1,44 s  |  
|  *Bendrai užtrukta*                               |*0,78 s*  |*8,02 s* | 



Naudojant class Studentas be O:

|                                                   |  100000  | 1000000 | 
| ------------------------------------------------- |:--------:|:-------:|
|  Failo generavimo laikas                          |   0.28 s |  2,85s  |  
|  Failo nuskaitymo vidutinis laikas                |   0.1  s |  0,77 s |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|   0.1  s |  0,77 s |  
|  Failo išrūšiavimo vidutinis laikas               |   0.02 s |  0,1  s |  
|  Kietiakų failo spausdinimo vidutinis laikas      |   0.28 s |  1,87 s |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |   0.21 s |  1,33 s |  
|  *Bendrai užtrukta*                               |*0,99 s*  |*7,69 s* | 


Išvada: Iš tyrimo matyti, kad naudojant class Studentas viskas išskyrus nuskaitymą vyko greičiau nei naudojant struct Studentas.


#Struct Studentas ir class Studentas laiko tyrimas su optimizavimo flagais


_Su class_


Naudojant class Studentas O1:

|                                                   |  100000 | 1000000 | 
| ------------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                          |  0,29 s |  2,96s  |  
|  Failo nuskaitymo vidutinis laikas                |  0,09 s |  0,79 s |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|  0,09 s |  0,84 s |  
|  Failo išrūšiavimo vidutinis laikas               |  0,02 s |  0,11 s |  
|  Kietiakų failo spausdinimo vidutinis laikas      |  0,2 s  |  2,06 s |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |  0,15 s |  1,37 s |  
|  *Bendrai užtrukta*                               |*0,84 s* |*8,13 s* | 

**exe failo dydis:** 90,5 KB (92 672 bytes)

Naudojant class Studentas O2:

|                                                   |  100000  | 1000000 | 
| ------------------------------------------------- |:--------:|:-------:|
|  Failo generavimo laikas                          |   0.28 s |  2,85s  |  
|  Failo nuskaitymo vidutinis laikas                |   0.1  s |  0,77 s |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|   0.1  s |  0,77 s |  
|  Failo išrūšiavimo vidutinis laikas               |   0.02 s |  0,1  s |  
|  Kietiakų failo spausdinimo vidutinis laikas      |   0.28 s |  1,87 s |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |   0.21 s |  1,33 s |  
|  *Bendrai užtrukta*                               |*0,99 s*  |*7,69 s* | 

**exe failo dydis:** 93,0 KB (95 232 bytes)

Naudojant class Studentas O3:

|                                                   |  100000 | 1000000 | 
| ------------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                          |  0,26 s |  2,77 s |  
|  Failo nuskaitymo vidutinis laikas                |  0,08 s |  0,75 s |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|  0,05 s |  0,72 s |  
|  Failo išrūšiavimo vidutinis laikas               |  0,01 s |  0,1  s |  
|  Kietiakų failo spausdinimo vidutinis laikas      |  0,19 s |  1,77 s |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |  0,13 s |  1,29 s |  
|  *Bendrai užtrukta*                               |*0,72 s* |*7,4 s*  | 

**exe failo dydis:** 116 KB (118 784 bytes)


Išvada: Iš padarytų tyrimų matyta, kad flag O1 kūrė didžiausią exe failą, o flag O3 kūrė mažiuasią exe failą. Greičiausiai programa veikė su O3, lėčiausiai su O1 flagais.



_Su struct_

Naudojant struct Studentas su flag O1:

|                                                   |  100000 | 1000000 | 
| ------------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                          |  0,33 s |  3,05 s  |  
|  Failo nuskaitymo vidutinis laikas                |  0,07 s |  0,85 s |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|  0,02 s |  0,29 s |  
|  Failo išrūšiavimo vidutinis laikas               |  0,01 s |  0,22 s |  
|  Kietiakų failo spausdinimo vidutinis laikas      |  0,2  s  |  2,07 s |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |  0,14 s |  1,52 s |  
|  *Bendrai užtrukta*                               |*0,77 s* |*8,00 s* | 

**exe failo dydis:** 93,5 KB (95 744 bytes)

Naudojant struct Studentas flag O2:

|                                                   |  100000  | 1000000 | 
| ------------------------------------------------- |:--------:|:-------:|
|  Failo generavimo laikas                          |   0,31 s | 3,04 s  |  
|  Failo nuskaitymo vidutinis laikas                |   0,09 s | 0,93 s  |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|   0,02 s | 0,32 s  |  
|  Failo išrūšiavimo vidutinis laikas               |   0,02 s | 0,22 s  |  
|  Kietiakų failo spausdinimo vidutinis laikas      |   0,2  s | 2,07 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |   0,14 s | 1,44 s  |  
|  *Bendrai užtrukta*                               |*0,78 s*  |*8,2 s* | 

**exe failo dydis:**  92,5 KB (94 720 bytes)

Naudojant struct Studentas flag O3:

|                                                   |  100000 | 1000000 | 
| ------------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                          |  0,31 s |  3,01 s |  
|  Failo nuskaitymo vidutinis laikas                |  0,07 s |  0,79 s |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|  0,02 s |  0,22 s |  
|  Failo išrūšiavimo vidutinis laikas               |  0,01 s |  0,22 s |  
|  Kietiakų failo spausdinimo vidutinis laikas      |  0,2 s  |  2,0 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |  0,14 s |  1,42 s |  
|  *Bendrai užtrukta*                               |*0,75 s* |*7,66 s* | 
 **exe failo dydis:**  113 KB (116 224 bytes)

Išvada:  Naudojant struct Studentas su flag O3 programos exe failas buvo didžiausias ir programa veikė greičiausiai, o su flag O2 programa veikė lėčiausiai ir jos exe failas buvo mažiausias.

Taigi, pastebėjome, jog tiek su struct tiek su class Studentas programa greičiausiai veikė naudojant flag O3.




Parametrai, su kuriais buvo atlikti bandymai:
<img width="1007" alt="image" src="https://github.com/miglmigl/1uzduotis/assets/144427943/46785d58-94c8-48de-8d6c-8efab2b6dd17">
<img width="1025" alt="image" src="https://github.com/miglmigl/1uzduotis/assets/144427943/4c678d3f-07b0-434e-8cd7-bfddc782f4e1">
<img width="1036" alt="image" src="https://github.com/miglmigl/1uzduotis/assets/144427943/d80a9898-c956-4f68-b96a-735f61673c54">













