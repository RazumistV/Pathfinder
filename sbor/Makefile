NAME	=	pathfinder

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	pathfinder.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC  =  main.c \
		mx_algoritm.c \
		mx_create_res_lst.c	\
		mx_parse_apex.c	\
		mx_print_errors.c \
		mx_sort_lst.c \
		mx_vivod.c \
		mx_connect_count.c \
		mx_error_cases.c \
		mx_pop_elem_of_lst.c \
		mx_print_errors2.c \
		mx_swap_lst.c \
		mx_validator.c




SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install