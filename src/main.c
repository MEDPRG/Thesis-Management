#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

typedef struct account{
    char email[40],password[8];
}acnt;
typedef struct source{
    char so[40],ST[40];
}sr;
typedef struct person{
    char ID[6],NP[40],TM[40],Rus[10000];
    int ANS,PORS2;
    char URL[200];
}psr;
typedef struct memoire{
    char NDMS[50],DMP[30];
    int PORS1;
    psr DMS;
}me;
typedef struct index{
    char cle;
    int indice,occu;
}indx;

acnt AAC[50];
acnt SAC[500];
indx T2[26];
indx O;
me T[1000];
me Q;
FILE *F1;
FILE *F2;
FILE *F3;
FILE *F5;
FILE *F6;
FILE *F7;
void add_ad(int x){
    int i,j;
    char V[40];
    do{
            printf("Enter the email address :\n");
            gets(V);
            j=0;
            i=0;
            while((i<x)&&(j==0)){
                if(strcmp(V,AAC[i].email)==0)
                    j++;
                i++;
            }
            if(j==1)
                printf("The email you entered already exists !");
            else{
                strcpy(V,AAC[x].email);
            }
    }while(j==1);
    printf("Enter your password\n");
    gets(AAC[x].password);
    printf("Account saved successfully\n");

}
void add_sp(int x){
    int i,j;
    char V[40];
    do{
            printf("Enter the email address :\n");
            gets(V);
            system("cls");
            j=0;
            i=0;
            while((i<x)&&(j==0)){
                if(strcmp(V,SAC[i].email)==0)
                    j++;
                i++;
            }
            if(j==1)
                printf("The email you entered already exists !");
            else{
                strcpy(V,SAC[x].email);
            }
    }while(j==1);
    printf("Enter your password\n");
    gets(SAC[x].password);
    printf("Account saved successfully\n");
}

void trindx(int x){
     int i,j;
     me H;
     do{
        j=0;
       for(i=0;i<x-1;i++){
           if(strcmp(T[i].DMS.TM,T[i+1].DMS.TM)>0){
                H=T[i];
                T[i]=T[i+1];
                T[i+1]=H;
                j++;
           }
       }
      }while(j>0);
}

void remplir_s(int *x){
    int j,k,i=0;
    bool B=false;
    char v[100],p[5]=".pdf",f[200] = "D:/Mémoires/";
        printf("The key word of The Project N%d:",*x+1);
        gets(Q.DMP);
        printf("The Subject of The Project N%d:",*x+1);
        gets(Q.NDMS);
        printf("The ID of The Theme N%d:",*x+1);
                    do{ gets(Q.DMS.ID);
                     j=0;k=1;
                    while ((j<*x)&&(k == 1)) {
                        if (strcmp(Q.DMS.ID,T[j].DMS.ID)==0) {
                            printf(" This code already exists !\n");
                            k = 0;
                        }
                        j++;
                    }
                    }while(k==0);
        printf(" The Name of The owner of The Project N%d:",*x+1);
        gets(Q.DMS.NP);
        printf(" The Theme of The Project N%d:",*x+1);
        gets(Q.DMS.TM);
        strcpy(strupr(Q.DMS.TM),v);
        while(i<26 && B==false){
                if(T2[i].cle==v[0]){
                    T2[i].occu=T2[i].occu+1;
                    T2[i+1].indice=T2[i].occu;
                    B=true;
                }
                else{
                    i++;
                }
            }
        printf(" The Name of The File of The Theme: ");
        gets(v);
        strcat(f,v);
        strcat(f,p);
        strcpy(Q.DMS.URL,f);
        printf(" The Resume of The Project N%d:",*x+1);
        gets(Q.DMS.Rus);
        printf(" The percentage of work in His Theme N%d:",*x+1);
        scanf("%d",&Q.DMS.PORS2);
        printf(" The percentage of work in The Subject N%d:",*x+1);
        scanf("%d",&Q.PORS1);
        for(k=0;k<*x;k++){
            if(strcmp(Q.NDMS,T[k].NDMS)==0){
                T[k].PORS1=Q.PORS1;
            }
        }
        printf(" The Theme year:");
        scanf("%d",&Q.DMS.ANS);
        T[*x]=Q;
    }


