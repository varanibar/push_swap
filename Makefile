NAME = push_swap

SRCS = push_swap.c \
	ft_check_input.c \
	ft_check_input_utils.c \
	ft_free_stack.c \
	ft_stack_size.c \
	ft_rotate_operation.c \
	ft_push_operation.c \
	ft_selection_sort.c \
	ft_add_to_stack.c \
	ft_disorder_metric.c \
	ft_reverse_rotate_operation.c \
	ft_swap_operation.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_A = libft.a

RM = rm -f

all: $(NAME)

$(NAME) : $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C libft
	cp libft/libft.a libft/libft.h .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME) $(LIBFT_A) libft.h
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
