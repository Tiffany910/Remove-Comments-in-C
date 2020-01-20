//Tiffany910

/*
Question 1 : Remove comments from a text files in C language
*/

#include <stdio.h>

int main (int argc, char *argv[])
{
 
  FILE *file_to_read;//,
  FILE *file_to_write; //Declare file
  char character, next_character;
  
  file_to_read = fopen (argv[1], "r"); //Open to read
  file_to_write = fopen ("result.txt", "w");  //Open to write

char ch, nextc;
  if (argc !=2)
  {
       printf ("No file name given");
  }


 // file_to_read = fopen (argv[1], "r");
  //file_to_write = fopen (argv[2], "w");


//If cannot be open then there is a problem 
  if (file_to_read == NULL)
    printf ("1) File does not exist or there is an opening error");
 // if (file_to_write == NULL)
   // printf ("2) File does not exist or there is an opening error");

  next_character = fgetc (file_to_read);
  while (next_character != EOF)   //Loop until end of file
  {
     character = next_character;
     next_character = fgetc (file_to_read);

     if ((character == '/') && (next_character == '*'))  //If comment is like --> /* <code> */
     {
        character = fgetc (file_to_read);
        next_character = fgetc (file_to_read);
        while (!((character == '*') && (next_character == '/'))) /* unroll until the end of comment*/
        {
         // printf("%c", character);
          character = next_character;
          next_character = fgetc (file_to_read);
          //printf("%c", next_character);

        }
        next_character = fgetc (file_to_read);  
        continue;

     }
     else if((character=='/') && (next_character == '/')) // block to handle single line comment.
     {
        next_character = fgetc (file_to_read);
        //printf("%c", next_character);
        while (!(next_character == '\n'))
        {
           next_character = fgetc (file_to_read);
           //printf("%c", next_character);  
        }
      next_character = fgetc (file_to_read);
    

       continue;
     }
     putc (character, file_to_write);
   }

  fclose (file_to_read);
  fclose (file_to_write);
  return 0;
 }
