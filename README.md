# Simple Shell

Simple shell is a Holberton project to end a semester of learning C. This shell can perform basic functions. The shell was kept fairly basic as this was the first major project tackled after learning how to code for a few months.

There were quite a few challenges involved with this project. The biggest being that this was our first attempt at creating our own program. There was a fair bit of frustration in trying to get everything working together nicely. Once this got sorted implementing features was much easier than trying to get the program to work initially.

### Features

cd - built-in to change directory

```
   cd [DIRECTORY]
```

env - built-in to print the current environment

```
env
```

exit - built-in to exit the shell

```
exit
```

## Installation

Simply clone the repo below and compile!

```
https://github.com/ranicholson/simple_shell
```
## Environment
Created and tested with **Ubuntu 14.04 LTS**

Compiled with **GCC 4.8.4**
## Usage

```
peytonbrsmith@penguin:~/simple_shell$ ./a.out
($) /bin/ls
a.out  builtins.c  execute.c  holberton.h  parse.c  path.c  _printf.c  README.md  simpshell.c  strtools2.c  strtools.c
($) ls -la /usr/
total 0
drwxr-xr-x 1 root root    80 Jul 21 23:26 .
drwxrwxrwx 1 root root   172 Nov  4 11:54 ..
drwxr-xr-x 1 root root 22188 Nov  4 11:53 bin
drwxr-xr-x 1 root root    10 Oct 27 11:00 games
drwxr-xr-x 1 root root  2262 Nov  3 18:50 include
drwxr-xr-x 1 root root  1880 Nov  3 19:34 lib
drwxr-xr-x 1 root root     6 Jul 21 23:26 lib64
drwxr-xr-x 1 root root    72 Jul 21 00:26 local
drwxr-xr-x 1 root root  4122 Nov  3 19:32 sbin
drwxr-xr-x 1 root root  2592 Nov  4 11:53 share
drwxr-xr-x 1 root root     0 May  2  2020 src
($) pwd
/home/peytonbrsmith/simple_shell
($) cd /home/
($) pwd
/home
($) ls
peytonbrsmith
($) exit
```

## Support

#### [Peyton](https://github.com/peytonbrsmith)

##### - Allen Nicholson <a href="https://github.com/ranicholson">Github</a> | <a href="https://www.linkedin.com/in/allen-nicholson/">LinkedIn</a> | <a href="https://twitter.com/allencodes2020">Twitter</a>
Allen is an amateur software engineer trying to find his way in this strange new world. Everyday he tries to learn a little bit more. Hoping to go pro someday soon.

## Project Status

There are a few small issues involving spacing that are uncorrected.

The following commands were not implemented: getline, exit status, set/unset env

Currently there are no plans to continue working on the simple shell after completion of the project.
