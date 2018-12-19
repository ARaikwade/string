/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
#define init_size 1
using namespace std;

class mystring
{
  char *str;
  int iCapacity;

public:
  //constructor
    mystring ();
    mystring (const char *s);
    mystring (const mystring & s);

  //member functions
  bool empty () const;
  int size () const;
  char *data () const;
  int & capacity();
  
  //operator overloading
  bool operator==(const mystring & s);

  //destructor
   ~mystring ();
};

bool
mystring::operator==(const mystring & s)
{
    if(this->size() != s.size())
        return false;
        
    else
    {
        for(int i = 0; i < size; i++)
        {
            if(this->str[i] != s.str[i])
            break;
        }
        if(str[i] == '\0')
        return true
    }
    return false
}
mystring::mystring ()
{
  iCapacity = init_size;
  str = new char[iCapacity];
  *str = '\0';
}

mystring::mystring (const char *s)
{
  iCapacity = strlen (s) + 1;
  str = new char[iCapacity];
  strcpy (this->str, s);
}

mystring::mystring (const mystring & s)
{
  if (!s.empty ())
    {
      this->iCapacity = s.size () + 1;
      this->str = new char[this->iCapacity];
      memset (this->str, 0, iCapacity);
      memcpy (this->str, s.data (), this->iCapacity);
    }
}

mystring::~mystring ()
{
  delete this->str;
}

int
mystring::size () const
{
  int i = 0;
  for (; str[i]; i++);
  return i;
}

bool
mystring::empty () const
{
  if (str[0] == '\0')
    return true;
  else
    return false;
}

char *
mystring::data () const
{
  return this->str;
}

int & 
mystring::capacity()
{
    return iCapacity;
}


int
main ()
{

  mystring q;
  cout << "size = " << q.size () << endl;
  cout << "empty = " << q.empty () << endl;
  cout << "data = " << q.data () << endl;

  mystring p ("abc");
  cout << "size = " << p.size () << endl;
  cout << "empty = " << p.empty () << endl;
  cout << "data = " << p.data () << endl;
  p.capacity() = 10;
  cout << "capacity = " << p.capacity () << endl;

  mystring r (p);
  cout << "size = " << r.size () << endl;
  cout << "empty = " << r.empty () << endl;
  cout << "data = " << r.data () << endl;
}

