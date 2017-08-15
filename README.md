# Makefile

The standard Unix tool make is used to automate the separate compilation process. When
you ask make to build a program, it only rebuilds those parts of the program whose source has
changed, and any parts of the program that depend on those parts etc. In order to accomplish
this, we tell make (via a Makefile) which parts of the program depend on which other parts
of the program. Make then uses the Unix \last modied" timestamps of the les to decide
when a le is older than a le it depends on, and thus needs to be rebuilt. In this problem,
you will simulate the dependency-tracking functionality of make. We provide a test harness
(main.cc) that accepts the following commands:
 target: source|indicates that the le called target depends on the le called source
 touch file | indicates that the le called file has been updated. Your program will
respond with
file updated at time n
where n is a number whose signicance is explained below
 make file|indicates that the le called file should be rebuilt from the les it depends
on. Your program will respond with the names of all targets that must be rebuilt in
order to rebuild file.
A target should be rebuilt whenever any target it depends on is newer than the target itself.
In order to track ages of les, you will maintain a virtual \clock" (just an int) that \ticks"
every time you issue the touch command (successful or not). When a target is rebuilt, its last-
modied time should be set to the current clock time. Every target starts with a last-modied
time of 0. For example:

a: b
touch b
touch b
touch b

will produce the output (on stdout)
b updated at time 1
b updated at time 2
b updated at time 3

It is not valid to directly update a target that depends on other targets. If you do, your
program should issue an error message on stdout, as illustrated below:
a: b
touch a
(Output:)
Cannot update non-leaf object
When you issue the make file (build) command, the program should rebuild any les within
the dependency graph of file that are older than the les they depend on. For example:
a: b
a: c
b: d
c: e
touch e
make a
will produce the output
e updated at time 1
Building c
Building a
because file c depends on e, and a depends on c. Note that b is not rebuilt. The order in
which the Building messages appear is not important.
A file may depend on at most 10 other lines. If you attempt to give a file an 11th dependency,
issue the error message
Max dependencies exceeded
on stdout, but do not end the program. If you give a file the same dependency more than
once, this does not count as a new dependency, i.e., if you give a file a dependency that
it already has, the request is ignored. For example, if a depends on b, then adding b as a
dependency to a a second time has no effect. On the other hand, if b also depends on c,
then c may still be added to a as an additional dependency, even though a already indirectly
depends on c.
There may be at most 20 files in the system. (Note that files are created automatically when
you issue the : command, but if a line with the same name already exists, you use the existing
file, rather than create a new one.) If you create more than 20 lineles, issue the error message
Max targets exceeded.

