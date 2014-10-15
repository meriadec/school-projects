/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:24:11 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/05 17:38:17 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "get_next_line.h"

# define TRUE		1
# define FALSE		0

/*
** structs
*/
typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*parent;
	struct s_btree	*right;
	struct s_btree	*left;
	size_t			content_size;
	void			*content;
}					t_btree;

/*
** memory
*/
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);

/*
** strings
*/
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_isblank(char c);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
int			ft_startswith(const char *str, const char *s);
char		*ft_lpad(char *input, size_t len, char c);
char		*ft_rpad(char *input, size_t len, char c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_multijoin(int count, ...);
char		*ft_struntil(char *str, char stop);
char		*ft_struntil_fn(char *str, int (*fn)(int c));
void		ft_streplace(char **str, char *pattern, char *replace);
int			ft_stronly(char *str, int (*fn)(int c));

/*
** tabs
*/
int			ft_tab_len(char **array);
void		ft_printab(char **array);
void		ft_free_tab(void ***arr);
void		ft_trunc_tab(char ***arr, int nb);
void		ft_copy_tab(char ***dest, char **arr);

/*
** output
*/
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*
** lists
*/
t_list		*ft_lstnew(void const *content, size_t content_size);
t_dlist		*ft_dlstnew(void const *content, size_t content_size);
void		ft_dlstadd(t_dlist **alst, t_dlist *new);
void		ft_dlstpush(t_dlist **alst, t_dlist *new);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void		ft_lstadd(t_list **alst, t_list *new);
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void		ft_lstpush(t_list **alst, t_list *new);
int			ft_charin(char *str, char c);
void		ft_lstswap(t_list *lst1, t_list *lst2);
void		ft_lstsort(t_list *lst, int (*f)(t_list *, t_list *));
int			ft_indexof(char *str, char c);
void		ft_printlst(t_list *lst);
int			ft_lstlen(t_list *lst);

/*
** btree
*/
t_btree		*btree_create_node(void *content, size_t content_size);
void		btree_insert_data(t_btree **root, void *content,
		size_t content_size, int (*cmpf)(void *, void *));
void		btree_print(t_btree *root, char *type, int level);

#endif
