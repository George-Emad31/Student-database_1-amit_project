//***************************************************************
//                   HEADER FILE USED IN PROJECT
//***************************************************************
#include<conio.h>
#include<stdio.h>
#include<process.h>
//***************************************************************
//                   STURUCTURE USED IN PROJECT
//****************************************************************
struct SimpleDb
{
 int Id,Course_Id_1,Course_Id_2,Course_Id_3,i;
 char name[50];
 int A_marks,B_marks,C_marks,Student_Year;
 float per;
 char grade;
 int std;
}st;
//***************************************************************
//        global declaration
//****************************************************************
 FILE *fptr;
 //***************************************************************
//        function to write in file
//****************************************************************
void write_student()
   {
    fptr=fopen("SimpleDb.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The Id number of student ");
    scanf("%d",&st.Id);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(st.name);
    printf("\n\nEnter The student Year ");
    scanf("%d",&st.Student_Year);
    printf("\nEnter Course_1 Id :",st.Course_Id_1);
    scanf("%d",&st.Course_Id_1);
    printf("\nEnter The marks in Course_1 out of 100 :",st.A_marks);
    scanf("%d",&st.A_marks);
    printf("\nEnter Course_2 Id :",st.Course_Id_2);
    scanf("%d",&st.Course_Id_2);
    printf("\nEnter The marks in Course_2 out of 100 :",st.B_marks);
    scanf("%d",&st.B_marks);
    printf("\nEnter Course_3 Id :",st.Course_Id_3);
    scanf("%d",&st.Course_Id_3);
    printf("\nEnter The marks in Course_3 of 100 :",st.C_marks);
    scanf("%d",&st.C_marks);
    st.per=(st.A_marks+st.B_marks+st.C_marks)/3.0;
    if(st.per>=85)
       st.grade='A';
    else if(st.per>=75 &&st.per<60)
      st.grade='B';
    else if(st.per>=60 &&st.per<50)
      st.grade='C';
    else
     st.grade='F';
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    printf("\n\Press Enter To Continue.......");
    getch();
}

//***************************************************************
//        function to read all records from file
//****************************************************************


void SBD_GetIdList()
{
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("SimpleDb.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\nId Number of Student : %d",st.Id);
      printf("\nName of student : %s",st.name);
      printf("\nStudent Year : %d",st.Student_Year);
      printf("\nMarks in Course_1 (ID=%d): %d",st.Course_Id_1,st.A_marks);
      printf("\nMarks in Course_2 (ID=%d): %d",st.Course_Id_2,st.B_marks);
      printf("\nMarks in Course_3 (ID=%d): %d",st.Course_Id_3,st.C_marks);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nGrade of student is : %c",st.grade);
      printf("\n\n====================================\n");
       printf("\n\nPress enter Please \n");
      getch();
    }
    fclose(fptr);
    getch();
}

//***************************************************************
//        function to read specific record from file
//****************************************************************

