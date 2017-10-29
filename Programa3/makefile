RM = rm -rf
# Compilador
CC=g++
# Variaveis para os subdiretorios
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
# Outras variaveis
# Opcoes de compilacao
CFLAGS = -Wall -g  -O0 -pedantic -ansi -std=c++14 -I. -I$(INC_DIR)
# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy
programa3: $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel criado em $(BIN_DIR)] +++"
	@echo "============="
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/listaord.h $(INC_DIR)/lista.h $(INC_DIR)/node.h
	$(CC) -c $(CFLAGS) -o $@ $<
