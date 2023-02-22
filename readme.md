# Algorithme de Davies-Putnam:
## 1 - Introduction:
L'algorithme de ***Davis-Putnam*** est un algorithme de résolution de formules de **logique propositionnelle**. Il s'agit d'un algorithme de **backtracking**, c'est-à-dire qu'il essaie différentes valeurs pour les variables dans la formule jusqu'à ce qu'il trouve une solution qui **satisfasse** la formule, ou bien qu'il détermine que la formule est **insatisfiable**.

L'algorithme de ***Davis-Putnam*** utilise une méthode de réduction des formules appelée **"sous-formules implicites"** pour essayer de simplifier la formule de départ avant de commencer le processus de **backtracking**. Cette méthode consiste à remplacer une sous-formule par une nouvelle variable, ce qui peut permettre de réduire la taille de la formule et de rendre le processus de résolution plus efficace.

En général, l'algorithme de ***Davis-Putnam*** est considéré comme étant l'un des algorithmes de résolution de formules de **logique propositionnelle** les plus efficaces et est largement utilisé dans de nombreux domaines, tels que l'***intelligence artificielle*** et la vérification de ***programmes informatiques***.

## 2 - Description de la structure utiliser `clause`:
La structure `clause` est une structure de données utilisée pour représenter une clause dans une formule booléenne en conjonctive normal form (CNF). Elle est utilisée pour stocker une formule booléenne sous forme de liste chaînée de clauses.

La structure `clause` se compose de deux champs :

-   `literal` : un entier qui représente un littéral dans la clause. Les littéraux sont des variables propositionnelles ou leurs négations, et sont représentées par des entiers positifs ou négatifs, où le signe détermine si le littéral est la variable propositionnelle elle-même ou sa négation.
-   `next` : un pointeur vers la clause suivante dans la liste chaînée. Si c'est la dernière clause de la formule, `next` est initialisé à `NULL`.

## 3 - Explication des différentes fonctions utiliser:
### a - la fonction `remove_clauses()`:
La fonction `remove_clauses()` prend en entrée un pointeur vers le début de la liste chaînée de clauses et un littéral x, et supprime toutes les clauses qui contiennent x ou sa négation ¬x de la liste. Elle renvoie `true` si une clause vide a été trouvée, `false` sinon.

### b - la fonction `select_literal()`:
La fonction `select_literal()` prend en entrée un pointeur vers le début de la liste chaînée de clauses, sélectionne un littéral x dans la première clause de la liste et appelle `remove_clauses()` pour supprimer les clauses qui contiennent x ou sa négation ¬x. Elle renvoie `true` si une clause vide a été trouvée par `remove_clauses()`, `false` sinon.

### c - la fonction `device_putnam()`:
La fonction `davis_putnam()` itère sur les clauses de la formule jusqu'à ce qu'il n'y ait plus de clause ou qu'une clause vide soit trouvée. À chaque étape, elle appelle `select_literal()` pour sélectionner un littéral x dans une clause et supprimer toutes les clauses qui contiennent x ou sa négation ¬x. Si une clause vide est trouvée par `select_literal()`, cela signifie que la formule est insatisfiable et l'algorithme se termine avec échec. Si la formule n'a plus de clause, cela signifie qu'elle est satisfiable et l'algorithme se termine avec succès.

## 4 - test d'exécution d'algorithme:

## 5 - Conclusion:

Nous avons étudié l'algorithme de ***Davis-Putnam***, qui est un algorithme de décision utilisé pour déterminer si une formule booléenne en conjonctive normal form ***(CNF)*** est ***satisfiable*** ou ***insatisfiable***. Nous avons également vu un exemple d'implémentation de cet algorithme en **C++**, ainsi que l'implementation des tests pour valider le ***fonctionnement*** de l'algorithm.

Cependant, il y a encore de nombreuses choses qui ne sont pas traitées dans ce projet. Par exemple, nous n'avons pas examiné en détail les ***optimisations*** qui peuvent être apportées à l'algorithme de ***Davis-Putnam*** pour améliorer sa ***performance***, ni discuté de sa ***complexité temporelle*** et de sa place dans l'étude des algorithmes de décision en général que nous voulions voir dans notre projet pour mieux comprendre la place de l'algorithme dans une matière de complexité temporelle.

