#include <cstddef>

struct clause {
  int literal;
  clause* next;
};

// Supprime les clauses qui contiennent le littéral x ou sa négation ¬x.
// Renvoie true si une clause vide a été trouvée, false sinon.
bool remove_clauses(clause** f, int x) {
  clause** p = f;
  while (*p != NULL) {
    if ((*p)->literal == x || (*p)->literal == -x) {
      clause* q = *p;
      *p = q->next;
      delete q;
    } else {
      p = &(*p)->next;
    }
  }

  return (*f == NULL);
}

// Sélectionne un littéral dans une clause et appelle remove_clauses pour
// supprimer les clauses qui contiennent ce littéral ou sa négation.
// Renvoie true si une clause vide a été trouvée, false sinon.
bool select_literal(clause** f) {
  int x = (*f)->literal;
  clause* next = (*f)->next;
  delete *f;
  *f = next;
  return remove_clauses(f, x);
}

bool davis_putnam(clause* f) {
  while (f != NULL) {
    // S'il n'y a plus de clause, la formule est satisfiable.
    if (f->literal == 0) {
      return true;
    }

    // Sélectionnez un littéral x dans une clause de la formule.
    if (select_literal(&f)) {
      return false;
    }
  }

  return true;
}
