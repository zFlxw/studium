/* File Analyzer.c
     TO DO 1: Write a program which reads a file and counts for each byte value (0-255) how often it occurs.
     TO DO 2: Display the number of occurences as bars (i.e. as a histogram)
     TO DO 3: fgetc(...) is quite inefficient, replace it by reading bigger chunks of the file with fread(...)
     TO DO 4: How do the histogramms of various file types differ, e.g. .txt, .doc, .c, .jpg, .zip
     TO DO 5: Can you make any conclusions regarding the storage efficiency of the format? 
              (optional, further reading: 'Entropy' in information theory)
     TO DO 6: Develop a metric for calculating a measure of 'information density' in the file. 
              (the less likely you can predict values, the higher is their information content)
     TO DO 7: Try to develop a file format guesser, which guesses the file type based on the character histogram.
*/

#include <stdio.h>
#include <stdlib.h>


int read_file(char *file_name)
{
   FILE *file;     // File pointer
   int val;

   file=fopen(file_name,"rb");   // "rb" = Read bytes (not text)
   if(file==NULL) {
       printf("Error: can't open file.\n");
       return -1;
   }

   while(!feof(file))  {    // End of file not yet reached
       val=fgetc(file);     // Read next character

       // Do something
   }
   fclose(file);    // Do not forget this!
   return 0;
}

main() {
	read_file("Test");
}
   