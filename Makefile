NAME = libftprintf.a
COMP = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
      ft_printf_utils.c \
      ft_printf_utils_conv.c \
      ft_printf_spec.c \
      ft_printf_spec_set.c \
      ft_printf_conv.c \
      ft_printf_conv_charstr.c  \
      ft_printf_conv_nums_utils.c \
      ft_printf_conv_ptr.c \
      ft_printf_conv_nums.c \
      ft_printf_conv_nums_hex.c

SRC_BONUS = ft_printf_bonus.c \
      ft_printf_utils_bonus.c \
      ft_printf_utils_conv_bonus.c \
      ft_printf_spec_bonus.c \
      ft_printf_spec_set_bonus.c \
      ft_printf_conv_bonus.c \
      ft_printf_conv_charstr_bonus.c  \
      ft_printf_conv_nums_utils_bonus.c \
      ft_printf_conv_ptr_bonus.c \
      ft_printf_conv_nums_bonus.c \
      ft_printf_conv_nums_hex_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HDR = libft/hdr/libft.h

all : $(NAME)

bonus : $(OBJ_BONUS)
	make -C libft
	cp libft/libft.a ./libft.a
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS) $(HDR)

$(NAME) : $(OBJ)
	make -C libft
	cp libft/libft.a ./libft.a
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) $(HDR)

%.o: %.c
	$(COMP) $(CFLAGS) -c $^ -o $@ -I libft/hdr/

clean : 
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: all fclean clean re bonus
