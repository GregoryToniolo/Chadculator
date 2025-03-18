//objetcives: square roots, remainder, 4 basic operations, exponentiation, all prime divisors, a function to check wether a number is prime, greatest common divisor,
//least common multiple
//rules: only allowed to use operations you have already created

#include <iostream>
using namespace std;

//adds 1 to a b amount of times
//then returns a as the result
//add negative number support
int addition(int a, int b)
{
  for (int i = 0; i < b; i++)
  {
    a++;
  }

  return a;
}

//same thing as addtion but subtracts 1 instead
//add negative number support
int subtraction(int a, int b)
{
  for (int i = 0; i < b; i++)
  {
    a--;
  }

  return a;
}


//ad negative number support
int multiplication(int a, int b)
{
  
  bool reverseSign = false;

  if ( a < 0 && b < 0)
  {
    a = a - a - a;
    b = b - b - b;
  }
  else if (a < 0)
  {
    a = a - a - a;
    reverseSign = true;
  }
  else if (b < 0)
  {
    b = b - b - b;
    reverseSign = true;
  }

  for (int i = 1; i < b; i++)
  {
    a = a + a;
  }

  if (reverseSign)
  {
    a = a - a - a;
    return a;
  }

  return a;

}

//add negative number support
//euclid's algorithm
int division(int a, int b)
{
  int c = 0;
  bool reverseSign = false;

  if (a < 0 && b < 0)
  {
    a = a - a - a;
    b = b - b - b; 
  }
  else if (a < 0) 
  {
    a = a - a - a;
    reverseSign = true;
  }
  else if (b < 0) 
  {
    b = b - b - b;
    reverseSign = true;
  }
  else if (a == 0 || b == 0)
  {
    return -2147483648;
  }

  while (a >= b)
  {
    a = a - b;
    c++;
  }

  if (reverseSign)
  {
    c = c - c - c;
    return c;
  }

  return c;

}

int remainder(int a, int b)
{
  bool reverseSign = false;

  if (a < 0 && b < 0)
  {
    a = a - a - a;
    b = b - b - b; 
  }
  else if (a < 0) 
  {
    a = a - a - a;
    reverseSign = true;
  }
  else if (b < 0) 
  {
    b = b - b - b;
    reverseSign = true;
  }
  else if (a == 0 || b == 0)
  {
    return -2147483648;
  }

  while (a >= b)
  {
    a = a - b;
  }

  if (reverseSign)
  {
    a = a - a - a;
    return a;
  }

  return a;

}

//positive base and exponent: multiplies a by itself b times
//negative base: reverses a and returns a negative number if the exponent is odd and a positive number if the exponent is even.
//negative exponent and positive base: returns a to the b and main() prints 1/a^b 
//negative exponent and base: same as prevoius cases but main prints -1/a^b
int exponentiation(int a, int b)
{
  int c = 0;
  int d = 0;
  bool reverseSign = false;
  
  if (b == 0)
  {
    return 1;
  }
  else if (b < 0 && a == 0)
  {
    return -2147483648;
  }

  if (a < 0 && (b % 2) == 0 && b > 0)
  {
    a = a - a - a;
  }
  else if ( a < 0 && (b % 2) != 0 && b > 0)
  {
    a = a - a - a;
    reverseSign = true;
  }
  

  if (a < 0 && b < 0 && (b % 2) == 0)
  {
    a = a - a - a;
    b = b - b - b;
  }
  else if (a < 0 && b < 0 && (b % 2) != 0)
  {
    a = a - a - a;
    b = b - b - b;
    reverseSign = true;
  }
  else if (a > 0 && b < 0)
  {
    b = b - b - b;
  }

  c = a;
  d = a;
  
  for (int j = 1; j < b; j++)
  {
    for (int i = 1; i < d; i++)
    {
      a = a + c;
    }
    c = a;
  }

  if (reverseSign)
  {
    a = a - a - a;
    return a;
  }

  return a;

}

//Heron/Babylonian algorithm (repeat 50 times)
//the x0 in the paper from texas university is the nearest perfect square
double squareRoot(double a)
{
  double c = a / 2;
  

  for (int i = 0; i < 50; i++)
  {
    c = 0.5 * (c + a / c);
  }

  return c;

}

//checks for the first divisor of a and if it finds it then the number isn't prime
bool isPrime(int a)
{
  if (a < 0)
  {
    a = a - a - a;
  }

  for (int i = 2; i < a / i; i++)
  {
    if ((a % i) == 0)
    {
      return false;
    }
  }

  return true;
}

