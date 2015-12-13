#ifndef PATH_H
#define PATH_H

class Path
{
public:
  Path(int i, int j);
  bool move(int i, int j);
  void pop();
protected:
  int i, j;
  Path *next;
};
#endif
