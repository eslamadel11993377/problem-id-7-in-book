#include <iostream>
#include<bits/stdc++.h>
#include <cassert>


using namespace std;


struct matrix
{
  int* data;
  int row, col;


matrix operator+  (matrix mat2){
    assert((row == mat2.row) && (col == mat2.col));
    matrix mat3;
    mat3.row=row;
    mat3.col=col;
    mat3.data = new int [row * col];
    for (int i = 0; i < row*col; i++){
        mat3.data[i]=data[i]+data[i];
    }
    return mat3;
    }

 matrix operator-  (matrix mat2){
    assert((row == mat2.row) && (col == mat2.col));
    matrix mat4;
    mat4.row=row;
    mat4.col=col;
    mat4.data = new int [row * col];

    for (int i = 0; i < row*col; i++){

        mat4.data[i]=data[i]-mat2.data[i];
    }
    return mat4;
 }
 matrix operator*  (matrix mat2)
 {
    assert((col == mat2.row));
     matrix mat4;
     mat4.row=row;
     mat4.col=mat2.col;
     mat4.data = new int [row * mat2.col];
     for (int i = 0; i < row; i++) {
        for (int j = 0; j < mat2.col; j++) {
            float sum = 0.0;
            for (int k = 0; k < mat2.row; k++)
                sum = sum + data[i * col + k] * mat2.data[k * mat2.col + j];
            mat4.data[i * mat4.col + j] = sum;
        }
    }

    return mat4;
 }

 matrix operator+  (int scalar){
    matrix mat4;
    mat4.row=row;
    mat4.col=col;
    mat4.data = new int [row * col];

    for (int i = 0; i < row*col; i++){

        mat4.data[i]=data[i]+scalar;
    }
    return mat4;
 }
 matrix operator-  (int scalar){
     matrix mat4;
    mat4.row=row;
    mat4.col=col;
    mat4.data = new int [row * col];
    for (int i = 0; i < row*col; i++){

        mat4.data[i]=data[i]-scalar;
    }
    return mat4;
 }

  matrix operator* (int scalar){
    matrix mat4;
    mat4.row=row;
    mat4.col=col;
    mat4.data = new int [row * col];
    for (int i = 0; i < row*col; i++){

        mat4.data[i]=data[i]*scalar;

    }
    return mat4;
 }


//20170047


 matrix operator+= (matrix mat2){
    assert((row == mat2.row) && (col == mat2.col));
    for (int i = 0; i < row*col; i++){

        data[i]=data[i]+mat2.data[i];

    }
    return *this;
 }

 matrix operator-= (matrix mat2){
    assert((row == mat2.row) && (col == mat2.col));
    for (int i = 0; i < row*col; i++){

        data[i]=data[i]-mat2.data[i];

    }
    return *this;
 }

 matrix operator+= (int scalar){

    for (int i = 0; i < row*col; i++){

        data[i]=data[i]+scalar;
    }
    return *this;
 }

 matrix operator-= (int scalar){

    for (int i = 0; i < row*col; i++){

        data[i]=data[i]-scalar;

    }
    return *this;
 }

 void operator++ (){

    for (int i = 0; i < row*col; i++){

        data[i]=data[i]+1;
    }
 }
  void operator-- (){

    for (int i = 0; i < row*col; i++){

        data[i]=data[i]-1;
    }
 }

 friend istream& operator >> (istream& in, matrix & mat)
{
        in>>mat.row>>mat.col;
        for (int i = 0; i < mat.row*mat.col; i++){

            in>>mat.data[i];
        }
        return in;
}

//20170019

friend ostream& operator<< (ostream& out, matrix mat)
{
        for (int i = 0; i < mat.row*mat.col; i++){
                if(i%mat.col==0)
                {
                    cout<<endl;
                }
            out<<mat.data[i]<<" ";

        }
        return out;
}

 bool   operator== ( matrix mat2)
 {
     for(int i=0;i<row*col;i++)
     {
         if(data[i]==mat2.data[i])
            return true;
         else
            return false;
     }
 }
  bool   operator!= ( matrix mat2)
 {
     for(int i=0;i<row*col;i++)
     {
         if(data[i]!=mat2.data[i])
            return true;
         else
            return false;
     }
 }

