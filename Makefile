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

OBJS_DIR = object_files

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT_A = libft.a

RM = rm -rf

all: $(NAME)

$(NAME) : $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C libft

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJS_DIR)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
