#include <stdio.h>
int main(){
	int c = 1;
    switch (3){
        case 1: c+=3;
            break;
        case 2: c++;
            break;
        case 3: c=0;
            break;            
        case 4: c+=3;
            break;            
        case 5: c -=10;
            break;
        default: c--;
            break;
    }
    printf("%d\n",c);
int d = 1;
    switch (3){
        case 1: d+=3;
        case 2: d++;
        case 3: d=0;
        case 4: d+=3;
        case 5: d -=10;
        default: d--;
    }
    printf("%d",d);
}
