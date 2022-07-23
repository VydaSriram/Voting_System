#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
int totalcount=0,count1=0,count2=0,count3=0,count4=0,count5=0,vflag=0;
struct vote{
  int id;
  char name[30];
  char father[30];
  char mother[30];
  char area[40];
  struct vote* next;
};
struct vote* head;
void voterlist()
{
  vflag=1;
  int countv,i;
  head=(struct vote*)malloc(sizeof(struct vote));
  head=NULL;
  printf("Enter the number of voters\n");
  scanf("%d",&countv);
  printf("enter the voterlist of the  hyderabad constituency\n");
  for(i=0;i<countv;i++)
  {
    struct vote* temp=(struct vote*)malloc(sizeof(struct vote));
    printf("enter %d candidates details\n",i+1);
    scanf("%d",&temp->id);
    scanf("%s",temp->name);
    scanf("%s",temp->father);
    scanf("%s",temp->mother);
    scanf("%s",temp->area);
    temp->next=NULL;
    if(head==NULL)
    {
      head=temp;
    }
    else
    {
      struct vote* temp1=(struct vote*)malloc(sizeof(struct vote));
      temp1=head;
      while(temp1->next!=NULL)
      {
        temp1=temp1->next;
      }
       temp1->next=temp;
    }
      system("cls");
  }
}
void resultdisplay()
{
  printf("#--------------FINAL RESULT OF 2O2O ELECTIONS -------------#\n");

    printf("TRS = %d votes\n",count1);
    printf("CONGRESS =%d votes \n",count2);
    printf("BJP =%d votes \n",count3);
    printf("MIM =%d votes \n",count4);
    printf("NOTA =%d votes \n",count5);
}
void voterlistdisplay()
{
  if(vflag==0)
  {
    printf("voter list is empty first fill the voter list\n");
  }
  else
  {
    struct vote* temp5=(struct vote*)malloc(sizeof(struct vote));
    temp5=head;
    while(temp5)
    {
      printf("id: %d\t name: %s\t father: %s\t mother: %s\t area: %s\n",temp5->id,temp5->name,temp5->father,temp5->mother,temp5->area);
      temp5=temp5->next;
    }
  }
}
int votercheck(int a,char b[30],char c[30],char d[30])
{
  int i=1;
  if(vflag==0)
  printf("first enter the voter list");
  else
  {
  struct vote* temp7=(struct vote*)malloc(sizeof(struct vote));
  temp7=head;
  while(temp7)
  {

    if(temp7->id==a && strcmp(temp7->name,b)==0 && strcmp(temp7->father,c)==0 && strcmp(temp7->mother,d)==0)
    {
     votecasted(i);
      return 1;
    }
    temp7=temp7->next;
    i++;
  }

  return 0;
}
}
void votecasted(int p)
{
  int j=0;
  struct vote* temp9=(struct vote*)malloc(sizeof(struct vote));
  struct vote* temp8=(struct vote*)malloc(sizeof(struct vote));
  temp9=head;

  if(p==1)
  {
    head=temp9->next;
    temp9->next=NULL;
    free(temp9);
  }
  else
  {
    for(j=0;j<p-2;j++)
    {
      temp9=temp9->next;
    }
    temp8=temp9->next;
    temp9->next=temp8->next;
    temp8->next=NULL;
    free(temp8);
  }
}
int main()
{
  int p,c,e=0,vid,z,v;
  int id[20];
  char code[10],r[6],fname[30],mname[30],name[30],area[30];
  char designation[20];
  do{
  printf("Hello Welcome to Polling Booth\n");
  Sleep(10);
  printf("Please Enter Your Designation\n");
  scanf("%s",designation);
  if(!strcmp(designation,"admin"))
  {
    do{
      p=0;
    printf("Enter Your Unique code \n");
    scanf("%s",code);
    if(!strcmp(code,"504208"))
    {

      printf("Enter Your Choice Of Operation\n 1:entering the voter list\n 2:Total no of votes casted\n 3:votes secured by each candidate\n 4:voterlist to display\n ");
      scanf("%d",&c);
      switch (c) {
        case 1:
          system("cls");
          voterlist();
          break;
        case 2:
          printf(" Total no of votes casted in the election is %d \n",totalcount);
          break;
        case 3:
          system("cls");
          resultdisplay();
          break;
        case 4:
          system("cls");
          voterlistdisplay();
          break;
        default:
          printf("wrong option choosed\n");
          exit(0);
        }
      }
    else
    {
      printf("Sorry your Unique code is incorrect \n");
      printf("do you want to retry \n");
      scanf("%s",r);
      if(strcmp(r,"no")==0)
      {
        printf("Thank you\n");
        exit(0);
      }
      p=!strcmp(r,"yes");
      system("cls");
    }

  }while(p);
}
else if(strcmp(designation,"voter")==0)
{
  system("cls");
  printf("--------------CAST YOUR VOTE HERE----------------\n");
  printf("->enter your voter id details\n");
  printf("1,voter identity number \n");
  scanf("%d",&vid);
  printf("2,name of the voter \n");
  scanf("%s",name);
  printf("3,father name of the voter \n");
  scanf("%s",fname);
  printf("4,mother name of the voter \n");
  scanf("%s",mname);
  z=votercheck(vid,name,fname,mname);
  if(z==0)
  {
    printf("Sorry your id number does't match with your details \n");
  }
  else
  {
    system("cls");
    printf("THE FOLLOWING ARE THE CONTESTANTS IN THE GHMC ELECTIONS\n");
    printf("PARTYCODE : 1 \t PARTYNAME : TRS \t CANDIDATE :KTR\n");
    printf("PARTYCODE : 2 \t PARTYNAME : CONGRESS \t CANDIDATE :REVANTH\n");
    printf("PARTYCODE : 3 \t PARTYNAME : BJP \t CANDIDATE :SANJAY\n");
    printf("PARTYCODE : 4 \t PARTYNAME : MIM \t CANDIDATE :AKBARUDDIN\n");
    printf("CODE :5 \t -----NOTA----\n");
    printf("SELECT YOUR OPTION\n");
    scanf("%d",&v);
    if(v==1)
    count1++;
    else if(v==2)
    count2++;
    else if(v==3)
    count3++;
    else if(v==4)
    count4++;
    else
    count5++;
    totalcount++;
  }
}
else{
  printf("you have choosen wrong designation\n");
  printf("only admin and voter are possible \n");
  exit(0);
}
//only admin can have chance to continue
printf("do you want to contine\n");

scanf("%d",&e);
system("cls");
}while(e);
return 0;
}
