# Labb6
Linux som utvecklingsmiljö - Labb 6
Grupp 149

### Saker kvar att göra

- [x] libresistance

- [x] libpower
- [ ] bug: fel uteffekt i libpower 

- [x] libcomponent
 
- [ ] electrotest
- [ ] felinmatningar säkrade i electrotest

- [ ] Makefile

### Förväntad resultat

När electrotest körs är detta det förväntade resultatet.

```
%./electrotest
Ange spänningskälla i V: 50
Ange koppling[S | P]: S
Antal komponenter: 3
Komponent 1 i ohm: 300
Komponent 2 i ohm: 500
Komponent 3 i ohm: 598
Ersättningsresistans:
1398,0 ohm
Effekt:
1.78 W
Ersättningsresistanser i E12-serien kopplade i serie:
1200
180
18
```
