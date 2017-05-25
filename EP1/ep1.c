//Thiago  Inocêncio

// 2.1
int eh_palindromo(char *n, int ini, int fim) {

	if(ini > fim) return 1;

	if(n[ini] == n[fim]) return eh_palindromo(n, ini+1, fim-1);
	  
	return 0;
}

int palindromo(char *n) {
	
	int sizeString = strlen(n);

    if(eh_palindromo(n, 0, sizeString-1)) {
    	printf("E palindromo");
    	return 1;
    }
     
    printf("Nao e palindromo");
    
    return 0;
}

// 2.2

int inversa(char *str) {

	int sizeStr = strlen(str);

	if(sizeStr==0) return 0;

	printf("%c", str[sizeStr-1]);

	char *temp = (char*) malloc(sizeof(str[sizeStr-1]));

	strncpy(temp, str, sizeStr-1);

	return inversa(temp);

}

// 2.3

int fibonacciN(int n) {

	for(int i = 1; i<=n;i++) {
	if(n == 1) {
		return 0;
	} else if (n == 2 || n == 3) return 1;

	 return fibonacciN(n-1) + fibonacciN(n-2);
	}

}

int fibonacci(int n) {

	int i;
  
	for(i=1;i<=n;i++)
		printf("%d " , fibonacciN(i));
		
	return 0;
}

// 2.4

int pisoLog (int x) {

     if (x < 2) return 0;

      return 1 + pisoLog (x/2);
}
