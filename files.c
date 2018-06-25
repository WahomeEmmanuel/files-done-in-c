#include <stdio.h>

int main()
{
 FILE *fp;
 char filename[100];
 char ch;
 int linecount, wordcount, charcount;
 int letters[1000];
 int oldcharcount = 0;
 int letterinword = 0;

 //stores number of words for 3,4,5,6,7 letters respectively
 int array[5];

 // Initialize counter variables
 linecount = 0;
 wordcount = 0;
 charcount = 0;

 // Prompt user to enter filename
  printf("Enter a filename :");
  scanf("%s",filename);
  printf("\n");


  
    // Open file in read-only mode
   fp = fopen(filename,"r");

   // If file opened successfully, then write the string to file
   if ( fp )
   {
	//Repeat until End Of File character is reached.	
	   while ((ch=getc(fp)) != EOF) {
	   	  // Increment character count if NOT new line or space
		    if (ch != ' ' && ch != '\n' && ch != '.') {
			 ++charcount;
			printf("%c", ch);
			}
		  // Increment word count if new line or space character
		   if (ch == ' ' || ch == '\n') {
			++wordcount;
			printf(" ");
			letterinword = charcount - oldcharcount;
			oldcharcount = charcount;			
			letters[wordcount] = letterinword;
			}
		   
		  // Increment line count if new line character
		   if (ch == '\n') { ++linecount; }
		   


	   }

	   if (charcount > 0) {
		++linecount;
	   }
    }
   else
      {
         printf("Failed to open the file\n");
        }
    printf("\n");
    printf("\nLines : %d \n", linecount);
    printf("Words : %d \n", wordcount);
    printf("Characters : %d \n", charcount);
    printf("\n");

for (int n = 0; n < 3; n++)
{
  // Prompt user to enter number of letters in a word to search
  int searchletters = 0;
  int countwords = 0;
  printf("Enter the number of letters of words you want to see :");
  scanf("%d", &searchletters);
  for(int i = 1; i <= wordcount;i++)
 {
  if(letters[i] == searchletters)
  {countwords++;}
 }
 
  printf("%d letter words in text file : %d \n", searchletters, countwords); 
}


for(int i = 1; i <= wordcount;i++)
 {
  if(letters[i] == 3)
   {++array[0];}
 if(letters[i] == 4)
   {++array[1];}
 if(letters[i] == 5)
   {++array[2];}
 if(letters[i] == 6)
   {++array[3];}
 if(letters[i] == 7)
   {++array[4];}
 }
printf("\nNumber of letters with corresponding words \n");
for(int j=0; j<=4; j++)
{
  printf("%d letters-%d words \n",j+3,array[j]);
}

printf("\n");
printf("\n");

    int highest = array[0];
    for(int check=0;check<=4;check++){
        if(array[check]>highest)
        {
          highest=array[check];
        }
    }
    for(int rows=highest;rows>=1;rows--){//rows
        for(int cols=0;cols<=4;cols++){//cols
            if(array[cols] >= rows){
                printf("*   ");
            }
            else{
                printf("    ");
            }
        }
        printf("\n");
    }
    for(int cols = 0;cols <=4;cols++){
        printf("----");
    }
    printf("\n");
    for(int cols = 3;cols <=7;cols++){
        printf("%d   ",cols);
    }
printf("\n");

fclose(fp);
return(0);
}
