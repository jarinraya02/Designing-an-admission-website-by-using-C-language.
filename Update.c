#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


void circular_result(float x,int age[3],int subject){
    printf("Your combined(SSC+HSC) GPA is %.2f\n",x);
    printf("Your age is %d years %d months %d days.\n",age[2],age[1],age[0]);
    if(7.50<=x && x<=10 && 17<=age[2] && age[2]<=23 && subject==1){
        printf("You are eligible for applying department of Civil Engineering.\n");
    }
    else if(6<=x && x<=10 && 17<=age[2] && age[2]<=23 && subject==2){
        printf("You are eligible for applying department of Computer Science Engineering.\n");
    }
    else if(6<=x && x<=10 && 17<=age[2] && age[2]<=23 && subject==3){
        printf("You are eligible for applying department of Electrical and Electronics Engineering.\n");
    }
    else if(6<=x && x<=10 && 17<=age[2] && age[2]<=23 && subject==4){
        printf("You are eligible for applying department of Architecture.\n");
    }
    else
        printf("You are not eligible for apply.\n");
    printf("\n\n                        ----------**********----------\n\n\n");
}

float cgpa_calculation(int ia[30]){
    int i,a;
    float x=0;
    for(i=0; i<7; i++){
        if(i!=2){
            ia[i]=ia[i]/2;
        }
    }
    for(i=0; i<7; i++){
        if(ia[i]>=80 && 100>=ia[i])
            x=x+4.00;
        else if(ia[i]>=75 && 79>=ia[i])
            x=x+3.75;
        else if(ia[i]>=70 && 74>=ia[i])
            x=x+3.50;
        else if(ia[i]>=65 && 69>=ia[i])
            x=x+3.25;
        else if(ia[i]>=60 && 64>=ia[i])
            x=x+3.00;
        else if(ia[i]>=55 && 59>=ia[i])
            x=x+2.75;
        else if(ia[i]>=50 && 54>=ia[i])
            x=x+2.50;
        else if(ia[i]>=45 && 49>=ia[i])
            x=x+2.25;
        else if(ia[i]>=40 && 44>=ia[i])
            x=x+2.00;
        else
            x=x+0.00;
    }
    x=x/7.00;
    printf("Your CGPA is %.2f.\n",x);
    return x;
}

void birth_gpa_calculation(float pa[20],int birth[3]){
    float x;
    int age[3],subject;
    x=pa[1]+pa[2];
    age[0]=31-birth[0];
    if(age[0]<0){
        age[0]=age[0]+30;
        birth[1]--;
    }
    age[1]=5-birth[1];
    if(age[1]<0){
        age[1]=age[1]+12;
        birth[2]--;
    }
    age[2]=2021-birth[2];

    subject=pa[0];
    circular_result(x,age,subject);

}
int serial_calculation(float x, float c[200],int count){
    int i,p=0;
    for(i=0; i<count; i++){
        if(c[i]>x){
            p++;
        }
    }
    p++;
    return p;
}

void Result_function(int count,int ID[200],float c[200],char name[200][200]){
    int scan_id,y,i,serial,j,x,n=0,m,k=0;
    char nm[100],fault[30];
    float q;
    system("color c");
    printf("Enter your Application ID: ");
        scanf("%d",&scan_id);
        for(i=0; i<count; i++){
            if(scan_id==ID[i]){
                y=i;
                n++;
                break;
            }
        }
        if(n==0){
            printf("Not found your application Id.\nPlease enter your name: ");
            gets(fault);
            gets(nm);
            for(j=0; j<count; j++){
                m=strcmp(name[j],nm);
                if(m==0){
                    q=c[j];
                    serial=serial_calculation(q,c,count);
                    printf("Application ID: %d\n",ID[j]);
                    printf("Name          : %s\n",name[j]);
                    printf("Your CGPA is %.2f\n",q);
                    k++;

                    if(serial<51){
                        printf("Congratulations! Your position is %d.\n",serial);
                    }
                    else{
                        serial=serial-50;
                        printf("Your waiting position is %d.\n",serial);
                    }
                    break;
                }
            }
            if(k==0){
                printf("Not found your name and ID. Please try again.\n");
            }
        }
        else{
            q=c[y];
            serial=serial_calculation(q,c,count);
            printf("Application ID: %d\n",ID[y]);
            printf("Name          : %s\n",name[y]);
            printf("Your CGPA is %.2f\n",q);

            if(serial<51){
                printf("Congratulations! Your position is %d.\n",serial);
            }
            else{
                serial=serial-50;
                printf("Your waiting position is %d.\n",serial);
            }
        }
    printf("\n\n                        ----------**********----------\n\n\n");
}

