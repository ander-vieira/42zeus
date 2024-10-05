#include "test.h"

static void	test_strtrim_testone(char *str, char *set, char *expected) {
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_strtrim(str, set);
	tlib_testresult_str(result, expected, "ft_strtrim(%S, %S)", str, set);
	tlib_testmalloc_size(result, strlen(expected) + 1, "ft_strtrim(%S, %S)", str, set);
	free(result);
	tlib_testmalloc_leak("ft_strtrim(%S, %S)", str, set);
}

static void	test_strtrim_child1(void) {
	test_strtrim_testone("HOLA", " ", "HOLA");
	test_strtrim_testone("HOLA MUNDO", " ", "HOLA MUNDO");
	test_strtrim_testone("  HOLA", " ", "HOLA");
	test_strtrim_testone("HOLA   ", " ", "HOLA");
	test_strtrim_testone("  HOLA MUNDO ", " ", "HOLA MUNDO");
	test_strtrim_testone("HOLA MUNDO", "H", "OLA MUNDO");
	test_strtrim_testone("  HOLA MUNDO", "H", "  HOLA MUNDO");
	test_strtrim_testone("HOLA MUNDO", "O", "HOLA MUND");
	test_strtrim_testone("HOLA MUNDO ", "O", "HOLA MUNDO ");
	test_strtrim_testone("HOLA MUNDO", "HO", "LA MUND");
	test_strtrim_testone("  HOLA MUNDO", " O", "HOLA MUND");
	test_strtrim_testone("   ", " ", "");
	test_strtrim_testone(" .. . ...", " .", "");
	test_strtrim_testone("", " ", "");
	test_strtrim_testone("HOLA MUNDO", "", "HOLA MUNDO");
}

static void	test_strtrim_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_addr(ft_strtrim("HOLA", " "), NULL, "ft_strtrim(\"HOLA\", \" \") (with malloc fail)");
}

static void	test_strtrim_child3(void) {
	tlib_testresult_addr(ft_strtrim(NULL, " "), NULL, "ft_strtrim(NULL, \" \")");
}

static void	test_strtrim_child4(void) {
	tlib_testresult_addr(ft_strtrim("HOLA", NULL), NULL, "ft_strtrim(\"HOLA\", NULL)");
}

void	test_strtrim(void) {
	tlib_testprocess_ok(&test_strtrim_child1);
	tlib_testprocess_ok(&test_strtrim_child2);
	tlib_testprocess_ok(&test_strtrim_child3);
	tlib_testprocess_ok(&test_strtrim_child4);
}
