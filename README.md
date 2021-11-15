# TP2: Décryption du chiffrement de César

---

## Description
Ce programme permet de traduire (décrypter) des messages encoder avec l'encryption de César avec des sauts de +3 dans des fichiers donnés en argument au programme et écrit la traduction dans un autre fichier aussi donné en argument.
### Description générale du projet, des détails et le contexte du projet

- **Cours** : Construction et maintenance de logiciels
- **Sigle** : INF3135
- **Enseignant** : Serge Dogny
- **Université** : UQAM

## Auteur

Carl Montpetit (MONC08069000)

## Fonctionnement
1. En premier lieu, il faut compiler le programme avec la commande `make`.

2. Il suffit ensuite de passer deux fichiers en argument au programme comme par exemple :
`./cesar input.txt output.txt`

3. Il est possible de nettoyer (effacer) les fichiers afin de préparer le programme à une autre compilation avec la commande `make clean`.

4. Finalement, on peut lancer les tests avec la commande `make test`.
5. Il existe aussi d'autres fonctionnalités comme :
   - `make all` : Va lancer le tout, compiler et créer l'exécutable
   - `make link` : Va faire l'étape d'édition des liens et va s'arrêter là
   - `make build` : Va construire les fichiers.o (objects) uniquement
   - `make start` : Va lancer le programme, l'exécuter
### Explication du fonctionnement et du résultat des tests
Les tests sont lancés avec l'outil `bats` qui va vérifier le résultats contenue dans certaines variables lorsque le programme est exécuté avec certains arguments prédéfinies. Il va aussi vérifier la présence ou l'absence de certaines lignes dans le `stdout` ou `stderr`. Si un test retourne des valeurs qui n'étaient pas attendus alors le test en question échoue et vice-versa.

>Tous les tests passent sans problèmes localement, mais avec `CI` sur `gitlab` pour une raison ou une autre ils ne passent pas.
## Dépendances
- `gcc`
  - https://gcc.gnu.org
- `bats`
  - https://github.com/sstephenson/bats

## Références
- Ce site a été utilisé comme référence:
https://www.cplusplus.com/reference/
## État du projet

* [x] Le nom du dépôt GitLab est exactement `inf3135-automne2021-tp2` (Pénalité de
  **50%**).
* [x] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab) `https://gitlab.info.uqam.ca/utilisateur/inf3135-automne2021-tp2`
  (Pénalité de **50%**).
* [x] L'utilisateur `dogny_g` et `@correcteurs` a accès au projet en mode *Developer*
  (Pénalité de **50%**).
* [x] Le dépôt GitLab est privé (Pénalité de **50%**).
* [x] Le dépôt contient au moins un fichier `.gitignore`.
* [x] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `test` et `clean`.
* [x] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [x] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [x] L'en-tête du fichier est documentée.
* [x] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [x] Le programme ne contient pas de valeurs magiques.

---
