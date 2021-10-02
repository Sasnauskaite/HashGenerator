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

-1. Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).

**ĮRODYMAS:**

![image](https://user-images.githubusercontent.com/78842487/135724404-a697f8b5-c542-43b4-816f-314adb4fbc0b.png)

`*empty.txt failas yra tuščias failas, simbolis.txt turi tik 1 simbolį, o 3000random.txt turi 3000 atsitiktinų simbolių, mano hash funkcija dirba su visais jai paduotais failais.*`

-2. Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (pageidautina 256 bit'ų ilgio, t.y., 64 simbolių hex'as).

`*Įrodymas yra viršuje, nesvarbu, kokio ilgio failas, jam vistiek pateikiamas 64 simbolių kodas.*`

-3. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.

![image](https://user-images.githubusercontent.com/78842487/135724563-00668de9-095b-40e9-98aa-bc5df627f9d4.png)

`*Ši ekrano nuotrauka parodo, jog žodžiui „labas" hash kodas visuomet yra tas pats.*`

