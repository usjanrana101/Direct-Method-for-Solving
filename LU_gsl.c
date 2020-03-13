#include <stdio.h>
#include <gsl/gsl_linalg.h>
int main()
{
	/* This code generates LU Decompositon of a given matrix A
	   i.e PA=LU , P=Permutation Matrix */
	double matrix-data[]= {1.0, 0.67,0.33,0.45,1.0,0.55,0.67,0.33,1.0};

	gsl_matrix_view A= gsl_matrix_view_array(matrix-data,3,3); //3*3 matrix view of the given data
	gsl_permutation *p= gsl_permutation_alloc(3); // allocation of memory for permutation matrix P

	int signum,i,j,k;
    double L[3][3],U[3][3],store[3][3],LU[3][3],PA[3][3];

    for ( i = 0; i < 3; i++)
    {
    	/* To store the A matrix for verification of PA=LU
    	    as during LU decomp A is changing to get the final
    	      compact form */
    	for (j = 0; j < 3; j++)
    	{
    		store[i][j]=gsl_matrix_get(&A.matrix,i,j); // That's how A[i][j] is accsesed
    	}
    }
    gsl_linalg_LU_decomp(&A.matrix,p, &signum); //LU decomposition using gsl function
    
    printf("U= \n");
    for ( i = 0; i < 3; i++)
    {
    	/* As after using the previous gsl funtion A is modified to compact
    	   LU form ; this is the loop for extraction of U from it , where U is 
    	   the upper half element with diagonal same as of modified compact A
    	   */
    	for (j = 0; j < 3; j++)
    	{
    		if (i<=j)
    		{
    			printf("%g ",U[i][j]=gsl_matrix_get(&A.matrix,i,j));
    		}
    		else
    			printf("%g ",U[i][j]=0);
    	}
    	printf("\n");
    }
    printf("L= \n");
    for ( i = 0; i < 3; i++)
    {
    	/* This is the loop for extraction of L from it , where L is 
    	   the Lower half element as of modified compact A and with diagonal =1 
    	   */
    	for (j = 0; j < 3; j++)
    	{
    		if (i>j)
    		{
    			printf("%g ",L[i][j]=gsl_matrix_get(&A.matrix,i,j));
    		}
    		else if (i==j)
    			printf("%g ",L[i][j]=1);
    		else
    			printf("%g ",L[i][j]=0);
    	}
    	printf("\n");
    }
    printf("LU= \n");
    for ( i = 0; i < 3; i++)
    {
    	/* multiplication of L and U
    	   */
    	for (k = 0; k < 3; k++)
    	{
    		LU[i][k]=0;
    		for ( j = 0; j < 3; j++)
    		{
    			printf("%g  ",LU[i][k]=LU[i][k]+L[i][j]*U[j][k]); // multiplication rule of two matrix
    		}
    	}
    	printf("\n");
    }
    printf("PA= \n");
    for ( i = 0; i < 3; i++)
    {
    	/* PA means doing the same operation on A ,indicated by p
    	   suppose p=(1,0,2) i.e PA = A but row 1 and 2 being swapped
    	   this operation is done on this loop
    	   */
    	for (j = 0; j < 3; j++)
    	{
    		printf("%g ",PA[i][j]=store[gsl_permutation_get(p,i)][j]);
    	}
    	printf("\n");
    }
    gsl_permutation_free(p); // free the allocated memory by p
	return 0;
}
