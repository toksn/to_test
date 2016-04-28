//#include "stdio.h"
#include "Windows.h"

class I
{
public:
	virtual void Func01() = 0;
	//virtual ~I(){}
};

class A : public I
{
public:
	virtual void Func01() = 0;
	virtual void Func02() = 0;

	//~A(){}
};

class D : public A
{
public:
	virtual void Func01();
	virtual void Func02();

	//virtual ~D(){}
};

class B : public A
{
public:
	//virtual void Func01() = 0;
	virtual void Func03() = 0;
};

class C : public B, public D
{
public:
	virtual void Func01();
	virtual void Func02();
	virtual void Func03();
};


void A::Func01()
{
	int i = 1;
	OutputDebugString(L"A::Func01 called\n");
}

void D::Func01()
{
	int i = 2;
	OutputDebugString(L"D::Func01 called\n");
}

void D::Func02()
{
	int i = 3;
	OutputDebugString(L"D::Func02 called\n");
}

void C::Func03()
{
	int i = 4;
	
	OutputDebugString(L"C::Func03 called\n");
}

void C::Func01()
{
	D::Func01();
}

void C::Func02()
{
	D::Func02();
}


void testThis()
{

	C* myC = new C();
	D* myD = new D();
	if( myC ) {
		myC->Func03();
		//myC->Func01();
		myC->Func02();

		//B* myB = dynamic_cast < B* >( myC );
		B* myB = myC;
		if( myB ) {
			myB->Func01();
			myB->Func02();
			delete myB;
		}
// 
// 		A* myA = myC;
// 		if(myA)
// 		{
// 			myA->Func01();
// 		}

		//delete myC;
	}

	if(myD)
	{
		myD->Func01();

		A* myA = static_cast<A*>(myD);
		if(myA)
		{
			myA->Func01();
			delete myA;
		}
	}

	return;
}