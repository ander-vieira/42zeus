# 42Zeus

## Summary

42zeus is an automated testing tool intended to help find problems in official 42 projects. It is designed to be lightweight and simple to use, while providing valuable assistance during the bugfixing and refining phases of development.

## What is 42

42 is a programming school with an innovative pedagogical approach, which involves peer-learning as the main drive in improving one's abilities.
A majority of the mandatory projects are developed using C and C++, and there is a strong focus on fundamentals, such as data structures, algorithms, and an emphasis on testing and clean coding practices.
You can read more about it [here](https://42.fr/en/homepage).

## Disclaimer

The main purpose of the tester is to be used as a safeguard against test cases that students are likely to overlook, or as a last resort for problems that are difficult to diagnose. However, overreliance on this or any other tester is harmful to the learning process and takes away from the 42 experience. When developing a project, you should be relying on your own testing and error-checking first, on your fellow students second, and on a testing tool last.

This tester is also not intended for use when evaluating other students' work. Evaluations need to ensure the student being evaluated understands the core concepts of the project, can explain how their own code works, and defend the decisions they made. The evaluated student should also be able to test their own code.

Ultimately, 42zeus is just a tool; whether it is used to add value to your experience or misused is up to you.

## Installing and updating

42Zeus is compatible with both Mac and Linux systems (tested on Ubuntu 22.04). In particular, it should work on the computers used in 42 facilities, as it is built on the same technologies used for most official projects. If working on a personal computer, you will also need to have curl and git installed (these are provided by default on 42 computers).

Running the following command will install 42zeus for the current user (it does not require root access):

	curl https://raw.githubusercontent.com/ander-vieira/42zeus/master/setup | bash

The command will install 42zeus on the ~/42zeus directory, inside the user's home directory. If this directory is already in use due to a previous install, you will need to remove this folder manually before installing. If you are using the directory for other purposes, please consider renaming the directory in order to allow 42zeus to be installed.

This will also set up the aliases needed to run the "zeus" command on both zsh and bash. However, these aliases will not be added to the current terminal session; opening a new terminal will enable the command.

In order to update an existing install to a newer version, simply run this command:

	zeus --update

This will pull the latest version of the repository.

## Usage

42zeus will automatically detect the project that needs to be tested. Thus, in order to run the tester on the current directory, you can run it directly as:

	zeus

Alternatively, you can specify the directory that contains the project to test by passing it as an argument. For example, to test a project inside the projects/libft/ directory:

	zeus projects/libft/

## Testable projects

These are the project that 42zeus currently has tests for:

- libft

The following projects are 

- ft_printf
- get_next_line
- pipex
- minitalk