float application_form(char b[16][200],int count,float c[200],long long int mobile[200],char name[200][200]){
    long long int user_mobile;
    int i,j,x=0,y=0,marks[30],serial,n,m=0;
    char s[6][50],fault[30];
    float p;
    gets(fault);
    for(j=0; j<16; j++){
        if(j==0){
            printf("Name         : ");
            gets(s[0]);
        }
        else if(j==1){
            printf("Fathers Name : ");
            gets(s[1]);
        }
        else if(j==2){
            printf("Mothers Name : ");
            gets(s[2]);
        }
        else if(j==3){
            printf("Gender       : ");
            gets(s[3]);
        }
        else if(j==4){
            printf("Email        : ");
            gets(s[4]);
        }
        else if(j==5){
            printf("Mobile       : ");
            scanf("%lld",&user_mobile);
            printf("\n\n");
        }
        else if(j==9){
            printf("Bangla   : ");
            scanf("%d",&marks[0]);
        }
        else if(j==10){
            printf("English  : ");
            scanf("%d",&marks[1]);
        }
        else if(j==11){
            printf("ICT      : ");
            scanf("%d",&marks[2]);
        }
        else if(j==12){
            printf("Math     : ");
            scanf("%d",&marks[3]);
        }
        else if(j==13){
            printf("Physics  : ");
            scanf("%d",&marks[4]);
        }
        else if(j==14){
            printf("Chemistry: ");
            scanf("%d",&marks[5]);
        }
        else if(j==15){
            printf("Biology  : ");
            scanf("%d",&marks[6]);
            printf("\n\n");
        }
        else
            puts(b[j]);
    }

    p=cgpa_calculation(marks);

    for(i=0; i<count; i++){
        n=strcmp(name[i],s[0]);
        if(n==0 && mobile[i]==user_mobile && p==c[i]){
            printf("You are already applied.");
            m++;
        }
    }
    if(m==0){
        FILE *fc=fopen("Information.txt","a");
        FILE *fd=fopen("Details.txt","a");
        fprintf(fc,"%d          %lld            %.2f            ",count+210001,user_mobile,p);
        fprintf(fc, "%s\n",s[0]);
        fclose(fc);

        fprintf(fd,"\n%d\t\t%s\t\t%s\t\t\t%s\t\t\t%s\t\t%s\t\t\t\t%lld\t\t",count+210001,s[0],s[1],s[2],s[3],s[4],user_mobile);
        fprintf(fd,"%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t%.2f",marks[0],marks[1],marks[2],marks[3],marks[4],marks[5],marks[6],p);
        fclose(fd);

        serial=serial_calculation(p,c,count);
        printf("Application ID: %d\n",count+210001);
        printf("Name          : %s\n",s[0]);

        printf("Successfully complete your application.\nYour current position is %d.\n",serial);
    }
    m=0;

    printf("\n\n                        ----------**********----------\n\n\n");

    return p;
}

void circular_function(char a[18][200]){
    system("color 9");
    int i,px=11,py=0,birth[3];
    float pa[20];
     for(i=0; i<19; i++){
        if(px==i && px<16){
            printf("Ans: ");
            scanf("%f",&pa[py]);
            py++;
            px=px+2;
        }
        else if(i==17){
                printf("Ans: ");
            scanf("%d/%d/%d",&birth[0],&birth[1],&birth[2]);
        }
        else
            puts(a[i]);
        if(i==8){
            printf("Todays date is ");
            time_t t;
            time(&t);
            struct tm *myTime=localtime(&t);
            printf("%i/%i/%i\n",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900);
        }
    }
    birth_gpa_calculation(pa,birth);
}

int main(){
    FILE *fa=fopen("Circular.txt","r");
    FILE *fb=fopen("Form.txt","r");
    FILE *fc=fopen("Information.txt","r");
    char a[18][200],b[16][200],name[200][200];
    int i,j,k,p,count=0,ID[200],serial,scan_id,y,h,n;
    long long int mobile[200];
    float c[200],x,q;

    for(i=0; i<18; i++){
        fgets(a[i],200,fa);
    }

    for(j=0; j<16; j++){
        fgets(b[j],200,fb);
    }
    while((fscanf(fc,"%d %lld %f\t\t",&ID[k],&mobile[k],&c[k]))!=EOF){
        fgets(name[k],200,fc);
        //n=strlen(long_name[k]);
        //strncpy(name[k],long_name[k],n-1);
        //puts(name[k]);
        //n=strlen(name[k]);
        //printf("%d\n",n);
        count++;
        k++;
    }
    for(k=0; ; k++){
    printf("What you want to see?(Press 0 to exit)\n1.Circular\n2.Application form\n3.Result\nAns: ");
    scanf("%d",&p);
    printf("\n\n");
    if(p==0){
            system("color 6");
            printf("                        ----------THANK YOU----------\n\n\n");
        break;
    }
    else if(p==1)
        circular_function(a);
    else if(p==2){
        system("color a");
        x=application_form(b,count,c,mobile,name);
    }
    else if(p==3){
            Result_function(count,ID,c,name);

        }
    }

    return 0;
}


