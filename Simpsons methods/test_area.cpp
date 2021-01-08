#include<stdio.h>
#include <iostream>
#include<math.h>

/* Define function here */
#define f(x) 1/(1+x*x)

int maind()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;
 /* Input */
 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &subInterval);

 /* Calculation */
 /* Finding step size */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);
 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;
  if(i%2==0)
  {
   integration = integration + 2 * f(k);
  }
  else
  {
   integration = integration + 4 * f(k);
  }
     std::cout << pow(2.0, i) << ":" << integration << "\n";
 }
 integration = integration * stepSize/3;
 printf("\nRequired value of integration is: %.3f", integration);
 return 0;
}
