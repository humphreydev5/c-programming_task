#include "main.h"

int _printf(const char *format, ...)
{
  int character_print = 0;
  va_list list_of_characters;
  if(format == NULL)
  return-1;
  va_start(list_of_characters, format);
  while (*format)/*A loop that iterate the character of the string*/
  {
    if(*format != '%')/*If format is not the % sign*/
    {
      write(1, format, 1);/*write the char to the standard output (terminal) */
      character_print ++;
    }
    else/*If format is the % sign*/
    {
      format++; /*Skip '%' then check the next character*/
      if(*format == '\0')
        break;
      if (*format == '%') /* This solves the '%'*/
      {
        /*Handle '%%' (double '%')*/
        write(1, format, 1);
        character_print++;
      }
      else if (*format == 'c')
      {
         /*Handle 'c' (character)*/
      char c = va_arg(list_of_characters, int); /*Use va_arg(list, char) for char*/
      write(1, c, 1);
      character_print++;
      }
      else if(*format == 'c')
      {
        /*Handle '%c'(character)*/
        char c = va_arg(list_of_characters, int);
        /* Use va_arg (list, char) for char*/
        write (1, c, 1);
        character_print ++;
      }
      else if(*format == 's')
      {
        char *str = va_arg(list_of_characters, char);
        int str_len = 0; //Calculate the lenght of the string
        while (str[str_len] !='\0');
        str_len++;
        while (1, str, str_len);
        character_print += str_len; 
      }
    } 
    format++;
    var_end(list_of_characters);
  }
}
