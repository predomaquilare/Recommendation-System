#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "../../purchase history module/include/purchase_history_modulelib.hpp"
#include "../../similarity module/include/similarity_modulelib.hpp"

struct RecommendedProduct {
  int product_id;
  float ranking_score;
};

class RecommendationModule {
  public:
    static std::vector<RecommendedProduct> get_recommendations(
      int client_id, 
      int k, 
      SimilarityModule& similarity, 
      PurchaseHistory& history
    );
  private:
    static bool compareRanking(const RecommendedProduct& a, const RecommendedProduct& b);
};
