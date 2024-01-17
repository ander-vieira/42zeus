# 42Zeus

To install, use this command:

	curl https://raw.githubusercontent.com/ander-vieira/42zeus/master/setup | bash

Once installed, you will need to start a new terminal process to be able to use the "zeus" command.

Usage: "zeus \<directory\>" will test the directory passed by the argument, as a relative or absolute path. For example, to test the current directory, you can use:

	zeus .

42Zeus will automatically detect the project it is testing and act accordingly. The currently supported projects are:

- libft

I plan to add tests for (at least) the following projects in the future:

- ft_printf
- get_next_line
- pipex
- minitalk