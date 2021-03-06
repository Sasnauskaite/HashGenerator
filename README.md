# HashGenerator
# V0.0.1

Sukurtas HASH generatorius, kuris bet kokią įvestį paverčia 64 simbolių hex kodu.
Mano hash funkcijos idėja:
* I. Kiekvienam įvesto string'o simboliui priskiriama tam tikra reikšmė.
* II. Su priskirtomis reikšmėmis atliekami matematiniai veiksmai ir gainamos atskiros galutinio rezultato dalys (tam tikra skaičių seka bei raidė).
* III. Po kiekvienos atskiros galutinio rezultato gavimo dalies ji yra pridedama prie išeigos string'o.
* IV. Jei išeigos stringas po visų įvesto stringo simbolių suhashavimo nesiekia 64 simbolių prie jo yra pridedamos skaitinės reikšmės, kol išvesties stringas pasiekia 64 simbolių ilgį.

# V0.0.2

Sukurta galimybė lyginti iš skirtingų failų (max 5 failai) sukurtus hash'us vienu metu. 
Taip įrodau, kad mano programoje įvykdyti šie reikalavimai: 

**1.** Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).

**ĮRODYMAS:**

![image](https://user-images.githubusercontent.com/78842487/135724404-a697f8b5-c542-43b4-816f-314adb4fbc0b.png)

*empty.txt failas yra tuščias failas, simbolis.txt turi tik 1 simbolį, o 3000random.txt turi 3000 atsitiktinų simbolių, mano hash funkcija dirba su visais jai paduotais failais.*

**2.** Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (pageidautina 256 bit'ų ilgio, t.y., 64 simbolių hex'as).

*Įrodymas yra viršuje, nesvarbu, kokio ilgio failas, jam vistiek pateikiamas 64 simbolių kodas.*

**3.** Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.

![image](https://user-images.githubusercontent.com/78842487/135724563-00668de9-095b-40e9-98aa-bc5df627f9d4.png)

*Ši ekrano nuotrauka parodo, jog žodžiui „labas" hash kodas visuomet yra tas pats.*

# V0.0.3

**FUNKCIJOS EFEKTYVUMAS:**

![image](https://user-images.githubusercontent.com/78842487/136349847-9a4c8215-2dcc-456e-bffd-fdc6ba9caef3.png)

*Hash'uodama skirtingas failo `konstitucija.txt` eilutes mano sukurta funkcija užtruko tiek laiko.*

**PAPILDOMA UŽDUOTIS:**

![image](https://user-images.githubusercontent.com/78842487/136349993-611ad1b2-7471-4e5b-85ad-854de70d751a.png)

*Norėdama objektyviai patikrinti SHA256 ir savo hash'avimo funkcijas tikrinau jų veikimą su 100 000 skirtingų stringų (abi funkcijos gavo vienodus stringus).*
*Kaip ir buvo tikėtasi, mano hash'avimo funkcija yra daug kartų lėtesnė, nei SHA256.*

*Papildomai užduočiai naudojau failą `visos.txt`, tačiau jis buvo per didelis, jog galėčiau jį įkelti į šią repozitoriją.*

**KOLIZIJOS TIKRINIMAS:**

![image](https://user-images.githubusercontent.com/78842487/136350387-e4ecc2ce-5b21-40ec-9663-e94303abebbf.png)

*Visų kolizijos atvejų anuliuoti galutinai nepavyko, tačiau galime pastebėti, jog, kuo ilgesnių stringų pora yra paduodama funkcijai, tuo mažesnė tikimybė, kad hash'ai sutaps.*

*Šiai užduočiai naudojau failus `poros10.txt`, `poros100.txt`, `poros500.txt`, `poros1000.txt`, deja failas `poros1000.txt` buvo per didelis ir negalėjau jo įkelti į šią repozitoriją.*

# V0.1

Ši versija yra galutinė mano hash generatoriaus versija. Ji yra papildyta procentinio skirtingumo skaičiuokle, kuri parodo, kaip mano programa atitinka *lavinos efekto* reikalavimą.

![image](https://user-images.githubusercontent.com/78842487/136405198-0df2680b-7c83-4479-843c-d75aeaad25fb.png)

# IŠVADOS 

Taigi, atlikus šią analizę galiu teigti, jog ne visus reikalavimus sugebėjau įgyvendinti.

**1.** Mano funkcija nėra pilnai atspari kolizijai. Manau, kad taip yra dėl to, jog hash'indama trumpus stringus pridedu atsitiktinius skaičius, o jie dažnai sutampa.

**2.** Mano funkcijos skirtingumo koeficientas yra labai mažas.

Visus kitus reikalavimus išpildžiau:

 - funkcija yra deterministinė. 
 - ji visus, bet kokio ilgio, jai pateikiamus string'us paverčia 64 simbolių ilgio hex kodais.
 - funkcijos reikšmė bet kokiai input'o reikšmei yra apskaičiuojamas pakankamai greitai.
 - iš funkcijos rezultato beveik neįmanoma atgaminti pradinės reikšmės.
