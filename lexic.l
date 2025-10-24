%{
#include "synta.tab.h"
#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
extern int nb_ligne;
extern YYSTYPE yylval;
%}

%option noyywrap

lettres [a-zA-Z]
idf [a-zA-Z][a-zA-Z0-9_]{0,7}
constante "("[+-]?[0-9]+")"|[+-]?[0-9]+
constanteVirg "("[+-]?[0-9]+\.[0-9]+")"|[+-]?[0-9]+\.[0-9]+
string \"[^"]*\"
commentaire "%%"[^\n]*

%%

VAR_GLOBAL return mc_var_global;
DECLARATION return mc_declaration;
INSTRUCTION return mc_instruction;
INTEGER {
    yylval.string = strdup(yytext);
    return mc_integer;
}
FLOAT {
    yylval.string = strdup(yytext);
    return mc_float;
}
CHAR {
    yylval.string = strdup(yytext);
    return mc_char;
}
CONST return mc_const;
FOR return mc_for;
IF return mc_if;
MAIN return mc_main;
READ return mc_read;
WRITE return mc_write;
ELSE return mc_else;

{idf}\[{constante}\] {
    inserer(yytext, "idf");  
    yylval.string = strdup(yytext);
    return idf;
}

{idf} {
    if (yyleng <= 8) {
        inserer(yytext, "idf");  // Regular insertion for simple identifiers
        yylval.string = strdup(yytext);
        return idf;
    } else {
        printf("Identificateur trop long: %s\n", yytext);
    }
}

{constante} {
    if (-32768 <= atoi(yytext) && atoi(yytext) <= 32767) {
        yylval.string = strdup(yytext);
        return cst;
    } else {
        printf("Valeur entière invalide à la ligne %d: %s\n", nb_ligne, yytext);
    }
}

{constanteVirg} {
    yylval.string = strdup(yytext);
    return cstF;
}



{string} {
    yylval.string = strdup(yytext);
    return chaine_ecrire;
}

{commentaire} { /* Ignore comments */ }

"+" return addition;
"-" return soustraction;
"*" return multip;
"/" return division;
"==" return egl;
"!=" return diff;
">" return sup;
"<" return inf;
">=" return sup_egl;
"<=" return inf_egl;
"&&" { return et; }
"||" { return ou; }
"!"  { return non; }
"{" { return aco_ov; }      
"}" { return aco_fr; }      
"[" { return cr_ov; }        
"]" { return cr_fr; }        
";" { return pvg; }          
"=" { return afc; }          
":" { return dp; }           
"::" { return dpo; }         
"," { return vrg; }          
"(" { return par_ouv; }     
")" { return par_fer; }      

[ \t]+  /* Ignore whitespace */
\n { nb_ligne++; }
. { printf("Erreur lexicale à la ligne %d: %s\n", nb_ligne, yytext); return erreur; }
