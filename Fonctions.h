#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// 1-define the structure of the symbol table
typedef struct TypeTS TypeTS;
struct TypeTS {
    char NomEntite[20];
    char CodeEntite[20];
    char TypeEntite[20];
    char isconstante[3];
    int valeurInt;
    float valeurFloat;
    char valeurChar[20];
};

// Structure for a list cell
typedef struct CaseListe CaseListe;
struct CaseListe {
    struct CaseListe *svt;
    struct CaseListe *prec;
    TypeTS entite;
};

// Structure for quadruplets
typedef struct Quad Quad;
struct Quad {
    char operateur[10];    // Opérateur : "+", "-", "=", "IF", etc.
    char operande1[20];    // Premier opérande
    char operande2[20];    // Deuxième opérande (peut être NULL)
    char resultat[20];     // Résultat (ou temporaire)
    struct Quad *svt;      // Pointeur vers le suivant
};

// Global variables for quadruplets
extern Quad *teteQuad;    // Tête de la liste des quadruplets
extern Quad *queueQuad;   // Queue de la liste des quadruplets
extern int compteurTemp;  // Compteur pour les variables temporaires
extern int compteurLabel; // Compteur pour les labels conditionnels

// Structure for identifier list
typedef struct listIdf listIdf;
struct listIdf {
    struct listIdf *svt;
    struct listIdf *prec;
    char idf[20];
};

// Structure for affect list
typedef struct listAffect listAffect;
struct listAffect {
    struct listAffect *svt;
    struct listAffect *prec;
    char idf[20];
};

// Global variables declarations
extern CaseListe *tete;
extern CaseListe *queue;
extern int CpTabSym;
extern int dec;
extern char val[20];
extern char valeurReturn[20];
extern listIdf *teteIdf;
extern listIdf *queueIdf;
extern int pos;
extern listAffect *queueAffec;
extern listAffect *teteAffec;
extern bool conditionResult;

// Function prototypes for symbol table management
int recherche(char entite[]);
TypeTS *rechercheEssai(char entite[]);
void inserer(char enitite[], char code[]);
void afficher(void);
void insererType(char entite[], char type[]);
int DoubleDeclaration(char entite[]);
int isDeclared(char entite[]);
int typeEnregistrer(char entite[]);
void isConstante(char entite[]);
void insererValeur(char entite[], char valeur[]);
int testeSignFormatage(char sign, char type[20]);
int traitementLire(char idf[]);
int traitementEcrire(char chaineEcrire[]);
listIdf *rechercheIdf(char idf[]);
void ajouterElement(char idf[]);
int verifierType(char typeEnre[], char type[]);
int idfEstCst(char entite[]);
int indexOutBound(char idf_tab[], char index[]);
int constanteDec(char constante[]);
int CompatibiliteType(char idf[], char type[], char valeur[], int nb_ligne);
char* rechercheValeur(char entite[]);
listAffect *rechercheIdfAffec(char idf[]);
void ajouterElementAffec(char idf[]);
char* evaluateCondition(const char* condition);
char* createCondition(const char* left, const char* operator, const char* right);

// Define the LoopVariable structure
typedef struct {
    char name[20];  // Name of the variable
    int value;      // Current value of the variable
} LoopVariable;

#define MAX_LOOP_VARS 10
extern LoopVariable loopVars[MAX_LOOP_VARS];  // Array to hold loop variables
extern int loopVarCount;                      // Counter for the number of loop variables

// Function declarations
void addLoopVariable(const char *name, int value);// Function prototypes for intermediate code (quadruplet) management
void ajouterQuad(char operateur[], char operande1[], char operande2[], char resultat[]);
void genererTemp(char temp[]);
void afficherQuads();
void traiterAddition(char a[], char b[], char c[]);
void traiterCondition(char a[], char b[], char label[]);
void genererLabel(char label[]); 
void traiterListeEcriture(const char* liste);

// Function prototypes for new loop-related functionalities
void genererQuad(const char* op, const char* arg1, const char* arg2, const char* result);
void ajouterEtiquette(const char* label);
void ajouterInstructions(const char* instructions);

#endif // FONCTIONS_H
