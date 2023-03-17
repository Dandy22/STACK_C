#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
	char NIM[50];
	int GPA;
	struct Node *next;
}*head = NULL, *tail = NULL, *curr = NULL;

struct Node *newNode(char NIM[], int GPA){
	struct Node* tnode = (struct Node *) malloc (sizeof(struct Node));
	strcpy(tnode->NIM, NIM);
	tnode->GPA = GPA;
	tnode->next = NULL;
	return tnode;
}

void pushTail(char NIM[], int GPA){
	struct Node* tnode=newNode(NIM, GPA);
	if(head==NULL){
		head=tail=tnode;
	}
	else{
		tail->next = tnode;
		tail = tnode;
	}
}

void popHead(){
	if(head==NULL){
		printf("UNDERFLOW!\n");
	}
	if(head==tail){
		free(head);
		head=tail=NULL;
	}else{
		curr = head;
		head = curr->next;
		free(curr);
	}
}

void view(){
	curr = head;
	if(curr == NULL){
		printf("OVERFLOW!\n");
	}
	while(curr!=NULL){
		printf("%s - %d\n", curr->NIM, curr->GPA);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	
	printf("ADDING SOME QUEUE\n");	
	pushTail("Soko", 20);view();
	pushTail("Ryan", 30);view();
	pushTail("Jojo", 21);view();
	printf("AFTER DELETING SOME QUEUE\n");
	popHead();view();
	return 0;
}
