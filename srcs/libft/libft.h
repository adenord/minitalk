/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:56:09 by adenord           #+#    #+#             */
/*   Updated: 2023/11/04 18:20:23 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdarg.h>
# include <fcntl.h>

/* ************************ */
/*                          */
/*     Struct for Bonus     */
/*                          */
/* ************************ */

typedef struct s_list {
	void			*content;
	size_t			len;
	struct s_list	*next;
}					t_list;

/* ************************ */
/*                          */
/*     Part 1 prototypes    */
/*                          */
/* ************************ */

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);		
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* ************************ */
/*                          */
/*     Part 2 prototypes    */
/*                          */
/* ************************ */

char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/* ************************ */
/*                          */
/*     Bonus prototypes     */
/*                          */
/* ************************ */

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
t_list		*ft_lst_insert(t_list *lst, t_list **elem, t_list *new);

/* ************************ */
/*                          */
/*  Additional prototypes   */
/*                          */
/* ************************ */

void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strstr(const char *haystack, const char *needle);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(const char *str);
void		ft_putchar(char c);
void		ft_putnbr(long nb);
void		ft_strrev(char *str);
long		ft_atol(const char *str);

/* ************************ */
/*                          */
/*    ft_printf functions   */
/*                          */
/* ************************ */

int			ft_printf(const char *format, ...);
int			nbr_args(const char *format);
t_list		*fct_unsigned(t_list **lst, t_list *elem, int arg);
t_list		*fct_address(t_list **lst, t_list *elem, long adr);
t_list		*fct_hexa(t_list **lst, t_list *elem, int arg, char op);
t_list		*cutting(const char *format);
void		replace_and_add(t_list **lst, va_list args);
t_list		*fct_integer(t_list **lst, t_list *elem, int arg);
t_list		*fct_string(t_list **lst, t_list *elem, char *arg);
t_list		*fct_character(t_list **lst, t_list *elem, int arg);
int			ft_lst_strlen(t_list *lst);
void		display_list(t_list *lst);
char		*ft_itoun(unsigned int nbr);
char		*gen_excp(char *fmt, char *str);
char		*gen_excp_str(char *fmt, char *str);
char		*min_width(char *fmt, char *str);
void		left_aligned(char *str, size_t len);
char		*precision(char *fmt, char *str);
char		*zeroed(char *fmt, char *str);
char		*formater(int len, int zeros, char *minus, char *str);
char		*precision_str(char *format, char *str);
char		*gen_excp_adr(char *fmt, char *str);
t_list		*gen_excp_chr(t_list *temp2, t_list **lst, t_list *elem, int arg);
char		*hex_header(char *format, char *str);
char		*plus_header(char *str, int len);
char		*space_header(char *str);

/* ************************ */
/*                          */
/*       gnl functions      */
/*                          */
/* ************************ */

char		*get_next_line(int fd);

#endif
