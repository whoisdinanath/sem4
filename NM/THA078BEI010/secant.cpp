#include <iostream>
#include <cmath>
#include <cstdlib>

#define f(x) (x*x*x - 2*x - 5)

class Secant{
  private:
  float x0, x1, x2, f0, f1, f2, e;
  int i, N;
  double ans;

  void solve(){
      while(abs(f2) > e)
      {
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        i++;
        if(i>=N)
        {
          std::cout << "Solution doesnot converge" << std::endl;
          exit(0);
        }
      }
      ans = double(x2);
  }


  public:
    Secant(float a, float b, float c, int itr){
      x0 = a, x1 =b, e = c, N = itr, i=1;
      f0 = f(x0), f1 = f(x1);
      x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
      f2 = f(x2);
      std::cout << "Initial guesses provided" << std::endl;
    }
    
    ~Secant(){
      
    }

    void printAns(){
      this->solve();
      std::cout << "The approximate root is: " << this->ans << std::endl;
    }    
};

int main()
{
  Secant s1(10, 20, 0.00001, 12);
  s1.printAns();
  return 0;
}
