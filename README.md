# Fract-ol

Fractol est un projet de l'école 42 qui consiste à générer et explorer des fractales en utilisant la librairie graphique MinilibX.

## Objectif
L'objectif du projet est de comprendre les nombres complexes et leur utilisation pour générer des fractales comme :
- L'ensemble de Mandelbrot
- L'ensemble de Julia

## Compilation et Exécution

### Prérequis
- MinilibX installée
- Un compilateur C (gcc ou clang)
- Make

### Compilation
```sh
make
```

### Exécution
```sh
./fractol <type>
```
Exemples :
```sh
./fractol mandelbrot
./fractol julia <valeur> <valeur>
```

## Contrôles
- **molette** : Zoom
- **Flèches directionnelles** : Déplacement
- **Touches +/-** : Augmenter la precision de la fractal
- **Echap** : Quitter

## Dépendances
Le projet utilise la **MinilibX**, qui doit être installée avant de compiler le programme.

Pour macOS :
```sh
brew install minilibx
```

Pour Linux :
```sh
sudo apt install libxext-dev libx11-dev libbsd-dev
```

## Auteur
Projet réalisé par Adam Medeneche dans le cadre du cursus 42 Paris.

## Ressources utiles
- [Wiki Fractales](https://fr.wikipedia.org/wiki/Fractale)
- [Documentation MinilibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [Guide Mandelbrot](https://mathworld.wolfram.com/MandelbrotSet.html)
