#include "Vector.h"
#include <iostream>
#include <complex>

using namespace std;

//constructor
Vector::Vector()
{
	fDimension=2;
	this->initialize(fDimension);
	allocSize=0;
}

Vector::Vector(int dimension)
{
	this->initialize(dimension);
	fDimension=dimension;
	allocSize=0;
}

Vector::Vector(int size, const double elements[])
{
	fDimension=size;
	this->initialize(fDimension);
	for(allocSize=0;allocSize<fDimension;++allocSize)
	{
		fElements[allocSize]=elements[allocSize];
	}
}

Vector::Vector(const Vector &source)
{
	fDimension=source.fDimension;
	this->initialize(fDimension);
	for(allocSize=0;allocSize<fDimension;++allocSize)
		fElements[allocSize]=source.fElements[allocSize];
}

//destructor
Vector::~Vector()
{
	delete [] fElements;
}

int 
Vector::getDimension() const
{
	return fDimension;
}

void 
Vector::setDimension(int dimension)
{
	if(dimension<fDimension)
	{
		double *a=new double[fDimension];
		for(int i=0;i<fDimension;++i)
			a[i]=fElements[i];
		this->initialize(dimension);

		for(int i=0;i<dimension;++i)
			fElements[i]=a[i];

		delete [] a;
		if(allocSize>=dimension)
			allocSize=dimension-1;
		fDimension=dimension;
	}

	else if(dimension>fDimension)
	{
		double *a=new double[fDimension];
		for(int i=0;i<fDimension;++i)
			a[i]=fElements[i];
		this->initialize(dimension);

		for(int i=0;i<fDimension;++i)
			fElements[i]=a[i];

		delete [] a;
		fDimension=dimension;
	}
}

void 
Vector::initialize(int size)
{
	fElements=new double[size]();
}

Vector &Vector::operator=(const Vector &v2)
{
	if(this==&v2)
		return *this;
	this->setDimension(v2.fDimension);
	for(int i=0;i<fDimension;++i)
		fElements[i]=v2.fElements[i];
	return *this;
}

double &Vector::operator[] (int index)
{
	double tmp=0;
	double &err=tmp;
	if(index>=0 && index<fDimension)
	{
		return fElements[index];
	}
	cout<<"Array index out of bound, exiting\n";
	return err;
}

double Vector::operator[] (int index) const
{
	if(index>=0 && index<fDimension)
	{
		return fElements[index];
	}
	cout<<"Array index out of bound, exiting\n";
	return 0;
}

Vector Vector::operator+ (const Vector &v2) const
{
//	if(v2.fDimension>fDimension)
//	{
//		double sum[v2.fDimension];
//		for(int i=0;i<fDimension;++i)
//			sum[i]=fElements[i]+v2.fElements[i];
//		for(int i=fDimension;i<v2.fDimension;++i)
//			sum[i]=v2.fElements[i];
//		Vector result(v2.fDimension,&sum[0]);
//		return result;
//	}
//	else if(fDimension>=v2.fDimension)
//	{
		double sum[fDimension];
		for(int i=0;i<v2.fDimension;++i)
			sum[i]=v2.fElements[i]+fElements[i];
//		for(int i=v2.fDimension;i<fDimension;++i)
//			sum[i]=fElements[i];
		Vector result(v2.fDimension,&sum[0]);
		return result;
//	}
}

Vector &Vector:: operator+= (const Vector &v2)
{
//	if(v2.fDimension>=fDimension)
//	{
		for(int i=0;i<fDimension;++i)
			fElements[i]+=v2.fElements[i];
//	}
//	else if(fDimension>v2.fDimension)
//	{
//		for(int i=0;i<v2.fDimension;++i)
//			fElements[i]+=v2.fElements[i];
//	}
	return *this;
}

Vector Vector::operator- (const Vector &v2) const
{
//	if(v2.fDimension>fDimension)
//	{
//		double sum[v2.fDimension];
//		for(int i=0;i<fDimension;++i)
//			sum[i]=fElements[i]-v2.fElements[i];
//		for(int i=fDimension;i<v2.fDimension;++i)
//			sum[i]=0-v2.fElements[i];
//		Vector result(v2.fDimension,&sum[0]);
//		return result;
//	}
//	else if(fDimension>=v2.fDimension)
//	{
		double sum[fDimension];
		for(int i=0;i<v2.fDimension;++i)
			sum[i]=fElements[i]-v2.fElements[i];
///		for(int i=0;i<fDimension;++i)
//			sum[i]=fElements[i];
		Vector result(fDimension,&sum[0]);
		return result;
//	}
}

Vector &Vector:: operator-= (const Vector &v2)
{
//	if(v2.fDimension>=fDimension)
//	{
		for(int i=0;i<fDimension;++i)
			fElements[i]-=v2.fElements[i];
//	}
//	else if(fDimension>v2.fDimension)
//	{
//		for(int i=0;i<v2.fDimension;++i)
//			fElements[i]-=v2.fElements[i];
//	}
	return *this;
}

Vector Vector::operator- ()
{
	for(int i=0;i<fDimension;++i)
		fElements[i]*=-1;
	return *this;
}

Vector Vector::operator* (double scale)
{
	double sum[fDimension];
	for(int i=0;i<fDimension;++i)
		sum[i]=fElements[i]*scale;
	Vector result(fDimension,&sum[0]);
	return result;
}

Vector operator*(double scale, Vector v)
{
	return v*scale;
//	double *sum=new double(this->fDimension);
//	for(int i=0;i<this->fDimension;++i)
//		sum[i]=this->fElements[i]*scale;
//	Vector result(this->fDimension,sum);
//	delete [] sum;
//	return result;
}

Vector &Vector::operator*= (double scale)
{
	for(int i=0;i<fDimension;++i)
		fElements[i]*=scale;
	return *this;
}

bool Vector::operator== (const Vector &v2) const
{
	if(v2.fDimension!=fDimension)
		return false;
	for(int i=0;i<fDimension;++i)
	{
		if(v2.fElements[i]!=fElements[i])
			return false;
	}
	return true;
}

bool Vector::operator!= (const Vector &v2) const
{
	if(v2.fDimension!=fDimension)
		return true;
	for(int i=0;i<fDimension;++i)
	{
		if(v2.fElements[i]!=fElements[i])
			return true;
	}
	return false;
}

double 
Vector::length() const
{
	double len=0;
	for(int i=0;i<fDimension;++i)
		len+=(fElements[i]*fElements[i]);
	return sqrt(len);
}

ostream & operator << (ostream &os, const Vector &v)
{
	os<<"(";
	for(int i=0;i<v.fDimension-1;++i)
		os<<v.fElements[i]<<", ";
	os<<v.fElements[v.fDimension-1]<<")";
	return os;
}
