%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Fonctions.h"
#include "synta.tab.h"

int yylex();
void yyerror(const char *message);

int nb_ligne = 1;  
char TypeEnregistrer[20];
char valeur[20] = "";
char idfType[20] = "";
char type[10] = "";
char constante[20] = "";
int isOperateur = 0;
int priorite = 0;
%}

%union {
    int entier;
    char* string;
    float reel;
}

%token <string> mc_var_global mc_declaration mc_instruction
%token <string> mc_integer mc_float mc_char mc_const mc_for mc_if mc_else mc_main mc_read mc_write
%token <string> cst cstF chaine_ecrire
%token <string> aco_ov aco_fr cr_ov cr_fr par_ouv par_fer  vrg
%token <string>  idf
%token increment decrement
%token inf sup inf_egl sup_egl diff egl afc addition soustraction multip division
%token et ou non dp dpo erreur
%token <string>pvg

%type <string> TYPE GLOBAL_DECLS DECLS INSTRUCTIONS
%type <string> PROGRAM DEC DEC_VAR DEC_TAB DEC_CONST LISTE_IDF LISTE_IDF_TAB ASSIGNMENT LOOP IO CONDITIONAL  CONDITION  EXP EXPP  IDF_CST CONSTANTE
%type <string> GLOBAL_DEC INSTRUCTION  
%type <string>  inst_ecrire
%type <string>  LISTE_IDF_ECRITURE
%type <string>  inst_lire

%start PROGRAM

%nonassoc non
%left ou
%left et
%left egl diff
%left sup inf sup_egl inf_egl
%left addition soustraction
%left multip division

%%

PROGRAM:
    mc_var_global aco_ov GLOBAL_DECLS aco_fr
    mc_declaration aco_ov DECLS aco_fr
    mc_instruction aco_ov INSTRUCTIONS aco_fr
    {
        printf("Programme syntaxiquement correct.\n");
        YYACCEPT;
    }
;

GLOBAL_DECLS:
    GLOBAL_DEC GLOBAL_DECLS
    { $$ = strdup(""); }
    |
    { $$ = strdup(""); }
;

GLOBAL_DEC:
    TYPE LISTE_IDF pvg
    {
        $$ = strdup(""); 
    }
;

DECLS:
    DEC DECLS
    { $$ = strdup(""); }
    |
    { $$ = strdup(""); }
;

DEC:
    DEC_VAR { $$ = strdup(""); }
    | DEC_TAB { $$ = strdup(""); }
    | DEC_CONST { $$ = strdup(""); }
;

DEC_VAR:
    TYPE LISTE_IDF pvg
    {
        $$ = strdup(""); 
    }
;

DEC_TAB:
    TYPE LISTE_IDF_TAB pvg
    {
        $$ = strdup(""); 
    }
;

DEC_CONST:
    mc_const TYPE idf afc CONSTANTE pvg
    {
        if (DoubleDeclaration($3) == 0) {
            insererType($3, TypeEnregistrer);  
            isConstante($3);                  
            
            if (verifierType(TypeEnregistrer, type) == 0) {  
                insererValeur($3, valeur);  
                CompatibiliteType($3, type, valeur, nb_ligne);  
                strcpy(valeur, " ");
            } else {
                printf("Erreur semantique: type incoherent pour la constante %s a la ligne %d.\n", $3, nb_ligne);
            }
        } else {
            printf("Erreur semantique: double declaration de %s a la ligne %d.\n", $3, nb_ligne);
        }
        $$ = strdup(""); 
    }
;

TYPE:
    mc_integer { strcpy(TypeEnregistrer, $1); $$ = strdup($1); }
    | mc_float { strcpy(TypeEnregistrer, $1); $$ = strdup($1); }
    | mc_char { strcpy(TypeEnregistrer, $1); $$ = strdup($1); }
;

