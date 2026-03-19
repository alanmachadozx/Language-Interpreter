#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "lexer/scanner.hpp"

void runFile(const std::string& path) {
    // 1. Abre o arquivo
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo " << path << std::endl;
        return;
    }

    // 2. Lê todo o conteúdo para uma string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sourceCode = buffer.str();

    // 3. Passa para o seu Scanner
    Scanner scanner(sourceCode);
    std::vector<Token> tokens = scanner.scanTokens();

    // 4. Mostra o resultado
    for (const auto& token : tokens) {
        std::cout << "Token: [" << (int)token.type << " | '" << token.lexeme << "']" << std::endl;
    }
}

int main() {
    runFile("../text.txt"); 
    return 0;
}