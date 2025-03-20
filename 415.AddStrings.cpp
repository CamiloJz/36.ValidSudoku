#include <iostream>
#include <string> //Libreria que nos permite el manejo mas cómodo de strings
#include <algorithm> //Librería que permite invertir
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = 0, digit2 = 0;

            if (i >= 0) { //Dos if que "convierte" cada char del string en el valor asignado ascii 
                digit1 = num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                digit2 = num2[j] - '0';
                j--;
            }
            int sum = digit1 + digit2 + carry;
            result += (sum % 10) + '0';  // Guardar el dígito en la cadena
            carry = sum / 10;            // Actualizar el acarreo
        }
        reverse(result.begin(), result.end()); // Invertimos el resultado final con ayuda de la libreria algorithm
        return result;
    }
};

int main() {
    Solution solution;
    string num1 = "1325889";
    string num2 = "1026";
    cout << solution.addStrings(num1, num2) << endl;
    return 0;
}