LISTE_IDF:
    idf vrg LISTE_IDF
    {
        if (DoubleDeclaration($1) == 0) {
            insererType($1, TypeEnregistrer);
        } else {
            printf("Erreur semantique: double declaration de %s a la ligne %d.\n", $1, nb_ligne);
        }
        $$ = strdup($1); 
    }
    | idf
    {
        if (DoubleDeclaration($1) == 0) {
            insererType($1, TypeEnregistrer);
        } else {
            printf("Erreur semantique: double declaration de %s a la ligne %d.\n", $1, nb_ligne);
        }
        $$ = strdup($1); 
    }
;

LISTE_IDF_TAB:
    idf cr_ov mc_integer cr_fr
    { 
        if (DoubleDeclaration($1) == 0) {
            int size = atoi($3);
            if (size <= 0) {
                printf("Erreur semantique: la taille du tableau %s doit être un entier positif à la ligne %d.\n", $1, nb_ligne);
            } else {
                char sizeStr[10];                // Déclare une chaîne pour stocker la taille
                sprintf(sizeStr, "%d", size);   // Convertit l'entier size en chaîne
                inserer($1, sizeStr);  // Insérer le tableau avec sa taille
            }
        } else {
            printf("Erreur semantique: double déclaration de %s à la ligne %d.\n", $1, nb_ligne);
        }
        $$ = strdup($1); 
    }
    | idf cr_ov mc_integer cr_fr vrg LISTE_IDF_TAB
    { 
        if (DoubleDeclaration($1) == 0) {
            int size = atoi($3);
            if (size <= 0) {
                printf("Erreur semantique: la taille du tableau %s doit être un entier positif à la ligne %d.\n", $1, nb_ligne);
            } else {
                char sizeStr[10];                // Déclare une chaîne pour stocker la taille
                sprintf(sizeStr, "%d", size);   // Convertit l'entier size en chaîne
                inserer($1, sizeStr);  // Insérer le tableau avec sa taille
            }
        } else {
            printf("Erreur semantique: double déclaration de %s à la ligne %d.\n", $1, nb_ligne);
        }
        $$ = strdup($1);
    }
;

INSTRUCTIONS:
    INSTRUCTION INSTRUCTIONS
    {
        // Concaténation des instructions
        char temp[1000];
        sprintf(temp, "%s;%s", $1, $2);  // Séparer les instructions par un délimiteur ";"
        $$ = strdup(temp);
    }
    |
    { $$ = strdup(""); }  // Cas vide
;

INSTRUCTION:
    ASSIGNMENT { $$ = strdup(""); }
    | LOOP { $$ = strdup(""); }
    | IO { $$ = strdup(""); }
    | CONDITIONAL { $$ = strdup(""); }
;

CONDITIONAL:
   mc_if par_ouv CONDITION par_fer aco_ov INSTRUCTIONS aco_fr {
    char labelFalse[20], labelEnd[20];
    genererLabel(labelFalse);
    genererLabel(labelEnd);

    // Quadruplet pour tester la condition
    ajouterQuad("IF", $3, labelFalse, "");

    // Instructions du bloc IF
  
    // Saut à la fin du bloc
    ajouterQuad("GOTO", "", "", labelEnd);

    // Étiquette pour le bloc ELSE
    ajouterEtiquette(labelFalse);

    // Étiquette de fin
    ajouterEtiquette(labelEnd);
}

    
    | mc_if par_ouv CONDITION par_fer aco_ov INSTRUCTIONS aco_fr mc_else aco_ov INSTRUCTIONS aco_fr {
    char labelFalse[20], labelEnd[20];
    genererLabel(labelFalse);
    genererLabel(labelEnd);

    // Quadruplet pour tester la condition
    ajouterQuad("IF", $3, labelFalse, "");

  
    // Saut à la fin
    ajouterQuad("GOTO", "", "", labelEnd);

    // Étiquette pour ELSE
    ajouterEtiquette(labelFalse);

     
    // Étiquette de fin
    ajouterEtiquette(labelEnd);
}

;



