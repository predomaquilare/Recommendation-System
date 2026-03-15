#include "../include/similarity_modulelib.hpp"

int main() {
  std::vector<std::vector<float>> matriz1 = {{2,3,4},{1,2,3},{8,6,5}};
  std::vector<std::vector<float>> matriz2, matriz3;
  SimilarityModule::show_matrix(matriz1);
  matriz2 = SimilarityModule::transposed_matrix(matriz1);
  SimilarityModule::show_matrix(matriz2);
  matriz3 = SimilarityModule::matrix_multiplication(matriz1, matriz2); 
  SimilarityModule::show_matrix(matriz3);
  return 0;
}
