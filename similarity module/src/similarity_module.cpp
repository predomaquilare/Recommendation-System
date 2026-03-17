#include "../include/similarity_modulelib.hpp"

int main() {
  std::vector<std::list<int>> matriz1 = {{2,3,4},{1,2,3},{8,6,5}};
  SimilarityModule similarity(8, matriz1);
  SimilarityModule::show_matrix(similarity.get_purchase_matrix());
  SimilarityModule::show_matrix(similarity.get_purchase_matrix_transposed());
  SimilarityModule::show_matrix(similarity.get_intersection_matrix());
  SimilarityModule::show_matrix(similarity.get_similarity_matrix());
  return 0;
}
