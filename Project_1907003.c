//chariot
//1907003
//admin name:AAS
//admin password:1202
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

 struct admin
{
    char id[50],pass[50];
};
//declaring admin structure containing admin id & password
 struct student
{
    char id[50];
    char pass[50];
    char sname[50];
    char cname[50];
    char number[50];
};
//declaring student structure containing id, password, student name, course name, obtained course mark
struct teacher
{
    char id[50];
    char pass[50];
    char tname[50];
    char cname[50];

};
//declaring teacher structure containing teacher id ,password, teacher's name, teacher's course name

//function prototype declaring
//fflush(stdin) flushing out input buffer
void add_teacher();
void admin_work();
int admin_verification();
int teacher_verification();
void teacher_work();
int stud_verification();
void stud_work();
void display_stud();
void update_stud();
void add_stud();
void display_teacher();
void assign_courses();
void update_tinformation();
void search_stud_name();
void total_stud();
void provide_marks();

int admin_verification()
{
    struct admin a1,a2;
    int s1=sizeof(a1);
    //declaring structure and determining its size
    printf("\n<<<*** WELCOME TO ADMIN VERIFICATION CHECK ***>>>\n\n");
    printf("> PLEASE ENTER YOUR USER ID & PASSWORD \n\n");
    //asking for id & password
    printf("> USER ID: ");
    scanf("%s", &a1.id);
    fflush(stdin);//flushing out input buffer
    printf("\n");
    printf("> PASSWORD: ");
    scanf("%s", &a1.pass);
    fflush(stdin);//flushing out input buffer
    printf("\n");
    FILE *f1;
    f1=fopen("Admin.txt","rb+");//checking the file previously created or not
    if(f1==NULL)
    {
        f1=fopen("Admin.txt","wb+");//if not, then creating a txt file in binary encoded format.
        if(f1==NULL)
        {
            printf(">> CANNOT OPEN ADMIN FILE\n");//when program cannot find the target file
            fclose(f1);
            exit(1);
        }
        else
        {
            fwrite(&a1,s1,1,f1);//writing new admin id and password into file
        }
    }
    int token=0;
    while(fread(&a2,s1,1,f1))//if admin information are previously written then checking given information
    {
        if(!strcmp(a1.id,a2.id) && !strcmp(a1.pass,a2.pass))token=1;
        //strcmp("ABC","agc");
    }
    fclose(f1);
    return token;//returning the value of token

}

void admin_work()
{
    if(!admin_verification())//checking the value of token
    {
        printf(">> SORRY ! YOU HAVE ENTERED WRONG ID OR PASSWORD \n");
        printf(">> INTRUSION DETECTED! EXITING THE PROGRAM......");
        //error message
        exit(2);
    }
    system("cls");//clearing console screen
    printf("\n>=> YOU ARE ADMIN NOW <=<\n\n");
    printf("> WELCOME ADMIN!\n\n");

    printf(">=> TEACHER OPERTATION MENU <=<\n\n");
    // offering operation menu
    printf("> Press 1 to ADD NEW TEACHER\n");
    printf("> Press 2 to DISPLAY TEACHERS\n");
    printf("> Press 3 to ASSIGN COURSES\n");
    printf("> Press 4 to UPDATE TEACHER'S INFORMATION\n\n");

    printf(">=> STUDENT OPERATION MENU <=<\n\n");
    printf("> Press 5 to ADD NEW STUDENT\n");
    printf("> Press 6 to DISPLAY STUDENTS\n");
    printf("> Press 7 to UPDATE STUDENT'S INFORMATION\n");
    printf("> Press 0 to EXIT\n\n");

    printf("> ENTER YOUR CHOICE ....(1/2/3/4/5/6/7/0)..: ");//asking for choice
    int q;
    scanf("%d",&q);
    if(q==1)
    {
        add_teacher();
        //going to add teacher menu
    }
    else if(q==2)
    {
        display_teacher();
        //going to display teacher menu
    }
    else if(q==3)
    {
        assign_courses();
        //going to assign courses menu
    }
    else if(q==4)
    {
        update_tinformation();
        //going to update teacher information menu
    }
    else if(q==5)
    {
        add_stud();
        //going to add student menu
    }
    else if(q==6)
    {
        display_stud();
        //going to display stude menu
    }
    else if(q==7)
    {
        update_stud();
        //going to update stud menu
    }
    else
    {
        return;//returning from where it has been called.
    }

}

