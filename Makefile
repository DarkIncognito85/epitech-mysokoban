##
## EPITECH PROJECT, 2023
## Sokoban
## File description:
## Makefile
##

SOURCE	=	./main.c							\
			./src/get/get_content_from_file.c	\
			./src/put/my_putstr.c				\
			./src/my_str_to_word_array.c		\
			./src/get/get_count_tab.c			\
			./src/put/my_put_nbr.c				\
			./src/my_strlen.c					\
			./src/free_all.c					\
			./src/my_strdup.c					\
			./src/display/render.c				\
			./src/display/help.c				\
			./src/put/my_putchar.c				\
			./src/player.c						\
			./src/sokoban.c						\
			./src/get/get_count.c

SOURCE_TEST = 		./tests/test_settingup.c							\

OBJS	=	$(SOURCE:.c=.o)
OUT		=	my_sokoban
CC		=	gcc
CFLAGS	+=	-W -Wall -Wextra -I ./include
NAME	=	libmy.a

all: $(OUT)

$(OUT): $(OBJS)
	@ $(CC) $(OBJS) -o $(OUT) -lncurses
	@ echo -e "\033[1;32m$(OUT) successfully created!\033[0m"

clean:
	@ $(RM) $(OBJS) *~ *# *.o *.gc* src/*.gc* src/*.o *.out
	@ echo -e "\033[1;31mAll cleaned!\033[0m"

fclean: clean
	@ rm -f *.gcno
	@ rm -f *.gcda
	@ rm -f libmy.a
	@ rm -f vgcore.*
	@ $(RM) $(OUT)
	@ echo -e "\033[1;31m$(OUT) (executable) is removed!\033[0m"

re: fclean all

valgrind:
	@ $(CC) $(SOURCE) -o $(OUT) $(LFLAGS) $(LDFLAGS) $(CFLAGS) -g3 -lncurses
	@ echo -e "\033[1;34mRunning valgrind on $(OUT)...\033[0m"
	@ valgrind ./$(OUT) map

gdb:
	@ $(CC) $(SOURCE) -o $(OUT) $(LFLAGS) $(LDFLAGS) $(CFLAGS) -g3
	@ echo -e "\033[1;34mDebugging $(OUT)...\033[0m"
	@ gdb ./$(OUT)

refresh: re
	@ ./$(OUT)
	@ echo "exit\n"
	@ ./$(OUT)
mango:
	make fclean
	mango
