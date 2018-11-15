#include<bits/stdc++.h>
using namespace std;
//CLASS Matrix3D
class Matrix3D{
public:
    Matrix3D();
    Matrix3D operator+(const Matrix3D _mat);
    Matrix3D operator-(const Matrix3D _mat);
    Matrix3D operator*(const Matrix3D _mat);
    void zeros();
    void print(); //ok
    void transpose();
    void setIdentity(); //ok
    void setMatrix(int m[3][3]);
    int** getMatrix();
private:
    int mat[3][3];
};

//MENGINISIASI CONSTRUCTOR Matrix3D
Matrix3D::Matrix3D(){
    zeros();
    }

//INISAISI 
void Matrix3D::zeros(){ //SOAL 1 ::zeros
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            mat[i][j] = 0;
    }

void Matrix3D::setIdentity(){ //SOAL 2 ::setIdentity
    mat[0][0] = mat[1][1] = mat[2][2] = 1; //SOAL 3 = 1
    }

void Matrix3D::print(){ //SOAL NO 4 ::print
    cout << "[ ";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << mat[i][j] << ' '; //SOAL NO 5 [j]
            }
        cout << ';' << endl;
        }
    cout << " ]" << endl;
    }
void Matrix3D::setMatrix(int m[3][3]){ //SOAL NO 6 (m)
    //int m[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mat[i][j]=m[i][j];
            }
        }
    }
//MEMBUAT OBJECT Matrix3d DAN MENGINISIASI +
Matrix3D Matrix3D::operator+( Matrix3D _mat){ //SOAL NO 7 const Matrix3d _mat
    Matrix3D ret; //SOAL NO 8 Matrix3d
    int **matx;
    int m[3][3];
 
    matx = _mat.getMatrix();
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           m[i][j] = mat[i][j] + matx[i][j];
            }
        }
    ret.setMatrix(m);
    return ret;
    }
//MEMBUAT OBJECT Matrix3d DAN MENGINISIASI -
Matrix3D Matrix3D::operator-( Matrix3D _mat){ //SOAL NO 9 const Matrix3d _mat
    Matrix3D ret; //SOAL NO 10 Matrix3d
    int **matx;
    int m[3][3];
 
    matx = _mat.getMatrix();
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m[i][j] = mat[i][j] - matx[i][j];
            }
        }
    ret.setMatrix(m);
    return ret;
    }
//INISIASI TRANSPOSE
void Matrix3D::transpose(){
    int m[3][3];
    // m = mat;
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    m[i][j] = mat[i][j];
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
        mat[i][j] = m[j][i]; //SOAL 11=i 12=j 13=j 14=i
        }
    }
}
//MEMBUAT OBJECT Matrix3d DAN MENGINISIASI *
Matrix3D Matrix3D::operator*(Matrix3D _mat){ //SOAL NO 15 const Matrix3d _mat
    Matrix3D ret; //SOAL NO 16 Matrix3d
    int **matx;
    int m[3][3];
 
    matx = _mat.getMatrix();
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m[i][j] = 0;
                for(int k=0; k<3; k++)
                m[i][j] += mat[i][j] * matx[k][j];} //SOAL 17=j 18=j
        }
    ret.setMatrix(m);
    return ret;
    }
//INISASI 
int** Matrix3D::getMatrix(){ //SOAL 19 getMatrix
    int **ret;
    //ret = (int**) malloc (sizeof(int*)*3);
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    ret[i][j] = mat[i][j];
    return ret;
}

//MAIN PROGRAM
int main(){
Matrix3D A,B,C;
int a[3][3],b[3][3],c[3][3];

for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cin >> a[i][j];
        }
    }
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cin >> b[i][j];
        }
    }
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        c[i][j]=0;
        }
    }
A.setMatrix(a);
B.setMatrix(b);
C.setMatrix(c);
// operasi penambahan matriks A dengan B dan hasilnya disimpan pada matriks C
//C=A+B; //SOAL 20 C=A+B
C.print();
// operasi pengurangan matriks A dengan B dan hasilnya disimpan pada matriks C
//C=A-B; //SOAL 21 C=A-B
C.print();
// operasi perkalian matriks A T dengan B dan hasilnya disimpan pada matriks C
A.transpose();
//C=A * B; // SOAL 22 A=A.transpose(); C=A*B
C.print();
A.print(); // matriks A
B.print(); // matriks B
return 0;
}