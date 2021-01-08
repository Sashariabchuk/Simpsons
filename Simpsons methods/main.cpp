/* Created by: Riabchuk */

#include <iostream>
#include <math.h>

using namespace std;

// Define the function
#define M_PI                3.14159265358979323846  /* pi */

float f(float x) { return sin(x)*sin(x)*sin(x); }

/*
 ZADANI

 Simpsonovou metodou. Sestavte program pro výpočet ysin3 x,a0,b. Program
 sestavte tak, aby bylo možno výpočet opakovat pro jiné n, pokud uživatel po skončení jednoho běhu programu odpoví na otázku, zda ve výpočtu pokračovat  ́A ́ nebo  ́a ́.
 Interval dělte postupně na 2, 4, 8, 16, 32, 64, 128 dílků.
 
 */


// Function for Simpsons methods
float simpsons_methods(float a, float b, int n, float(*funkce)(float))
{
    float h = (b - a)/n, simpsons_result = 0.0, x, integral_result;
    
    /* Calculating */
    for (int i = 0; i <= n; i++)
    {
        x = a + i * h;
        if (i == 0 || i == n)
            simpsons_result += f(x);
        else if (i % 2 != 0)
        {
            simpsons_result += 4 * f(x);
        }
        else{
            simpsons_result += 2 * f(x);
        }
        
        integral_result = simpsons_result * (h / 3);
        cout << pow(2.0, i) << " : " << integral_result << "\n";
        integral_result = 0;
    }
    simpsons_result = simpsons_result * (h / 3);
    return simpsons_result;
}
 
// Main function
int main()
{
    float n, a = 0, b = M_PI;
    char choice;
    do{
        //* Input */
        cout << "ZADEJTE HODNOTU 'n': ";
        cin >> n;
    
        //* Output */
        cout << simpsons_methods(a, b, n, f);
        
        //Repeat it while true
        cout<<"\nPOKRACOVAT VE VYPOCTECH? A/N ";
        cin>>choice;
    }while(choice == 'a' || choice == 'A');
    
    return 0;
}

/* OUTPUT */
/*
Input value of n is 7
Result is:
 ZADEJTE HODNOTU 'n': 7
 1 : 0
 2 : 0.0488777
 4 : 0.191866
 8 : 0.746374
 16 : 1.02363
 32 : 1.3096
 64 : 1.33404
 128 : 1.33404
*/