int teacher_verification()
{
    struct teacher t1,t2;
    int s1=sizeof(t1);
    //declaring structure and determining its size
    printf("\n>=> WELCOME TO TEACHER VERIFICATION CHECK <=< \n");
    fflush(stdin);
    //asking for user id & password to check valid teacher or not
    printf("\n> USER ID: ");
    scanf("%s", &t1.id);
    printf("\n");
    fflush(stdin);
    printf("> PASSWORD: ");
    scanf("%s", &t1.pass);
    printf("\n");
    fflush(stdin);
    FILE *f2;
    char *name="Teacher.txt";//taking file name into a character pointer
    f2=fopen(name,"r");//file opened reading mode
    if(f2==NULL)
    {
        printf("CANNOT OPEN TEACHER FILE\n");
        fclose(f2);
        //exiting message
        exit(5);
    }
    int token=0;
    while(fread(&t2,s1,1,f2))//checking given information are matched with real one or not
    {
        if(!strcmp(t1.id,t2.id) && !strcmp(t1.pass,t2.pass))token=1;
    }
    fclose(f2);
    return token;//returning the value of token

}
void teacher_work()
{
    if(!teacher_verification())//checking real teacher logged in or not.
    {
        printf("\n>> SORRY! WRONG USER ID OR PASSWORD!.\n\n");
        printf(">> INTRUSION DETECTED! EXITING THE PROGRAM......\n");
        //exiting message
        exit(1);
    }
    system("cls");
    printf("\n>=> YOU ARE A VERIFIED TEACHER NOW <=<\n\n");
    printf("> WELCOME SIR\n\n");

    printf("\n>=> TEACHER MENU OPTION <=<\n\n");
    printf("> Press 1 To SEARCH A STUDENT\n");
    printf("> Press 2 To DISPLAY TOTAL STUDENT\n");
    printf("> Press 3 To PROVIDE CLASS TEST MARK\n");
    printf("> Press 0 to EXIT\n");

    printf("\n> Enter Your Choice...(1/2/3/0)..: ");//asking for choice

    int q;
    scanf("%d", &q);
    if(q==1)
    {
        search_stud_name();//going to search student option
    }
    else if(q==2)
    {
        total_stud();//going to total student option
    }
    else if(q==3)
    {
        provide_marks();//going to provide marks option
    }
    else
    {
        return;
    }

}
int stud_verification()
{
    struct student s3,s2;
    int s1=sizeof(s2);
    //declaring structure and determining its size
    printf("\n>=> WELCOME TO STUDENT VERIFICATION CHECK <=< \n\n");
    //asking for user id, password and name to be matched
    printf("> USER ID:");
    fflush(stdin);
    scanf("%s", &s2.id);
    printf("\n");
    printf("> PASSWORD:");
    fflush(stdin);
    scanf("%s", &s2.pass);
    printf("\n");
    printf("> NAME:");
    fflush(stdin);
    scanf("%s", &s2.sname);
    printf("\n");
    fflush(stdin);

    FILE *f3;
    char *name="Student.txt";
    f3=fopen(name,"r");
    if(f3==NULL)
    {
        printf("\n>> CANNOT OPEN STUDENT FILE\n");
        fclose(f3);
        //showing error message
        exit(6);
    }
    int token=0;
    while(fread(&s3,s1,1,f3))
    {
        if(!strcmp(s2.id,s3.id) && !strcmp(s2.pass,s3.pass) && !strcmp(s2.sname,s3.sname))token=1;
    }
    fclose(f3);
    return token;

}
void stud_work()
{
    if(!stud_verification())//checking given information with real information
    {
        printf("\n>> SORRY! WRONG USER ID OR PASSWORD!.\n");
        printf(">> INTRUSION DETECTED!....EXITING THE PROGRAM..\n");
        //showing error message;
        exit(2);
    }
    system("cls");
    struct student s2,s3;
    int s1=sizeof(s2);
    //declaring structure and determining its size
    printf(">>> YOU ARE A VERIFIED STUDENT NOW <<<\n\n");
    printf("> WELCOME!\n\n");
    printf("> Press 1 to DISPLAY YOUR CLASS TEST MARKS\n");
    printf("> Press 0 to EXIT\n");

    printf("\n> Enter Your Choice...(1/0)..: ");//asking for choice

    int x;
    scanf("%d", &x);
    if(x==1)
    {
        //asking for password and course name to be matched
        printf("\n> PASSWORD: ");
        fflush(stdin);
        scanf("%s", &s2.pass);
        printf("\n");
        printf("> COURSE NAME: ");
        fflush(stdin);
        scanf("%s", &s2.cname);
        printf("\n");
        fflush(stdin);

        FILE *f4;
        f4=fopen("Student.txt","r");
        int token=0;

        while(fread(&s3,s1,1,f4))
        {
            if(!strcmp(s2.pass,s3.pass) && !strcmp(s2.cname,s3.cname))
            {
                printf("\n>> RECORD FOUND!\n\n");//found message
                printf("> OBTAINED MARKS: %s\n\n",s3.number);//showing marks
                token=1;
            }
        }
        if(token==0)
        {
            printf(">> WRONG INFORMATION GIVEN!\n");//error message
        }
         fclose(f4);
         printf("\n> PRESS ANY KEY TO CONTINUE: ");
         getch();
         return;
    }
    else
    {
        return;
    }
}
void add_stud()
{
    FILE *fs;
    char *name="Student.txt";//file name taking in a character pointer
    fs=fopen(name,"a+");//file opened in append mode
    if(fs==NULL)
    {
        printf("\n>> CANNOT OPEN FILE\n");
        //failure message
        exit(3);
    }
    struct student s2,s3;
    int s1=sizeof(s2);
    //declaring structure and determining its size
    system("cls");
    printf("\n >=> WELCOME TO ADD STUDENT OPTION <=<\n\n");
    char another='Y';
    while(another=='Y')
    {

    printf("\n> ENTER STUDENT ID: ");
    fflush(stdin);//flashing out input buffer
    scanf("%s", &s2.id);
    printf("\n");
    printf("> ENTER STUDENT PASSWORD: ");
    fflush(stdin);//flashing out input buffer
    scanf("%s", &s2.pass);
    printf("\n");
    printf("> ENTER STUDENT NAME: ");
    scanf("%s", &s2.sname);
    fflush(stdin);//flashing out input buffer
    printf("\n");
    printf("> ENTER STUDENT COURSE: ");
    fflush(stdin);//flashing out input buffer
    scanf("%s", &s2.cname);
    fflush(stdin);//flashing out input buffer
    printf("\n");
    fwrite(&s2,s1,1,fs);//information written in student file.

    printf(">>> INFORMATION UPDATE SUCCESSFUL!<<<\n\n");//confirmation message
    printf("> Press Y to ADD ANOTHER STUDENT\n");
    printf("> Press N to EXIT \n");
    printf("\n> Enter YOUR CHOICE...(Y/N)...: ");
    //asking for repeat operation or exit
    scanf("%c", &another);
    printf("\n");
    fflush(stdin);

    }
     fclose(fs);
    return;
}

