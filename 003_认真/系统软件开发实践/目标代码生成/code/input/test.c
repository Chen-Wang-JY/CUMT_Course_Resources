int main()
{
  int sum;
  int i;
  int r;
  i = 1;
  while(i <= 10){
    r = i - 5;
    if(r <= 0){
      sum = sum + i;
    }
    i = i + 1;
  }
}