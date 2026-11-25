#include "raylib.h"
#include <stdbool.h>

/* =========================================================
   CONSTANTES
   ========================================================= */

#define LARGEUR_FENETRE 600
#define HAUTEUR_FENETRE 800

#define NB_NIVEAUX 10      /* nombre de tailles de fruits */
#define MAX_FRUITS 200     /* taille du tableau de fruits */

#define BOITE_X 10
#define BOITE_Y 180
#define BOITE_LARGEUR 580
#define BOITE_HAUTEUR 600

/* =========================================================
   ETAPE 0 : STRUCTURES DE DONNEES
   ========================================================= */

/* Les caracteristiques d'un NIVEAU de fruit (commun a tousles fruits de ce niveau). */
typedef struct {
    float rayon;
    Color couleur;
    int   points;
} InfoNiveau;

typedef struct {
    Vector2 position;            // type = Vector2, nom = position
    Vector2 ancienne_position;
    int     niveau;
    bool    actif;
} Fruit;


static const InfoNiveau NIVEAUX[NB_NIVEAUX] = {
    {  20.0f, { 220,  20,  60, 255 },  1 },  /* niveau 0 : cerise    - rouge cerise   */
    {  30.0f, { 255,  80, 120, 255 },  2 },  /* niveau 1 : fraise    - rose fraise    */
    {  40.0f, { 140,  60, 200, 255 },  3 },  /* niveau 2 : raisin    - violet         */
    {  50.0f, { 255, 220,  40, 255 },  4 },  /* niveau 3 : citron    - jaune          */
    {  60.0f, { 255, 140,   0, 255 },  5 },  /* niveau 4 : kaki      - orange         */
    {  70.0f, { 120, 200,  40, 255 },  6 },  /* niveau 5 : pomme     - vert pomme     */
    {  80.0f, { 210, 190, 120, 255 },  7 },  /* niveau 6 : poire     - beige          */
    {  90.0f, { 200, 150,  30, 255 },  8 },  /* niveau 7 : ananas    - doré           */
    { 100.0f, { 170, 230, 160, 255 },  9 },  /* niveau 8 : melon     - vert pâle      */
    { 120.0f, {  30, 130,  50, 255 }, 10 },  /* niveau 9 : pastèque  - vert foncé     */
};

/* Le tableau de tous les fruits */
static Fruit fruits[MAX_FRUITS];


/* =========================================================
   ETAPE 1 : AFFICHAGE
   ========================================================= */

int main(void)
{
    InitWindow(LARGEUR_FENETRE, HAUTEUR_FENETRE, "Suika Game");   // 1. créer la fenêtre
    SetTargetFPS(60);

    for (int i = 0; i < MAX_FRUITS; i++){
        fruits[i].actif = false;
    }

    while (!WindowShouldClose()) {        // 2. boucle : 1 tour = 1 image
        /* --- 1. Mise a jour (vide pour l'instant) --- */

        /* --- 2. Dessin --- */
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleLinesEx((Rectangle){BOITE_X, BOITE_Y, BOITE_LARGEUR, BOITE_HAUTEUR}, 4, DARKGRAY);

        Vector2 centre = { BOITE_X + BOITE_LARGEUR / 2.0f, BOITE_Y + BOITE_HAUTEUR / 2.0f };
        DrawCircleV(centre, NIVEAUX[2].rayon, NIVEAUX[2].couleur);

        EndDrawing();
    }

    CloseWindow();                        // 3. fermer
    return 0;
}