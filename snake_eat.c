#include<stdio.h>
#include<string.h>

int main() {
	char a[11][11] , c[2];
	int body[50]={15,14,13,12,11};
	int i , j , over , len=5 , direction;
	memset(a,' ',sizeof(a));
	for(i=0;i<11;i++) {
		a[0][i] = a[10][i] = '*';
		a[i][0] = a[i][10] = '*';
	}
	a[body[0] / 10][body[0] % 10] = 'H';
	for(i=1;i<5;i++) {
		a[body[i] / 10][body[i] % 10] = 'X';
	}
	a[5][5] = '$';
	a[2][3] = '*';
	for(i=0;i<11;i++) {
		for(j=0;j<11;j++) {
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	while(1) {
		scanf("%s",c);
		a[body[len-1] / 10][body[len-1] % 10] = ' ';
		switch(c[0]) {
			case 'A': {
				direction = -1;
				break;
			}
			case 'S': {
				direction = 10;				
				break;
			}
			case 'D': {
				direction = 1;
				break;
			}
			case 'W': {
				direction = -10;
				break;
			}
		}
		if(a[(body[0]+direction) / 10][(body[0]+direction) % 10] == '*') {
			break;
		}
		else {
			if(a[(body[0]+direction) / 10][(body[0]+direction) % 10] == '$') {
				len++;
			}
				for(i=len-1;i>0;i--) {
					body[i] = body[i-1];
				}
				body[i] += direction;
			}
		over = 0;
		for(i=0;i<5;i++) {
			for(j=i+1;j<5;j++) {
				if(body[i] == body[j]) {
					over = 1;
					break; 
				}
			}
		}
		if(over) {
			break;
		}
		a[body[0] / 10][body[0] % 10] = 'H';
		for(i=1;i<len;i++) {
			a[body[i] / 10][body[i] % 10] = 'X';
		}
		for(i=0;i<11;i++) {
			for(j=0;j<11;j++) {
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	}
	printf("Game Over!\n");
    return 0;
}