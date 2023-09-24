#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct question
{
	char text [100];
	char answers[3][50]; 
	int correct_answer; 
};

struct test
{
	int true_count;
	int wrong_count;
};
void input(struct question *qu);
void output(struct question *qu);
void calculate_result(struct test *te);

int main()
{
	struct question questions[10];
	int i, m;
	do
	{
		printf("Count of questions:\n");
		scanf("%d", &m);
	}while(m<1||m>10);
	for(i=0;i<m;i++)
	{
		input(&questions[i]);
	}
	printf("\n==================ENTERED QUESTIONS========================\n");
	for(i=0;i<m;i++)
	{
		printf("Question no. : %d\n", i);
		output(&questions[i]);
	}
    printf("\n===========================================================\n");
	int choice;
	while(1){
	printf("\n\n\n---MENU---\n");
	printf("Would you like to perform another operation? Pick a number from 1-4.\n");
	printf("1. Take a test.\n");
	printf("2. Show all questions.\n");
	printf("3. Edit question.\n");
	printf("0. NO\n");
	scanf("%d", &choice);
	if (choice==0){
		break;
	}
	switch(choice){
		case 1:{
			printf("\n===================TAKING A TEST=================================\n");
			int answer;
			struct test my_test;
			for(i=0;i<m;i++){
				printf("Question no. : %d", i+1);
				output(&questions[i]);
				printf("\n Pick answer's number:");
				scanf("%d", &answer);
				if (questions[i].correct_answer == answer){
					my_test.true_count += 1;
				}else{
					my_test.wrong_count += 1;
				}
			}
			calculate_result(&my_test);
			break;
		}
		case 2:{	
			printf("\n======================ENTERED QUESTIONS==============================\n");
			for(i=0;i<m;i++){
				printf("\nQuestion no. : %d", i+1);
				output(&questions[i]);
			}
			break;
		}
		case 3:{
			printf("\n=================EDITING QUESTION==========================\n");
			int i;
			printf("Enter the number of the question you'd like to edit:");
			scanf("%d", &i);
			input(&questions[i]);
			break;
		}
		default: break;
			
		}
	}
}
void input(struct question *qu)
{
	int i;
	printf("Question:\n");
	fflush(stdin);
	gets(qu->text);
	for(i=0;i<3;i++){
		printf("answer %d: ", i+1);
		fflush(stdin);
		gets(qu->answers[i]);
	}
	printf("Number of the correct answer:\n");;
	scanf("%d", &qu->correct_answer);
}

void calculate_result(struct test *te){
	
	int points;
	points = te->true_count*5;
	points -= te->wrong_count*1;
	printf("\n================RESULT========================\n");
	if (points >= 10){
		printf("Congrats! The test was successful\n");
	}else{
		printf("The test was unsuccessful! Your points were bellow the minimun of 10 points. Try again.\n");
	}
	printf("\n You got %d points.\n", points);
	printf("\n===========================================================\n");
}

void output(struct question *qu)
{
	int i;
	printf("\n%s", qu->text);
	printf("\n\nAnswers:");
	for(i=0;i<3;i++)
	{
		printf("\nAnswers %d: %s", i+1, qu->answers + i);
	}
}
