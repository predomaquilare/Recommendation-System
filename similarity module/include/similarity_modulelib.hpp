#include <string>
#include <thread>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <iostream>


class SimilarityModule {
  public:
    SimilarityModule(int qnt_products, std::vector<std::list<int>> purchase_vector, int multithread_option);
    ~SimilarityModule();
    static void show_matrix(std::vector<std::vector<float>> matrix);
    std::vector<std::vector<float>> get_purchase_matrix();
    std::vector<std::vector<float>> get_purchase_matrix_transposed();
    std::vector<std::vector<float>> get_intersection_matrix();
    std::vector<std::vector<float>> get_similarity_matrix();
    std::vector<int> get_most_similar_client(unsigned int client_code);
    
  private:
    std::vector<std::vector<float>> purchase_matrix;
    std::vector<std::vector<float>> purchase_matrix_transposed;
    std::vector<std::vector<float>> intersection_matrix;
    std::vector<std::vector<float>> similarity_matrix;
    int multithread;

    std::vector<std::vector<float>> matrix_multiplication(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
    std::vector<std::vector<float>> matrix_multiplication_threads(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B);
    std::vector<std::vector<float>> set_transposed_matrix(std::vector<std::vector<float>> A);
    std::vector<std::vector<float>> set_purchase_matrix(int qnt_products, std::vector<std::list<int>> purchase_vector);
    std::vector<std::vector<float>> set_intersection_matrix(std::vector<std::vector<float>> matrix);
    std::vector<std::vector<float>> set_similarity_matrix(std::vector<std::vector<float>> intersection_matrix);
};
