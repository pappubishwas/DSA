#include<stdio.h>
void display(int array[][20],int r,int c)
{
    int i,j;
    for ( i = 0; i < r; i++){
    for ( j = 0; j < c; j++)
        printf(" %d ",array[i][j]); 

    printf("\n");           
    }
    printf("\n");
}
void readData(int array[][20], int r ,int c)
{
    int i,j;
    for ( i = 0; i < r; i++)
    for ( j = 0; j < c; j++)
        scanf("%d",&array[i][j]);   
}

void triple_matrix(int array[][20], int r ,int c,int sp[][20])
{
    int i,j,k=0;
    sp[0][0]=r;
    sp[0][1]=c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++){
            if(array[i][j]!=0)
            {
                k++;
                sp[k][0]=i;
                sp[k][1]=j;
                sp[k][2]=array[i][j];
                sp[0][2]=k;
            }
        }
    }
    display(sp,k+1,3);
}
int main()
{
    int r,c,array[20][20],array2[20][20],sum[20][20],sp1[20][20],sp2[20][20];
    printf("How many number row you want : ");
    scanf("%d",&r);
    printf("How many number colum you want : ");
    scanf("%d",&c);
    printf("Give the element of matrix A: ");
    readData(array,r,c);
    printf("Matrix A :\n");
    display(array,r,c);
    printf("Give the element of matrix B: ");
    readData(array2,r,c);
    printf("Matrix B :\n");
    display(array2,r,c);
    printf("\nSparse Matrix1 : \n");
    triple_matrix(array,r,c,sp1);
    printf("\nSparse Matrix2 : \n");
    triple_matrix(array2,r,c,sp2);

    int i=1,j=1,k=0,t1=sp1[0][2],t2=sp2[0][2];
    sum[0][0]=r;sum[0][1]=c;
    while (i<=t1 && j <=t2)
    {
        if (sp1[i][0]==sp2[j][0] && sp1[i][1]==sp2[j][1])
        {
            k++;
            sum[k][0]=sp1[i][0];
            sum[k][1]=sp1[i][1];
            sum[k][2]=sp1[i][2]+sp2[j][2];
            i++;j++;
        }else{
            if((sp1[i][0]==sp2[j][0] && sp1[i][1]<sp2[j][1]) || (sp1[i][0]<sp2[j][0])){
                k++;
                sum[k][0]=sp1[i][0];
                sum[k][1]=sp1[i][1];
                sum[k][2]=sp1[i][2];
                i++;
            }
            else{
                k++;
                sum[k][0]=sp2[j][0];
                sum[k][1]=sp2[j][1];
                sum[k][2]=sp2[j][2];
                j++; 
            }
        }
    }

    while (i<=t1)
    {
        k++;
        sum[k][0]=sp1[i][0];
        sum[k][1]=sp1[i][1];
        sum[k][2]=sp1[i][2];
        i++;        
    }
    while (j<=t2)
    {
        k++;
        sum[k][0]=sp2[j][0];
        sum[k][1]=sp2[j][1];
        sum[k][2]=sp2[j][2];
        j++;        
    }
    sum[0][2]=k;
    printf("\nAdd of tripple matrix : \n");
    display(sum,k+1,3);
    
return 0;
}


//Name:Pappu Bishwas
//Roll:2106287
//Section: IT-2