#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "../../similarity module/include/similarity_modulelib.hpp"

struct RecommendedProduct {
  int product_id;
  float ranking_score;
};

class RecommendationModule {
  public:
    RecommendationModule(SimilarityModule& similarity);
    ~RecommendationModule();
    std::vector<RecommendedProduct> get_recommendations(int client_id, int k);
    std::vector<std::vector<float>> get_ranking_vector();

  private:
    static bool compare_ranking(const RecommendedProduct& a, const RecommendedProduct& b);
    SimilarityModule& similarity_object;

    std::vector<std::vector<RecommendedProduct>> ranking_vector;
    std::vector<std::vector<float>> purchase_matrix;
    std::vector<std::vector<float>> similarity_matrix;

    std::vector<std::vector<RecommendedProduct>> create_ranking_vector();
    void sort_ranking_vector();

};
