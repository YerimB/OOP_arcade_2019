##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

CC = g++ -std=c++14

SFML = ./SFML/
NCURSES = ./ncurses/
OPENGL = ./OpenGL/

NCURSES_FLAGS	= -lncurses

SFML_FLAGS		= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

DetectedOs := $(shell uname)

ifeq ($(DetectedOs), Darwin)
    OPENGL_FLAGS	= `sdl2-config --cflags --libs` -framework GLUT -framework OpenGL -lsfml-graphics -lsfml-system
endif
ifeq ($(DetectedOs), Linux)
    OPENGL_FLAGS	= `sdl2-config --cflags --libs` -lGL -lsfml-graphics -lsfml-system
endif

NAME = graphicals

$(NAME):
	$(CC) -shared -fPIC $(wildcard Templates/*.cpp $(SFML)*.cpp) -o lib_arcade_sfml.so $(SFML_FLAGS)
	$(CC) -shared -fPIC $(wildcard Templates/*.cpp $(NCURSES)*.cpp) -o lib_arcade_ncurses.so $(NCURSES_FLAGS)
	$(CC) -shared -fPIC $(wildcard Templates/*.cpp $(OPENGL)*.cpp $(OPENGL)classes/*.cpp) -o lib_arcade_opengl.so $(OPENGL_FLAGS)

all: $(NAME)

clean:
	rm -rf SFML/*.o
	rm -rf ncurses/*.o
	rm -rf OpenGL/*.o

fclean: clean
	rm -rf lib_arcade_*.so

re: fclean all
