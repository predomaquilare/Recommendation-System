#include "../include/purchase_history_modulelib.hpp"

PurchaseHistory::PurchaseHistory(int num, char **file) {
  quit_flag = false;
  PurchaseHistory::load_csv(num, file);
  PurchaseHistory::terminal_acess();
}

PurchaseHistory::~PurchaseHistory(){}

void PurchaseHistory::load_csv(int num, char **file) {
  for (int i = 0; i < num - 1; i++) {
    std::ifstream arquivo(file[i + 1]);
    std::string linha;
    if (!arquivo.is_open()) {
      std::cerr << "Erro ao abrir arquivo: " << file[i + 1] << std::endl;
      continue;
    }
    while (std::getline(arquivo, linha)) {
      std::stringstream ss(linha);
      std::string data, cliente, produto, nome;
      std::getline(ss, data, ',');
      if(data == "DATA_COMPRA") continue;
      std::getline(ss, cliente, ',');
      std::getline(ss, produto, ',');
      std::getline(ss, nome);
      all_clients.push_back(cliente);
      all_products.push_back(nome);
    }
  }
  PurchaseHistory::clean_vector(all_clients);
  PurchaseHistory::clean_vector(all_products);
  PurchaseHistory::vectorToMap(all_clients, map_client);
  PurchaseHistory::vectorToMap(all_products, map_product);
  purchase_history = std::vector<std::list<int>>(all_clients.size());

  for (int i = 0; i < num - 1; i++) {
    std::ifstream arquivo(file[i + 1]);
    std::string linha;
    if (!arquivo.is_open()) {
      std::cerr << "Erro ao abrir arquivo: " << file[i + 1] << std::endl;
      continue;
    }
    while (std::getline(arquivo, linha)) {
      std::stringstream ss(linha);
      std::string data, cliente, produto, nome;
      std::getline(ss, data, ',');
      if(data == "DATA_COMPRA") continue;
      std::getline(ss, cliente, ',');
      std::getline(ss, produto, ',');
      std::getline(ss, nome);
      purchase_history[map_client[cliente]].push_back(map_product[nome]);
    }
  }
}

void PurchaseHistory::vectorToMap(std::vector<std::string> &vetor, std::unordered_map<std::string, int> &mapping) {
  for(size_t i = 0; i < vetor.size(); i++) mapping[vetor[i]] = i;
}

void PurchaseHistory::clean_vector(std::vector<std::string> &clean_vector) {
  std::sort(clean_vector.begin(), clean_vector.end());
  clean_vector.erase(std::unique(clean_vector.begin(), clean_vector.end()), clean_vector.end());
}

void PurchaseHistory::terminal_acess() {
  do {
    int option_choosen = 0;
    std::cout << "\033[2J\033[H"; // limpa terminal
    std::cout << "<=== PurchaseHistoryModule Menu ===>" << std::endl;
    std::cout << "<===      Choose an option      ===>" << std::endl;
    std::cout << "<=   1 -> Get client items        =>" << std::endl;
    std::cout << "<=   2 -> Get client code by id   =>" << std::endl;
    std::cout << "<=   3 -> Get product code by id  =>" << std::endl;
    std::cout << "<=   4 -> Quit                    =>" << std::endl;
    std::cin >> option_choosen;

    switch(option_choosen) {
      case 1:

      break;

      case 2:

      break;

      case 3:

      break;

      case 4:
        quit_flag = true;
      break;


    }


  } while(quit_flag == false);


}
