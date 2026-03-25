#include "../purchase history module/include/purchase_history_modulelib.hpp"
#include "../similarity module/include/similarity_modulelib.hpp"
#include "../recommendation module/include/recommendation_modulelib.hpp"
#include <array>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "You need to pass at least 1 additional arg to use this program" << std::endl;
    return 1;
  }

  std::vector<RecommendedProduct> products;
  std::vector<std::string> clients = std::vector<std::string>(3, "");
  int k;

  std::cout << "Digite o codigo para o cliente 1: ";
  std::cin >> clients[0];
  std::cout << std::endl;

  std::cout << "Digite o codigo para o cliente 2: ";
  std::cin >> clients[1];
  std::cout << std::endl;

  std::cout << "Digite o codigo para o cliente 3: ";
  std::cin >> clients[2];
  std::cout << std::endl;

  std::cout << "Digite o numero de produtos recomendados: ";
  std::cin >> k;
  std::cout << std::endl;

  PurchaseHistory module((argc - 1), argv, false);
  SimilarityModule similarity(module.get_products_size(), module.get_client_purchase_history(), 1);
  RecommendationModule recommendation(similarity);

  for(int i = 0; i < clients.size(); i++) {
    std::cout << "Cliente " << i+1 << std::endl;
    products = recommendation.get_recommendations(module.get_client_id_by_client_code(clients[i]), k);
    for(int j = 0; j < products.size(); j++) {
      std::cout << module.get_product_name_by_id(products[j].product_id) << " | Ranking Value: "<<  products[j].ranking_score << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