CONDITION:
idf inf idf {
    const char* leftValue = rechercheValeur($1);
    const char* rightValue = rechercheValeur($3);

    if (leftValue == NULL || rightValue == NULL) {
        printf("Erreur : Variable non déclarée.\n");
        $$ = 0; // Faux
    } else {
        char temp[20];
        genererTemp(temp);

        // Quadruplet pour la condition
        ajouterQuad("<", $1, $3, temp);

        // Résultat de la condition
        $$ = strdup(temp);
        printf("Condition vérifiée : %s < %s.\n", $1, $3);
    }
}


    | idf sup idf { 
        const char* leftValue = rechercheValeur($1);
        const char* rightValue = rechercheValeur($3);

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", $1, $3, nb_ligne);
        } else if (atof(leftValue) > atof(rightValue)) {
            printf("Condition verifiee: %s > %s.\n", $1, $3);
        } else {
            printf("Condition non verifiee: %s <= %s.\n", $1, $3);
        }
        $$ = strdup(""); 
    }
    | idf inf_egl idf { 
        const char* leftValue = rechercheValeur($1);
        const char* rightValue = rechercheValeur($3);

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", $1, $3, nb_ligne);
        } else if (atof(leftValue) <= atof(rightValue)) {
            printf("Condition verifiee: %s <= %s.\n", $1, $3);
        } else {
            printf("Condition non verifiee: %s > %s.\n", $1, $3);
        }
        $$ = strdup(""); 
    }
    | idf sup_egl idf { 
        const char* leftValue = rechercheValeur($1);
        const char* rightValue = rechercheValeur($3);

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", $1, $3, nb_ligne);
        } else if (atof(leftValue) >= atof(rightValue)) {
            printf("Condition verifiee: %s >= %s.\n", $1, $3);
        } else {
            printf("Condition non verifiee: %s < %s.\n", $1, $3);
        }
        $$ = strdup(""); 
    }
    | idf egl idf { 
        const char* leftValue = rechercheValeur($1);
        const char* rightValue = rechercheValeur($3);

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", $1, $3, nb_ligne);
        } else if (strcmp(leftValue, rightValue) == 0) {
            printf("Condition verifiee: %s == %s.\n", $1, $3);
        } else {
            printf("Condition non verifiee: %s != %s.\n", $1, $3);
        }
        $$ = strdup(""); 
    }
    | idf diff idf { 
        const char* leftValue = rechercheValeur($1);
        const char* rightValue = rechercheValeur($3);

        if (leftValue == NULL || rightValue == NULL) {
            printf("Erreur semantique: Une des variables %s ou %s n'est pas declaree à la ligne %d.\n", $1, $3, nb_ligne);
        } else if (strcmp(leftValue, rightValue) != 0) {
            printf("Condition verifiee: %s != %s.\n", $1, $3);
        } else {
            printf("Condition non verifiee: %s == %s.\n", $1, $3);
        }
        $$ = strdup(""); 
    }
    | non CONDITION { 
        const char* conditionValue = evaluateCondition($2);

        if (conditionValue == NULL) {
            printf("Erreur semantique: Condition non valide à la ligne %d.\n", nb_ligne);
        } else if (!atoi(conditionValue)) {
            printf("Condition verifiee: NON %s.\n", $2);
        } else {
            printf("Condition non verifiee: %s.\n", $2);
        }
        $$ = strdup(""); 
    }
    | CONDITION et CONDITION {
    char temp1[20], temp2[20], tempResult[20];
    genererTemp(temp1);
    genererTemp(temp2);
    genererTemp(tempResult);

    // Quadruplets pour les deux conditions
    ajouterQuad("AND", $1, $3, tempResult);

    // Résultat global
    $$ = strdup(tempResult);
    printf("Condition combinée (ET) : %s ET %s.\n", $1, $3);
}

    | CONDITION ou CONDITION { 
        const char* leftCondition = evaluateCondition($1);
        const char* rightCondition = evaluateCondition($3);

        if (leftCondition == NULL || rightCondition == NULL) {
            printf("Erreur semantique: Conditions non valides à la ligne %d.\n", nb_ligne);
        } else if (atoi(leftCondition) || atoi(rightCondition)) {
            printf("Condition verifiee: %s OU %s.\n", $1, $3);
        } else {
            printf("Condition non verifiee: %s ET %s.\n", $1, $3);
        }
        $$ = strdup(""); 
    }
