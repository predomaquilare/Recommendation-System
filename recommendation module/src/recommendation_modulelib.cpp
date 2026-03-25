#include "../include/recommendation_modulelib.hpp"


RecommendationModule::RecommendationModule(SimilarityModule& similarity) : similarity_object(similarity) {
  purchase_matrix = similarity_object.get_purchase_matrix();
  similarity_matrix = similarity_object.get_similarity_matrix();
  ranking_vector = RecommendationModule::create_ranking_vector();


}

RecommendationModule::~RecommendationModule() {}

std::vector<std::vector<RecommendedProduct>> RecommendationModule::create_ranking_vector() {
  std::vector<std::vector<RecommendedProduct>> temp = std::vector<std::vector<RecommendedProduct>>(purchase_matrix.size(), std::vector<RecommendedProduct>(purchase_matrix[0].size(), RecommendedProduct{0, 1.0f}));
  std::list<int> sim_clients;
  for(int c = 0; c < purchase_matrix.size(); c++) {
    sim_clients = similarity_object.get_most_similar_client(c);
    for(auto &s : sim_clients) {
      std::cout << "cliente " << c << " -> similar " << s 
        << " sim=" << similarity_matrix[c][s] << std::endl;
      for(int p = 0; p < purchase_matrix[c].size(); p++) {
        bool c_comprou = purchase_matrix[c][p];
        bool s_comprou = purchase_matrix[s][p];
        // if((s_comprou && !c_comprou) && (similarity_matrix[c][s] > 0.0f && similarity_matrix[c][s] < 1.0f)) {
        if(s_comprou && !c_comprou)  {
          temp[c][p].ranking_score *= similarity_matrix[c][s];
          temp[c][p].product_id = p;
        }
      }
    }
  }
  return temp;
}

std::vector<std::vector<float>> RecommendationModule::get_ranking_vector() {
  std::vector<std::vector<float>> temp = std::vector<std::vector<float>>(purchase_matrix.size(), std::vector<float>(purchase_matrix[0].size(), 0.0));
  for(int i = 0; i < purchase_matrix.size(); i++) {
    for(int j = 0; j < purchase_matrix[0].size(); j++) {
      temp[i][j] =  ranking_vector[i][j].ranking_score; 
    }
  }
  return temp;
}




std::vector<RecommendedProduct> RecommendationModule::get_recommendations(
  int client_id, int k) {
  
  // int num_products = history.get_products_size();
  // auto sim_matrix = similarity.get_similarity_matrix();
  // auto purchase_history = history.get_client_purchase_history();

  // std::vector<RecommendedProduct> R(num_products);
  // for (int p = 0; p < num_products; p++) {
  //   R[p].product_id = p;
  //   R[p].ranking_score = 1.0f;
  // }

  // for (int s = 0; s < (int)sim_matrix.size(); s++) {
  //   if (s == client_id) continue;
  //   float sim_val = sim_matrix[client_id][s];

  //   if (sim_val < 1.0f) {
  //     for (int p_id : purchase_history[s]) {
  //       bool bought_by_c = false;
  //       for (int p_c : purchase_history[client_id]) {
  //         if (p_c == p_id) {
  //           bought_by_c = true;
  //           break;
  //         }
  //       }

  //       if (!bought_by_c) {
  //         R[p_id].ranking_score *= sim_val;
  //       }
  //     }
  //   }
// }

// std::sort(R.begin(), R.end(), compareRanking);

  //   // 4. Seleção: Retorna os k primeiros produtos 
  //   std::vector<RecommendedProduct> top_k;
  //   for (int i = 0; i < k && i < (int)R.size(); i++) {
  //       // Opcional: só recomendar se o score foi alterado (p < 1.0)
  //       if (R[i].ranking_score < 1.0f) {
  //           top_k.push_back(R[i]);
  //       }
  //   }
  //   return top_k;
}

// Comparador: menor valor de score = maior similaridade/recomendação
// bool RecommendationModule::compareRanking(const RecommendedProduct& a, const RecommendedProduct& b) {
//     return a.ranking_score < b.ranking_score;
// }
