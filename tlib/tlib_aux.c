#include "tlib_int.h"

/****** Static functions ******/

static char	*tlib_readall_join(char *result_old, char *buf) {
	char	*result;
	size_t	old_len;
	size_t	buf_len;

	old_len = tlib_str_len(result_old);
	buf_len = tlib_str_len(buf);
	result = libc_malloc(old_len + buf_len + 1);
	if (result == NULL)
		return (NULL);
	tlib_str_cpy(result, result_old);
	tlib_str_cpy(result + old_len, buf);
	libc_free(result_old);
	return (result);
}

/****** Exposed functions ******/

t_bool	tlib_isalloc(void *addr) {
	return (tlib_mockmalloc_lookup(addr) != 0);
}

t_bool	tlib_mem_isset(void *addr, size_t n, unsigned char c) {
	size_t	i;

	if (addr == NULL)
		return (FALSE);
	i = 0;
	while (i < n) {
		if (((unsigned char *)addr)[i] != c)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	tlib_mem_cmp(void *addr1, void *addr2, size_t n) {
	size_t	i;

	i = 0;
	while (i < n) {
		if (((unsigned char *)addr1)[i] != ((unsigned char *)addr2)[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	*tlib_readall(int fd) {
	char	buf[33];
	char	*result;
	ssize_t	read_bytes;

	result = libc_malloc(1);
	result[0] = '\0';
	while (1) {
		read_bytes = read(fd, buf, 32);
		if (read_bytes == -1)
			return (libc_free(result), NULL);
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		result = tlib_readall_join(result, buf);
	}
	return (result);
}

void	tlib_str_cpy(char *dst, char *src) {
	size_t	i;

	if (dst == NULL || src == NULL)
		return ;
	i = 0;
	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

t_bool	tlib_str_cmp(char *str1, char *str2) {
	size_t	i;

	if (str1 == NULL && str2 == NULL)
		return (TRUE);
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

size_t	tlib_str_len(char *str) {
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