;



ASSIGNMENT:
    idf afc EXP pvg
    {
        const char* varType = rechercheEssai($1)->TypeEntite;

        if (varType == NULL) {
            printf("Erreur semantique: La variable %s n'est pas declaree a la ligne %d.\n", $1, nb_ligne);
        } else if (strcmp(varType, "FLOAT") == 0) {
            // Directly assign the float value
            insererValeur($1, $3);
        } else if (strcmp(varType, "INTEGER") == 0) {
            // Format and insert as integer
            int intValue = atoi($3);
            char buffer[20];
            sprintf(buffer, "%d", intValue);
            insererValeur($1, buffer);
        } else if (strcmp(varType, "CHAR") == 0) {
            // Direct assignment for CHAR type
            insererValeur($1, $3);
        } else {
            printf("Erreur semantique: Type inconnu pour %s.\n", $1);
        }

        // Ajout du quadruplet pour l'affectation
        // Le quadruplet aura la forme (operande1 = operande2) où operande1 est la variable et operande2 est la valeur assignée
        ajouterQuad("=", $3, "", $1);

        $$ = strdup($3); 
    }
;

LOOP:
    mc_for par_ouv idf afc EXPP dp EXPP dp EXPP par_fer aco_ov INSTRUCTIONS aco_fr
    {
        char loopVar[20];
        strcpy(loopVar, $3);  
       
        int start = atoi($5);   // Starting value
        int step = atoi($7);    // Step value
        int limit = atoi($9);   // Limit value
        
        char buffer[20];  // Buffer pour la conversion des entiers
        int lastValue = start;

        sprintf(buffer, "%d", start);  
        inserer(loopVar, buffer);  // Insérer la variable de boucle dans la table des symboles
        insererValeur(loopVar, buffer);  // Mettre à jour la valeur de la variable de boucle dans la table des symboles

        char loopLabel[20];
        genererLabel(loopLabel);
        ajouterQuad("LABEL", loopLabel, "", "");

        // Générer une étiquette pour la fin de la boucle
        char endLabel[20];
        genererLabel(endLabel);  // Générez une étiquette unique pour la fin

        // Exécuter la boucle FOR
        for (int i = start; i <= limit; i += step) {
            lastValue = i;   
            sprintf(buffer, "%d", i);
            insererValeur(loopVar, buffer);  // Mettre à jour la valeur de loopVar dans la table des symboles

            // Vérification conditionnelle et instruction de saut (fin de boucle)
            ajouterQuad("IF", loopVar, ">", endLabel);  // Si loopVar > limit, sauter à endLabel

            int currentSum = atoi(rechercheValeur(loopVar));
            currentSum += i;
            sprintf(buffer, "%d", currentSum);
            ajouterQuad("=", buffer, "", loopVar);  // Mettre à jour "Sum"

            // Ajouter un quadruplet pour le saut à l'étiquette de fin de boucle
            ajouterQuad("GOTO", "", "", loopLabel);  // Retourner au début de la boucle
        }

        // Ajouter un quadruplet pour l'étiquette de fin de boucle
        ajouterQuad("LABEL", endLabel, "", "");  // Fin de la boucle

        // Insérer la valeur finale de loopVar dans la table des symboles
        sprintf(buffer, "%d", limit);  // La valeur finale de loopVar est égale à limit
        insererValeur(loopVar, buffer);  // Insérer la valeur finale de loopVar dans la table des symboles

        $$ = strdup("");  // Retourner une valeur vide pour la consistance du parser
    }
;



IO:
    inst_lire
    |inst_ecrire
;

inst_lire:
    mc_read par_ouv idf par_fer pvg {
        if(traitementLire($5)==-1){
            printf("erreur semantique dans la ligne %d la variable %s est mal lu\n",nb_ligne,$3);}
    }
