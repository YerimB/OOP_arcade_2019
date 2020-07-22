##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CC = g++ -std=c++17 -ldl

SRC = $(wildcard *.cpp */*.cpp)

OBJ = $(SRC:.cpp=.o)

CFLAGS = -ldl

RM = rm -rf

all: $(OBJ)
	$(CC) $^ -o $(EXE) $(CFLAGS)
	mv $(EXE) ../$(EXE)

$(OBJ): %.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

EXE = arcade
NAME = core

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(CFLAGS)
	mv $(EXE) ../$(EXE)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bin: fclean all
	$(RM) $(OBJ)