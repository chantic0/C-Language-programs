#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAX 20

int checkStudentNum(char a[]);
int length(char a[]);
int checkUpperLetter(char a[]);
int checkDigit(char a[]);
int checkpwdLength(char a[]);
int checkSpecialchar(char a[]);
int string_compare(char a[], char b[]);
int replace(char s[], int i);
void reverse(char s[], char t[]);
void sort_string(char s[]);

int main(void){
	char studentNum[MAX];
	char studentPass[MAX];
	char string1[MAX];
	char string2[MAX];
	int replaceNum=0;
	char bonusString[MAX];
	printf("\n\nEnter the string for Student ID: ");
	scanf("%s", studentNum);
	while(checkStudentNum(studentNum)==0){
		printf("\n\nInvalid student number, ID should be 6-8 digits");
		printf("\n\nEnter the student ID again please: ");
		scanf("%s", studentNum);
	}
	printf("\n\nEnter the string for password: ");
	scanf("%s", studentPass);
	while(checkUpperLetter(studentPass)==0 || checkDigit(studentPass)==0 || checkpwdLength(studentPass)==0 || checkSpecialchar(studentPass)==0){
		if(checkUpperLetter(studentPass)==0){
			printf("\n\nThere should be at least one upper case character in the password");
		}
		else if(checkDigit(studentPass)==0){
			printf("\n\nThere should be at least one number in the password");
		}
		else if(checkpwdLength(studentPass)==0){
			printf("\n\nInvalid password, password should be 6-10 characters long");
		}
		else if(checkSpecialchar(studentPass)==0){
			printf("\n\nThere should be at least one special character in the password");
		}
		printf("\n\nEnter the password again: ");
		scanf("%s", studentPass);
	}
	printf("\n\nCongrats! Your account is created. Your credidentials are \n%s\n%s",studentNum, studentPass);
	printf("\n\nEnter string 1 for comparison: ");
	scanf("%s", string1);
	printf("\n\nEnter string 2 for comparison: ");
	scanf("%s", string2);
	if(string_compare(string1, string2)>0){
		printf("\n\n%s is Bigger than %s",string1, string2);
	}
	else if(string_compare(string1, string2)<0){
		printf("\n\n%s is Smaller than %s",string1, string2);
	}
	else if(string_compare(string1, string2)==0){
		printf("\n\n%s is Equal to %s",string1, string2);
	}
	printf("\n\nEnter a position for replacement: ");
	scanf("%d", &replaceNum);
	if(replaceNum<=0 || replaceNum>length(string1)){
		printf("\n\nUnable to replace invalid position in %s",string1);
	}
	else{
	replace(string1, replaceNum);
	printf("\n\nReplacement successful %s",string1);
	}
	printf("\n\n*** BONUS ***");
	reverse(string1, bonusString);
	printf("\n\nReverse of %s is %s",string1, bonusString);

}

int checkStudentNum(char a[]){
	int i=0;
	int result=0;
	int checker=0;
	for(i=0; i<MAX; i++){
		if(a[i]=='\0'){
			break;
		}
		if(isdigit(a[i])){
			result=1;
		}
		else checker++;
	}
	if(checker>0){
		result=0;
	}
	else result=1;
	int j=0;
	while(a[j]!='\0'){
		j++;
	}
	if(j>8||j<6){
		result=0;
	}
	return result;
}
int length(char a[]){
	int i=0;
	while(a[i]!='\0'){
		i++;
	}
	return i;
}
int checkUpperLetter(char a[]){
	int i=0;
	int counter=0;
	for(i=0; i<MAX; i++){
		if(a[i]=='\0'){
			break;
		}
		if(isupper(a[i])){
			counter++;
		}
	}
	if(counter==0){
		return 0;
	}
	else return 1;
}
int checkDigit(char a[]){
	int i=0;
	int counter=0;
	for(i=0; i<MAX; i++){
		if(a[i]=='\0'){
			break;
		}
		if(isdigit(a[i])){
			counter++;
		}
	}
	if(counter==0){
		return 0;
	}
	else return 1;
}
int checkpwdLength(char a[]){
	int i=0;
	for(i=0; i<MAX; i++){
		if(a[i]=='\0'){
			break;
		}
	}
	if(i<6||i>10){
		return 0;
	}
	else return 1;
}
int checkSpecialchar(char a[]){
	int i=0;
	int counter=0;
	int nothing=0;
	for(i=0; i<MAX; i++){
		if(a[i]=='\0'){
			break;
		}
		if(isalnum(a[i])){
			nothing++;
		}
		else counter++;
	}
	if(counter==0){
		return 0;
	}
	else return 1;
}
int string_compare(char a[], char b[]){
	int i=0;
	int value=0;
	int total=0;
	for(i=0; i<MAX; i++){
		if(a[i]=='\0' || b[i]=='\0'){
			break;
		}
		value=a[i]-b[i];
		total+=value;
	}
	return total;
}
int replace(char s[], int i){
	s[--i]='#';
}
void reverse(char s[], char t[]){
	int i=0;
	int j=0;
	while(s[i]!='\0'){
		i++;
	}
	for(j=0; j>i; j++){
		for(i=i; i>0; i--){
			t[j]=s[i];
		}
	}
}

