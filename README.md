# Suika Game en C

Le jeu de la pastèque (Suika Game), écrit en C avec [raylib](https://www.raylib.com/) pour l'affichage. Le moteur physique (gravité, collisions, fusion) est fait à la main, avec l'intégration de Verlet.

## Compiler et lancer

Il faut raylib (sur macOS : `brew install raylib`).

```bash
make        # compile
make run    # compile puis lance
make clean  # supprime l'executable
```

## Avancement

Le plan complet est dans [jeu_pasteque_plan.txt](jeu_pasteque_plan.txt).

- [x] 0. Structures de données
- [x] 1. Affichage
- [x] 2. La main
- [x] 3. Gravité
- [x] 4. Collisions avec la boîte
- [x] 5. Collisions entre fruits
- [x] 6. Fusion
- [ ] 7. Score
- [ ] 8. Game over
- [ ] 9. Graphisme final
