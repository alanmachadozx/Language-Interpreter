cmake_minimum_required(VERSION 3.10)
project(Language-Interpreter)

# 1. Primeiro você cria o alvo (adicione todos os seus arquivos .cpp aqui)
add_executable(Language-Interpreter 
    src/main.cpp 
    src/lexer/scanner.cpp 
    src/lexer/mod.cpp
)

# 2. Depois você diz onde estão os headers para ESSE alvo
target_include_directories(Language-Interpreter PUBLIC include)

# 3. Habilita a geração do arquivo para o Zed
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)