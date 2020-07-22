##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME = arcade

CORE = ./core/
GRAPHICALS = ./lib/
GAMES = ./games/

all: $(NAME)

core:
	@make -C $(CORE)

games:
	@make -C $(GAMES)

graphicals:
	@make -C $(GRAPHICALS)

$(NAME):
	@make -C $(CORE)
	@make -C $(GRAPHICALS)
	@make -C $(GAMES)

clean:
	rm -rf $(NAME)

fclean: clean
	@ make fclean -C $(CORE)
	@ make fclean -C $(GRAPHICALS)
	@ make fclean -C $(GAMES)

re: fclean all $(FOLDERS)

.PHONY: all clean fclean re core graphicals games