void display_stud()
{
    struct student s2,s3;
    int s1=sizeof(s2);
    //declaring structure and determining its size
    FILE *fdd;
    fdd=fopen("Student.txt","r");//file opened in reading mode
    int cnt=0;
    while(fread(&s2,s1,1,fdd))
    {
        printf("%d\n",++cnt);
        printf("> STUDENT ID              : %s\n",s2.id);
        printf("> STUDENT NAME            : %s\n",s2.sname);
        printf("> STUDENT PASSWORD        : %s\n",s2.pass);
        printf("> STUDENT COURSE NAME     : %s\n",s2.cname);
        printf("> STUDENT'S OBTAINED MARKS: %s\n",s2.number);
        printf("\n");
        //displaying student information
    }
    fclose(fdd);
    printf("\n> PRESS ANY KEY TO CONTINUE: ");
    getch();
    return;

}
void update_stud()
{
    struct student s2,s3;
    int s1=sizeof(s2);
    //declaring student structure and determining its size.
    printf("\n");
    printf(">>> WELCOME STUDENT UPDATE OPTION <<<\n\n");
    FILE *fo,*ft;
    char *name1="Student.txt", *name2="Temp.txt";

    char another='Y';
    while(another=='Y')
    {
    fo=fopen(name1,"r");//gonna read from student file and write in temp file
    ft=fopen(name2,"w");
    printf("> PLEASE ENTER THE USER ID OF THE STUDENT TO BE UPDATED: ");
    scanf("%s", &s3.id);
    fflush(stdin);
    printf("\n");
    printf("> PLEASE ENTER THE COURSE_NAME OF THE STUDENT: ");
    scanf("%s", &s3.cname);
    fflush(stdin);
    //taking student user id and course name to check actually these information are valid or not.
    printf("\n");

    int token=0;

    while(fread(&s2,s1,1,fo))
    {
        if(!strcmp(s2.id,s3.id)&& !strcmp(s2.cname,s3.cname))//checking student information by user id & course name
        {
            token=1;
            printf("\n>> RECORD FOUND!\n\n");
            //given what program finds
            printf("> GIVEN ID              : %s\n",s2.id);
            printf("> GIVEN NAME            : %s\n",s2.sname);
            printf("> GIVEN PASSWORD        : %s\n",s2.pass);
            printf("> GIVEN COURSE NAME     : %s\n",s2.cname);
            printf("> OBTAINED COURSE NUMBER: %s\n\n",s2.number);
            //given what admin can do
            printf("> Press 1 to UPDATE STUDENT'S NAME\n");
            printf("> Press 2 to UPDATE STUDENT'S PASSWORD\n");
            printf("> Press 3 to UPDATE STUDENT'S COURSE NAME\n");
            printf("> Press 4 to UPDATE STUDENT'S OBTAINED NUMBER\n");

            printf("\n> Enter Your Choice....(1/2/3/4)..: ");//asking for choice

            int a;
            scanf("%d", &a);
            if(a==1)
            {
                printf("\n> ENTER NEW NAME: ");
                fflush(stdin);
                gets(s3.sname);
                fflush(stdin);
                printf("\n");
                strcpy(s2.sname,s3.sname);//copying new name

            }
            else if(a==2)
            {
                printf("\n> ENTER NEW PASSWORD: ");
                fflush(stdin);
                scanf("%s", &s3.pass);
                printf("\n");
                fflush(stdin);
                strcpy(s2.pass,s3.pass);//copying new password

            }
            else if(a==3)
            {
                printf("\n> REQUIRED FORMATE:CSE_1202\n");
                printf("> ENTER NEW COURSE: ");
                scanf("%s", &s3.cname);
                strcpy(s2.cname,s3.cname);//copying new course

            }
            else
            {
                printf("\n> ENTER NEW OBTAINED MARK: ");
                fflush(stdin);
                scanf("%s", &s3.number);
                printf("\n");
                fflush(stdin);
                strcpy(s2.number,s3.number);//copying new obtained number
            }

              printf("\n>> RECORD UPDATED SUCCESSFULLY!...\n\n");
//              getch();

        }
        fwrite(&s2,s1,1,ft);//writing to temp file

    }
    fclose(fo);
    fclose(ft);
    fo=fopen(name1,"w");//file opening in written mode
    ft=fopen(name2,"r");//file opening in reading mode
    while(fread(&s2,s1,1,ft))
    {
        fwrite(&s2,s1,1,fo);//taking records back from temp file and writing in student file.
    }
    if(token==0)
    {
        printf("\n>> INVALID USER ID!...\n");//showing error message
    }
    printf("> Press Y to UPDATE ANOTHER RECORD\n");
    printf("> Press N to EXIT\n");
    printf("\n> Enter YOUR CHOICE...(Y/N)...: ");
    //asking for repeat operation or exit
    fflush(stdin);
    scanf("%c", &another);
    fclose(fo);
    fclose(ft);
    }
    return;
}

