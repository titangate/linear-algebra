// Mr. Arkiletian ICTP 12
// Simultaneous linear equation assignment (2 team members)
// Solved using the STL generic vector container class 
// I added something for fun

#include <iostream>
#include <vector>
#include <cmath> // for pow function

using namespace std;

typedef vector <double> Dvector;
typedef vector <Dvector> Dmatrix;

// Prototypes (variable names included, but not needed)
// DO NOT change any prototypes!! NO other functions allowed.

Dmatrix GetA(){
	Dmatrix m(3);
	for (int i=0;i<3;i++)
	{
		Dvector v(3);
		for (int j=0;j<3;j++)
			cin>>v[j];
		m[i]=v;
	}
	return m;
}
// gets the matrix A from the user and returns it

Dvector Getb(const int &siz){
	Dvector v(siz);
	for (int j=0;j<siz;j++)
		cin>>v[j];
	return v;
}
// gets the vector b from the user and returns it

void Display(const Dvector &xvect){
	for (Dvector::const_iterator i=xvect.begin();i!=xvect.end();i++){
		cout << *i<<'\t';
	}
}
// displays the contents of vector xvect

void Display(const Dmatrix &Amat){
	for (Dmatrix::const_iterator xvect=Amat.begin();xvect!=Amat.end();xvect++){
		for (Dvector::const_iterator i=xvect->begin();i!=xvect->end();i++){
			cout << *i<<'\t';
		}
		cout << endl;
	}
}

// displays the contents of matrix Amat (Note: Display function is overloaded)

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect);
// Solves for systems of linear equations in the form Ax=b using cramer's rule 

double Det(const Dmatrix &Amat);
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect);
// Replaces the column 'col' in Rmat with bvect and returns Rmat

Dmatrix Minor(const Dmatrix &Amat, const int col){
	int n = Amat.size();
	Dmatrix m(n-1);
	for (int i=0;i<col;i++){
		Dvector v(n-1);
		for (int j=1;j<n;j++)
			v[j-1]=Amat[i][j];
		m[i]=v;
	}
	return m;
}
	
// Gets the Minor matrix of Amat by crossing out the first row and 
// column 'col' then returns that smaller matrix


//-------------------------------------------
int main(){

Dmatrix A;     
Dvector b,x;

A=GetA();
Display(A);
b=Getb(A.size());
Display(b);
Display(Minor(A,1));
//x=Solvex(A,b);
//Display(x);

return(0);
}
//-------------------------------------------

