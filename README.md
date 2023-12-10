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







