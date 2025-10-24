#include "Fonctions.h"

//CaseListe stores the declaration details.
//listAffect tracks its use in assignments.


// Global variables definitions
CaseListe *tete = NULL; //Pointer to the head  of the linked list representing the symbol table
CaseListe *queue = NULL; //Pointersto the tail of the linked list representing the symbol table
int CpTabSym = 0; //Counter tracking the number of symbols in the table
int dec = 0;
char val[20];
char valeurReturn[20];
listIdf *teteIdf = NULL; //Head and tail of the list of identifiers
listIdf *queueIdf = NULL;
int pos = 0;
listAffect *queueAffec = NULL; //Head and tail for the list of identifiers used in assignments.
listAffect *teteAffec = NULL;
bool conditionResult = false;

//Variables globales
Quad *teteQuad = NULL;
Quad *queueQuad = NULL;
int compteurTemp = 0;
int compteurLabel = 0;

// 4- Search in the table
int recherche(char entite[]) {
    CaseListe *courant; CaseListe *suivant;

    if (tete != NULL) {
        courant = tete;
        suivant = courant->svt;
        int i = 0;
        if (strcmp(entite, tete->entite.NomEntite) == 0) {
            return i;
        }
        while (suivant != NULL) {
            if (strcmp(entite, courant->entite.NomEntite) == 0) {
                return i;
            }
            courant = suivant;
            suivant = courant->svt;
            i++;
        }
        queue = courant;

        if (strcmp(entite, queue->entite.NomEntite) == 0) {
            return i;
        }
        return -1;
    }
    return -1;
}

TypeTS* rechercheEssai(char entite[]) {
    CaseListe *courant = tete;  

    while (courant != NULL) {
        if (strcmp(courant->entite.NomEntite, entite) == 0) {
            return &courant->entite;  
        }
        courant = courant->svt;  
    }

    return NULL;  // Not found
}


void inserer(char enitite[], char code[]) {
    CaseListe *courant; CaseListe *suivant;
    CaseListe *caseAjout = (CaseListe*) malloc(sizeof(CaseListe));

    if (tete != NULL) {
        courant = tete;
        suivant = courant->svt;

        if (rechercheEssai(enitite) == NULL) { 
            strcpy(caseAjout->entite.NomEntite, enitite);
            strcpy(caseAjout->entite.CodeEntite, code);
            strcpy(caseAjout->entite.isconstante, "Non");
            strcpy(caseAjout->entite.valeurChar, "");

            caseAjout->prec = queue;
            caseAjout->svt = NULL;
            queue->svt = caseAjout;
            queue = caseAjout;
            CpTabSym++;
        } else {
            dec = 1; // Duplicate declaration
        }
    } else { 
        tete = caseAjout;
        strcpy(tete->entite.NomEntite, enitite);
        strcpy(tete->entite.CodeEntite, code);
        strcpy(tete->entite.TypeEntite, "class");
        strcpy(tete->entite.isconstante, "Non");
        strcpy(tete->entite.valeurChar, "");

        tete->svt = NULL;
        tete->prec = NULL;
        queue = tete;
        CpTabSym++;
    }
}
// Génère un quadruplet et l'ajoute à la liste des quadruplets
void genererQuad(const char* operateur, const char* operande1, const char* operande2, const char* resultat) {
    Quad *newQuad = (Quad*) malloc(sizeof(Quad));
    
    strcpy(newQuad->operateur, operateur);
    strcpy(newQuad->operande1, operande1);
    strcpy(newQuad->operande2, operande2);
    strcpy(newQuad->resultat, resultat);
    
    newQuad->svt = NULL;

    // Si la liste des quadruplets est vide, on initialise la tête et la queue
    if (teteQuad == NULL) {
        teteQuad = newQuad;
        queueQuad = newQuad;
    } else {
        queueQuad->svt = newQuad;
        queueQuad = newQuad;
    }
}
// Génère une étiquette et l'ajoute à la liste des étiquettes
void ajouterEtiquette(const char* label) {
    // Crée un quadruplet d'étiquette
    genererQuad("LABEL", label, "", "");
}
// Ajoute une instruction à la liste des quadruplets
void ajouterInstructions(const char* instructions) {
    // Exemple : Ajouter une instruction de saut ou d'opération à un quadruplet
    genererQuad("GOTO", "", "", instructions);  // Instructions de saut par exemple
}
// Génère un label unique pour les boucles ou conditions
void genererLabel(char* label) {
    sprintf(label, "L%d", compteurLabel++);
}
void traiterListeEcriture(const char* liste) {
    char* liste_modifiable = strdup(liste);
    if (liste_modifiable == NULL) {
        printf("Erreur : allocation mémoire échouée.\n");
        return;
    }
    char* token = strtok(liste_modifiable, ","); 
    while (token != NULL) {
        if (rechercheEssai(token) == NULL) { 
            printf("Erreur sémantique : La variable %s n'est pas declaree.\n", token);
        } else {
            printf("Variable %s prete pour l'ecriture.\n", token);
        }
        token = strtok(NULL, ",");
    }

    free(liste_modifiable); 
}

