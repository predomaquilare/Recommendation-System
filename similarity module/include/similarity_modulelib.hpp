#include <string>
#include <vector>


class SimilarityModule {
  public:
    SimilarityModule();
    ~SimilarityModule();
  private:
    std::vector<std::vector<float>> matrix_multiplication(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
    std::vector<std::vector<float>> transposed_matrix(std::vector<std::vector<float>> A);

}
