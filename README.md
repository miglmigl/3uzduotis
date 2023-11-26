# v1.1


Šioje versijoje iš struct Studentas buvo sukurta class Studentas. Visos funkcijos buvo pakeistos, kad veiktų kartu su klase.
Programa nuskaito, generuoja, leidžia įrašyti studentus/ jų failus.


Laiko tyrimas su struct ir class Studentas vector konteinerio atveju:

Naudojant struct Studentas:

|                                                   |  100000 | 1000000 | 
| ------------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                          |  0,89 s | 9,14 s  |  
|  Failo nuskaitymo vidutinis laikas                |  0,17 s | 1,68 s  |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|  0,5 s  | 0,58 s  |  
|  Failo išrūšiavimo vidutinis laikas               |  0,013 s| 0,21 s  |  
|  Kietiakų failo spausdinimo vidutinis laikas      |  0,55 s | 5,41 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |  0,38 s | 3,75 s  |  
|  *Bendrai užtrukta*                               |*2,07 s* |*20,95 s*| 




Naudojant class Studentas:

|                                                   |  100000 | 1000000 | 
| ------------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                          |  0,63 s | 6,26 s  |  
|  Failo nuskaitymo vidutinis laikas                |  0,28 s | 2,87 s  |  
|  Failo surūšiavimas (pagal gal.p) vidutinis laikas|  0,04 s | 0,56 s  |  
|  Failo išrūšiavimo vidutinis laikas               |  0,01 s | 0,09 s  |  
|  Kietiakų failo spausdinimo vidutinis laikas      |  0,3 s  | 2,95s   |  
|  Vargšiukų failo spausdinimo vidutinis laikas     |  0,21 s | 2,07 s  |  
|  *Bendrai užtrukta*                               |*1,47 s* |*14,8 s* | 

Išvada: Iš tyrimo matyti, kad naudojant class Studentas viskas išskyrus nuskaitymą vyko greičiau nei naudojant struct Studentas.


Struct Studentas ir class Studentas versija tyrimas su optimizavimo flagais


Su class:



Išvada: Iš padarytų tyrimų matyta, kad flag O1 kūrė didžiausią exe failą, o flag O3 kūrė mažiuasią exe failą. Greičiausiai programa veikė su O3, lėčiausiai su O1 flagais.



Su struct:


Išvada: 









