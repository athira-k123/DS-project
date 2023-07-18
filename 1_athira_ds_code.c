#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct residence
{
    int resid_id;
    char name[100];
    char house_name[100];
    char contact_no[100];
    int no_of_people;
    struct residence *next;
    
}* head;
void insert(int resid_id, char* name,char* house_name, char* contact_no, int no_of_people)
{
    
    struct residence * residence = (struct residence *) malloc(sizeof(struct residence));
    residence->resid_id = resid_id;
    strcpy(residence->name, name);
    strcpy(residence->house_name,house_name);
    strcpy(residence->contact_no, contact_no);
    residence->no_of_people = no_of_people;
    residence->next = NULL;
    
    if(head==NULL){
        head = residence;
    }
    else{
    	struct residence *t;
    	t=head;
    	while(t->next!=NULL)
    	{
    		t=t->next;
		}
		t->next=residence;
    }
    
}
void search(int resid_id)
{
    struct residence * temp = head;
    while(temp!=NULL){
        if(temp->resid_id==resid_id){
            printf("Residence id: %d\n", temp->resid_id);
            printf("Name: %s\n", temp->name);
            printf("House name: %s\n", temp->house_name);
            printf("contact number: %s\n", temp->contact_no);
            printf("no_of_people: %d\n", temp->no_of_people);
            return;
        }
        temp = temp->next;
    }
    printf("Residence with Residence ID %d is not found \n", resid_id);
}
void update(int resid_id)
{
    
    struct residence * temp = head;
    while(temp!=NULL){
        
        if(temp->resid_id==resid_id){
            printf("Residence with Residence ID %d Found \n", resid_id);
            printf("Enter new name:\n ");
            scanf("%s", temp->name);
            printf("Enter new House name :\n ");
            scanf("%s",temp->house_name);
            printf("Enter new contact number:\n ");
            scanf("%s", temp->contact_no);
            printf("Enter number of people:\n ");
            scanf("%d",&temp->no_of_people);
            printf("Updation Successful\n");
            return;
        }
        temp = temp->next;
        
    }
    printf("residence with resid_id %d is not found \n", resid_id);
    
}
void Delete(int resid_id)
{ 
    struct residence *t = head;
    
    if(head == NULL){
    	printf("List is Empty\n");
	}else if(head->resid_id == resid_id){
		head = head->next;
		printf("Deletion Successful\n");
	}else{
		while(t->next != NULL && t->next->resid_id != resid_id){
			t = t->next;
		}
		if(t->next == NULL){
			printf("Element Not Found\n");
		}else{
			t->next = t->next->next;
			printf("Deletion Successful\n");
		}
	}
}
void display()
{
    struct residence * temp = head;
    if(temp==NULL)
    {
    	printf("residence record is empty");
	}
    while(temp!=NULL){
        
        printf("Residence ID: %d\n", temp->resid_id);
        printf("Name: %s\n", temp->name);
        printf("House name: %s\n",temp->house_name);
        printf("Contact number: %s\n", temp->contact_no);
        printf("no_of_people: %d\n", temp->no_of_people);
        printf("-----------------------\n");
        temp = temp->next;
        
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char house_name[100];
    char contact_no[100];
    int resid_id;
    int no_of_people;
    printf("1 to insert residence details\n2 to search for residence details\n3 to delete residence details\n4 to update residence details\n5 to display all residence details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Residence ID:\n ");
                scanf("%d", &resid_id);
                printf("Enter name: \n");
                scanf("%s", name);
                printf("Enter House name: \n");
                scanf("%s", house_name);
                printf("Enter contact number: \n");
                scanf("%s", contact_no);
                printf("Enter number of people: \n");
                scanf("%d", &no_of_people);
                insert(resid_id, name, house_name, contact_no , no_of_people);
                break;
            case 2:
                printf("Enter Residence ID to search:\n ");
                scanf("%d", &resid_id);
                search(resid_id);
                break;
            case 3:
                printf("Enter Residence ID to delete:\n ");
                scanf("%d", &resid_id);
                Delete(resid_id);
                break;
            case 4:
                printf("Enter Residence ID to update:\n ");
                scanf("%d", &resid_id);
                update(resid_id);
                break;
            case 5:
                display();
                break;
        }
        
    } while (choice != 0);
}


