#include "../purchase history module/include/purchase_history_modulelib.hpp"
#include "../similarity module/include/similarity_modulelib.hpp"


int main (int argc, char **argv) {
  if (argc < 2){
    std::cerr << "You need to pass at least 1 additional arg to use this program" << std::endl;
    return 1;
  }
  PurchaseHistory module((argc - 1), argv, false);
  SimilarityModule similarity(module.get_products_size(), module.get_purchase_history());
  SimilarityModule::show_matrix(similarity.get_purchase_matrix());
  SimilarityModule::show_matrix(similarity.get_purchase_matrix_transposed());
  SimilarityModule::show_matrix(similarity.get_intersection_matrix());
  SimilarityModule::show_matrix(similarity.get_similariry_matrix());
  return 0;
}
