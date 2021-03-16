#include "std_lib_facilities.h" 

class P{ 
public: 
  virtual void pvf()=0; 
  }; 
 
class B1 : public P { 
public: 
   virtual void vf() {cout<<"B1::vf"<<endl;} 
   void f() {cout<<"B1::f"<<endl;} 
   void pvf() {cout<<"B1::pvf"<<endl;} 
  }; 

class D1 : public B1 { 
public: 
    void vf() override {cout<<"D1::vf"<<endl;} 
    void f(){cout<<"D1::f"<<endl;} 
  }; 
 
class D2 : public D1 { 
public: 
    void pvf() override {cout<<"D2::pvf"<<endl;} 
  }; 

class B2{
public: 
    virtual void pvf()=0; 
  }; 
   
class D21 : public B2{ 
   string s="D21's string"; 
   void pvf() override {cout<<s<<endl;} 
  }; 

class D22 : public B2{
   int x=22; 
   void pvf() override {cout<<x<<endl;}
  };

void f(B2& b){ 
   b.pvf();
  }; 

   int main(){

     cout<<"B1"<<endl; 
     
     B1 b;
     b.vf();
     b.f();
     b.pvf(); 

     cout<<"B2"<<endl; 
     
     D1 d; 
     d.vf(); 
     d.f(); 
     d.pvf(); 

     cout<<"B1&"<<endl; 

     B1& b_ref=d; 
     b_ref.vf(); 
     b_ref.f(); 
     b_ref.pvf(); 

     cout<<"D2"<<endl; 
     
     D2 dd; 
     dd.vf(); 
     dd.f(); 
     dd.pvf(); 

     cout<<"D21"<<endl;

     D21 d21;
     f(d21);

     cout<<"D22"<<endl;

     D22 d22;
     f(d22);

 return 0;
}