void afficher() {
    printf("\n\n***************Table de symbole***************\n");
    CaseListe *courant;

    if (tete != NULL) {
        courant = tete;
        printf("_______________________________________________________________________________\n");
        printf("\t|NomEntite  |  CodeEntite | TypeEntite  | Constante | Valeur\n");
        printf("_______________________________________________________________________________\n");

        while (courant != NULL) {
            if (strcmp(courant->entite.TypeEntite, "class") != 0) {
                printf("\t|%10s |%12s |%12s |%10s |%10s\n",
                    courant->entite.NomEntite,
                    courant->entite.CodeEntite,
                    courant->entite.TypeEntite,
                    courant->entite.isconstante,
                    courant->entite.valeurChar);
            }
            courant = courant->svt;
        }
    } else {
        printf("La partie declaration est vide !\n");
    }
}

void insererType(char entite[], char type[]) {
    TypeTS *entiteExiste = rechercheEssai(entite);
    if (entiteExiste != NULL) {
        strcpy(entiteExiste->TypeEntite, type);
    }
}


int DoubleDeclaration(char entite[]) {
    int position;

    if (dec == 0) {
        position = recherche(entite);

        if (tete != NULL && position != -1) {
            return 0; 
        }
    } else {
        dec = 0; 
        return -1;
    }

    return -1; 
}

int isDeclared(char entite[]) {
    if (recherche(entite) != -1) {
        return 0;
    }
    return -1;
}

int typeEnregistrer(char entite[]) {
    TypeTS *entiteRchercher = rechercheEssai(entite);
    if (entiteRchercher != NULL) {
        if (strcmp(entiteRchercher->TypeEntite, "") == 0) {
            return -1;
        }
        return 0;
    }
    return -1;
}

void isConstante(char entite[]) {
    TypeTS *entiteRchercher = rechercheEssai(entite);
    if (entiteRchercher != NULL) {
        strcpy(entiteRchercher->isconstante, "Oui");
    }
}

void insererValeur(char entite[], char valeur[]) {
    int position, encours;
    position = recherche(entite);
    CaseListe *courant; CaseListe *suivant;

    if (position != -1) {
        courant = tete;
        suivant = courant->svt;
        encours = 0;

        while (encours != position) {
            courant = suivant;
            suivant = courant->svt;
            encours++;
        }
        strcpy(courant->entite.valeurChar, valeur);
       if (strcmp(courant->entite.TypeEntite, "CHAR") == 0) {
            if (valeur[0] == '"' && valeur[strlen(valeur) - 1] == '"') {
                valeur[strlen(valeur) - 1] = '\0';  // Remove the ending quote
                memmove(valeur, valeur + 1, strlen(valeur));  // Remove the starting quote
            }
            strcpy(courant->entite.valeurChar, valeur);  
        }
    }
}

int testeSignFormatage(char sign, char type[20]) {
    if (strcmp(type, "Entier") == 0) {
        if (sign == 'd') {
            return 0;
        }
        return -1;
    }
    if (strcmp(type, "Reel") == 0) {
        if (sign == 'f') {
            return 0;
        }
        return -1;
    }
    if (strcmp(type, "Chaine") == 0) {
        if (sign == 's') {
            return 0;
        }
        return -1;
    }
    return -1;
}

int traitementLire(char idf[]) {
    TypeTS *entiteRchercher = rechercheEssai(idf);

    if (entiteRchercher == NULL) {
        return -1; 
    }

    printf("READ est syntaxiquement et semantiquement correct pour l'identifiant %s.\n", idf);
    return 0; 
}

