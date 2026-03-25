#include "../include/recommendation_modulelib.hpp"


RecommendationModule::RecommendationModule(SimilarityModule& similarity) : similarity_object(similarity) {
  purchase_matrix = similarity_object.get_purchase_matrix();
  similarity_matrix = similarity_object.get_similarity_matrix();
  ranking_vector = RecommendationModule::create_ranking_vector();
  RecommendationModule::sort_ranking_vector();


}

RecommendationModule::~RecommendationModule() {}

std::vector<std::vector<RecommendedProduct>> RecommendationModule::create_ranking_vector() {
  std::vector<std::vector<RecommendedProduct>> temp = std::vector<std::vector<RecommendedProduct>>(purchase_matrix.size(), std::vector<RecommendedProduct>(purchase_matrix[0].size()));
  std::list<int> sim_clients;

  for(int c = 0; c < purchase_matrix.size(); c++) {
    for(int p = 0; p < purchase_matrix[c].size(); p++) {
      temp[c][p].product_id = p;
      temp[c][p].ranking_score = 1.0f;
    }

    sim_clients = similarity_object.get_most_similar_client(c);
    for(auto &s : sim_clients) {
      for(int p = 0; p < purchase_matrix[c].size(); p++) {
        bool c_comprou = purchase_matrix[c][p];
        bool s_comprou = purchase_matrix[s][p];
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
  std::vector<std::vector<float>> temp = std::vector<std::vector<float>>(purchase_matrix.size(), std::vector<float>(purchase_matrix[0].size(), 1.0));
  for(int i = 0; i < purchase_matrix.size(); i++) {
    for(int j = 0; j < purchase_matrix[0].size(); j++) {
      temp[i][j] =  ranking_vector[i][j].ranking_score; 
    }
  }
  return temp;
}


void RecommendationModule::sort_ranking_vector() {
  for(int i = 0; i < ranking_vector.size(); i++) {
    std::sort(ranking_vector[i].begin(), ranking_vector[i].end(), compare_ranking);
  }
}



std::vector<RecommendedProduct> RecommendationModule::get_recommendations(int client_id, int k) {
  std::vector<RecommendedProduct> recommended_products;

  if(k > purchase_matrix[0].size()) k  = purchase_matrix[0].size(); 

  for(int i = 0; i < purchase_matrix[0].size(); i++) {
    if(i == k) break;
    recommended_products.push_back(ranking_vector[client_id][i]);
  }
  return recommended_products;
}

bool RecommendationModule::compare_ranking(const RecommendedProduct& a, const RecommendedProduct& b) {
    return a.ranking_score < b.ranking_score;
}

  


