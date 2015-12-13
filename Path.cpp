#include <Path.h>

Path::Path(int i, int j)
{
  this->i = i;
  this->j = j;
  this->next = 0;
}

bool Path::move(int i, int j)
{
  if(this->i == i && this->j == j)
  {
    return false;
  }
  else if(this->next != 0)
  {
    return this->next->move(i, j);
  }
  else
  {
    this->next = new Path(i, j);
    return true;
  }
}

void Path::pop()
{
  if(this->next->next == 0)
  {
    delete this->next;
    this->next = 0;
  }
  else
  {
    this->next->pop();
  }
}