void display_sp(int n)
{
    int flag=0;
    fptr=fopen("SimpleDb.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.Id==n)
        {
            printf("\nId number of student : %d",st.Id);
      printf("\nName of student : %s",st.name);
      printf("\nStudent Year: %d",st.Student_Year);
      printf("\nMarks in Course_1 (ID=%d) : %d",st.Course_Id_1,st.A_marks);
      printf("\nMarks in Course_2 (ID=%d) : %d",st.Course_Id_2,st.B_marks);
      printf("\nMarks in Course_3 (ID=%d) : %d",st.Course_Id_3,st.C_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
 printf("\n\Press Enter To Continue.........");
    getch();
}

//***************************************************************
//        function to modify record of file
//****************************************************************


void SBD_ReadEntry()
{
    int no,found=0;
// modify data (ID , name , grade only )
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The Id number of student");
    scanf("%d",&no);

    // Read from .Dat file if student id is found or not

    fptr=fopen("SimpleDb.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.Id==no)
           {
            printf("\nId Number of student : %d",st.Id);
            printf("\nName of student : %s",st.name);
            printf("\nStudent Year: %d",st.Student_Year);
               printf("\nMarks in Course_1 : %d",st.A_marks);
      printf("\nMarks in Course_2 : %d",st.B_marks);
      printf("\nMarks in Course_3 : %d",st.C_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The Id number of student ");
            scanf("%d",&st.Id);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(st.name);
            printf("\n\nEnter The Student Year");
            scanf("%d",&st.Student_Year);
            printf("\nEnter The marks in COURSE_1 out of 100 : ");
            scanf("%d",&st.A_marks);
            printf("\nEnter The marks in COURSE_2 out of 100 : ");
            scanf("%d",&st.B_marks);
            printf("\nEnter The marks in COURSE_3 out of 100 : ");
            scanf("%d",&st.C_marks);
            st.per=(st.A_marks+st.B_marks+st.C_marks)/3.0;
            if(st.per>=85)
               st.grade='A';
            else if(st.per>=75 && st.per<85)
               st.grade='B';
            else if(st.per>=60 && st.per<75)
               st.grade='C';
            else
               st.grade='F';
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            printf("\n\Press Enter To Continue");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    printf("\n\Press Enter To Continue");
    getch();
}
//***************************************************************
//        function to delete record of file
//****************************************************************


void SBD_DeleteEntry()
   {
    int no;
    FILE *fptr2;
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The Id Number of student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("SimpleDb.dat","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.Id!=no)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("SimpleDb.dat");
    rename("Temp.dat","SimpleDb.dat");
    printf("\n\n\tRecord Deleted ..");
    printf("\n\Press Enter To Continue......");
    getch();
}

//***************************************************************
//        function to display all students grade report
//****************************************************************

    void class_result()
    {
     fptr=fopen("SimpleDb.dat","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\t\t\t==============ALL STUDENTS RESULT================== \n\n");
      printf("=======================================================================================================================\n");
      printf(" Id\tName\t  Student Year\t\t1\t2\t3\tpercent\t\tGrade\n");
      printf("=======================================================================================================================\n");

      while((fread(&st,sizeof(st),1,fptr))>0)
     {
         //
       printf("%d\t%3s\t\t%d\t\t%3d\t%3d\t%3d\t%3.2f\t\t%1c\n",st.Id,st.name,st.Student_Year,st.A_marks,st.B_marks,st.C_marks,st.per,st.grade);

     }
     fclose(fptr);
      printf("\n\tPress Enter To Continue......");
     getch();
}

//***************************************************************
//        function to display result menu
//****************************************************************


   void result()
   {
    int ans,rno;
    char ch;
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2)? or 3 to return");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result();break;
     case 2 : {
        do{
        char ans;
        printf("\n\nEnter Id Number Of Student : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }

//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************

void intro()
{


 printf(" \n\n\n\n\n\t\t\t\t\t    *   *   *   *   *   *   *   *");
		printf("\n\n\t\t\t\t\t    *    MADE BY George Emad    *");
		printf("\n\n\t\t\t\t\t    *          Welcome          *");
		printf("\n\n\t\t\t\t\t    *       Amit learning       *");
		printf("\n\n\t\t\t\t\t    *   *   *   *   *   *   *   *\n\n\n");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue ");

		for(int i=0; i<7; i++)
        {
             printf(".");
				 Sleep(100);
        }




 getch();
}

//***************************************************************
//        ENTRY / EDIT MENU FUNCTION
//****************************************************************
void SBD_AddEntry()
{
    char ch2;

  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD By (ID) ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1':
          write_student();
          break;
    case '2': SBD_GetIdList();break;
    case '3':  {
           int num;

           printf("\n\n\tPlease Enter The Student number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '4': SBD_ReadEntry();break;
      case '5': SBD_DeleteEntry();break;
      case '6': break;
    default:printf("\a");SBD_AddEntry();
   }
}


//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
  char ch;
  intro();
  do
    {

      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01-> RESULT MENU");
      printf("\n\n\t02-> ENTRY/EDIT MENU");
      printf("\n\n\t03-> EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1':
               result();
               break;
         case '2': SBD_AddEntry();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
}
//***************************************************************
//                END OF PROJECT
//***************************************************************