int traitementEcrire(char chaineEcrire[]) {
    int i = 0, taille = strlen(chaineEcrire), retour = 0;
    char idf[20];  
    char message[256];  
    
    while (i < taille && chaineEcrire[i] != '"') {
        i++;  
    }

    i++;

    int msg_index = 0;
    while (i < taille && chaineEcrire[i] != '"') {
        message[msg_index++] = chaineEcrire[i++];
    }
    message[msg_index] = '\0'; 

    printf("Message: %s\n", message);

    i++;
    while (i < taille && (chaineEcrire[i] == ' ' || chaineEcrire[i] == ',')) {
        i++;
    }
    int j = 0;
    while (i < taille && (isalpha(chaineEcrire[i]) || chaineEcrire[i] == '_')) {
        if (j < sizeof(idf) - 1) {  
            idf[j++] = chaineEcrire[i++];
        } else {
            break;  
        }
    }
    idf[j] = '\0';  

    return 0;  // Success
}


listIdf *rechercheIdf(char idf[]) {
    listIdf *courant;
    listIdf *suivant;

    if (teteIdf != NULL) {
        courant = teteIdf;
        suivant = courant->svt;

        if (strcmp(idf, teteIdf->idf) == 0) {
            return teteIdf;
        }

        // Search through the list of identifiers.
        while (suivant != NULL) {
            if (strcmp(idf, courant->idf) == 0) {
                return courant;
            }
            courant = suivant;
            suivant = courant->svt;
        }

        queueIdf = courant;

         if (strcmp(idf, queueIdf->idf) == 0) {
            return queueIdf;
        }

        return NULL;  // if identifier is not found.
    }

    return NULL;  //if the list is empty.
}

void ajouterElement(char idf[]) {
    listIdf *courant; listIdf *suivant;
    listIdf *caseAjout = (listIdf*) malloc(sizeof(listIdf));

    if (teteIdf != NULL) {
        courant = teteIdf;
        suivant = courant->svt;

        if (rechercheIdf(idf) == NULL) {
            strcpy(caseAjout->idf, idf);
            caseAjout->prec = queueIdf;
            caseAjout->svt = NULL;
            queueIdf->svt = caseAjout;
            queueIdf = caseAjout;
            CpTabSym++;
        } else {
            dec = 1;
        }
    } else { // First element treatment
        teteIdf = caseAjout;
        strcpy(teteIdf->idf, idf);
        teteIdf->svt = NULL;
        teteIdf->prec = NULL;
        queueIdf = teteIdf;
        CpTabSym++;
    }
}

int verifierType(char typeEnre[], char type[]) {
    if (strcmp(typeEnre, type) == 0) {
        return 0;
    }
    return -1;
}

int idfEstCst(char entite[]) {
    TypeTS *entiteRchercher = rechercheEssai(entite);
    if (entiteRchercher != NULL) {
        if (strcmp(entiteRchercher->isconstante, "Oui") == 0) {
            return 0;
        }
        return 1;
    }
    return -1;
}

int indexOutBound(char idf_tab[], char index[]) {
    TypeTS *entiteRchercher = rechercheEssai(idf_tab);
    if (entiteRchercher != NULL) {
        if ((atoi(entiteRchercher->valeurChar) > atoi(index)) && atoi(index) >= 0) {
            return 0;
        }
        return -1;
    }
    return -1;
}

int constanteDec(char constante[]) {
    TypeTS *entiteRchercher = rechercheEssai(constante);
    if (entiteRchercher != NULL) {
        if (strcmp(entiteRchercher->valeurChar, "") == 0 && strcmp(entiteRchercher->isconstante, "Oui") == 0) {
            return 0;
        }
        return -1;
    }
    return -1;
}

char* rechercheValeur(char entite[]) {
    TypeTS *entiteRchercher = rechercheEssai(entite);
    if (entiteRchercher != NULL) {
        return entiteRchercher->valeurChar;
    }
    return NULL;
}

int CompatibiliteType(char idf[], char type[], char valeur[], int nb_ligne) {
    TypeTS *entiteIdfRechercher = rechercheEssai(idf);

    if (entiteIdfRechercher != NULL) {

        if (strcmp(entiteIdfRechercher->TypeEntite, "FLOAT") == 0) {

            if (strcmp(type, "FLOAT") == 0) {
                return 0; 
            }
        }

        else if (strcmp(entiteIdfRechercher->TypeEntite, "INTEGER") == 0) {
            if (strcmp(type, "INTEGER") == 0) {
                return 0; 
            }
            else if (strcmp(type, "FLOAT") == 0) {
                printf("Erreur semantique: Le type de %s (%s) n'est pas compatible avec %s (%s) a la ligne %d.\n",
                       idf, entiteIdfRechercher->TypeEntite, valeur, type, nb_ligne);
                return -1; 
            }
        }

        else if (strcmp(entiteIdfRechercher->TypeEntite, "CHAR") == 0) {
            if (strcmp(type, "CHAR") == 0) {
                return 0; 
            }
            else if (strcmp(type, "INTEGER") == 0 || strcmp(type, "FLOAT") == 0) {
                printf("Erreur semantique: Le type de %s (%s) n'est pas compatible avec %s (%s) a la ligne %d.\n",
                       idf, entiteIdfRechercher->TypeEntite, valeur, type, nb_ligne);
                return -1;
            }
        }

        printf("Erreur semantique: Le type de %s (%s) n'est pas compatible avec %s a la ligne %d.\n",
               idf, entiteIdfRechercher->TypeEntite, valeur, nb_ligne);
        return -1; 
    }


    printf("Erreur semantique: La variable %s n'est pas declaree a la ligne %d.\n", idf, nb_ligne);
    return -1; 
}


