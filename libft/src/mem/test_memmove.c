#include "test.h"

static void	test_memmove_child1(void) {
	char	buf[11];

	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memmove(buf, "HOLA MUNDO", 11), buf, "ft_memmove(%p, \"HOLA MUNDO\", 11)", buf);
	tlib_testresult_str(buf, "HOLA MUNDO", "ft_memmove(%p, \"HOLA MUNDO\", 11)", buf);
	tlib_testresult_addr(ft_memmove(buf, buf + 5, 2), buf, "ft_memmove(%p, %p, 2)", buf, buf + 5);
	tlib_testresult_str(buf, "MULA MUNDO", "ft_memmove(%p, %p, 2)", buf, buf + 5);
	tlib_testresult_addr(ft_memmove(buf + 3, buf, 4), buf + 3, "ft_memmove(%p, %p, 4)", buf + 3, buf);
	tlib_testresult_str(buf, "MULMULANDO", "ft_memmove(%p, %p, 4)", buf + 3, buf);
	tlib_testresult_addr(ft_memmove(buf + 7, buf, 3), buf + 7, "ft_memmove(%p, %p, 3)", buf + 7, buf);
	tlib_testresult_str(buf, "MULMULAMUL", "ft_memmove(%p, %p, 3)", buf + 7, buf);
	tlib_testmalloc_leak(NULL);
}

static void	test_memmove_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memmove(buf, NULL, 0), buf, "ft_memmove(%p, NULL, 0)", buf);
	tlib_testresult_addr(ft_memmove(NULL, "ASDFG", 0), NULL, "ft_memmove(NULL, \"ASDFG\", 0)");
	tlib_testresult_addr(ft_memmove(NULL, NULL, 0), NULL, "ft_memmove(NULL, NULL, 0)");
	tlib_testresult_addr(ft_memmove(NULL, NULL, 3), NULL, "ft_memmove(NULL, NULL, 3)");
	tlib_testmalloc_leak(NULL);
}

static void	test_memmove_child3(void) {
	ft_memmove(NULL, "ASDFG", 5);
}

static void	test_memmove_child4(void) {
	char	buf[5];

	ft_memmove(buf, NULL, 5);
}

void	test_memmove(void) {
	tlib_testprocess_ok(&test_memmove_child1);
	tlib_testprocess_ok(&test_memmove_child2);
	tlib_testprocess_segfault(&test_memmove_child3);
	tlib_testprocess_segfault(&test_memmove_child4);
}
