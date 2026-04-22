all:
	cc -Wall -Wextra -Werror push_swap.c libft.a -o push_swap

libft_a:
	make -C libft
	cp libft/libft.a libft/libft.h .
	make clean -C libft

.PHONY: all libft_a
