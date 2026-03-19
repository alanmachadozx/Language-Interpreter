cmake_minimum_required(VERSION 3.10)
project(Language-Interpreter)

# Define o padrão do C++ (C++17 é ótimo para começar)
set(CMAKE_CXX_STANDARD 17)

# Inclui a pasta de cabeçalhos
include_directories(include)

# Adiciona os arquivos fonte
add_executable(meu_itp 
    src/main.cpp 
    src/lexer/scanner.cpp
)