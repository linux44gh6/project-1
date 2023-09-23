#include<stdio.h>
struct student{
     char name[20];
     int Roll;
     float GPA;
};
//using quick sort to sort the student details
void swap(struct student*a, struct student *b){
struct student temp;
temp=*a;
*a=*b;
*b=temp;
}
void quicksort(struct student a[],int low,int high){
if(low<high){
    int pidx=partion(a,low,high);
    quicksort(a,low,pidx-1);
    quicksort(a,pidx+1,high);
}
}
int partion(struct student a[],int low,int high){
float pivot=a[high].GPA;
int i=low-1;
for(int j=low;j<=high-1;j++){
    if(a[j].GPA>=pivot){
        i++;
        swap(&a[i],&a[j]);
    }
}
swap(&a[i+1],&a[high]);
return i+1;
}
int main()
{
    int n;
    printf("How many student's add in this file: ");
    scanf("%d",&n);
    struct student student[n];
    int i;
    for(int i=0;i<n;i++){
    printf(" Information of Student : %d\n",i+1);
    printf("Name of student : ");
    scanf(" %[^\n]%*c", student[i].name);
    printf("Roll of student : ");
    scanf("%d",&student[i].Roll);
    while(1){
    printf("Result(GPA) : ");
    scanf("%f",&student[i].GPA);
    if(student[i].GPA>4||student[i].GPA<1)
    {
    printf("wrong input!!!\nplease input the correct gpa.\n");
    }
    else if(student[i].GPA>=1&&student[i].GPA<=4)
    {
    break;
    }
    }
    }
    //call the sorting function
    quicksort(student,0,n-1);

    printf("\n\n");

     for(int i=0;i<n;i++){
    printf("Information of Student: %d \n",i+1);
    printf("Name:");
    printf("%s\t",student[i].name);
    printf("Roll:");
    printf("%d\t",student[i].Roll);
    printf("Result:");
    printf("%.2f\n",student[i].GPA);
    }
    FILE *fptr;
        fptr=(fopen("C:\\Users\\User\\OneDrive\\Documents\\c program\\scholarship.txt","w"));
        FILE *fptr1;
         fptr1=(fopen("C:\\Users\\User\\OneDrive\\Documents\\c program\\punishment.txt","w"));
         FILE*fptr2;
          fptr2=(fopen("C:\\Users\\User\\OneDrive\\Documents\\c program\\simple.txt","w"));

    for(i=0;i<n;i++)
    {

      if(student[i].GPA>=3.5)
      {

        fprintf(fptr,"\nName: %s, Roll=%d with GPA=%.2f will get scholarship.",student[i].name,student[i].Roll,student[i].GPA);
       printf("\nName: %s, Roll=%d with GPA=%.2f will get scholarship.",student[i].name,student[i].Roll,student[i].GPA);
      }
      else if(student[i].GPA<3.5&&student[i].GPA>=3.00)
      {
         fprintf(fptr2,"\nName: %s, Roll=%d with GPA=%.2f will get simple valobasa.",student[i].name,student[i].Roll,student[i].GPA);
      printf("\nName: %s, Roll=%d with GPA=%.2f will get simple.",student[i].name,student[i].Roll,student[i].GPA);
      }
      else if(student[i].GPA<3)
      {
         fprintf(fptr1,"\nName: %s, Roll=%d with GPA=%.2f will get punishment jorche.",student[i].name,student[i].Roll,student[i].GPA);
         printf("\nName: %s, Roll=%d with GPA=%.2f will get punishment jorche.",student[i].name,student[i].Roll,student[i].GPA);
      }
    }
}

