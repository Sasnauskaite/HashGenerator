# HashGenerator
# V0.0.1

Sukurtas HASH generatorius, kuris bet kokią įvestį paverčia 64 simbolių hex kodu.
Mano hash funkcijos idėja:
* 1.* Kiekvienam įvesto string'o simboliui priskiriama tam tikra reikšmė.
* 2.* Su priskirtomis reikšmėmis atliekami matematiniai veiksmai ir gainamos atskiros galutinio rezultato dalys (tam tikra skaičių seka bei raidė).
* 3.* Po kiekvienos atskiros galutinio rezultato gavimo dalies ji yra pridedama prie išeigos string'o.
* 4.* Jei išeigos stringas po visų įvesto stringo simbolių suhashavimo nesiekia 64 simbolių prie jo yra pridedamos skaitinės reikšmės, kol išvesties stringas pasiekia 64 simbolių ilgį.
