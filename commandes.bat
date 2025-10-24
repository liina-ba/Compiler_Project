flex lexic.l
bison -d synta.y
gcc lex.yy.c synta.tab.c Fonctions.c -o MinING
MinING < expLangage.txt