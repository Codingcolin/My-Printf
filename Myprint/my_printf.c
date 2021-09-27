#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>


void my_putchar(char c) {
    write(1, &c, 1);
}

void print_oct(int dec)
  { 
    if (dec / 8 != 0)
    {
        print_oct(dec / 8);
        
    } 
        my_putchar((dec % 8) + '0');
  }

void print_int(int num)
  { 
    if (num < 0)
    {
        my_putchar('-');
        num = -num;
    }
    if (num / 10 != 0)
    {
        print_int(num / 10);
        
    } 
        my_putchar((num % 10) + '0');
  }

int my_strlen(char* str)
{
    int len = 0;

    while(*str) 
    {
        str++;
        len++;
    }
    return len;
}
 

  void put_str(char *str)
{
    int len = my_strlen(str);
    write(1, str , len);
}

void print_hexa(long long num) 
{
    char hexiaDeci[100] = {'\0'};
    int i = 1;
    int temp;
    
    while(num != 0) 
    {
        //printf("While loop starting %d\n", num);
        
        temp = num % 16;
        //printf("this the temp value %d\n", temp);

        if(temp < 10) {
           temp = '0' + temp;
        }
        else {
            temp = 'a' + temp-10;
        }
        hexiaDeci[i++] = temp;
        num = num / 16; 
    }
    int j = i - 1;

   while(j > 0) 
    {
        
        my_putchar(hexiaDeci[j]);
        j--;
        
    }       
    
}

void print_unint(unsigned int num)
  { 
    if (num / 10 != 0)
    {
        print_unint(num / 10);
        
    } 
        my_putchar((num % 10) + '0');
  }

void print_ptr(long long ptr) 
{
    
   
        print_hexa(ptr); 
}

int my_printf(char* format, ...)
{
    //printf("test %s", format);
    va_list arg;
    va_start(arg, format);

    int i = 0;
    while(format[i] != '\0') 
    { //Print first string
    //printf("\nThis format %s\n", format);
        if(format[i] != '%')
        {
            my_putchar(format[i]);
        }   
        else if(format[i] == '%')
        {
            i++;
            switch(format[i])
                {
                long long value; 
                char* string;
                
                  
                case 'c' : value = va_arg(arg, int);
                    my_putchar(value);
                    break;
                case 's' : string = va_arg(arg, char *);
                    put_str(string);
                    break;
                case 'd' : value = va_arg(arg, int);
                    print_int(value);
                    break;
                case 'o' : value = va_arg(arg, int);
                    print_oct(value);
                    break;
                case 'u' : value = va_arg(arg, unsigned int);
                    print_unint(value);
                    break;
                case 'x' : value = va_arg(arg, unsigned int);
                    print_hexa(value);
                    break;     
               case 'p' : value = va_arg(arg,  long long);
                    put_str("Ox");
                    print_ptr(value);
                    break;   
               
                }
        }
        i++;
    }
    va_end(arg);
}



int main() {
    int a = 0;
   my_printf("This is a ptr %p\n", &a);
   //printf("This is a ptr %p\n", &a);
   
   my_printf("This is decimal to hexidecimal conversion %x \n", 2545);
   my_printf("The octal value of this number is : %o\n", 80);
   my_printf("This is the decimal %d\n", 10);
   my_printf("This is the string %s\n", "hey");
   my_printf("This is the unsigned int %u\n", 2);
   my_printf("This is the character %c %c\n", 'h', 'e');

    return 0;
}


