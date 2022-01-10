#include <stdio.h>
#define TAB 8

int main(int argc, char *argv[]){
	int currPos = 0;
	int c; /* c will represent character, however chars are integer values*/
	int blanks; /* # of blanks to add */

	while((c=getchar()) != EOF){
		if(c != '\t' && c != '\n' && c != '\b'){
			putchar(c); /*If c isn't a tab or newLine */
			currPos++;
		}
		else if(c == '\t'){
			blanks = TAB - (currPos % TAB);
		       	while(blanks != 0){
				putchar(' ');
				blanks--;
				currPos++;
			}
		}
		else if(c == '\n'){
			currPos = 0;
			putchar(c);
	
		} 
		else if(c== '\b'){ /*Don't allow backspaces past left margin*/
			if(currPos != 0){
				currPos--;
			}
			putchar(c);
		}
		else if(c=='\r'){
			currPos = 0;
			putchar(c);
		}
	}

	return 0;
}
