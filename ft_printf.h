/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:08:58 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 18:31:45 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# ifndef MAX_MEM
#  define MAX_MEM 10000000
# endif

# define B10 "0123456789"
# define B16_L "0123456789abcdef"
# define B16_U "0123456789ABCDEF"
# define B8 "01234567"
# define B2 "01"

typedef struct s_spec
{
	short	alt;
	char	pad;
	char	sign;
	long	width;
	long	precision;
	char	l;
	char	conv;
}	t_spec;

//ft_printf
int		ft_printf(const char *s, ...);
int		ft_printargs(const char *s, va_list args, t_list *strs);
void	ft_checkspec(size_t n, t_list **strs, size_t *len, size_t *len_m);
short	ft_print(t_list **strs, size_t *len, size_t *len_total);
short	ft_printcheck(t_list **strs, size_t *len, size_t *len_m, size_t *len_t);

//ft_printf_utils
void	ft_freehalf(void *tstr);
int		ft_nextspec(const char *s);
t_list	*ft_add_tstr(t_list **lst, t_list *curr, const char *s, int len);
t_list	*ft_add_conv(t_list **lst, t_list *curr, t_str *conv);

//ft_printf_spec
size_t	ft_addspec(t_list **lst, t_list **curr, const char **s, va_list args);
short	ft_setspec(const char **s, t_spec *spec, short *minor, va_list args);

//ft_printf_spec_set
size_t	ft_setflags(const char *s, t_spec *spec);
size_t	ft_setwidth(const char *s, t_spec *spec, short *error, va_list args);
size_t	ft_setpre(const char *s, t_spec *spec, short *error, va_list args);
size_t	ft_setconv(const char *s, t_spec *spec, short *minor, short *error);

//ft_printf_conv
t_str	*ft_get_conv_tstr(t_spec spec, va_list args);
t_str	*ft_percent(void);
t_str	*ft_bad(t_spec spec);
int		ft_fill_flags(t_spec spec, char *str);
int		ft_fill_conv(t_spec spec, char *str);

//ft_printf_utils_conv
void	ft_putnbrbase_str(ssize_t n, char *dest, char *base, int *i);
void	ft_putnbrbase_pos_str(size_t n, char *dest, char *base, int *i);
t_str	*ft_newtstr_pad(size_t len, size_t word_len, char pad);
long	ft_parsewidth(int width, char *pad);

//ft_printf_conv_charstr
t_str	*ft_char(t_spec spec, va_list args);
t_str	*ft_str(t_spec spec, va_list args);

//ft_printf_conv_nums_utils
size_t	ft_numlen(size_t n, size_t baselen);
void	ft_nbrbase(char *str, t_spec spec, size_t num, char *base);

//ft_printf_conv_ptr
t_str	*ft_ptr(t_spec spec, va_list args);
t_str	*ft_nil(t_spec spec);

//ft_printf_conv_nums
t_str	*ft_nums(t_spec spec, va_list args);
t_str	*ft_int(t_spec spec, va_list args);
t_str	*ft_int2(t_spec spec, ssize_t num);
t_str	*ft_uint(t_spec spec, size_t n);
t_str	*ft_bin(t_spec spec, size_t n);

//ft_printf_conv_nums_hex
t_str	*ft_hexl(t_spec spec, size_t n);
t_str	*ft_hexu(t_spec spec, size_t n);
t_str	*ft_oct(t_spec spec, size_t n);

#endif
