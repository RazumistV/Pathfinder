NAME = libmx.a
CC = clang

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -I inc

SRC =	is_whitespace.c \
		mx_hex_to_nbr.c	\
		mx_sqrt.c \
		mx_strncpy.c \
		mx_binary_search.c \
		mx_itoa.c \
		mx_str_reverse.c \
		mx_bubble_sort.c \
		mx_memset.c \
		mx_strcat.c \
		mx_strnew.c \
		mx_count_substr.c \
		mx_nbr_to_hex.c \
		mx_strcmp.c \
		mx_count_words.c \
		mx_pow.c \
		mx_strcpy.c \
		mx_strstr.c \
		mx_del_extra_spaces.c \
		mx_strdel.c \
		mx_strtrim.c \
		mx_del_strarr.c \
		mx_printchar.c \
		mx_strdup.c \
		mx_swap_char.c \
		mx_foreach.c \
		mx_printint.c \
		mx_strjoin.c \
		nbrlen.c \
		mx_get_char_index.c \
		mx_printstr.c \
		mx_strlen.c \
		str_is_null.c \
		mx_get_substr_index.c \
		mx_quicksort.c \
		mx_strncmp.c \
		mx_print_strarr.c \
		mx_memcpy.c \
		mx_memccpy.c \
		mx_memcmp.c \
		mx_memchr.c \
		mx_memrchr.c \
		mx_memmem.c \
		mx_memmove.c \
		mx_create_node.c \
		mx_push_back.c \
		mx_push_front.c \
		swap_strings.c \
		mx_realloc.c \
		mx_pop_back.c \
		mx_pop_front.c \
		mx_list_size.c \
		count_letters.c \
		mx_strsplit.c \
		mx_replace_substr.c \
		mx_print_unicode.c \
		mx_file_to_str.c \
		mx_sort_list.c \
		mx_strndup.c \
		mx_printerr.c \
		mx_atoi.c \
		mx_isdigit.c \
		freearray.c \
		mx_min_elem.c


OBJ_DIR = ./obj/
SRC_DIR = ./src/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

all: install clean

install: $(OBJ)
	@mkdir -p $(OBJ_DIR)
	@ar rc $(NAME) $(OBJ)
clean:
	@rm -rf $(OBJ_DIR)
uninstall: clean
	@rm -f $(NAME)
reinstall: uninstall all