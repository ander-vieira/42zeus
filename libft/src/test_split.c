#include "test.h"

//TODO make custom log messages

static size_t	split_mocked;

static void	test_split_free(char **split) {
	size_t	i;

	if (split != NULL) {
		i = 0;
		while (split[i] != NULL) {
			free(split[i]);
			i++;
		}
		free(split);
	}
}

static void	test_split_testone(char *str, char c, size_t len, ...) {
	va_list	args;
	char	**split;
	char	*expected;
	size_t	split_len;
	size_t	i;

	va_start(args, len);
	tlib_mockmalloc_reset();
	split = ft_split(str, c);
	tlib_testresult_notnull(split, "ft_split(%S, %c)", str, c);
	if (split != NULL) {
		split_len = 0;
		while (split[split_len] != NULL)
			split_len++;
		tlib_testresult_custom(len == split_len,
			"ft_split(%S, %c) did not return the expected number of elements\n- (expected: %z, actual: %z)\n", str, c, len, split_len);
		if (len == split_len) {
			tlib_testmalloc_size(split, sizeof(char *) * (len + 1), "ft_split(%S, %c)", str, c);
			i = 0;
			while (i < len) {
				expected = va_arg(args, char *);
				tlib_testresult_str(split[i], expected, "ft_split(%S, %c) (substring %z)", str, c, i);
				tlib_testmalloc_size(split[i], strlen(expected) + 1, "ft_split(%S, %c) (substring %z)", str, c, i);
				i++;
			}
		}
	}
	test_split_free(split);
	tlib_testmalloc_leak("ft_split(%S, %c)", str, c);
	va_end(args);
}

static void	test_split_child1(void) {
	test_split_testone("HOLA", ' ', 1, "HOLA");
	test_split_testone("HOLA MUNDO", ' ', 2, "HOLA", "MUNDO");
	test_split_testone("  HOLA   MUNDO ", ' ', 2, "HOLA", "MUNDO");
	test_split_testone("..HOLA...MUNDO.", '.', 2, "HOLA", "MUNDO");
	test_split_testone("   ", ' ', 0);
	test_split_testone("", ' ', 0);
}

static void	test_split_child2(void) {
	test_split_testone("HOLA MUNDO", '\0', 1, "HOLA MUNDO");
}

static void	test_split_child3(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(split_mocked);
	tlib_testresult_addr(ft_split("HOLA MUNDO", ' '), NULL, "ft_split(\"HOLA MUNDO\", ' ') (with malloc %z fail)", split_mocked);
	tlib_testmalloc_leak("ft_split(\"HOLA MUNDO\", ' ') (with malloc %z fail)", split_mocked);
}

static void	test_split_child4(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_split(NULL, ' '), NULL, "ft_split(NULL, ' ')");
	tlib_testmalloc_leak("ft_split(NULL, ' ')");
}

static void	test_split_testmock(size_t mocked) {
	split_mocked = mocked;
	tlib_testprocess_ok(&test_split_child3, NULL);
}

void	test_split(void) {
	tlib_testprocess_ok(&test_split_child1, NULL);
	tlib_testprocess_ok(&test_split_child2, "ft_split(\"HOLA MUNDO\", '\0')");
	test_split_testmock(1);
	test_split_testmock(2);
	test_split_testmock(3);
	tlib_testprocess_ok(&test_split_child4, "ft_split(NULL, ' ')");
}
