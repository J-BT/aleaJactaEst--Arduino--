# Alea Jacta Est

En utilisant la fonction random pour selectionner un chiffre
au hazard compris entre 0 et 5, le programme va allumer ou pas
un certain nombre de led dès que l'on appuiera sur le bouton.

Les combinaisons de leds (de 0 à 5) representant les surfaces
d'un dés (sans le six) s'enchaineront en ralentissant à chaque
tour, grâce à la fonction `delay()` pour enfin s'arrêter sur 
le dernier chiffre tiré au hazard (voir photo).

## A propos de `ledEteintes[6][5]` et `digitalWrite()`

### digitalWrite()

 `digitalWrite(2, HIGH )` le pin 2 emet du courant
`digitalWrite(2, LOW )` le pin 2 n'emet aucun courant
(HIGH == 1, LOW == 0).
Ainsi tel que le montage est configuré une LED reliée au pin 2
s'allume lorsque le pin n'evoie pas de courant:
- `digitalWrite(2, 0 )` => la LED s'allume
- `digitalWrite(2, 1 )` => la LED s'eteint

 
### ledEteintes[6][5]
 
`boolean ledEteintes[6][5]={
  1,1,1,1,1,      
  1,0,1,1,1,      
  1,1,0,0,1,     
  1,0,0,0,1,      
  0,1,0,0,0,      
  0,0,0,0,0      
};`

Ce tableau à 2 dimensions nous permet de créer
6 combinaisons de LED.
(1 == LED eteinte, 0 == LED allumée)

la premiere ligne `1,1,1,1,1,` correspondant à
`ledEteintes[6][0],
ledEteintes[6][1],
ledEteintes[6][2],
ledEteintes[6][3],
ledEteintes[6][4],`
permet d'eteindre toutes les LED.

à l'inverse la derniere ligne `0,0,0,0,0` les allume
toutes.

 

 

 
