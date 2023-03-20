/*
    RESULTS:
        my_atoi:    1.76s
        my_itoa:    6.86s
        
        atoi10:     2.98s
        itoa10:     3.02s
        
        strtoul:    1.70s
        sprintf:    4.38s
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void my_itoa(int num, char *target) {
    char holder[20];
    int i = 0;
    int j = 0;
    int mod;

    while (num) {
        mod = num % 10;
        num -= mod;
        num /= 10;
        holder[i] = (mod + '0');
        i++;
    }

    while (i) {
        target[j] = holder[(i - 1)];
        i--;
        j++;
    }
    
    target[j] = '\0';
}

void my_atoi(const char *source, int *num) {
    int i = 0;
    int n = 0;

    while (source[i] != '\0') {
        n = (n * 10) + (source[i] - '0');
        i++;
    }

    *num = n;
}

void itoa10( int n, char *p )
{
  char buffer[12];
  char *e = buffer + sizeof buffer;
  char *q = e - 1;
  long long int m;  // Need better precision because -INT_MIN cannot be
                    // represented in an 'int'.

  m = ( n < 0 ) ? -n : n;

  *q = '\0';

  // These divisions will probably be transformed in a
  // single multiplication.
  do
    *--q = '0' + m % 10;
  while ( m /= 10 );

  if ( n < 0 )
    *--q = '-';

  memcpy( p, q, e - q );
}

int atoi10( const char *p )
{
  _Bool negative = 0;
  int oldn;
  int n = 0;

  // 'int' can be negative!
  if ( *p == '-' )
  {
    negative = 1;
    p++;
  }

  oldn = 0;
  while ( *p )
  {
    // We need to check if char is a decimal digit.
    if ( ! isdigit( *p ) )
      break;

    n *= 10;
    n += *p - '0';

    // If overflows, return the previous value.
    if ( n < oldn )
    {
      n = oldn;
      break;
    }

    oldn = n;

    p++;
  }

  // Finally negates the value if "negative".
  if ( negative )
    n = -n;

  return n;
}

int main(int argc, char *argv[]) {
    if (argc != 2 || (argv[1][0] < '0' || argv[1][0] > '6')) {
        printf(
            "Give a number as argument to the program in order to run a specific function a lot of times. For instance:\n"
            "\ttime ./a.out 2\n"
            "\n"
            "Valid numbers:\n"
            "0 - my_atoi\n"
            "1 - my_itoa\n"
            "2 - atoi10\n"
            "3 - itoa10\n"
            "4 - strtoul\n"
            "5 - sprintf\n"
        );
        return 0;
    }

    long loops = 99999999;

    if (argv[1][0] == '0') {
        char *str = "123456";
        int num;
        
        while(loops--) {
            my_atoi(str, &num);
        }
    }
    else if (argv[1][0] == '2') {
        char *str = "123456";
        int num;
        
        while(loops--) {
            num = atoi10(str);
        }
    }
    else if (argv[1][0] == '4') {
        char *str = "123456";
        int num;
        
        while(loops--) {
            num = (int)strtoul(str, NULL, 10);
        }
    }
    else if (argv[1][0] == '1') {
        int num = 123456;
        char str[7];
        
        while(loops--) {
            my_itoa(num, str);
        }
    }
    else if (argv[1][0] == '3') {
        int num = 123456;
        char str[7];
        
        while(loops--) {
            itoa10(num, str);
        }
    }
    else if (argv[1][0] == '5') {
        int num = 123456;
        char str[7];
        
        while(loops--) {
            sprintf(str, "%d", num);
        }
    }

    return 0;   
}