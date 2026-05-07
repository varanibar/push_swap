NAME = push_swap

SRCS = ft_add_to_stack.c \
	ft_assign_rank.c \
	ft_benchmark.c \
	ft_check_input_utils.c \
	ft_check_input.c \
	ft_chunk_sort_utils.c \
	ft_chunk_sort.c \
	ft_disorder_metric.c \
	ft_free_stack.c \
	ft_init_variables.c \
	ft_is_stack_sorted.c \
	ft_push_operation.c \
	ft_radix_sort.c \
	ft_reverse_rotate_operation.c \
	ft_rotate_operation.c \
	ft_selection_sort.c \
	ft_stack_size.c \
	ft_swap_operation.c \
	push_swap.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT_A = libft.a

RM = rm -f

all: $(NAME)

$(NAME) : $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C libft

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
