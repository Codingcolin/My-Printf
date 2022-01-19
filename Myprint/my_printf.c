#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>


int my_putchar(char c) {
 return write(1, &c, 1);
}

int print_oct(int dec)
  { 
    int result = 0;  
    if (dec / 8 != 0)
    {
       result = print_oct(dec / 8);
        
    } 
      result += my_putchar((dec % 8) + '0');
    return result;
    }

    

int print_int(int num)
  { 
    int result = 0;    
    if (num < 0)
    {
        my_putchar('-');
        num = -num;
    }
    if (num / 10 != 0)
    {
       result = print_int(num / 10);
        
    } 
        my_putchar((num % 10) + '0');
        return result;
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
 

  int put_str(char *str)
{
    if(str == NULL) 
    {
        return 0;
    } else {
        int len = my_strlen(str);
        return write(1, str , len);
    }
    
}

int print_hexa(long long num) 
{
    char hexiaDeci[100] = {'\0'};
    int i = 1;
    int temp;
    int result = 0;  
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
      result = hexiaDeci[i++] = temp;
        num = num / 16; 
    }
    int j = i - 1;

   while(j > 0) 
    {
        
    result = my_putchar(hexiaDeci[j]);
        j--;
        
    }       
    return result;
}

int print_unint(unsigned int num)
  { 
    int result = 0;  
    if (num / 10 != 0)
    {
       result = print_unint(num / 10);
        
    } 
        my_putchar((num % 10) + '0');
        return result;
  }

int print_ptr(long long ptr) 
{
    int result = 0;
   
     result = print_hexa(ptr); 
     return result;
}

int my_printf(char* format, ...)
{
    //printf("test %s", format);
    va_list arg;
    va_start(arg, format);
    int count = 0;
    int i = 0;
    while(format[i] != '\0') 
    { //Print first string
    //printf("\nThis format %s\n", format);
        if(format[i] != '%')
        {
            count += my_putchar(format[i]);
            
        }   
        else if(format[i] == '%')
        {
            i++;
            switch(format[i])
                {
                long long value; 
                char* string;
                
                  
                case 'c' : value = va_arg(arg, int);
                   count += my_putchar(value);
                    break;
                case 's' : string = va_arg(arg, char *);
                   count += put_str(string);
                    break;
                case 'd' : value = va_arg(arg, int);
                   count += print_int(value);
                    break;
                case 'o' : value = va_arg(arg, int);
                   count += print_oct(value);
                    break;
                case 'u' : value = va_arg(arg, unsigned int);
                   count +=  print_unint(value);
                    break;
                case 'x' : value = va_arg(arg, unsigned int);
                   count +=  print_hexa(value);
                    break;     
               case 'p' : value = va_arg(arg,  long long);
                  count +=  put_str("Ox");
                    print_ptr(value);
                    break;   
               
                }
        }
        i++;
    }
    va_end(arg);
    return count;
}



int main() {
    int a = 0;
    int result = 0;
   result = my_printf("This is a ptr %p\n", &a);
   printf("size is %d\n", result);
   //printf("This is a ptr %p\n", &a);
   
    result = my_printf("This is decimal to hexidecimal conversion %x \n", 2545);
    printf("size is %d\n", result);
    result = my_printf("The octal value of this number is : %o\n", 80);
    printf("size is %d\n", result);
    result = my_printf("This is the decimal %d\n", 10);
    printf("size is %d\n", result);
    result = my_printf("This is the string %s\n", "hey");
    printf("size is %d\n", result);
    result = my_printf("This is the unsigned int %u\n", 2);
    printf("size is %d\n", result);
    result = my_printf("This is the character %c %c\n", 'h', 'e');
    printf("size is %d\n", result);
    result = printf("The octal value of this number is : %o\n", 80);
    printf("result should be %d\n", result);
    my_printf("NULL STRING %s\n", (char*)NULL);
    return 0;
}