void remplir_p(int *N){
    int y,I,j=0;
    bool B=false;
    char v[100],p[5]=".pdf",f[200] = "D:/Mémoires/";
    do{
        I=*N;
        if(I==1){
            printf(" The key word of the project N%d:",I+1);
            gets(T[I-1].DMP);
            printf(" The Subject of The Project N%d:",I+1);
            gets(T[I-1].NDMS);
            printf(" The ID of The Theme N%d:",I+1);
            gets(T[I-1].DMS.ID);
            printf(" The Name of The owner of The Project N%d:",I+1);
            gets(T[I-1].DMS.NP);
            printf(" The Theme of The Project N%d:",I+1);
            gets(T[I-1].DMS.TM);
            strcpy(strupr(T[I-1].DMS.TM),v);
            while(j<26 && B==false){
                if(T2[j].cle==v[0]){
                    T2[j].occu=T2[j].occu+1;
                    T2[j+1].indice=T2[j].occu;
                    B=true;
                }
                else{
                    j++;
                }
            }
            printf(" The Name of The File of The Theme:");
            gets(v);
            strcat(f,v);
            strcat(f,p);
            strcpy(T[I-1].DMS.URL,f);
            printf(" The Resume of The Theme N%d:",I+1);
            gets(T[I-1].DMS.Rus);
            printf(" The Percentage of work in His Theme N%d:",I+1);
            scanf("%d",&T[I-1].DMS.PORS2);
            printf(" The Percentage of work in The Subject N%d:",I+1);
            scanf("%d",&T[I-1].PORS1);
            printf(" The Theme year:");
            scanf("%d",&T[I-1].DMS.ANS);
        }
        else{
                if ((F1 = fopen("Memoire.bin","rb")) == NULL){
                        printf("there has been an error!");

                }
                else{
                fread(&T, sizeof(me), (I-1),F1);
                }
               fclose(F1);
               if ((F3 = fopen("index.bin","rb")) == NULL){
                        printf("there has been an error!");

               }
               else{
               fread(&T2, sizeof(indx),26,F3);
               }
               fclose(F3);
            remplir_s(&I);
        }

        do{
            printf("Do you want to continue:\n\n1-Yes\n\n2-No\n");
            scanf("%d",&y);
        }while(y!=1 && y!=2);
        *N=*N+1;

                trindx(I);
                 if ((F1 = fopen("Memoire.bin","wb")) == NULL){
                                printf("there has been an error!\n");

                 }
                 else{
                 fwrite(&T, sizeof(me), I, F1);
                 }
                 fclose(F1);
                 if ((F3 = fopen("index.bin","wb")) == NULL){
                        printf("there has been an error!");

               }
               else{
               fwrite(&T2, sizeof(indx),26,F3);
               }
               fclose(F3);
    }while(y!=2);
}
void supprimer(int *x,int*s){
    int y,j;
    char v[50];
    do{
        printf("The remove menu :\n");
        printf("Choose What you want deleted :\n1-Project\n2-Theme\n3-Administrator account\n4-Spectator account\n");
        scanf("%d",&y);
    }while((y<1)&&(y>4));
    switch(y){
    case 1: printf(" The Project Name witch you want deleted:  ");
            gets(v);
             if ((F1 = fopen("Memoire.bin","rb")) == NULL){
                        printf("there has been an error!");

                }
                if ((F2 = fopen("Delete.bin","wb")) == NULL){
                        printf("there has been an error!");

                }
            while(!feof(F1)){
                fread(&Q, sizeof(me),1,F1);
                if(strcmp(Q.NDMS,v)!=0){
                    fwrite(&Q, sizeof(me),1,F2);
                }
            }
                fclose(F1);
               fclose(F2);
            remove("Memoire.bin");
            rename("Delete.bin","Memoire.bin");

        break;
    case 2:printf(" The Theme Name which you want deleted:\t");
            gets(v);
             if ((F1 = fopen("Memoire.bin","rb")) == NULL){
                        printf("there has been an error!");

                }
                if ((F2 = fopen("Delete.bin","wb")) == NULL){
                        printf("there has been an error!");

                }
            while(!feof(F1)){
                fread(&Q, sizeof(me),1,F1);
                if(strcmp(Q.DMS.TM,v)!=0){
                    fwrite(&Q, sizeof(me),1,F2);
                }
            }
                fclose(F1);
               fclose(F2);
            remove("Memoire.bin");
            rename("Delete.bin","Memoire.bin");
        break;
    case 3: printf("Please write the email address of the account you want deleted \t");
            do{
            gets(v);
            y=0;
            j=0;
            while((y<*x)&&(j=0)){
                if(strcmp(AAC[y].email,v)==0){
                    for (j=y;j<*x-1;j++){
                        AAC[j]=AAC[j+1];
                    }
                    *x=*x-1;
                    j++;
                }
            y++;
            }
            if(j==0)
                printf("The email you entered does not exist, please retry\n");
            else printf("Account deleted successfully\n");
            }while(j==0);
            break;
        case 4: printf("Please write the email address of the account you want deleted \t");
            do{
            gets(v);
            y=0;
            j=0;
            while((y<*s)&&(j=0)){
                if(strcmp(SAC[y].email,v)==0){
                    for (j=y;j<*s-1;j++){
                        SAC[j]=SAC[j+1];
                    }
                    *s=*s-1;
                    j++;
                }
            y++;
            }
            if(j==0)
                printf("The email you entered does not exist, please retry\n");
            else printf("Account deleted successfully\n");
            }while(j==0);
}}
bool r_seq1(int x,char y[40]){
    int i=0,j=0;

    while((i<x)&&(j==0)){

        if(strcmp(y,T[i].DMS.TM)==0){
            return true;
            j=1;
        }
    i++;
    }
    return false;
}
void rsd (int x){
    char d[30];
    int i,j;
    printf("Enter the domain's name :\t");
    gets(d);
    for(i=0;i<x;i++){
        if(strcmp(d,T[i].DMP)==0){
            j++;
            printf("%d\t%s",j,T[i].NDMS);
        }
    }
}
void r_dic(int b,int c, char p[40]){
    int a;
    a=(b+c)/2;
    if(strcmp(p,T[a].DMS.TM)==0){
        printf("Modify The Resume of This Theme:\n");
        gets(T[a].DMS.Rus);
    }
    else {
        if(strcmp(p,T[a].DMS.TM)<0)
            r_dic(a,c,p);
        else
            r_dic(b,a,p);
    }
}
int r_seq(int x,char y[40]){
    int i=0,j=0;

    while((i<x)&&(j==0)){

        if(strcmp(y,T[i].DMS.TM)==0){
            j=1;
            return i;
        }
    i++;
    }
}
void drct(int Y,char Y1[40]){
    if (r_seq1(Y,Y1)){
        if ((F1 = fopen("Memoire.bin","rb")) == NULL){
           printf("Error! opening file");

       }
        else{
                fseek(F1,(r_seq(Y,Y1))*sizeof(me),SEEK_SET);
                fread(&Q,sizeof(me),1,F1);
                system(Q.DMS.URL);
        }
       fclose(F1);
    }
    else printf("Object not found !\n");
}
void RPT2(){
    int i;
    T2[0].indice=0;
   for(i=0;i<26;i++){
    T2[i].cle=65+i;
    T2[i].occu=0;
   }
}
void r_indexe(char r){
    int i,j;
    bool B=false;
    if ((F3 = fopen("index.bin","rb")) == NULL){
                        printf("there has been an error!");
    }
    else{
                 while((!feof(F3))&& (B==false)){
                    fread(&O, sizeof(indx),1,F3);
                    if(O.cle==r){
                        B=true;
                    }
                 }
    }
    fclose(F3);
    me T4[O.occu];
    if ((F1 = fopen("Memoire.bin","rb")) == NULL){
                        printf("there has been an error!");

    }
    else{
        fseek(F1,(O.indice)*sizeof(me),SEEK_SET);
        fread(&T4,sizeof(me),O.occu,F1);
        printf("   Theme\t\t|Subject:\t\t|author\t\t|Year|\n");
        for(i=0;i<=O.occu;i++){
            printf("%d- %s\t|%s\t|%s\t|%d|\n",i+1,T4[i].DMS.TM,T4[i].NDMS,T4[i].DMS.NP,T4[i].DMS.ANS);
        }
        printf("%d-Exit\n",i+1);
        printf("Choose from 1 to %d",i+1);
        do{
        scanf("%d",&j);
        }while((j<1) && (j>i+1));
        if(j==i+1){

        }
        else{
            printf("Choose what do you want to see:\n1-Article\n2-Resume\n");
            printf("Choose 1 or 2\n");
            do{
            scanf("%d",&i);
            }while((i!=1) && (i!=2));
            switch(i){
                case 1: system(T4[j].DMS.URL);
                break;
                case 2: printf("Resume:\n%s",T4[j].DMS.Rus);
                break;
            }
        }

    }
    fclose(F1);

}

