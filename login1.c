#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#include <ctype.h>
#include <windows.h>

void reg();
void login();

int o;

struct web
{
  char name[30],pass[30];
  char id[30];
}w[99];
int main()
{
    int k;







  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE
                          );


      
 printf("enter 1 for admin login ");
 printf("\n");
  printf("enter  2 for registration of members \n");
 printf("enter 3 for normal account of login of members:");
 printf("enter 4 for exit from program");
 printf("\n");

 
 
 
  scanf("%d",&k);
  printf("\n");
 switch(k)
 {  
     case 1:
      printf("Admin login section:\n");
      char username[10]="Kalam";
      int password=123;
      char username1[10];
      int password1;
   
    
      bool p=true;
         
          if(strcmp(username,username1)!=0||password1!=password){
      while(p)
      {
          
           if(strcmp(username,username1)!=0||password1!=password)
          {
         
      printf("\nEnter the username=");
      scanf("%s",username1);
      printf("\n");
      printf("enter the password=");
      scanf("%d",&password1);
      printf("\n");
      
      
      }
      if(strcmp(username,username1)!=0||password1!=password)
      {
        printf("You have entered wrong password or username \n");

      }
           
          if(strcmp(username,username1)==0&&password1==password)
          {   
         
              break;
              
          }
          
      }
        }
      printf("You are successfully able to login\n");
      main();
  
    case 2:

      


reg();
main();


 break;
 case 3:
 printf("welcome to the login zone");
 login();
 main();

case 4:exit(0);

   


     default:printf("no valid user");
     printf("\n");
     
     
 }
     return 0;
}



    int static i=0;  
 void reg()
{ 
  

  i=i+1;
FILE *fp;
    char c,checker[30]; int z=0;
      fp=fopen("ravi.txt","ab+");
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");
    
   
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);

        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
              system ("cls");
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
         
            reg();
            }
          else
          {
            strcpy(w[i].name,checker);
            
            break;
          }
        }

  
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      
      while((c=getch())!=13)
        {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
    fseek(fp,0L,2);
           
    
      fwrite(&w[i],sizeof(w[i]),1,fp);


      fclose(fp);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
      system ("cls");
        printf("\n\n\t\tYou are successfully registered");
      
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        int n;
        scanf("%d",&n);
        switch(n)
          {
              case 1: system ("cls");
                    login();
                    break;
              case 2: system ("cls");
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        
      
    getch();



}
int static j;
int t;
void login()
{   

       
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("ravi.txt","rb+");
      printf("\n\n\t\t\t\t");
                        printf("------------------------------        \n");
                printf( "                               |                              |\n");
 printf( "                               |   WELCOME TO LOG IN ZONE     | \n");
        printf("                                 ------------------------------     \n " );
      
   
      
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
        
        static int j;
        fseek(fp,0L,0);
      while(!feof(fp))
        {
       ;
         j=0;
        fread(&w[j],sizeof(w[j]),1,fp);
          checku=strcmp(name,w[j].name);
         
          checkp=strcmp(pass,w[j].pass);
         j++;
         t=1;
          if(checku==0&&checkp==0)
          {
        
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
          
            break;
          }
        }
          fseek(fp,0L,0);
        while(!feof(fp)){
     
        j=0;
        fread(&w[j],sizeof(w[j]),1,fp);
          checku=strcmp(name,w[j].name);
         
          checkp=strcmp(pass,w[j].pass);
         j++;
       if(checku==0&&checkp!=0)
          {
           
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        }
        fseek(fp,0L,0);
         j=0; 
         while(!feof(fp)){
           
        
        fread(&w[j],sizeof(w[j]),1,fp);
       
          checku=strcmp(name,w[j].name);
         
          checkp=strcmp(pass,w[j].pass);
         j++;
         if(t!=1){
         if(checku!=0)
          { 
           
              printf("%s",w[j].name);
            printf("%s",w[j].pass);
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if(getch()==13)
            system ("cls");
            reg();
          }
         }
   
      
      getch();
}


}

