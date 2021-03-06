#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif

  
int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  
  int functionID = std::stoi (argv[1]);
  int a = std::stoi (argv[2]);
  int b = std::stoi(argv[3]);
  int n = std::stoi( argv[4]);
  int intensity =std::stoi( argv[5]);
 
  // printf("%i %i %i %i %i\n", functionID, a, b, n, intensity);

  float ban = 1.0 * (b-a) / n;
  //printf("%i    %f\n", bMinusA, ban);
  float result = 0;
  
  auto start = std::chrono::steady_clock::now();
  
  switch(functionID)
  {
  case 1 :
    //Use f1
    for (int i = 0; i <= n-1; i++)
      {
	float x = a + ((i + 0.5) * ban);
	//printf("%f\n", x);
	result += f1(x, intensity);
      }
    result *= ban;
    break;
  case 2 :
    //Use f2
    for (int i = 0; i <= n-1; i++)
      {
	float x = a + ((i + 0.5) * ban);
	result += f2(x, intensity);
      }
    result *= ban;    
    break;
  case 3 :
    //use f3
    for (int i = 0; i <= n-1; i++)
      {
	float x = a + ((i + 0.5) * ban);
	result += f3(x, intensity);
      }
    result *= ban;
   break;
  case 4 :
    //use f4
    for (int i = 0; i <= n-1; i++)
      {
	float x = a + ((i + 0.5) * ban);
	//printf("%f   %i    %f\n", ban, i,  x);
	result += f4(x, intensity);
      }
    result *= ban;
    break;
  default :
    std::cerr<<"invalid functionID";
      return -1;
  }

  auto end = std::chrono::steady_clock::now();
  auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  float elapsed = microseconds / 1000000.0;
  
  //printf("Result = %f     Elapsed = %f seconds\n", result, elapsed);

  std::cout << std::to_string(result) << std::endl;
  std::cerr << std::to_string(elapsed) << std::endl;

  
  
  return 0;
}
