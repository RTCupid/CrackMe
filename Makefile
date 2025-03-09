CC = g++
FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
	-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum \
	-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
	-Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
	-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
	-Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla \
	-D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJ_DIR=./build/obj
BIN_DIR=./build/bin

run: ${BIN_DIR}/a.exe

$(BIN_DIR)/a.exe: $(OBJ_DIR)/Tablet.o $(OBJ_DIR)/FreadFile.o $(OBJ_DIR)/Graphics.o $(OBJ_DIR)/main.o
	$(CC)  $(OBJ_DIR)/Tablet.o $(OBJ_DIR)/FreadFile.o $(OBJ_DIR)/Graphics.o $(OBJ_DIR)/main.o -o a.exe $(FLAGS)

$(OBJ_DIR)/Tablet.o: ./Tablet/Tablet.cpp ./Tablet/Tablet.h ./FreadFile/FreadFile.h
	$(CC) -c ./Tablet/Tablet.cpp -o $(OBJ_DIR)/Tablet.o $(FLAGS)

$(OBJ_DIR)/FreadFile.o: ./FreadFile/FreadFile.cpp ./FreadFile/FreadFile.h
	$(CC) -c ./FreadFile/FreadFile.cpp -o $(OBJ_DIR)/FreadFile.o $(FLAGS)

$(OBJ_DIR)/Graphics.o: ./Tablet/Graphics.cpp ./Tablet/Graphics.h
	$(CC) -c ./Tablet/Graphics.cpp -o $(OBJ_DIR)/Graphics.o $(FLAGS)

$(OBJ_DIR)/main.o: main.cpp ./Tablet/Tablet.h ./Tablet/Graphics.h
	$(CC) -c main.cpp -o $(OBJ_DIR)/main.o $(FLAGS)

clean:
	rm -f main $(OBJ_DIR)/*.o

