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
  PurchaseHistory::vectorToMap(all_clients, map_client_to_id, map_id_to_client);
  PurchaseHistory::vectorToMap(all_products, map_product_to_id, map_id_to_product);
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
      purchase_history[map_client_to_id[cliente]].push_back(map_product_to_id[nome]);
    }
  }
}

void PurchaseHistory::vectorToMap(std::vector<std::string> &vetor, std::unordered_map<std::string, int> &mapping_to_id, std::unordered_map<int, std::string> &id_to_mapping) {
  for(size_t i = 0; i < vetor.size(); i++) {
    mapping_to_id[vetor[i]] = i;
    id_to_mapping[i] = vetor[i];
  }
}

void PurchaseHistory::clean_vector(std::vector<std::string> &clean_vector) {
  std::sort(clean_vector.begin(), clean_vector.end());
  clean_vector.erase(std::unique(clean_vector.begin(), clean_vector.end()), clean_vector.end());
}

std::string PurchaseHistory::get_client_code_by_id(int client) {
  return map_id_to_client[client];
}

std::string PurchaseHistory::get_product_code_by_id(int product) {
  return map_id_to_product[product];
}

std::unordered_map<int,int> PurchaseHistory::get_items_from_client(int client_id) {
  std::unordered_map<int,int> product_count;
  for(int product : purchase_history[client_id]) {
    product_count[product]++;
  }
  return product_count;
}

void PurchaseHistory::terminal_acess() {
  int option_choosen;
  int id;
  do {
    option_choosen = 0;
    id = 0;
    std::cout << "\033[2J\033[H"; // limpa terminal
    std::cout << "<=== PurchaseHistoryModule Menu ===>" << std::endl;
    std::cout << "<===      Choose an option      ===>" << std::endl;
    std::cout << "<=   1 -> Get client items        =>" << std::endl;
    std::cout << "<=   2 -> Get client code by id   =>" << std::endl;
    std::cout << "<=   3 -> Get product code by id  =>" << std::endl;
    std::cout << "<=   4 -> Quit                    =>" << std::endl;
    std::cin >> option_choosen;

    switch(option_choosen) {
      case 1: {
                std::cout << "Type the client's id: ";
                std::cin >> id;
                auto items = PurchaseHistory::get_items_from_client(id);
                for(auto &p : items) std::cout << get_product_code_by_id(p.first) << " -> " << p.second << std::endl;
                sleep(3);
              }
              break;

      case 2: {
                std::cout << "<===      Choose an option      ===>" << std::endl;
                std::cout << "<===    Type the client's id    ===>" << std::endl;
                std::cin >> id;
                std::cout << PurchaseHistory::get_client_code_by_id(id) << std::endl;
                sleep(3);
              }
              break;

      case 3: {
                std::cout << "<===      Choose an option      ===>" << std::endl;
                std::cout << "<===   Type the product's id    ===>" << std::endl;
                std::cin >> id;
                std::cout << PurchaseHistory::get_product_code_by_id(id) << std::endl;
                sleep(3);
              }
              break;

      case 4:
              quit_flag = true;
              break;
    }


  } while(quit_flag == false);


}
