# Makefile para compilar

# Compilador
CC = gcc

# Parametros para compilador
C_FLAGS = \
	-c \
	-Wall \
	-g \

# Lista de objetos
OBJ = \
	main.o \
	fila.o \

# Regra para gerar executavel
Fila: $(OBJ)
	$(CC) $(OBJ) -o $@

# Regra para arquivos objetos
%.o: %.c 
	$(CC) $(C_FLAGS) $<

# Regra para executar o programa
run: Fila
	clear
	./Fila

# Regra para limpar os arqivos objetos
clean: 
	rm -f $(OBJ)
