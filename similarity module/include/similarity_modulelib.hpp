#include <string>
#include <vector>
#include <list>
#include <string>
#include <iostream>


class SimilarityModule {
  public:
    SimilarityModule();
    ~SimilarityModule();
    static void show_matrix(std::vector<std::vector<float>> matrix);
    static std::vector<std::vector<float>> matrix_multiplication(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
    static std::vector<std::vector<float>> transposed_matrix(std::vector<std::vector<float>> A);
    static std::vector<std::vector<float>> get_purchase_matrix(int qnt_products, std::vector<std::list<int>> purchase_vector);
    static std::vector<std::vector<float>> intersection_matrix(std::vector<std::vector<float>> matrix);

  private:

};
