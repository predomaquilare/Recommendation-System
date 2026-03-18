#include "../purchase history module/include/purchase_history_modulelib.hpp"
#include "../similarity module/include/similarity_modulelib.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "You need to pass at least 1 additional arg to use this program" << std::endl;
    return 1;
  }

  std::vector<std::string> clients = {"9O09ND01", "59292401", "99CWNZ01"};

  PurchaseHistory module((argc - 1), argv, false);
  SimilarityModule similarity(module.get_products_size(), module.get_client_purchase_history(), 1);

  // SimilarityModule::show_matrix(similarity.get_purchase_matrix());
  // SimilarityModule::show_matrix(similarity.get_purchase_matrix_transposed());
  // SimilarityModule::show_matrix(similarity.get_intersection_matrix());
  // SimilarityModule::show_matrix(similarity.get_similarity_matrix());

  for (int i = 0; i < clients.size(); i++) {
    int client_id = module.get_client_id_by_client_code(clients[i]);
    std::vector<int> most_similar_clients = similarity.get_most_similar_client(client_id);
    std::cout << clients[i] << " most similar client(s): ";
    for (int j = 0; j < most_similar_clients.size(); j++) {
      std::cout << module.get_client_code_by_id(most_similar_clients[j]);
      if (j < most_similar_clients.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
