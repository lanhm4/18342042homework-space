#include<stdio.h>
#include<string.h>

int main() {
	char a[11][11] , c[2];
	int body[5]={15,14,13,12,11};
	int i , j , over;
	memset(a,' ',sizeof(a));
	for(i=0;i<11;i++) {
		a[0][i] = a[10][i] = '*';
		a[i][0] = a[i][10] = '*';
	}
	a[body[0] / 10][body[0] % 10] = 'H';
	for(i=1;i<5;i++) {
		a[body[i] / 10][body[i] % 10] = 'X';
	}
	for(i=0;i<11;i++) {
		for(j=0;j<11;j++) {
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	while(1) {
		scanf("%s",c);
		a[body[4] / 10][body[4] % 10] = ' ';
		switch(c[0]) {
			case 'A': {
				for(i=4;i>0;i--) {
					body[i] = body[i-1];
				}
				body[i] -= 1;
				break;
			}
			case 'S': {
				for(i=4;i>0;i--) {
					body[i] = body[i-1];
				}
				body[i] += 10;				
				break;
			}
			case 'D': {
				for(i=4;i>0;i--) {
					body[i] = body[i-1];
				}
				body[i] += 1;
				break;
			}
			case 'W': {
				for(i=4;i>0;i--) {
					body[i] = body[i-1];
				}
				body[i] -= 10;
				break;
			}
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
		if(over || body[0] / 10 < 1 || body[0] / 10 > 9 || body[0] % 10 < 1 || body[0] % 10 > 9) {
			break;
		}
		a[body[0] / 10][body[0] % 10] = 'H';
		for(i=1;i<5;i++) {
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