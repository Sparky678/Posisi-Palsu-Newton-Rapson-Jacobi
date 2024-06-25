#include<iostream>
#include<iomanip>
#include<math.h>


/* In this example we are solving
   20x + y - 2z = 17
   3x + 20y - z = -18
   2x - 3y + 20z = 25

   4x - y - z = 3
   -2x + 6y + z = 9
   -x + y + 7z -6
*/

// /* Defining function */
// #define f1(x,y,z)  (17-y+2*z)/20
// #define f2(x,y,z)  (-18-3*x+z)/20
// #define f3(x,y,z)  (25-2*x+3*y)/20


#define f1(x,y,z)  (3+y+z)/4
#define f2(x,y,z)  (9+2*x-z)/6
#define f3(x,y,z)  (-6+x-y)/7

using namespace std;

/* Main function */
int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int step=1;

 /* Setting precision and writing floating point values in fixed-point notation. */
 cout<< setprecision(6)<< fixed;

 /* Input */
 /* Reading tolerable error */
 cout<<"Enter tolerable error: ";
 cin>>e;

 cout<< endl<<"Count\tx\t\ty\t\tz\t\te1\t\te2\t\te3"<< endl;
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x0,y0,z0);
  z1 = f3(x0,y0,z0);
  

  /* Error */
  e1 = fabs((x0-x1)*100/x0);
  e2 = fabs((y0-y1)*100/y0);
  e3 = fabs((z0-z1)*100/z0);

  cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< "\t"<< e1<<"\t"<< e2<<"\t"<< e3<< endl;
  step++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e || e2>e || e3>e);

 cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;
 return 0;
}