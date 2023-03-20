# atoi_vs_itoa benchmark

To prove to the guys on reddit that itoa cannot ever be faster than atoi because it has to include modulos and a bunch of math while atoi goes brrrr

atoi10 and itoa10 was made by u/Boring_Tension165, and strtoul and sprintf was suggested by u/Practical_Cartoonist who allegedly observed a 4x speed difference in favour of sprintf, saying it was "expected"

Speeds were measured by compiling the program with `gcc -O0 main.c` and running `time ./a.out [0-5]`

# Results:
    my_atoi:    1.76s
    my_itoa:    6.86s
        
    atoi10:     2.98s
    itoa10:     3.02s
        
    strtoul:    1.70s
    sprintf:    4.38s
