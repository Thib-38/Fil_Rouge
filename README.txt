Le compilateur retourne deux erreurs :



<    ================================================================================

gcc -c -std=c99 -O0 -g -Wall -Wextra -I./include src/jeu.c -o obj/jeu.o
src/jeu.c: In function ‘questionner_joueur_et_maj’:
src/jeu.c:375:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^

-------------------------------------------------------------------------------------

Dans la fonction en question, je fais un return à l'intérieur d'une boucle et aucun
return à l'extérieur de la boucle donc le Warning est levé; toutefois, le code est
tel que le programme ne peut pas passer à côté de la boucle et qu'il n'en sors que
via le return true/false.

-------------------------------------------------------------------------------------
================================================================================    >





<   =================================================================================

gcc -c -std=c99 -O0 -g -Wall -Wextra -I./include src/suspect.c -o obj/suspect.o
src/suspect.c: In function ‘creer_suspect’:
src/suspect.c:14:19: warning: assignment discards ‘const’ qualifier from pointer target type [enabled by default]
   le_suspect->nom = name ;
                   ^

-------------------------------------------------------------------------------------

On fait un pointeur avec une constante; ce n'est pas un problème dans notre cas car
on ne compte pas changer la valeur de l'entrée "nom" d'un suspect.

-------------------------------------------------------------------------------------
================================================================================    >




Je rends donc le dossier dans l'état, malgré les warnings. Le programme
remplit la fonction demandée :

- > Interface de jeu de qui-est-ce
- > Possibilité de savoir où en est l'I.A dans sa recherche,
- > Retourner le résultat si le joueur ne ment pas, sinon lui dire qu'il ment et que
    mentir c'est mal !


