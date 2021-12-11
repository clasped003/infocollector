#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
/*General-Purpose information collection menu. User can add information they want tied to
their profile. This will be transferred over to the profile struct later on.

Notes:
-Need to properly set up age entry prompt to not use getchar()
XNeed to edit "class selection" to "user status" selection
-Need to upload to github
XNeed to clean up prompts to generalize for all-use purpose
 */

int main(){
		char uName[20];
		char uGenderLetter;
		char uGender[10];
		char uClassLetter;
		char uClass[10];
		int looper = 0;

while(looper == 0){
    system("clear");						

//Name selection
int nameChoiceLoop = 1;
while(nameChoiceLoop == 1){ 								
printf("What is your name? (Max 20 Characters) "); 
if (fgets(uName, 20, stdin) != NULL) { 
		if (!strchr(uName, '\n')) { // consume rest of chars up to '\n' 
				int ch; while (((ch = getchar()) != EOF) && (ch != '\n')) /* void */; 
				if (ch == EOF) /* input error */; 
				printf("Your name is too long, try again. . .  \n" );			
				} else{ 
										printf("Your name is: %s", uName); // name includes ENTER 
										nameChoiceLoop = 0;
				} //if else
		}//if
}//Name while		
//Gender Selection
int genChoiceLoop = 1;
while(genChoiceLoop == 1){				
puts("What is your gender?('M'ale, 'F'emale, or 'O'ther)");
		uGenderLetter	= getchar();
		int uGenderch; while (((uGenderch = getchar()) != EOF) && (uGenderch != '\n')) /* void */;
		if(tolower(uGenderLetter) == 'm'){
						puts("You are a Male.");
						strcpy(uGender, "Male");		
						genChoiceLoop = 0;								
				}else if(tolower(uGenderLetter) == 'f'){
						puts("You are a Female");
						strcpy(uGender, "Female");		
						genChoiceLoop = 0;		
				}	else if(tolower(uGenderLetter) == 'o'){
						puts("You are an Other");
						strcpy(uGender, "Other");		
						genChoiceLoop = 0;		
				}	else{
						puts("Wrong selection");
				}	
}//Gender while

//Age Entry
int ageLoop = 0;
int uAge = 1;
int numberRead = 0;
  do {
    puts("What is your Age?(Numbers only and Age must be between 1 to 125)");
    numberRead = scanf("%d", &uAge);
    if(numberRead != 1 || uAge > 125){
        puts("That is not a correct Age. Please enter an age.\n");
        getchar();
        ageLoop = 1;//Error occured
    }else{
    printf("You entered: %d\n", uAge);
    getchar();
    ageLoop = 0;
    }
  }while (ageLoop != 0);
//Class Selection			
int classChoiceLoop = 1;
while(classChoiceLoop == 1){	
		puts("What is your Admin Status? ('A'Admin, 'U'User, 'O'Other?)");
		uClassLetter = getchar();
		int uClassch; while (((uClassch = getchar()) != EOF) && (uClassch != '\n')) /* void */;
		if(tolower(uClassLetter) == 'a'){
		    puts("Your Admin Status is: Admin");
				strcpy(uClass, "Admin");    				
				classChoiceLoop = 0;				
		}else if(tolower(uClassLetter) == 'u'){
						puts("Your Admin Status is: User");
						strcpy(uClass, "User");		
						classChoiceLoop = 0;							
				}else if(tolower(uClassLetter) == 'o'){
						puts("Your Admin Status is: Other");
						strcpy(uClass, "Other");		
						classChoiceLoop = 0;								
				}else{
						puts("Wrong selection -- Try again. . .");
				}//else if
}	//Class while
//User information review. Approve or redo profile prompt.
				int confirmLooper = 1;
				while(confirmLooper == 1){
						system("clear");
					 printf("Your Name is: %s \n", uName);
					 printf("Your Gender is: '%s' \n", uGender);						
           printf("Your Age is: '%d' \n", uAge);
					 printf("Your Admin Status is: '%s' \n", uClass);    
				   puts("Do you wish to proceed or would you like to redo your profile?");
				   puts("Press 'y' to continue, or 'n' to redo your profile.\n");
			  char uContinue = getchar();
				int chSecond; while (((chSecond = getchar()) != EOF) && (chSecond != '\n')) /* void */;		
				if(tolower(uContinue) == 'y'){
						puts("You have decided to Continue.\n");
						sleep(1);
						confirmLooper = 0;		
						looper = 1;
				}else if(tolower(uContinue == 'n')){	
						puts("Resetting your Profile. . . \n");
						sleep(1);
						confirmLooper = 0;					
						looper = 0;								
				}else{				
						puts("Invlid Entry - - Try again.");
						system("clear");		
						sleep(1);		
				}//else if
			}//confirmLooper while	 												
}	//Main while		
		return 0;
}		

