

class I
{
public:
	virtual void Func01() = 0;
};

class A : public I
{
public:
	virtual void Func01() = 0;
};

class D : public virtual A
{
public:
	virtual void Func01();
	virtual void Func02();
};

class B : public virtual A
{
public:
	virtual void Func03() = 0;
};

class C : public D, public B
{
public:
	virtual void Func03();
};

void testThis()
{

	C* myC = new C();
	if( myC ) {
		myC->Func03();
		myC->Func01();

		//B* myB = dynamic_cast < B* >( myC );
		B* myB = myC;
		if( myB ) {

			myB->Func01();
			delete myB;
		}

		delete myC;
	}
}