;
inst_ecrire:
    mc_write par_ouv chaine_ecrire  vrg LISTE_IDF_ECRITURE par_fer pvg { 
        if(traitementEcrire($3)==-1){
            printf("erreur semantique dans la ligne %d la variable est mal ecrite\n",nb_ligne);}}
    |mc_write par_ouv chaine_ecrire par_fer pvg  { 
        if(traitementEcrire($3)==-1){
            printf("erreur semantique dans la ligne %d la variable est mal ecrite\n",nb_ligne);}}
;

LISTE_IDF_ECRITURE : 
    idf vrg LISTE_IDF_ECRITURE  {
        if(typeEnregistrer($1)==-1){
            printf("erreur semantique dans la ligne %d la variable %s est non declare\n",nb_ligne,$1);}
        else{ajouterElement($1);}}
    |idf  {
        if(typeEnregistrer($1)==-1){
            printf("erreur semantique dans la ligne %d la variable %s est non declare\n",nb_ligne,$1);}
        else{ajouterElement($1);}}
;
EXP:
    EXP addition EXP { 
        float left = atof($1); 
        float right = atof($3); 
        float result = left + right;

        // Ajout du quadruplet pour l'addition
        char resultStr[20];
        sprintf(resultStr, "%.2f", result);  // Formater le résultat comme float
        ajouterQuad("+", $1, $3, resultStr);

        $$ = strdup(resultStr);
    }
    | EXP soustraction EXP { 
        float left = atof($1); 
        float right = atof($3); 
        float result = left - right;

        // Ajout du quadruplet pour la soustraction
        char resultStr[20];
        sprintf(resultStr, "%.2f", result);
        ajouterQuad("-", $1, $3, resultStr);

        $$ = strdup(resultStr);
    }
    | EXP multip EXP { 
        float left = atof($1); 
        float right = atof($3); 
        float result = left * right;

        // Ajout du quadruplet pour la multiplication
        char resultStr[20];
        sprintf(resultStr, "%.2f", result);
        ajouterQuad("*", $1, $3, resultStr);

        $$ = strdup(resultStr);
    }
    | EXP division EXP { 
        float left = atof($1); 
        float right = atof($3); 
        if (right == 0) {
            yyerror("Division by zero!");
            $$ = strdup("0.0");
        } else {
            float result = left / right; 
            char resultStr[20];
            sprintf(resultStr, "%.2f", result);

            // Ajout du quadruplet pour la division
            ajouterQuad("/", $1, $3, resultStr);

            $$ = strdup(resultStr);
        }
    }
    | IDF_CST { 
        $$ = strdup($1); 
    }
;

EXPP:
    cst { 
        $$ = strdup($1); 
    }
    | cstF { 
        $$ = strdup($1); 
    }
    | idf { 
        $$ = strdup(rechercheValeur($1)); 
    }
;





IDF_CST:
    idf { 
        $$ = strdup(rechercheValeur($1)); 
    }
    | CONSTANTE { 
        $$ = strdup($1); 
    }
;


CONSTANTE:
    cst  {
        if (isOperateur == 0) {
            strcpy(valeur, $1);
            strcpy(type, "INTEGER"); // Assign type as INTEGER
            ajouterElementAffec($1);
        } else {
            ajouterElementAffec($1);
        }
    }
    | cstF {
        if (isOperateur == 0) {
            strcpy(valeur, $1);
            strcpy(type, "FLOAT"); // Assign type as FLOAT
            ajouterElementAffec($1);
        } else {
            ajouterElementAffec($1);
        }
    }
    | chaine_ecrire {
        if (isOperateur == 0) {
            strcpy(valeur, $1);
            strcpy(type, "CHAR"); // Assign type as CHAR
            ajouterElementAffec($1);
        } else {
            ajouterElementAffec($1);
        }
    }


%%

int main() {
    yyparse();
    afficher();
    afficherQuads();
    return 0;
}

void yyerror(const char *message) {
    printf("Erreur syntaxique a la ligne %d: %s\n", nb_ligne, message);
}