void add_teacher()
{
    struct teacher t1,t2;
    int s1=sizeof(t1);
    //declaring structure and determining it's size.
    FILE *ftec;
    ftec=fopen("Teacher.txt","a");//opening teacher file in append mode.
    if(ftec==NULL)
    {
        printf("\n>> CANNOT ADD TEACHER INFORMATION\n");
        fclose(ftec);
        //showing error message
        return;//returning function from where it has been called
    }
     system("cls");//clearing screen
     printf("\n>=> WELCOME TO ADD TEACHER OPTION <=<\n");
    char another='Y';
    while(another=='Y')
    {
    printf("\n> ENTER TEACHER'S ID: ");
    fflush(stdin);
    scanf("%s", &t1.id);
    fflush(stdin);
    printf("\n");
    printf("> ENTER TEACHER'S NAME(FORMATE:Akib_sir): ");
    scanf("%s", &t1.tname);
    fflush(stdin);
    printf("\n> ENTER PASSWORD: ");
    scanf("%s", &t1.pass);
    fflush(stdin);
    printf("\n> ENTER COURSE NAME(FORMATE:CSE_1202): ");
    scanf("%s", &t1.cname);
    fflush(stdin);

    fwrite(&t1,s1,1,ftec);
    //information is written in teacher file.
    printf("\n>> NEW TEACHER ADDED! <<\n\n");//confirmation message
    printf("> Press Y to ADD ANOTHER RECORD\n");
    printf("> Press N to EXIT\n");
    printf("\n> Enter YOUR CHOICE...(Y/N)...: ");
    //asking for repeat operation or exit
    scanf("%c", &another);
    fflush(stdin);
    }
    fclose(ftec);
    return;
}

