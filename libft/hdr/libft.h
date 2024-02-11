/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:44 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 18:20:50 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_str
{
	char	*s;
	size_t	len;
}	t_str;

//arr
void	ft_delarr(void **arr, void (del)(void *));
void	ft_delnarr(void **arr, void (del)(void *), size_t n);
void	ft_freearr(void **arr);
void	ft_freenarr(void **arr, size_t n);
void	ft_swap(void *a, void *b, void *(cpy)(void *, void *));
void	ft_swapint(int *a, int *b);
void	ft_swaplen(void *a, void *b, size_t len);
void	ft_swaplong(size_t *a, size_t *b);
void	ft_swapptr(void **a, void **b);

//char
short	ft_isalnum(int c);
short	ft_isalpha(int c);
short	ft_isascii(int c);
short	ft_isdigit(int c);
short	ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

//lst
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
size_t	ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstpop(t_list **lst, void (del)(void *), int n);
char	*ft_lsttstr_to_str(t_list **lst, size_t len, void (del)(void *),
			short (end)(void *));

//math
ssize_t	ft_max(ssize_t a, ssize_t b);
ssize_t	ft_min(ssize_t a, ssize_t b);
ssize_t	ft_powi(ssize_t x, size_t n);

//mem
void	ft_bspace(void *s, size_t n);
void	ft_bzchar(void *s, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//print
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(ssize_t n, int fd);
void	ft_putnbrbase_fd(ssize_t n, int fd, char *base);
void	ft_putstr_fd(char *s, int fd);

//str
ssize_t	ft_atoi(const char *nptr);
ssize_t	ft_atoibase(const char *nptr, const char *base);
ssize_t	ft_in(char c, const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
char	*ft_itoa(ssize_t n);
char	*ft_itoabase(ssize_t n, const char *base);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//tstr
t_str	ft_tstrnew(char *str, size_t len);
void	ft_tstrfree(t_str *tstr);

#endif
