#include <stdio.h>
#include <stdlib.h>

struct student{
char name[20];
int rollno;
float marks;
char div[4];
};
void accept(struct student s[],int n){
  for(int i=0; i<n; i++){

    printf("Enter Name :\n ");
    scanf("%s",s[i].name);
    printf("Enter RollNo :\n ");
    scanf("%d",&s[i].rollno);
    printf("Enter Marks :\n ");
    scanf("%f",&s[i].marks);
    printf("Enter the div :\n");
    scanf("%s",&s[i].div);

        }
}
void display(struct student s[],int n){
 printf("\n Name RollNo Marks div \n");
        for(int i=0; i<n; i++)
printf("\n %s  %d    %f  %s \n", s[i].name, s[i].rollno, s[i].marks ,s[i].div);

}
void dis(struct student s[],int n){
 printf("\n Name RollNo Marks div \n");
printf("\n %s  %d    %f  %s \n", s[n].name, s[n].rollno, s[n].marks ,s[n].div);
}
void linear(struct student s[],int n){
    int key,pointer,flag=0;
printf("enter the roll no to be searched:\n");
scanf("%d",&key);
for(int i=0;i<n;i++){
    if(s[i].rollno==key){
        flag=1;pointer=i;
        break;
    }
}
if(flag==1){
    printf("The rollno is present\n");
    dis(s,pointer);
}
else{
printf("The rollno not found");
}
}
void binary_nonrecursive(struct student s[],int low,int high){
    int mid,keye,point,flag=0;
printf("enter the roll no to be searched:\n");
scanf("%d",&keye);
    while(low<=high){
        mid=low+(high-low)/2;
        if(s[mid].rollno==keye){
            flag=1;
            printf("record found");
            point=mid;
            break;
        }
        else if(s[mid].rollno>keye){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(flag==0){
        printf("record not found");
    }
    if(flag==1){
      dis(s,point);
    }

}
int binary_recursive(struct student s[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + r / 2;

		if (s[mid].rollno == x)
			return mid;


		if (s[mid].rollno > x)
			return binary_recursive(s, l, mid - 1, x);


		return binary_recursive(s, mid + 1, r, x);
	}
	return -1;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubblesort(struct student s[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (s[j].rollno > s[j+1].rollno)
                swap(&s[j].rollno, &s[j+1].rollno);
        }
    }
    display(s,n);
}
void insertionSort(struct student s[],int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = s[i].rollno;
        j = i - 1;//j will be previous ele of key

        while (j >= 0 && s[j].rollno > key) {//pev ele is greater than key
            s[j + 1].rollno = s[j].rollno; //at the key position greater ele is stored
            j = j - 1; //dec j
        }
        s[j + 1].rollno = key;//at greater ele pos key is stored

}
display(s,n);
}
void selectionSort(struct student s[],int n)
{

    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (s[j].rollno < s[min_idx].rollno)
            min_idx = j;
        swap(&s[min_idx].rollno, &s[i].rollno);
    }

display(s,n);
}

int main()

{
int n,x,choice,count=0;
printf("Enter no of students : ");
        scanf("%d",&n);
        struct student s[n];
        accept(s,n);

 do
    {
        printf("MENU");
        printf("\n1.Display records \n2.Linear search \n3.Binary search(non-recursive) \n4.Binary search(recursive) \n5.Bubble sort \n6.Insertion sort \n7.Selection sort \n8. Exit");
        printf("\n Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                display(s,n);
                break;
            }
            case 2:
            {
                linear(s,n);
                break;
            }
            case 3:
            {
                binary_nonrecursive(s,0,n);
                break;
            }
            case 4:
                {
                  printf("enter the roll no to be searched:\n");
                  scanf("%d",&x);
                  int result=binary_recursive(s,0,n,x);
                 if(result==-1){
                  printf("rollno not present");
                  }
                  else
                  {
                  printf("rollno is present\n");
                  }
                }
            case 5:
                {
                    bubblesort(s,n);
                    break;
                }
            case 6:
                {
                accept(s,n);
                 insertionSort(s,n);
                 break;

                }
            case 7:
                {
                 accept(s,n);
                 selectionSort(s,n);
                 break;
                }
            case 8:
                {
            printf("Thank you\n");
            count=1;
            break;
            }
           default:
            {
               printf("\n Wrong choice entered");
               break;
            }
        }
    }while(count!=1);
    return 0;
}
