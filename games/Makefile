##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CC = g++ -std=c++14

PACMAN = ./PacMan/
SNAKE = ./Snake2/

NAME = games

all: $(NAME)

$(NAME):
	$(CC) -shared -fPIC $(wildcard $(PACMAN)*.cpp) -o lib_arcade_pacman.so
	$(CC) -shared -fPIC $(wildcard $(SNAKE)*.cpp) -o lib_arcade_nibbler.so

clean:
	rm -rf PacMan/*.o
	rm -rf Snake/*.o

fclean: clean
	rm -rf rm -rf lib_arcade_*.so

re: fclean all
