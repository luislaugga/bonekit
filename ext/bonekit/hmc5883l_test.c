#include "hmc5883l.h"
#include <stdio.h>

int main()
{
  hmc5883l_t hmc5883l;
  
  hmc5883l_init(&hmc5883l);
  
  while(1)
  {
    double heading = hmc5883l_heading(&hmc5883l);
    printf("Heading %f\n", heading);
    usleep(100*1000);
  }
  
  return 0;
}
