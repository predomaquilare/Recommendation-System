#include "../include/similarity_modulelib.hpp"

int main() {
  std::vector<std::vector<float>> matriz = {{2,3,4},{1,2,3},{8,6,5}};
  SimilarityModule::show_matrix(matriz);
  return 0;
}
