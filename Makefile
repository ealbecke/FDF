NAME	= fdf

SRCDIR = src/
OBJDIR = obj/
INCDIR = includes/
LIBDIR = libft/

SRC	=	main.c \
		check_arg.c \
		draw.c \
		events.c \
		mlx_part.c \
		open_map.c \
		get_next_line.c \
		read_map.c

OBJ	= $(addprefix $(OBJDIR), $(SRC : .c=.o))

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
FRAMEWORK = -framework OpenGL -framework AppKit
LDFLAGS = -I $(LIBDIR) -I $(LIBDIR)$(INCDIR)
LIB = -lmlx
LIBFT = -L libft/includes -lft

all: libft.a $(NAME)

libft.a:
	make -C libft

$(NAME): $(OBJ)
	$(CC) -o $@ $(SRC) $(LDFLAGS) $(LIB) $(FRAMEWORK) $(LIBFT)
	@echo 'Make done'

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

clean:
	make -C libft $@
	/bin/rm -f $(OBJ)
	/bin/rm -df $(OBJDIR)
	@echo 'Clean done'

fclean:	clean
	make -C libft $@
	/bin/rm -f $(NAME)
	@echo 'Fclean done'

re:	fclean all
	@echo 're done'

.PHONY: all clean fclean re