#include "../purchase history module/include/purchase_history_modulelib.hpp"
#include "../similarity module/include/similarity_modulelib.hpp"
#include "../recommendation module/include/recommendation_modulelib.hpp"
#include <array>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "You need to pass at least 1 additional arg to use this program" << std::endl;
    return 1;
  }

  // int k = 5;
  // std::array<std::string, 3> clients;
  // std::cout << "Type the first user ID to search: ";
  // std::cin >> clients[0];
  // std::cout << "Type the second user ID to search: ";
  // std::cin >> clients[1];
  // std::cout << "Type the third user ID to search: ";
  // std::cin >> clients[2];

  PurchaseHistory module((argc - 1), argv, false);
  SimilarityModule similarity(module.get_products_size(), module.get_client_purchase_history(), 1);
  RecommendationModule recommendation(similarity);


  SimilarityModule::show_matrix(recommendation.get_ranking_vector());
  // for (const std::string& code : clients) {
  //   int c_id = module.get_client_id_by_client_code(code);

  //   std::vector<RecommendedProduct> recommendations = 
  //       RecommendationModule::get_recommendations(c_id, k, similarity, module);

  //   std::cout << "Cliente: " << code << std::endl;
  //   std::cout << "Produtos recomendados:" << std::endl;

  //   if (recommendations.empty()) {
  //     std::cout << "  Nenhuma recomendação encontrada." << std::endl;
  //   } else {
  //     for (const auto& rec : recommendations) {
  //       std::string p_name = module.get_product_name_by_id(rec.product_id); 
  //       std::cout << "  - " << p_name << " (Score: " << rec.ranking_score << ")" << std::endl;
  //     }
  //   }
  //   std::cout << "-----------------------------------" << std::endl;
  // }
  return 0;
}
