#include "../include/recommendation_modulelib.hpp"

std::vector<RecommendedProduct> RecommendationModule::get_recommendations(
  int client_id, int k, SimilarityModule& similarity, PurchaseHistory& history) {
  
  int num_products = history.get_products_size();
  auto sim_matrix = similarity.get_similarity_matrix();
  auto purchase_history = history.get_client_purchase_history();

  std::vector<RecommendedProduct> R(num_products);
  for (int p = 0; p < num_products; p++) {
    R[p].product_id = p;
    R[p].ranking_score = 1.0f;
  }

  for (int s = 0; s < (int)sim_matrix.size(); s++) {
    if (s == client_id) continue;
    float sim_val = sim_matrix[client_id][s];

    if (sim_val < 1.0f) {
      for (int p_id : purchase_history[s]) {
        bool bought_by_c = false;
        for (int p_c : purchase_history[client_id]) {
          if (p_c == p_id) {
            bought_by_c = true;
            break;
          }
        }

        if (!bought_by_c) {
          R[p_id].ranking_score *= sim_val;
        }
      }
    }
}

std::sort(R.begin(), R.end(), compareRanking);

    // 4. Seleção: Retorna os k primeiros produtos 
    std::vector<RecommendedProduct> top_k;
    for (int i = 0; i < k && i < (int)R.size(); i++) {
        // Opcional: só recomendar se o score foi alterado (p < 1.0)
        if (R[i].ranking_score < 1.0f) {
            top_k.push_back(R[i]);
        }
    }
    return top_k;
}

// Comparador: menor valor de score = maior similaridade/recomendação
bool RecommendationModule::compareRanking(const RecommendedProduct& a, const RecommendedProduct& b) {
    return a.ranking_score < b.ranking_score;
}
