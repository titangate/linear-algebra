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
Dmatrix Minor(const Dmatrix &Amat, const int col);
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
	cout << endl;
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

double Det(const Dmatrix &Amat){
	if (Amat.size()==2) {
		return Amat[1][1]*Amat[0][0]-Amat[0][1]*Amat[1][0];
	}
	else {
		double r = 0;
		int i = 1;
		for (unsigned int j=0;j<Amat.size();j++){
			r+=i*Amat[0][j]*Det(Minor(Amat,j));
			i*=-1;
		}
		return r;
	}
}
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect){
	for (unsigned int i=0;i<bvect.size();i++){
		Rmat[i][col]=bvect[i];
	}
	return Rmat;
}
// Replaces the column 'col' in Rmat with bvect and returns Rmat

Dmatrix Minor(const Dmatrix &Amat, const int col){
	int n = Amat.size();
	Dmatrix m;
	for (int j=0;j<n;j++){
		if (j==col)continue;
		Dvector v(n-1);
		for (int i=1;i<n;i++)
			v[i-1]=Amat[i][j];
		m.push_back(v);
	}
	
	return m;
}
	
// Gets the Minor matrix of Amat by crossing out the first row and 
// column 'col' then returns that smaller matrix

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect){
	Dvector r;
	double D = Det(Amat);
	for (unsigned int i=0;i<bvect.size();i++){
		Dmatrix Bmat = Replace(Amat,i,bvect);
		r.push_back(Det(Bmat)/D);
	}
	return r;
}
// Solves for systems of linear equations in the form Ax=b using cramer's rule 


//-------------------------------------------
int main(){

Dmatrix A;     
Dvector b,x;

A=GetA();
Display(A);
b=Getb(A.size());
x=Solvex(A,b);
Display(x);

return(0);
}
//-------------------------------------------

