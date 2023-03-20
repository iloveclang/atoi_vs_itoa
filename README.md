# atoi_vs_itoa benchmark

To prove to the guys on reddit that itoa cannot ever be faster than atoi because it has to include modulos and a bunch of math while atoi goes brrrr

atoi10 and itoa10 was made by u/Boring_Tension165, and strtoul and sprintf was suggested by u/Practical_Cartoonist who allegedly observed a 4x speed difference in favour of sprintf, saying it was "expected"

Speeds were measured by compiling the program with `gcc -O0 main.c` and running `time a.out [0-5]`
