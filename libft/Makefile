NAME = libft.a
COMP = cc 
CFLAGS = -Wall -Wextra -Werror

SRC_ARR = ft_freearr.c \
	  ft_freenarr.c \
	  ft_delarr.c \
	  ft_delnarr.c \
	  ft_swap.c \
	  ft_swapint.c \
	  ft_swaplen.c \
	  ft_swaplong.c \
	  ft_swapptr.c

SRC_CHAR = ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_tolower.c \
	   ft_toupper.c

SRC_LST = ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lstsize.c \
	  ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstpop.c \
	  ft_lsttstr_to_str.c

SRC_MATH = ft_max.c \
	   ft_min.c \
	   ft_powi.c

SRC_MEM = ft_bspace.c \
	  ft_bzchar.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_memchr.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_memcmp.c

SRC_PRINT = ft_putchar_fd.c \
	    ft_putendl_fd.c \
	    ft_putnbr_fd.c \
	    ft_putnbrbase_fd.c \
	    ft_putstr_fd.c

SRC_STR = ft_atoi.c \
	  ft_atoibase.c \
	  ft_in.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_striteri.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_itoabase.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strmapi.c \
	  ft_strtrim.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_substr.c \
	  ft_strncmp.c

SRC_TSTR = ft_tstrnew.c \
	   ft_tstrfree.c

SRC = $(addprefix src/arr/, $(SRC_ARR)) \
      $(addprefix src/char/, $(SRC_CHAR)) \
      $(addprefix src/lst/, $(SRC_LST)) \
      $(addprefix src/math/, $(SRC_MATH)) \
      $(addprefix src/mem/, $(SRC_MEM)) \
      $(addprefix src/print/, $(SRC_PRINT)) \
      $(addprefix src/str/, $(SRC_STR)) \
      $(addprefix src/tstr/, $(SRC_TSTR))


OBJ = $(SRC:.c=.o)

HDR = hdr/libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ) $(HDR)

%.o: %.c
	$(COMP) $(CFLAGS) -c $^ -o $@ -I hdr/

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re 
