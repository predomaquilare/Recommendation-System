#include <string>
#include <vector>
#include <iostream>


class SimilarityModule {
  public:
    SimilarityModule();
    ~SimilarityModule();
    static void show_matrix(std::vector<std::vector<float>> matrix);
    static std::vector<std::vector<float>> matrix_multiplication(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
    static std::vector<std::vector<float>> transposed_matrix(std::vector<std::vector<float>> A);

  private:

};
