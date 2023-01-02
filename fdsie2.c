// Online C compiler to run C program online
#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct hospital{
    int sr,age,Mo_no[10];
    char name[30],disease[30];
    struct hospital*next;
};
int count=0;
struct hospital*head=NULL;
struct hospital*insert(struct hospital*head){
     struct hospital*ter,*new;
    new=(struct hospital*)malloc(sizeof(struct hospital));
    ter=head;
    ter=(struct hospital*)malloc(sizeof(struct hospital));

    /*
    scanf("%d%d%d %s %s",&new->sr,&new->age,&new->Mo_no,new->name,new->disease);*/
    scanf("%d",&new->sr);
    scanf("%d",&new->age);
    for(int i=0;i<10;i++){scanf("%d",&new->Mo_no[i]);}
    scanf(" %s",new->name);
    scanf(" %s",new->disease);
    if(count==0)
    {
        new->next=NULL;
        new=head;
    }
    else if(count==1){
        head->next=new;
        new->next=NULL;
    }
    else{
        while(ter->next!=NULL){
            ter=ter->next;
        }
        ter->next=new;
        new->next=NULL;
    }
    count++;
    return head;
    
}
struct hospital*Delete(struct hospital*head){
    int data,rlog;
    struct hospital*temp,*r,*rt;
    temp=(struct hospital*)malloc(sizeof(struct hospital));
    r=(struct hospital*)malloc(sizeof(struct hospital));
    rt=(struct hospital*)malloc(sizeof(struct hospital));
    printf("Enter the serial no. of patient that has to be deleted from record\n");
    scanf("%d",&data);
    temp=head;
    if(data!=1){
        for(int x=0;x<data;x++){
            r=temp;
            temp=temp->next;
        }
    }
    if(temp->next!=NULL&&data!=1){
        r->next=temp->next;
        rlog=temp->sr;
        rt=temp;
        for(int x=rlog;x<count;x++){
            rt=rt->next;
            rt->sr--;
        }
        free(temp);
    }
    else if(data==1){
        head=head->next;
        rt=temp;
        for(int x=1;x<count;x++){
            rt=rt->next;
            rt->sr--;
        }
        free(temp);
    }
    else if(temp->next==NULL){
        r->next=NULL;
        free(temp);
    }
}
void search(struct hospital* head)
{
    struct hospital*ten;
    ten=head;
    ten=(struct hospital*)malloc(sizeof(struct hospital));
   
    int a=0;
    printf("Enter the age of person\n");
    scanf("%d",&a);
    while(ten->next!=NULL){
        if(ten->age==a){
            printf("%d\n",ten->sr);
    printf("%d\n",ten->age);
    for(int i=0;i<10;i++){printf("%d",ten->Mo_no[i]);}
    printf(" \n %s \n",ten->name);
    printf(" %s \n",ten->disease);
        }
        ten=ten->next;
    }if(ten->age==a){
            printf("%d\n",ten->sr);
    printf("%d\n",ten->age);
    for(int i=0;i<10;i++){printf("%d",ten->Mo_no[i]);}
    printf(" \n %s \n",ten->name);
    printf(" %s \n",ten->disease);}
}
int main() {
    // Write C code here
    printf("Hello world\n");
    head=(struct hospital*)malloc(sizeof(struct hospital));
    head=insert(head);
    head=insert(head);
    head=insert(head);
    head=insert(head);
    head=Delete(head);
    search(head);
    return 0;
}
