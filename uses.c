const int MAX_LEN = 5;

char word [] = {'p','O','p', 'p', 'Y'};

 int main(void)

{

 for(int i = 0 ; i < MAX_LEN; i++)

 {

 if(word[i] == 'M')

 {

 return i;

 break; 

 }


 }

 printf("-1");
 
 
 return 0; 
 
  
 
 
 
 
 
 }