 bool   isSquare   ()
  {
      if(row== col)
        return true;
      else
        return false;
  }


bool   isSymetric ()
{
    if(row==col)
    {
    matrix mat4;
    mat4.col=row;
    mat4.row=col;
    mat4.data = new int [row * col];
    int u=0,temp=0,p=0,i=0,o=0;

    while (u<col){
        u;
        for(i=u ; i<col*row;i+=col){
                mat4.data[p]=data[i];
                p++;
        }
        u++;
    }
    for(i=0;i<row*col;i++)
    {
        if(data[i]!=mat4.data[i])o++;}
        if(o==0)
            return true;
        else
            return false;
    }


    else
        return false;
}

bool isidentity ()
 {
      if(row== col)
     {
         int c=0,b=0;
     for(int i=0;i<row*col;i+=col+1)
     {
         if(data[i]!=1)c++;

     }
     for(int i=0;i<row*col;i++)
     {
         if (i%(col+1)==0)continue;

         else if(data[i]!=0)b++;
     }
     if (c==0 && b==0)return true;
     else return false;
 }
 else
    return false;

     }

matrix transpose (){
   matrix mat4;
    mat4.col=row;
    mat4.row=col;
    mat4.data = new int [row * col];
    int u=0,temp=0,p=0,i=0;

    while (u<col){
        u;
        for(i=u ; i<col*row;i+=col){
                mat4.data[p]=data[i];
                p++;
        }
        u++;
    }

    return mat4;
  }



};


void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int [row * col];
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}




int main()
{
  int scalar;
  int data1 [] = {10,20,30,40,50,60};
  int data2 [] = {1,2,3,4};
  int data3 [] = {5,2,3,4,5,6};
  int data4 [] = {10,20,30,40,50,60};
  int data5 [] = {10,20,30,40,50,60};
  int data6 [] = {1,0,0,5,1,0,0,0,1};
  matrix mat1, mat2, mat3 ,mat4,mat5,mat6;
  createMatrix (2, 3 ,data1, mat1);
  createMatrix (3, 2, data2, mat2);
  createMatrix (2, 3, data3, mat3);
  createMatrix (2, 3, data4, mat4);
  createMatrix (2, 3, data5, mat5);
  createMatrix (3, 3, data6, mat6);


  cout<<"mat1 = "<<endl<<mat1<<endl;
  cout<<"mat2 = "<<endl<<mat2<<endl;
  cout<<"mat3 = "<<endl<<mat3<<endl;

  //20170010

  cout<<"mat1+mat3 = "<<endl<<(mat1+mat3)<<endl;
  cout<<"mat3+mat3 = "<<endl<<(mat3+mat3)<<endl;
  cout<<"mat1-mat3 = "<<endl<<(mat1-mat3)<<endl;
  cout<<"mat1*mat2 = "<<endl<<(mat1*mat2)<<endl;
  cout<<"mat1+5 = "<<endl<<(mat1+5)<<endl;
  cout<<"mat1-5 = "<<endl<<(mat1+5)<<endl;
  cout<<"mat1*5 = "<<endl<<(mat1*5)<<endl;



  //20170047

  cout<<"mat1+=mat3 = "<<endl<<(mat1+=mat3)<<endl;
  cout<<"mat1-=mat3 = "<<endl<<(mat1-=mat3)<<endl;
  cout<<"mat1+=10 = "<<endl<<(mat1+=10)<<endl;
  cout<<"mat1-=10 = "<<endl<<(mat1-=10)<<endl;
  ++mat1;
  cout<<"++mat1 = "<<endl<<mat1<<endl;
  --mat1;
  cout<<"--mat1 = "<<endl<<mat1<<endl;
  /*cin>>mat1;
  cout<<mat1;*/
  cout<<endl;


//20170019

  cout<<"Is mat4==mat5 ? = "<<(mat4==mat5)<<endl;
  cout<<"Is mat1==mat3 ? = "<<(mat1==mat3)<<endl;
  cout<<"Is mat1!=mat3 ? = "<<(mat1!=mat3)<<endl;
  cout<<"Is mat4!=mat5 ? = "<<(mat4!=mat5)<<endl;
  cout<<"Is mat6 Square ? = "<<(mat6.isSquare())<<endl;
  cout<<"Is mat1 Square ? = "<<(mat1.isSquare())<<endl;

  cout<<"Is mat6 Symmetric ? = "<<(mat6.isSymetric())<<endl;
  cout<<"Is mat1 Symmetric ? = "<<(mat1.isSymetric())<<endl;
  cout<<"Is mat6 Identity ? = "<<(mat6.isidentity())<<endl;
  cout<<"Is mat1 Identity ? = "<<(mat1.isidentity())<<endl;
  cout<<"The transpose for mat1 == "<<endl<<mat1.transpose()<<endl;

    return 0;
}
