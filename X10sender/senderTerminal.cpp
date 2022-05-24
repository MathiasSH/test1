#include <iostream> 
#include <stdio.h>  
using namespace std;  

// int main() { 
//   // Output prompt 
//   cout << "Press any key to continue..." << endl; 

//   // Set terminal to raw mode 
//   system("stty raw"); 

//   // Wait for single character 
//   char input = getchar(); 

//   // Echo input:
//   cout << "--" << input << "--";

//   // Reset terminal to normal "cooked" mode 
//   system("stty cooked"); 

//   // And we're out of here 
//   return 0; 
// }

char input = getchar();

if (AlarmAktiv == 1)
{
    cout << Du kan ikke vælge scenarie << endl;
}
else
    cout << "Vælg scenarie\n\n" << "1. Aktiver/Deaktiver Simulator og Alarm\n" << "2. Indtast kontaktperson\n" << "3. Detekter bevægelse m. alarm aktiveret\n" << "4. Detekter bevægelse m. alarm deaktiveret\n" endl;
    cin >> "" >> endl;

// valgt scenarie aktiver/deaktiver simulator og alarm
if (input =='s')
{
    cout << "scenarie aktiver/deaktiver simulator og alarm"
    send scenariesStart Scenarie 1
}
//valgt scenarie indtast kontaktperson
else if (input =='k')
{
    cout <<"scenarie indtast kontaktperson"
    send scenarieStart Scenarie 2
}
//valgt scenarie Detekter bevægelse m. alarm aktiveret
else if (input =='a')
{
    cout << "scenarie Detekter bevægelse m. alarm aktiveret\n"
    send scenarieStart Scenarie 3
}
//valgt scenarie Detekter bevægelse m. alarm deaktiveret
else if (input =='d')
{
    send scenarieStart Scenarie 4
}






cout << "--" << input << "--" endl;

