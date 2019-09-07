#include <stdio.h>
//#include <math.h>
#include <stdlib.h>

int is_prime(int n){
    if(n == 1) return 0;
    else{
        int is_prime = 1;
        for(int i = 2;i < n;i++){
            if(n % i == 0) is_prime = 0;
        }
        if(is_prime) return 1;
        else return 0;
    }
}

int primes(int n){
  int ans = 0;
  for(int i = 2;i <= n;i++){
    if(is_prime(i)) ans++; 
  }
  return ans;
}

int is_square(int n){
  int square = 0;
  for(int i = 1;i * i <= n;i++){
    if(i * i == n) square = 1;
  }
  return square;
}

int is_cubic(int n){
  int i;
  for(i = 1;i * i * i < n;i++){}
  return i * i * i == n;
}

int is_squeare_sum(int n){
  int root_n = 0;
  for(int i = 1;i <= root_n;i++){
    for(int j = 1;j <= root_n;j++){
      if(n  == i * i + j * j) return 1;
    }
  }
  return 0;
}

int time_to_int(int h, int m, int s){
  return (3600 * h + 60 * m + s); 
}

int sec_between(int h1, int m1, int s1, int h2, int m2, int s2){
  int time1 = time_to_int(h1,m1,s1);
  int time2 = time_to_int(h2,m2,s2);
  if(time1 > time2) return (time1 - time2);
  else return (time2 - time1);
}

void times_between_p(int h1, int m1, int s1, int h2, int m2, int s2){
  int time = sec_between(h1,m1,s1,h2,m2,s2);
  printf("%d:%d:%d\n",
         time / 3600,
         (time % 3600) / 60,
         (time % 3600) % 60);
}

int to_heisei(int year){
  if(year < 1989) return -1;
  else return (year - 1989 + 1);
}

int leap(int year){
  if(year % 4 == 0){
    if(year % 100 == 0){
      if(year % 400 != 0) return 0;
    }
    return 1;
  }
  else return 0;
}

int days(int m1, int d1, int m2, int d2){
  int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int days1 = d1,days2 = d2;
  for(int i = 1;i < m1;i++) days1 += month[i - 1];
  for(int i = 1;i < m2;i++) days2 += month[i - 1];
  return days2 - days1;
}

int days_between(int y1, int m1, int d1, int y2, int m2, int d2){
  int _days = 0;
  for(int i = y1;i < y2;i++){
    _days += 365;
    if(leap(i)) _days++;
  }
  _days += days(m1,d1,m2,d2);
  return _days;
}

int rev3(int n){
  int k1 = n / 100;
  int k3 = n % 10;
  int k2 = n % 100 - k3;

  return k3 * 100 + k2 + k1;
}

int how_many_rev3(void){
  int count = 0;
  for(int i = 100;i < 1000;i++){
    if(i == rev3(i)) count++;
  }
  return count;
}

int zero(int n){
  return !n;
}

int abs(int n){
  if(n > 0) return n;
  else return -n;
}

int square(int n){
  return n * n;
}

int triple(int n){
  return n * n * n;
}

int power(int n, int m){
  int ans = 1;
  for(int i = 0;i < m;i++) ans *= n;
  return ans;
}

void squares_p(void){
  for(int i = 1;i < 21;i++)
    printf("%d\n",i * i);
}

int i_root(int n){
  int i;
  for(i = 1;i * i < n;i++){}
  return i - 1;
}

int max2(int x,int y){
  if(x > y) return x;
  else return y;
}

int max3(int x,int y,int z){
  return max2(max2(x,y),z);
}

int triangle(int x, int y, int z){
  return (max3(x,y,z) < x + y + z - max3(x,y,z));
}

int right_angle(int x, int y, int z){
  return x * x == y * y + z * z ||
    y * y == x * x + z * z ||
    z * z == x * x + y * y;
}

int fz(int n){
  if(n % 3 == 0 && n % 5 == 0) return 3;
  else if(n % 5 == 0) return 2;
  else if(n % 3 == 0) return 1;
  else return 0;
}

int sum(int n, int m){
  int ans = 0;
  for(int i = n;i <= m;i++)
    ans += i;
  return ans;
}

int product(int n, int m){
  int ans = 1;
  for(int i = n;i <= m;i++)
    ans *= i;
  return ans;  
}

int divisor_count(int n){
  int count = 0;
  for(int i = 1;i <= n;i++){
    if(n % i == 0) count++;
  }
  return count;
}

int most_divisors100(void){
  int count = 0,max_num = 1;
  for(int i = 1;i <= 100;i++){
    if(divisor_count(i) > count){
      count = divisor_count(i);
      max_num = i;
    }
  }
  return max_num;
}

int most_divisors(int n){
  int max = 0,max_div = 0;
  for(int i = 1;i <= n;i++){
    if(max_div < divisor_count(i)){
      max = i;
      max_div = divisor_count(i);
    }
  }
  return max;
}

int sum_of_digits3(int n){
  int k1 = n / 100;
  int k3 = n % 10;
  int k2 = (n % 100 - k3) / 10;

  return k1 + k2 + k3;
}

int sum_of_digits(int n){
  int ans = 0;
  for(int i = n;i > 0;i /= 10){
    ans += i %10;
  }
  return ans;
}

int teenage(int y){
  return 9 < y && y < 20;
}

int f_to_i(float x){
  int ans = (int)(x + 0.5);
  return ans;
}

float f_to_f1(float x){
  int int_i = (int)(x * 10 + 0.5);
  float ans = (float)int_i / 10;
  return ans;
}

float f_to_f(float x, int n){
  float f = x;
  for(int i = 0;i < n - 1;i++){
    f *= 10;
  }
  int i_ans = (int)(f + 0.5);
  float ans = (float)i_ans;
  for(int i = 0;i < n- 1;i++){
    ans /= 10;
  }
  return ans;
}

int my_rand(int n){
  return random() % n;
}

int main(){
  printf("%d\n", my_rand(100));

}
