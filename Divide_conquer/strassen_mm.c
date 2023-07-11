#include<stdio.h>

void takemat(int n, int a[][n])
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("Enter element %d%d: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n");
}

void printmat(int n,int a[][n])
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void add_submat(int n, int a[][n],int b[][n],int c[][n],int y)
{
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if (y)
				c[i][j] = a[i][j] + b[i][j];
			else
				c[i][j] = a[i][j] - b[i][j];
		} 
	}
}
// no need to write

// void strassen(int n, int a[][n],int b[][n],int c[][n])
// {
// 	if (n==1)
// 	{
// 		c[0][0] = a[0][0]*b[0][0];
// 	}
// 	else
// 	{	
// 		 int sp_ind = n/2;
// 		//   for (int i = 0; i < sp_ind; i++)
//         //   {  for (int j = 0; j < sp_ind; j++)
// 		// 	 {
//         //        int  a00[i][j] = a[i][j];
//         //          int a01[i][j] = a[i][j + sp_ind];
//         //         int a10[i][j] = a[sp_ind + i][j];
//         //         int a11[i][j] = a[i + sp_ind][j + sp_ind];
//         //         int b00[i][j] = b[i][j];
//         //         int b01[i][j] = b[i][j + sp_ind];
//         //         int b10[i][j] = b[sp_ind + i][j];
//         //         int b11[i][j] = b[i + sp_ind][j + sp_ind];
//         //     }
// 		//   }
// 		int a[2][2][sp_ind][sp_ind];
// 		int b[2][2][sp_ind][sp_ind];
// 		int c[2][2][sp_ind][sp_ind];
// 		int p[7][sp_ind][sp_ind];
// 		int temp1[sp_ind][sp_ind],temp2[sp_ind][sp_ind];

// 		    // divide A and B into 4 add_submat-matrices
//     for(int r=0;r<2;r++)
//         for(int c=0;c<2;c++)
//         {
//             int row=r*sp_ind,col=c*sp_ind;
//             for(int i=0;i<sp_ind;i++)
//             for(int j=0;j<sp_ind;j++)
//                 {
//                         a[r][c][i][j]=A[i+row][j+col];
//                         b[r][c][i][j]=B[i+row][j+col];
//                 }
//         }
// 		int q[n/2][n/2];
// 		int r[n/2][n/2];
// 		int s[n/2][n/2];
// 		int t[n/2][n/2];
// 		int u[n/2][n/2];
// 		int v[n/2][n/2];
// 		p[0][0]= (a00[0][0] + a00[1][1])*(b00[0][0] + b00[1][1]);
// 		q = b[0][0] * (a[1][0] + a[1][1]);
// 		r = a[0][0] * (b[0][1] - b[1][1]);
// 		s = a[1][1] * (b[1][0] - b[0][0]);
// 		t = b[1][1] * (a[0][0] + a[0][1]);
// 		u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
// 		v = (b[1][0] + b[1][1]) * (a[0][1] - a[1][1]); 

// 		c[0][0] = p + s - t + v;
// 		c[0][1] = r + t;
// 		c[1][0] = q + s;
// 		c[1][1] = p + r - q + u;
// 	}
// }


//upto here

void strassen(int n, int A[][n], int B[][n], int C[][n]) 
{
    if (n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    
    int sp_i=n/2;
    int a[2][2][sp_i][sp_i];
    int b[2][2][sp_i][sp_i]; 
    int c[2][2][sp_i][sp_i];
    int p[7][sp_i][sp_i]; 
    int temp1[sp_i][sp_i], temp2[sp_i][sp_i];
    
    // divide A and B into 4 add_submat-matrices
    for(int r=0;r<2;r++)
        for(int c=0;c<2;c++)
        {
            int row=r*sp_i,col=c*sp_i;
            for(int i=0;i<sp_i;i++)
            for(int j=0;j<sp_i;j++)
                {
                        a[r][c][i][j]=A[i+row][j+col];
                        b[r][c][i][j]=B[i+row][j+col];
                }
        }
    
    // calculate p[0] to p[6]
    //P1=A11*(B12 - B22)
    add_submat(sp_i,b[0][1], b[1][1], temp1,0);
    strassen(sp_i,a[0][0], temp1, p[0] );
    
    //P2=(A11 + A12)B22
    add_submat(sp_i,a[0][0], a[0][1], temp1,1);
    strassen(sp_i,temp1, b[1][1], p[1]);
    
    //P3 = (A21 + A22)B11
    add_submat(sp_i,a[1][0], a[1][1], temp1,1);
    strassen(sp_i,temp1, b[0][0], p[2]);
    
    //P4 = A22(B21 - B11)
    add_submat(sp_i,b[1][0], b[0][0], temp1,0);
    strassen(sp_i,a[1][1], temp1, p[3]);

    //P5 = (A11 + A22)(B11 + B22)
    add_submat(sp_i,a[0][0], a[1][1], temp1,1);
    add_submat(sp_i,b[0][0], b[1][1], temp2,1);
    strassen(sp_i,temp1, temp2, p[4]);

    
    //P6 = (A12 - A22)(B21 + B22)
    add_submat(sp_i,a[0][1], a[1][1], temp1 ,0);
    add_submat(sp_i,b[1][0], b[1][1], temp2,1);
    strassen(sp_i,temp1, temp2, p[5]);

    
    //P7 = (A11 - A21)(B11 + B12)
    add_submat(sp_i,a[0][0], a[1][0], temp1,0);
    add_submat(sp_i,b[0][0], b[0][1], temp2,1);
    strassen(sp_i,temp1, temp2, p[6]);

    // calculate c[0][0], c[0][1], c[1][0], c[1][1]
    add_submat(sp_i,p[4], p[3], temp1,1);
    add_submat(sp_i,temp1, p[1], temp2,0);
    add_submat(sp_i,temp2, p[5], c[0][0],1);

    add_submat(sp_i,p[0], p[1], c[0][1],1);

    add_submat(sp_i,p[2], p[3], c[1][0],1);

    add_submat(sp_i,p[4], p[0], temp1,1);
    add_submat(sp_i,temp1, p[2], temp2,0);
    add_submat(sp_i,temp2, p[6], c[1][1],0);
    
    // combine c[0][0], c[0][1], c[1][0], c[1][1] into C
    for (int i = 0; i < sp_i; i++) {
        for (int j = 0; j < sp_i; j++) {
            C[i][j] = c[0][0][i][j];
            C[i][j + sp_i] = c[0][1][i][j];
            C[i + sp_i][j] = c[1][0][i][j];
            C[i + sp_i][j + sp_i] = c[1][1][i][j];
        }
    }
}


void main()
{	
	int n;
	int a[100][100],b[100][100],c[100][100];
	printf("Enter the size of matrix: ");
	scanf("%d",&n);
	takemat(n,a);
	takemat(n,b);
	strassen(n,a,b,c);
	printf("\nA=\n");
	printmat(n,a);
	printf("\nB=\n");
	printmat(n,b);
	printf("\nC=\n");
	printmat(n,c);
	

	
}


















