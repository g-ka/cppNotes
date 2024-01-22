## Digit Handling: 
`DED10 - Digit extraction division 10`

```
int digits;

while(number){
  digits++;
  number /= 10;
}
```
`DRM10 - Digit reverse modulo 10`
```
int reverseNumber;

while(number){
  reverseNumber = reverseNumber*10 + number%10;
  number /= 10;
}
```
## Divisors Handling:
`DES - Divisor extraction squareRoot`
```
for(int i=0; i<sqrt(number); i++){
  if(number%i == 0){
    <!-- number and number/i are divisors -->
  }
}
```
`DEO2N - Divisor extraction one to n`
```
int end = number;

for(int start=1; start <= end; start++){
  int tempNum = number/start;
  if(number%tempNum == 0){
    <!-- start and tempNum are divisors -->
  }  
  end = tempNum - 1;
}
```
`EuclidianGCD`
> gcd(a, b) = gcd(a-b, b) where a > b

> gcd(a, b) = gcd(a%b, b) where a > b
```
while(a && b){
  if(a > b){
    a %= b;
  }else{
    b %= a;
  }  
}

if(!a){
  <!-- b is the gcd -->
}else{
  <!-- a is the gcd -->
}
```