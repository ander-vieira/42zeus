#include "tlib_int.h"

t_bool	tlib_islogging;
int		tlib_logfd;
char	*tlib_section;
t_bool	tlib_newsection;

t_alloc	*tlib_allocs;
t_amock	*tlib_mocks;

t_bool	tlib_ischild;
t_bool	tlib_testfailed;

int		tlib_testprint_pipe[2];