int main(){
     int tn[3],y;

    if ((F7 = fopen("Sizeof table.bin","rb")) == NULL){
                       tn[0]=0;
                       tn[1]=0;
                       tn[2]=0;
                }
                else{
                    fread(&tn,sizeof(tn),3,F7);
                }
if ((F5 = fopen("Sizeof AAC.bin","rb")) == NULL){
                        add_ad(0);
                        tn[1]=1;
                }
                else{
                    fread(&AAC,sizeof(acnt),tn[1],F5);
                    fclose(F5);
                }

    if ((F6 = fopen("Sizeof SAC.bin","rb")) == NULL){
                        tn[2]=0;
                }
                else{
                 fread(&SAC,sizeof(acnt),tn[2],F6);
                 fclose(F6);
                }
    if (tn[0]==0){
        RPT2();
    }
    char c,s[40],p[8];
    A:
    system("cls");
    printf("Are you :\n");
    do{
        printf("1-Administrator\n2-Spectator\n");
        scanf("%c",&c);
    }while((c!='1')&&(c!='2'));

    if(c==1){
        printf("Enter your email : \n");
        gets(s);
        y=0;
        int i=0;
        while((i<tn[1])&&(y==0)){
            if(strcmp(s,AAC[i].email)==0){
                y++;
            }
            else {
                    i++;
            }
        }
        if(y!=0){
            y=0;
            do{
            printf("Enter the password : ");
            gets(p);
            if(strcmp(p,AAC[i].password)!=0){
                printf("Wrong password !\n");
                y++;
            }
            }while((y==1)||(y>3));
            if(y>3){
                 goto A;
            }
        }
        else {
            printf("This email doesn't exist !\n");
            goto A;
        }
        system("cls");
        MENU:
        printf("Main Menu :\n");
        printf("1-Add\n2-modify\n3-Remove\n4-Search\n5-Exit\n");
        do{
            scanf("%d",&y);
        }while((y=!4)||(y=!3)||(y=!2)||(y=!1));
        system("cls");
        if((tn[0]==0)&&(y!=1)&&(y!=5)){
            printf("There is no subjects available to treat\n");
            goto MENU;
        }
        else{
            F1=fopen("Memoire.bin","rb");
            fread(&T,sizeof(me),tn[0],F1);
        }
        switch(y){
        case 1: printf(" Add menu :\n");
                printf("1-Administrator\n2-Subject\n3-Spectator account\n");
                do{
                    printf("Choose from 1 to 3\n");
                    scanf("%d",&y);
                }while((y!=1)&&(y!=2)&&(y!=3));
                switch(y){
                    case 1: add_ad(tn[1]);
                            tn[1]++;
                            break;
                    case 2:
                            remplir_p(&tn[0]);
                            break;
                    case 3: add_sp(tn[2]);
                            tn[2]++;
                            break;
                }
            break;
        case 2:
                printf("Enter the subject's theme : ");
                gets (s);
                if(r_seq1(tn[0],s)){
                   r_dic(0,tn[0]-1,s);
                }
                else printf("The project has not been found\n");
            break;

        case 3: supprimer(&tn[1],&tn[2]);
            break;

        case 4:  do{
                   printf("1-key word\n2-Subject\n3-Theme\n");
                    scanf("%d",&y);
                    system("cls");
                   }while((y!=1)||(y!=2)||(y!=3));
                   switch(y){
                   case 1: printf("Enter the first letter : ");
                        scanf("%c",&c);
                        r_indexe(c);
                    break;
                   case 2: printf("Enter the subject's name :\t");

                           gets(s);
                      break;
                   case 3: printf("Enter the theme : \n");
                           gets(s);
                        drct(tn[0],s);
                    break;
                   }
            break;
        }
        if(y!=5) goto MENU;
    }
    else{
        printf("Enter your email : \n");
        gets (s);
        y=0;
        int i=0;
        while((i<tn[1])&&(y==0)){
            if(strcmp(s,SAC[i].email)==0)
                y++;
            i++;
        }
        if(y!=0){
            y=0;
            do{
            printf("Enter the password : ");
            gets(p);
            if(strcmp(p,SAC[i-1].password)!=0){
                printf("Wrong password !\n");
                y++;
            }
            }while((y==1)||(y>3));
            if(y>3)
                 goto A;
        }
        else {
            printf("This email doesn't exist !\n");
            goto A;
        }
        M:
        printf("Main Menu :\n");
        printf("1-Search\n2-Exit");
        do{
        scanf("%c",&c);
        }while((c!='1')&&(c!='2')&&(c!='s')&&(c!='e'));
        if((tn[0]==0)&&((c!='2')&&(c!='e'))){
            printf("There is no subjects available to treat\n");
            goto M;
        }
        else{
            F1=fopen("Memoire.bin","rb");
            fread(&T,sizeof(me),tn[0],F1);
        }

        if((c=='1')||(c!='s')){
            do{
                   printf("1-key word\n2-Subject\n3-Theme\n");
                    scanf("%d",&y);
                    system("cls");
                   }while((y!=1)||(y!=2)||(y!=3));
                   switch(y){
                   case 1: printf("Enter the first letter : ");
                        scanf("%c",&c);
                        r_indexe(c);
                    break;
                   case 2: printf("Enter the subject's name :\t");
                           gets(s);

                        break;
                   case 3: printf("Enter th theme :\n");
                           gets(s);
                       drct(tn[0],s);
                    break;
                   }
                goto M;
        }
    }

    fwrite(&AAC,sizeof(acnt),tn[1],F5);
    fwrite(&SAC,sizeof(acnt),tn[2],F6);

    return 0;

}