listAffect *rechercheIdfAffec (char idf[]){
       listAffect *courant; listAffect *suivant;
       if (teteAffec!=NULL)
       {
       courant=teteAffec;
       suivant=courant->svt;
       int i=0;
       if (strcmp(idf, teteAffec->idf)==0)
       {
         return teteAffec;
       }
       while (suivant!=NULL)
       {
              if (strcmp(idf,teteAffec->idf)==0)
              {
                    return courant;
              }
              courant=suivant;
              suivant=courant->svt;
              i++;
       }
       queueAffec=courant;

       if (strcmp(idf, queueAffec->idf)==0)
       {
              return queueAffec;
       }
       return NULL;
       }
         return NULL;

}

void ajouterElementAffec(char idf[]){
      listAffect *courant; listAffect *suivant;
      listAffect *caseAjout=(listAffect*) malloc(sizeof(listAffect));
      if (teteAffec!=NULL)
       {
       courant=teteAffec;
       suivant=courant->svt;

       if(rechercheIdfAffec(idf)==NULL){
              strcpy(caseAjout->idf,idf);
              caseAjout->prec=queueAffec;
              caseAjout->svt=NULL;
              queueAffec->svt=caseAjout;
              queueAffec=caseAjout;
       }else {dec=1;}
       }else{//Traitement du premier element
          teteAffec=caseAjout;
          strcpy(teteAffec->idf,idf);
          teteAffec->svt=NULL;
          teteAffec->prec=NULL;
       }
}

char* createCondition(const char* left, const char* operator, const char* right) {
    size_t len = strlen(left) + strlen(operator) + strlen(right) + 4; // Extra space for spaces and null terminator
    char* condition = (char*)malloc(len);
    if (condition == NULL) {

        perror("Failed to allocate memory for condition");
        exit(1);
    }
    sprintf(condition, "%s %s %s", left, operator, right);
    return condition;
}

char* evaluateCondition(const char* condition) {
    static char result[6];  

    char left[50], operator[3], right[50];
    if (sscanf(condition, "%s %s %s", left, operator, right) != 3) {
        fprintf(stderr, "Invalid condition format: %s\n", condition);
        strcpy(result, "false");  
        return result;
    }
    const char* leftStr = rechercheValeur(left);
    const char* rightStr = rechercheValeur(right);

    if (!leftStr || !rightStr) {
        fprintf(stderr, "Undefined variable(s): %s or %s\n", left, right);
        strcpy(result, "false"); 
        return result;
    }

    float leftValue = atof(leftStr);
    float rightValue = atof(rightStr);

    printf("Evaluating: %s %s %s\n", leftStr, operator, rightStr);
    printf("Left value: %f, Right value: %f\n", leftValue, rightValue);

    if (strcmp(operator, "<") == 0) {
        if (leftValue < rightValue) {
            strcpy(result, "true");
        } else {
            strcpy(result, "false");
        }
    } else if (strcmp(operator, ">") == 0) {
        if (leftValue > rightValue) {
            strcpy(result, "true");
        } else {
            strcpy(result, "false");
        }
    } else if (strcmp(operator, "<=") == 0) {
        if (leftValue <= rightValue) {
            strcpy(result, "true");
        } else {
            strcpy(result, "false");
        }
    } else if (strcmp(operator, ">=") == 0) {
        if (leftValue >= rightValue) {
            strcpy(result, "true");
        } else {
            strcpy(result, "false");
        }
    } else if (strcmp(operator, "==") == 0) {
        if (leftValue == rightValue) {
            strcpy(result, "true");
        } else {
            strcpy(result, "false");
        }
    } else if (strcmp(operator, "!=") == 0) {
        if (leftValue != rightValue) {
            strcpy(result, "true");
        } else {
            strcpy(result, "false");
        }
    } else {
        fprintf(stderr, "Unknown operator: %s\n", operator);
        strcpy(result, "false");  
    }

    return result;  
}