void display_teacher()
{
    struct teacher t1,t2;
    int s1=sizeof(t1);

    FILE *fx;//declaring a file pointer
    fx=fopen("Teacher.txt","r");//file opening in reading mode
    int cnt=0;
    while(fread(&t1,s1,1,fx))
    {
        printf("%d.\n",++cnt);
        printf("> TEACHER'S NAME    : %s\n",t1.tname);
        printf("> TEACHER'S ID      : %s\n",t1.id);
        printf("> TEACHER'S PASSWORD: %s\n",t1.pass);
        printf("> TEACHER'S COURSE  : %s\n",t1.cname);

    }
    fclose(fx);
    printf("\n>> PRESS ANY KEY TO CONTINUE: ");
    getch();
    return;

}

void assign_courses()
{
    struct teacher t1,t2;
    int s1=sizeof(t1);
    system("cls");
    printf(">=> WELCOME TO COURSE ASSIGN OPTION <=<\n\n");
    char another ='Y';
    while(another=='Y')
    {
        FILE *ft,*fb;
        fb=fopen("Teacher.txt","r");
        ft=fopen("Temp.txt","w");
        printf("> ENTER THE ID OF THE TEACHER: ");
        scanf("%s", &t2.id);
        fflush(stdin);
        printf("\n");
        int token=0;
        while(fread(&t1,s1,1,fb))
        {
            if(!strcmp(t2.id,t1.id))
            {
                token=1;
                printf("\n>> RECORD FOUND!..\n");//showing found message
                printf("\n> NAME: %s\n",t1.tname);
                printf("\n> ENTER THE NEW COURSE NAME(FORMATE:CSE_1202): ");
                scanf("%s", &t2.cname);
                strcpy(t1.cname,t2.cname);
                fflush(stdin);
                //copying course name and and showing name of teacher
                printf("\n>> COURSE ASSIGNED SUCCESSFULLY!..\n");

            }
            fwrite(&t1,s1,1,ft);//writing information in temp file
        }
        fclose(ft);
        fclose(fb);
        ft=fopen("Temp.txt","r");
        fb=fopen("Teacher.txt","w");
    while(fread(&t1,s1,1,ft))
    {
        fwrite(&t1,s1,1,fb);//writing information in teacher file from temp file
    }
    if(token==0)
    {
        printf("\n>> INVALID USER ID!...\n");
    }
    printf("\n> Press Y to UPDATE ANOTHER RECORD\n");
    printf("> Press N to EXIT\n");
    printf("\n> Enter YOUR CHOICE...(Y/N)...: ");
    //asking for repeat operation or exit
    scanf("%c", &another);
    fclose(ft);
    fclose(fb);
    }
    return;
}

