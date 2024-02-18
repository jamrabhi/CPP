#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void fordJohnsonSort(const vector<int>& tableau) {
  if (tableau.size() <= 1) {
    return;
  }

  // Tri par paires récursif
  for (int i = 0; i < tableau.size() - 1; i += 2) {
    if (tableau[i] > tableau[i + 1]) {
      swap(tableau[i], tableau[i + 1]);
    }
  }

  // Tri par insertion et fusion récursifs (pas de création de vecteurs temporaires)
  fordJohnsonSort(vector<int>(tableau.begin(), tableau.begin() + tableau.size() / 2));
  fordJohnsonSort(vector<int>(tableau.begin() + tableau.size() / 2, tableau.end()));

  // Fusion des deux sous-tableaux triés
  for (int i = 0; i < tableau.size() / 2; i++) {
    if (tableau[i] > tableau[i + tableau.size() / 2]) {
      swap(tableau[i], tableau[i + tableau.size() / 2]);
    }
  }
}

int main() {
  vector<int> tableau = {5, 2, 4, 6, 1, 3};

  fordJohnsonSort(tableau);

  for (int i = 0; i < tableau.size(); i++) {
    cout << tableau[i] << " ";
  }

  cout << endl;

  return 0;
}
