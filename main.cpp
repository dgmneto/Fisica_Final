#include <stdio.h>
#include <string.h>
#include <Path.h>

#define QTD_DIR 4
#define LIMIT 10000

const int directions[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

double pos[] = {0, 0};

double resultados[LIMIT + 1];
int qtd_resultados[LIMIT + 1];
int limit;

Path *origin;

void processa(int n)
{
  qtd_resultados[limit - n] += 1;
  resultados[limit - n] += (pos[0]*pos[0] + pos[1]*pos[1])/qtd_resultados[limit - n] - resultados[limit - n]/qtd_resultados[limit - n];

  if(!n) return;

  for(int i = 0; i < QTD_DIR; i++)
  {
    if(origin->move(pos[0] + directions[i][0], pos[1] + directions[i][1]))
    {
      pos[0] += directions[i][0];
      pos[1] += directions[i][1];
      processa(n - 1);
      origin->pop();
      pos[0] -= directions[i][0];
      pos[1] -= directions[i][1];
    }
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  origin = new Path(0, 0);
  limit = n;
  processa(n);
  for(int i = 0; i <= n; i++) printf("%d\t%.9lf\n", i, resultados[i]);
  delete origin;
  return 0;
}
