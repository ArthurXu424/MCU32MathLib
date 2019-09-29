#include <stdio.h>
#include "include/tools/matrix.h"

#define TEST(FUNCTION_NAME)
void printLine()
{
	printf("**************************\n");
}
void printMatrix(const Matrix* mat)
{
	int i,j;
	for(i = 0; i < mat->rows; i++){
		for(j = 0; j < mat->cols ; j++){
			printf("%5.2f  ",mat->data[i*mat->cols + j]);
		}
		printf("\n");
	}
	printf("\n");
}

TEST(createMatrix);
void create()
{
	printLine();
	printf("����һ��3x3�ľ���:\n");
	float data3X3[] = {
		1.0,2.0,3.0,
		4.0,5.0,6.0,
		7.0,8.0,9.0
	};
	Matrix mat = createMatrix(3,3,data3X3);
	printMatrix(&mat);
}


TEST(inverse);
void inv(){
	printLine();
	printf("�Ծ���A�������:\n");
	float data4X4[] = {
	 1  ,   2 ,    3  ,   4,
     5  ,   5 ,    6  ,   7,
     8  ,   9 ,   10  ,  11,
    12  ,  13 ,    2  ,   5
	};
	float out4X4[16];
	Matrix A = createMatrix(4,4,data4X4);
	Matrix iA = createMatrix(4,4,out4X4);
	inverse(&iA,&A);
	
	printf("����A:\n");
	printMatrix(&A);
	printf("����A�������:\n");
	printMatrix(&iA);
}

TEST(det);
void detMatrix()
{
	printLine();
	printf("�Ծ���A������ʽ��ֵ:\n");
	float data4X4[] = {
	 1  ,   2 ,    3  ,   4,
     5  ,   5 ,    6  ,   7,
     8  ,   9 ,   10  ,  11,
    12  ,  13 ,    2  ,   5
	};
	Matrix A = createMatrix(4,4,data4X4);
	float detA;
	det(&detA,&A);
	
	printf("����A:\n");
	printMatrix(&A);	
	printf("det(A) = %f\n",detA);
}

TEST(transpose)
void trans()
{
	printLine();
	printf("�����A��ת��:\n");
	
	float data2X3[] = {
		2.0,4.0,2.5,
		3.5,6.0,8.0
	};
	float data3X2[6];
	Matrix A = createMatrix(2,3,data2X3);
	Matrix AT = createMatrix(3,2,data3X2);
	transpose(&AT,&A); 
	
	printf("����A:\n");
	printMatrix(&A);
	printf("����ת��:\n");
	printMatrix(&AT);
}

TEST(mul);
void matrixMul()
{
	printLine();
	printf("�����A�����B���˷��Ľ��:\n");
	
	float data2X3[] = {
		2.0,4.0,
		2.5,3.5,
		6.0,8.0
	};
	
	float data3X2[] = {
		2.0,4.0,5.0,
		1.0,3.0,7.0
	};
	
	float data2X2[4];
	
	Matrix A = createMatrix(2,3,data2X3);
	Matrix B = createMatrix(3,2,data3X2);
	Matrix result = createMatrix(2,2,data2X2);
	
	mul(&result,&A,&B);
	
	printf("����A:\n");
	printMatrix(&A);
	printf("����B:\n");
	printMatrix(&B);
	printf("A*B:\n");
	printMatrix(&result);
}

TEST(mulConst)
void matrixMulConst()
{
	printLine();
	printf("�����A���Գ���:\n");
	
	float data2X3[] = {
		2.0,4.0,2.5,
		3.5,6.0,8.0
	};
	float rdata2X3[6];
	Matrix A = createMatrix(2,3,data2X3);
	Matrix result = createMatrix(2,3,rdata2X3);
	mulConst(&result,&A,5); 
	printf("����:5\n\n");
	printf("����A:\n");
	printMatrix(&A);
	printf("������:\n");
	printMatrix(&result);
}

TEST(add)
void matrixPlus()
{
	printLine();
	printf("�����A�����B�ĺ�:\n");
	
	float dataA[] = {
		1.0,2.0,3.0,
		4.0,5.0,6.0,
		7.0,8.0,9.0
	};
	
	float dataB[] = {
		9.0,8.0,7.0,
		6.0,5.0,4.0,
		3.0,2.0,1.0
	};
	
	float data3X3[9];
	
	Matrix A = createMatrix(3,3,dataA);
	Matrix B = createMatrix(3,3,dataB);
	Matrix result = createMatrix(3,3,data3X3);
	add(&result,&A,&B);
	
	printf("����A:\n");
	printMatrix(&A);
	printf("����B:\n");
	printMatrix(&B);
	printf("������:\n");
	printMatrix(&result);
}

TEST(cloneMatrix)
void copy()
{
	float dataA[] = {
		1.0,2.0,3.0,
		4.0,5.0,6.0,
		7.0,8.0,9.0
	};
	float data3X3[9];
	Matrix mat = createMatrix(3,3,dataA);
	Matrix clone = createMatrix(3,3,data3X3);
	cloneMatrix(&clone,&mat);
}

TEST(matrixGet)
TEST(matrixSet)
void setterAndGetter()
{
	float dataA[] = {
		1.0,2.0,3.0,
		4.0,5.0,6.0,
		7.0,8.0,9.0
	};
	Matrix A = createMatrix(3,3,dataA);
	float n = matrixGet(&A,1,2);
	matrixSet(&A,1,1,3.0);
}

TEST(submatrix)
void sub()
{
	printLine();
	printf("�����A���Ӿ���(��2�е���3�У���3�е���3��):\n");
	
	float dataA[] = {
		1.0,2.0,3.0,
		4.0,5.0,6.0,
		7.0,8.0,9.0
	};
	float data2X1[2];
	Matrix A = createMatrix(3,3,dataA);
	Matrix sub = createMatrix(2,1,dataA);
	// �� : �� 1 ��ʼ ������ 3
	// �� : �� 2 ��ʼ ������ 3 
	submatrix(&sub,&A,1,3,2,3);
	
	printf("����A:\n");
	printMatrix(&A);
	printf("�Ӿ���:\n");
	printMatrix(&sub);
}
/*
int main(){
	
	//��δ������� 
	create();
	//��ζԾ�������
	inv(); 
	//���������ʽ��ֵ 
	detMatrix();
	//���ת�� 
	trans();
	//���������˻� 
	matrixMul();
	//�����������Գ��� 
	matrixMulConst(); 
	//���������ӷ�
	matrixPlus();
	//��θ��ƾ��� 
	copy(); 
	//���ȡ�������þ����ĳһ��ĳһ��ֵ 
	setterAndGetter();
	//���ȡ�Ӿ���
	sub();
	
	return 0;	
}
*/
