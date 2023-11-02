#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int ans;
	int pos, temp;
	float media, sum = 0;
	float mediana = 0, mitad = 0; int mitad_int;
	int comun, cont = 0, pos2, top = 0;
	int frec = 0, igual; float prob = 0;
	srand(time(NULL));
	
	printf("De que tamagno quieres el arreglo?: ");
	scanf("%d", &ans);
	
	printf("Lista sin ordenar:\n");
	int arreglo[ans];
	for(int a = 0; a < ans; a++){
		arreglo[a] = rand() % 30 + 1;
		printf(" %d", arreglo[a]);
	}
	
	printf("\nLista ordenada:\n");
	for(int b = 0; b < ans; b++){
		pos = b;
		for(int c = b + 1; c < ans; c++){
			if(arreglo[pos] > arreglo[c]) 
			pos = c;
		}
		if(pos != b){
			temp = arreglo[b];
			arreglo[b]= arreglo[pos]; 
			arreglo[pos] = temp;
		}
		printf(" %d", arreglo[b]);
	}
	printf("\n\nValor menor: %d\n", arreglo[0]);
	printf("Valor mayor: %d\n", arreglo[ans-1]);
	
	for(int d = 0; d < ans; d++){
		sum = sum + arreglo[d];
	}
	media = sum / ans;
	printf("Media: %f\n", media);
	
	if(ans % 2 == 0){
		mitad += arreglo[ans/2];
		mitad += arreglo[(ans/2) - 1];
		mitad = mitad / 2;
		printf("Mediana: %f\n", mitad);
	} else if(ans % 2 == 1){ 
		mitad = (ans/2) + 0.5;
		mitad_int = mitad;
		printf("Mediana: %d\n", arreglo[mitad_int]);
	}
	
	comun = arreglo[0];
	for(int f = 0; f < ans; f++){
		if(comun == arreglo[f]){
			cont ++;
			if(cont > top){
				top++;
				pos2 = arreglo[f];
			}
			
		} else if(comun != arreglo[f]){
			comun = arreglo[f];
			cont = 0;
		}
	}
	printf("Moda: %d\n\n", pos2);
	
	igual = arreglo[0];
	int lista[30];
	for(int e = 0; e < 30; e++){
		lista[e] = 0;
	}
	for(int g = 0; g < ans; g++){
		if(igual == arreglo[g]){
			frec ++;
		}
		if(igual != arreglo[g]){
			lista[igual] = frec;
			frec = 1;
			igual = arreglo[g];
		}
	}
	for(int h = 0; h < 30; h++){
		printf("%d\t\t: ", h+1);
		if (h < 30){
			for(int i = 0; i < lista[h+1]; i++){
				printf("*");
			}
		}
		if(h == 30){
			
		}
		printf("\n");
	}
	
	return 0;
}