// Ajouter un quadruplet
void ajouterQuad(char operateur[], char operande1[], char operande2[], char resultat[]) {
    Quad *nouveau = (Quad *)malloc(sizeof(Quad));
    strcpy(nouveau->operateur, operateur);
    strcpy(nouveau->operande1, operande1);
    strcpy(nouveau->operande2, operande2);
    strcpy(nouveau->resultat, resultat);
    nouveau->svt = NULL;

    if (teteQuad == NULL) {
        teteQuad = nouveau;
        queueQuad = nouveau;
    } else {
        queueQuad->svt = nouveau;
        queueQuad = nouveau;
    }
}
LoopVariable loopVars[10];  
int loopVarCount = 0;     

// Function to add a variable to the loopVars array
void addLoopVariable(const char *name, int value) {
    strcpy(loopVars[loopVarCount].name, name);
    loopVars[loopVarCount].value = value;
    loopVarCount++;
}

// Générer une variable temporaire
void genererTemp(char temp[]) {
    sprintf(temp, "T%d", compteurTemp);
    compteurTemp++;
}

// Afficher les quadruplets
void afficherQuads() {
    // Vérifier si la liste est vide
    if (teteQuad == NULL) {
        printf("\n\nAucun quadruplet a afficher.\n");
        return;
    }

    Quad *courant = teteQuad;
    printf("\n\n*************** Code Intermediaire ***************\n");
    printf("_________________________________________________________________\n");
    printf("| Operateur | Operande1  | Operande2  | Resultat   |\n");
    printf("_________________________________________________________________\n");

    while (courant != NULL) {
        // Affichage formaté pour chaque quadruplet
        printf("| %-10s | %-10s | %-10s | %-10s |\n",
               courant->operateur,
               courant->operande1,
               courant->operande2,
               courant->resultat);
        courant = courant->svt;
    }
    printf("_________________________________________________________________\n");
}


// Traiter une addition
void traiterAddition(char a[], char b[], char c[]) {
    char temp[20];
    genererTemp(temp);
    ajouterQuad("+", b, c, temp);
    ajouterQuad(":=", temp, "", a);
}

// Traiter une condition
void traiterCondition(char a[], char b[], char label[]) {
    ajouterQuad("IF<", a, b, label);
}
void traiterSoustraction(char a[], char b[], char c[]) {
    char temp[20];
    genererTemp(temp);
    ajouterQuad("-", b, c, temp);
    ajouterQuad(":=", temp, "", a);
}

void traiterMultiplication(char a[], char b[], char c[]) {
    char temp[20];
    genererTemp(temp);
    ajouterQuad("*", b, c, temp);
    ajouterQuad(":=", temp, "", a);
}

void traiterDivision(char a[], char b[], char c[]) {
    char temp[20];
    genererTemp(temp);
    ajouterQuad("/", b, c, temp);
    ajouterQuad(":=", temp, "", a);
}
void traiterAffectation(char a[], char b[]) {
    ajouterQuad(":=", b, "", a);
}
void traiterConditionEgal(char a[], char b[], char label[]) {
    ajouterQuad("IF==", a, b, label);
}

void traiterConditionDiff(char a[], char b[], char label[]) {
    ajouterQuad("IF!=", a, b, label);
}

void traiterConditionInf(char a[], char b[], char label[]) {
    ajouterQuad("IF<", a, b, label);
}

void traiterConditionSup(char a[], char b[], char label[]) {
    ajouterQuad("IF>", a, b, label);
}

void traiterConditionInfEgal(char a[], char b[], char label[]) {
    ajouterQuad("IF<=", a, b, label);
}

void traiterConditionSupEgal(char a[], char b[], char label[]) {
    ajouterQuad("IF>=", a, b, label);
}
void traiterDebutBoucle(char label[]) {
    genererLabel(label);
    ajouterQuad("LABEL", label, "", "");
}

void traiterFinBoucle(char label[]) {
    ajouterQuad("GOTO", label, "", "");
}

void traiterConditionBoucle(char a[], char b[], char label[]) {
    ajouterQuad("IF==", a, b, label); // Condition pour sortir de la boucle
}
void traiterIf(char condition[], char labelTrue[], char labelFalse[]) {
    ajouterQuad("IF", condition, "", labelTrue);
    ajouterQuad("GOTO", "", "", labelFalse);
}

void traiterElse(char label[]) {
    ajouterQuad("LABEL", label, "", "");
}