void update_tinformation()
{
    struct teacher t1,t2;
    int s1=sizeof(t1);
    //declaring teacher structure and determining its size
    system("cls");
    FILE *fb,*ft;
    char *name="Teacher.txt";
    fb=fopen(name,"r");//opening teacher file in reading mode
    ft=fopen("Temp.txt","w");//opening temp file in writing mode
    printf("\n\n>=> WELCOME TO TEACHER'S INFORMATION UPDATE OPTION <=<\n\n");
    char another='Y';
    while(another=='Y')
    {

    printf("> Enter ID OF THE TEACHER: ");
    scanf("%s", &t2.id);
    fflush(stdin);
    //taking id of the teacher
    int token=0;
//    rewind(fp);
//    rewind(ft);
    while(fread(&t1,s1,1,fb))
    {
        if(!strcmp(t1.id,t2.id))
        {
            token=1;
            printf("\n>> RECORD FOUND!..\n");
            //showing found information
            printf("> CURRENT NAME       : %s\n",t1.tname);
            printf("> CURRENT PASSWORD   : %s\n",t1.pass);
            printf("> CURRENT COURSE NAME: %s\n\n",t1.cname);
            //offering edit menu
            printf("> Press 1 to UPDATE NAME\n");
            printf("> Press 2 to UPDATE PASSWORD\n");
            printf("> Press 3 to UPDATE COURSE NAME\n");

            printf("\n> ENTER YOUR CHOICE....(1/2/3)..: ");//asking for choice
            int b;
            scanf("%d", &b);
            if(b==1)
            {
                printf("\n> ENTER NEW NAME: ");
                scanf("%s", &t2.tname);
                fflush(stdin);
                strcpy(t1.tname,t2.tname);
                printf("\n");
            }
            else if(b==2)
            {
                printf("\n> ENTER NEW PASSWORD: ");
                scanf("%s", &t2.pass);
                fflush(stdin);
                strcpy(t1.pass,t2.pass);
                printf("\n");
            }
            else
            {
                printf("\n> REQUIRED COURSE FORMATE: CSE_1202\n");
                printf("> ENTER NEW COURSE NAME: ");
                scanf("%s", &t2.cname);
                fflush(stdin);
                strcpy(t1.cname,t2.cname);
                printf("\n");
            }
            printf("\n>> RECORD UPDATED SUCCESSFULLY! <<\n");//course updated message
        }
        fwrite(&t1,s1,1,ft);//writing information in temp file
    }
    fclose(ft);
    fclose(fb);
    ft=fopen("Temp.txt","r");//opening temp file in reading mode
    fb=fopen(name,"w");//opening teacher file in writing mode
    while(fread(&t1,s1,1,ft))//reading information from temp file
    {
        fwrite(&t1,s1,1,fb);//writing information in teacher file
    }

    if(token==0)
    {
        printf("\n>> INVALID USER ID!...\n");
        //showing error message.
    }
    printf("\n> Press Y to UPDATE ANOTHER RECORD\n");
    printf("> Press N to EXIT\n");
    printf("\n> Enter YOUR CHOICE...(Y/N)...: ");
    //asking for choice
    scanf("%c", &another);

    }
    fclose(ft);
    fclose(fb);
    return;
}

