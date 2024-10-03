#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char	*copystring(char *src, size_t len) {
	char	*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	memcpy(result, src, len);
	result[len] = '\0';
	return (result);
}

static char	findinlist(char mode, char *elem1, char *lst2) {
	size_t	i;
	size_t	len;
	char	*elem2;

	i = 0;
	while (isspace(lst2[i]))
		i++;
	while (lst2[i] != '\0')
	{
		len = 0;
		while (lst2[i + len] != '\0' && !isspace(lst2[i + len]))
			len++;
		elem2 = copystring(lst2 + i, len);
		if (elem2 == NULL)
			break ;
		if (!strcmp(elem1, elem2))
			return (mode == '+');
		free(elem2);
		i += len;
		while (isspace(lst2[i]))
			i++;
	}
	return (mode == '-');
}

static void	mainloop(char mode, char *lst1, char *lst2) {
	size_t	i;
	size_t	len;
	char	*elem1;

	i = 0;
	while (isspace(lst1[i]))
		i++;
	while (lst1[i] != '\0')
	{
		len = 0;
		while (lst1[i + len] != '\0' && !isspace(lst1[i + len]))
			len++;
		elem1 = copystring(lst1 + i, len);
		if (elem1 == NULL)
			break ;
		if (findinlist(mode, elem1, lst2))
			printf("%s\n", elem1);
		free(elem1);
		i += len;
		while (isspace(lst1[i]))
			i++;
	}
}

int	main(int argc, char **argv) {
	if (argc < 4 || strlen(argv[1]) != 1
		|| (argv[1][0] != '+' && argv[1][0] != '-'))
		return (0);
	mainloop(argv[1][0], argv[2], argv[3]);
	return (0);
}
