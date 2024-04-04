

#include "ParseConf.hpp"




std::vector<std::string> separateServerBlocks(const std::string& config) {
    std::vector<std::string> blocks;
    std::string::size_type pos = 0;
    
    while ((pos = config.find("server {", pos)) != std::string::npos) {
        // Encontra o início do bloco
        std::string::size_type blockStart = pos;
        
        // Encontra o fim do bloco
        std::string::size_type blockEnd = config.find("}", blockStart);
        if (blockEnd == std::string::npos) {
            break; // Se não houver fechamento de bloco, termina
        }
        blockEnd = config.find("\n}", blockEnd); // Avança até a próxima linha após }
        if (blockEnd == std::string::npos) {
            break; // Se não houver fechamento de bloco, termina
        }
        blockEnd += 2; // Avança até o final do bloco

        // Adiciona o bloco encontrado ao vetor
        blocks.push_back(config.substr(blockStart, blockEnd - blockStart));

        // Move a posição de busca para após o bloco encontrado
        pos = blockEnd;
    }

    return blocks;
}


std::string extractServerParams(const std::string& serverBlock) {
    std::istringstream iss(serverBlock);
    std::string line;
    std::string serverParams;
    std::set<std::string> uniqueParams; // Usaremos um conjunto para armazenar apenas os parâmetros únicos

    bool insideLocation = false;

    while (std::getline(iss, line)) {
        if (line.find("location") != std::string::npos) {
            insideLocation = true;
            continue; // Ignoramos a linha que contém "location"
        }
        if (line.find("}") != std::string::npos) {
            insideLocation = false;
            continue; // Ignoramos a linha que contém "}"
        }
        if (insideLocation) {
            continue; // Ignoramos as linhas dentro de uma localização
        }
        if (line.find("server {") != std::string::npos) {
            continue; // Ignoramos a linha "server {"
        }

        // Verificamos se o parâmetro já foi adicionado
        if (uniqueParams.find(line) == uniqueParams.end()) {
            uniqueParams.insert(line);
            serverParams += line + "\n";
        }
    }

    return serverParams;
}