void search_stud_name()
{
    struct teacher t1,t2;
    struct student s2,s3;
    char *name1="Student.txt";
    char *name2="Teacher.txt";
    FILE *ft,*fs=fopen(name1,"r");
    ft=fopen(name2,"r");
    system("cls");
    printf("\n>=> WELCOME TO SEARCH STUDENT OPTION <=<\n\n");
    char another ='Y';
    while(another=='Y')
    {
        rewind(ft);
        rewind(fs);
        printf("> ENTER TEACHER'S ID: ");
        scanf("%s", &t1.id);
        fflush(stdin);
        printf("\n> ENTER TEACHER'S COURSE NAME: ");
        scanf("%s", &t1.cname);
        fflush(stdin);
        //asking teacher's id & course name,
        int flag=0;
        while(fread(&t2,sizeof(t2),1,ft))
        {

            if(!strcmp(t1.cname,t2.cname) && !strcmp(t1.id,t2.id))//checking if given id and course name are matched with data
            {
                int token=0;
                flag=1;
                printf("\n***YOU ARE ASSIGNED TO THIS COURSE***\n\n");
                printf("> ENTER THE ID OF STUDENT: ");
                scanf("%s", &s2.id);//asking for student id
                while(fread(&s3,sizeof(s3),1,fs))
                {
                    if(!strcmp(s3.id,s2.id))// checking if such student is assigned to that course ID & marks are showed below
                    {
                        printf("\n>> RECORD FOUND!\n\n");//showing found message
                        printf("> STUDENT NAME    : %s\n",s3.sname);
                        printf("> OBTAINED MARKS  : %s\n",s3.number);
                        printf("\n");
                        token=1;

                    }
                }
                if(token==0)
                {
                    printf("\n>> SORRY! YOU HAVE NO STUDENTS..\n");
                }

            }
        }
        if(flag==0)
        {
            printf("\n>> SORRY NO SUCH DATA IS FOUND!...\n");
            //showing error message
        }

        printf("\n> Press Y to REPEAT OPERATION\n");
        printf("> Press N to EXIT OPERATION\n");
        printf("\n> Enter YOUR CHOICE...(Y/N)...: ");
        fflush(stdin);
        scanf("%c", &another);
        //asking for another choice
        fflush(stdin);

    }
    fclose(ft);
    fclose(fs);
    return;

}