//variation of euclid's algorithm
int gcd(int a, int b)
{
  int r = 0;

  if (a < b)
  {
    int c = a;
    a = b;
    b = c;
  }

  r = b;

  while (r != 0)
  {
    r = a % b;
    if (r == 0)
    {
      r = b;
      break;
    }
    a = b;
    b = r;
  }

  return r;

}

//uses euclid's algorithm for gcd
//takes a multiplied by b and divides it by the gcd 

int lcm(int a, int b)
{
  int r = 0;
  int d = a * b;

  if (a < b)
  {
    int c = a;
    a = b;
    b = c;
  }

  r = b;

  while (r != 0)
  {
    r = a % b;
    if (r == 0)
    {
      r = b;
      break;
    }
    a = b;
    b = r;
  }

  d = d / r;

  return d;

}


int main() 
{
  //user input and output to console here:
  int firstNumber = 0;
  int secondNumber = 0;
  double thirdNumber = 0;

  //clear the console
  cout << "\x1B[2J\x1B[H";

  char operation = ' ';
  cout << "Enter an operation you would like to perform (*,/,-,+,^,%, P isPrime, s square root, g greatest common denominator, l least common multiple)\n";
  cin >> operation;
  
  switch (operation)
  {
    case '+':
    cout << "Please enter the two integers that you would like to add.\n";
    cin >> firstNumber >> secondNumber;
    cout << firstNumber << " added to " << secondNumber << " is equal to " << addition(firstNumber, secondNumber) << ".\n";
    break;

    case '-':
    cout << "Please enter the two integers that you would like to subtract.\n";
    cin >> firstNumber >> secondNumber;
    cout << secondNumber << " subtracted from " << firstNumber << " is equal to " << subtraction(firstNumber, secondNumber) << ".\n";
    break;

    case '*':
    cout << "Please enter the two integers that you would like to multiply.\n";
    cin >> firstNumber >> secondNumber;
    cout << firstNumber << " multiplied by " << secondNumber << " is equal to " << multiplication(firstNumber, secondNumber) << ".\n";
    break;

    case '/':
    cout << "Please enter the two integers that you would like to divide.\n";
    cin >> firstNumber >> secondNumber;
    cout << firstNumber << " divided by " << secondNumber << " is equal to " << division(firstNumber, secondNumber) << ".\n";
    break;

    case '%':
    cout << "Please enter the two integers for which you want find the remainder of their division.\n";
    cin >> firstNumber >> secondNumber;
    cout << "The remainder of " << firstNumber << " divided by " << secondNumber << " is equal to " << remainder(firstNumber, secondNumber) << ".\n";
    break;

    case '^':
    cout << "Please enter the two integers that will act as the base and the exponent.\n";
    cin >> firstNumber >> secondNumber;
    if (secondNumber < 0) 
    {
      cout << firstNumber << " raised to the power of " << secondNumber << " is equal to 1 / " << exponentiation(firstNumber, secondNumber) << ".\n";
      break;
    }
    cout << firstNumber << " raised to the power of " << secondNumber << " is equal to " << exponentiation(firstNumber, secondNumber) << ".\n";
    break;

    case 's':
    cout << "Please enter the natural number that you would like to find the approximated square root of: (only accurate to 5 decimal places)\n";
    cin >> thirdNumber;
    cout << "The square root of " << thirdNumber << " is approximately equal to " << squareRoot(thirdNumber) << ".\n";
    break;

    case 'g':
    cout << "Please enter the two natural numbers for which you want to find the greatest common denominator.\n";
    cin >> firstNumber >> secondNumber;
    cout << "The greatest common denominator of " << firstNumber << " and " << secondNumber << " is equal to " << gcd(firstNumber, secondNumber) << ".\n";
    break;

    case 'l':
    cout << "Please enter the two natural numbers for which you want to find the least common multiple.\n";
    cin >> firstNumber >> secondNumber;
    cout << "The least common multiple of " << firstNumber << " and " << secondNumber << " is equal to " << lcm(firstNumber, secondNumber) << ".\n";
    break;

    case 'P':
    cout << "Please enter the integer that you would like to verify if it is prime.\n";
    cin >> firstNumber;
    if (isPrime(firstNumber) == true)
    {
      cout << firstNumber << " is prime.\n";
    }
    else
    {
      cout << firstNumber << " is not prime.\n";
    }
    break;

    default:
    cout << "Sorry, operation " << operation << " is not currently available.\n";
    break;

  }

  return 0;
}
