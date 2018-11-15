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
    void setMatrix(int m[9]);
    int** getMatrix();
private:
    int mat[9];
};

//MENGINISIASI CONSTRUCTOR Matrix3D
Matrix3D::Matrix3D(){
    zeros();
    }

//INISAISI 
void Matrix3D::zeros(){ //SOAL 1 ::zeros
    for(int i=0; i<9; i++)
            mat[i] = 0;
    }

void Matrix3D::setIdentity(){ //SOAL 2 ::setIdentity
    mat[0] = mat[4]= mat[8] = 1; //SOAL 3 = 1
    }

void Matrix3D::print(){ //SOAL NO 4 ::print
    cout << "[ ";
    int k=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << mat[k] << ' '; //SOAL NO 5 [j]
            k++;
            }
        cout << ';' << endl;
        }
    cout << " ]" << endl;
    }

void Matrix3D::setMatrix(int m[9]){ //SOAL NO 6 (m)
    //int m[3][3];
    for(int i=0;i<9;i++){
            mat[i]=m[i];
        }
    }
//MEMBUAT OBJECT Matrix3d DAN MENGINISIASI +
Matrix3D Matrix3D::operator+( Matrix3D _mat){ //SOAL NO 7 const Matrix3d _mat
    Matrix3D ret; //SOAL NO 8 Matrix3d
    int **matx;
    int m[9];
 
    matx = _mat.getMatrix();
    for(int i=0; i<9; i++){
           m[i] = mat[i] + matx[i];
            }
    ret.setMatrix(m);
    return ret;
    }
//MEMBUAT OBJECT Matrix3d DAN MENGINISIASI -
Matrix3D Matrix3D::operator-( Matrix3D _mat){ //SOAL NO 9 const Matrix3d _mat
    Matrix3D ret; //SOAL NO 10 Matrix3d
    int **matx;
    int m[9];
 
    matx = _mat.getMatrix();
    for(int i=0; i<9; i++){
            m[i]= mat[i] - matx[i];
            }
    ret.setMatrix(m);
    return ret;
    }
//INISIASI TRANSPOSE
void Matrix3D::transpose(){
    int m[9];
    // m = mat;
    for(int i=0; i<9; i++)
    m[i] = mat[i];
    
    for(int i=0; i<3; i++){
        int x=i;
        for(int j=0; j<3; j++){
        mat[j]=m[x];
        x+3;
        }
    }
}
//MEMBUAT OBJECT Matrix3d DAN MENGINISIASI *
Matrix3D Matrix3D::operator*(Matrix3D _mat){ //SOAL NO 15 const Matrix3d _mat
    Matrix3D ret; //SOAL NO 16 Matrix3d
    int **matx;
    int m[9];
 
    matx = _mat.getMatrix();
    m[0]=(mat[0]*matx[0])+(mat[1]*matx[3])+(mat[2]*mat[6]);
    m[1]=(mat[0]*matx[1])+(mat[1]*matx[4])+(mat[2]*mat[7]);
    m[2]=(mat[0]*matx[2])+(mat[1]*matx[5])+(mat[2]*mat[8]);
    m[3]=(mat[3]*matx[0])+(mat[4]*matx[3])+(mat[5]*mat[6]);
    m[4]=(mat[3]*matx[1])+(mat[4]*matx[4])+(mat[5]*mat[7]);
    m[5]=(mat[3]*matx[2])+(mat[4]*matx[5])+(mat[5]*mat[8]);
    m[6]=(mat[6]*matx[0])+(mat[7]*matx[3])+(mat[8]*mat[6]);
    m[7]=(mat[6]*matx[1])+(mat[7]*matx[4])+(mat[8]*mat[7]);
    m[8]=(mat[6]*matx[2])+(mat[7]*matx[5])+(mat[8]*mat[8]);

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         m[i][j] = 0;
    //             for(int k=0; k<3; k++)
    //             m[i][j] += mat[i][j] * matx[k][j];} //SOAL 17=j 18=j
    //     }
    ret.setMatrix(m);
    return ret;
    }
//INISASI 
int** Matrix3D::getMatrix(){ //SOAL 19 getMatrix
    int **ret;
    //ret = (int**) malloc (sizeof(int*)*3);
    for(int i=0; i<9; i++)
    // for(int j=0; j<3; j++)
    ret[i] = mat[i];
    return ret;
}

//MAIN PROGRAM
int main(){
Matrix3D A,B,C;
int a[9],b[9],c[9];
std::cout<<"Masukkan Matriks Pertama"<<std::endl;
for(int i=0; i<9; i++){
    // for(int j=0; j<3; j++){
        cin >> a[i];
        // }
    }
std::cout<<"Masukkan Matriks Kedua"<<std::endl;
for(int i=0; i<9; i++){
    // for(int j=0; j<3; j++){
        cin >> b[i];
        // }
    }
for(int i=0; i<9; i++){
    // for(int j=0; j<3; j++){
        c[i]=0;
        // }
    }
A.setMatrix(a);
B.setMatrix(b);
C.setMatrix(c);
// operasi penambahan matriks A dengan B dan hasilnya disimpan pada matriks C
std::cout<<"PENJUMLAHAN A+B :"<<std::endl;
C=A+B; //SOAL 20 C=A+B
C.print();
// operasi pengurangan matriks A dengan B dan hasilnya disimpan pada matriks C
std::cout<<"PENGURANGAN A-B :"<<std::endl;
C=A-B; //SOAL 21 C=A-B
C.print();
// operasi perkalian matriks A T dengan B dan hasilnya disimpan pada matriks C
std::cout<<"TRANSPOSE A^t :"<<std::endl;
A.transpose();
C=A * B; // SOAL 22 A=A.transpose(); C=A*B
C.print();
A.print(); // matriks A
B.print(); // matriks B
return 0;
}