void total_stud()
{

    struct teacher t1,t2;
    struct student s2,s3;
    char *name1="Student.txt";
    char *name2="Teacher.txt";
    FILE *ft,*fs=fopen(name1,"r");
    ft=fopen(name2,"r");
    system("cls");
    printf("\n>=> WELCOME TO TOTAL STUDENT OPTION <=<\n\n");
    char another ='Y';
    while(another=='Y')
    {

        printf("> ENTER TEACHER'S ID: ");
        scanf("%s", &t1.id);
        fflush(stdin);
        printf("\n> ENTER TEACHER'S COURSE NAME: ");
        scanf("%s", &t1.cname);
        fflush(stdin);
        int cnt=0;
        int flag=0;
        while(fread(&t2,sizeof(t2),1,ft))
        {

            if(!strcmp(t1.cname,t2.cname) && !strcmp(t1.id,t2.id))//checking course name & id are matched or not
            {

                printf("\n***YOU ARE ASSIGNED TO THIS COURSE***\n\n");
                printf("***SHOWING THE NUMBER OF STUDENTS ASSIGNED TO YOUR COURSE***\n\n");
                while(fread(&s3,sizeof(s3),1,fs))
                {
                    if(!strcmp(s3.cname,t2.cname))//if they are matched specific names are checking matched or not
                    {
                        cnt++;//counting students to that course
                    }
                }
                if(cnt==0)
                {
                    printf("\n>> SORRY! YOU HAVE NO STUDENTS..\n");
                }
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\n>> SORRY NO SUCH DATA IS FOUND!...\n");
        }

        printf("> TOTAL %d STUDENTS ARE ASSIGNED TO THIS COURSE\n\n",cnt);//showing result
        printf("\n> Press Y to REPEAT TOTAL STUDENT OPERATION\n");
        printf("> Press N to EXIT OPERATION\n");
        //asking for choice
        printf("\n> Enter YOUR CHOICE...(Y/N)...: ");
        scanf("%c", &another);
        fflush(stdin);

    }
    fclose(ft);
    fclose(fs);
    return;
}
void provide_marks()
{
    struct teacher t1,t2;
    struct student s1,s2;
    system("cls");
    printf("\n>=> WELCOME TO PROVIDE MARKS OPTION <=<\n\n");
    char *name1="Student.txt";
    char *name2="Teacher.txt";
    char *name3="Temp.txt";
    FILE *ft,*ftemp,*fs=fopen(name1,"r");
    ft=fopen(name2,"r");
    ftemp=fopen(name3,"w");

    printf("> ENTER TEACHER'S ID: ");
    scanf("%s", &t1.id);
    fflush(stdin);
    printf("\n> ENTER TEACHER'S COURSE NAME: ");
    scanf("%s", &t1.cname);
    fflush(stdin);

    int token=0;
    while(fread(&t2,sizeof(t2),1,ft))//reading from teacher file
    {

        if(!strcmp(t1.cname,t2.cname) && !strcmp(t1.id,t2.id))//checking data matched or not
        {

            printf("\n***YOU ARE ASSIGNED TO THIS COURSE***\n\n");
            printf("> ENTER THE ID OF THE STUDENT: ");
            scanf("%s", &s1.id);
            fflush(stdin);
            while(fread(&s2,sizeof(s2),1,fs))//reading from student file
            {

                if(!strcmp(s1.id,s2.id) && !strcmp(s2.cname,t1.cname))//checking for data match
                {
                    token=1;
                    printf("\n>> RECORD FOUND!..\n");
                    printf("> STUDENT NAME : %s\n",s2.sname);
                    printf("> ENTER THE OBTAINED MARK: ");
                    scanf("%s", &s1.number);
                    fflush(stdin);
                    strcpy(s2.number,s1.number);
                    printf("\n\n");
                    //if data matched showing student name and taking input for updated mark
                    printf(">> RECORD UPDATED SUCCESSFULLY! \n\n");

                }
                fwrite(&s2,sizeof(s2),1,ftemp);//writing information into temp file
            }
        }

    }

    fclose(ftemp);
    fclose(fs);
    fclose(ft);
    ftemp=fopen(name3,"r");
    fs=fopen(name1,"w");
    while(fread(&s2,sizeof(s2),1,ftemp))//reading from temp file
    {
        fwrite(&s2,sizeof(s2),1,fs);//writing in student file
    }
    if(token==0)
    {
        printf("\n>> WRONG INFORMATION GIVEN!..\n");//error message
    }
    printf("PRESS ANY KEY TO EXIT: ");
    getch();
    fflush(stdin);
    fclose(ftemp);
    fclose(fs);
    return;
}

int main()
{
    int a;
    system("cls");
    printf("\n\n");
    printf(">>>>>> WELCOME TO KUET DEPARTMENTAL MANAGEMENT PROGRAM <<<<<<\n\n");
    printf("...... Designed by 1907003...\n");
    printf("\n\n");
    printf("\n");
    printf("Menu\n\n");//Menu Option
    printf("**Press 1 For ADMIN   PANEL:");
    printf("\n\n");
    printf("**Press 2 For TEACHER PANEL:");
    printf("\n\n");
    printf("**Press 3 For STUDENT PANEL:");
    printf("\n\n");
    printf("**Press 0 To EXIT:");
    printf("\n\n");
    printf(">> ENTER YOUR CHOICE...(1/2/3/0)..: ");//asking for choice
    scanf("%d", &a);
    if(a==1)
    {
        admin_work();//going to admin panel work
        main();
    }

    else if(a==2)
    {
        teacher_work();//going to teacher panel work
        main();
    }
    else if(a==3)
    {
        stud_work();//going to student panel work
        main();
    }
    else
    {
        printf("EXITING THE PROGRAM!...");//exiting message
        return 0;
    }

}


