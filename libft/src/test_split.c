#include "test.h"

static size_t	g_mocked;

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
	size_t	i;

	va_start(args, len);
	tlib_mockmalloc_reset();
	split = ft_split(str, c);
	tlib_testresult_raw(split != NULL);
	tlib_testmalloc_size(split, sizeof(char *) * (len + 1), NULL);
	i = 0;
	while (i < len) {
		expected = va_arg(args, char *);
		tlib_testresult_raw(split[i] != NULL && !strcmp(split[i], expected));
		tlib_testmalloc_size(split[i], strlen(expected) + 1, NULL);
		i++;
	}
	tlib_testresult_raw(split[len] == NULL);
	test_split_free(split);
	tlib_testmalloc_leak("ft_split(%S, %c)", str, c);
	va_end(args);
}

static void	test_split_child1(void) {
	test_split_testone("AB CDE F", ' ', 3, "AB", "CDE", "F");
	test_split_testone("   AB  CDE F  ", ' ', 3, "AB", "CDE", "F");
	test_split_testone("     ", ' ', 0);
	test_split_testone("AABABBACAA", 'A', 3, "B", "BB", "C");
}

static void	test_split_child2(void) {
	test_split_testone("ABC DE", '\0', 1, "ABC DE");
	test_split_testone("", ' ', 0);
	test_split_testone("", '\0', 0);
}

static void	test_split_child3(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(g_mocked);
	tlib_testresult_raw(ft_split("AB CD", ' ') == NULL);
	tlib_testmalloc_leak("ft_split(\"AB CD\", ' ') (malloc %z fail)", g_mocked);
}

static void	test_split_child4(void) {
	tlib_testresult_raw(ft_split(NULL, ' ') == NULL);
}

static void	test_split_testmock(size_t mocked) {
	g_mocked = mocked;
	tlib_testprocess_ok(&test_split_child3);
}

void	test_split(void) {
	tlib_testprocess_ok(&test_split_child1);
	tlib_testprocess_ok(&test_split_child2);
	test_split_testmock(1);
	test_split_testmock(2);
	test_split_testmock(3);
	tlib_testprocess_ok(&test_split_child4);
}
