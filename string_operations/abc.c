#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

void charSet(char *a,char c,int size){
	int i;
	for(i=0;i<size;i++){
		a[i]=c;
	}
}

int stringIsEmpty(char *a,int sizea){
	int i=0,flag=0;
	while(i<sizea){
		if(a[i]!='0'){
			flag=1;
			break;
		}
		i++;
	}
	if(flag==1){
		return 0;
	}else{
		return 1;
	}
}

void stringAdd(char *a,int sizea,char *b,int sizeb,char **c,int *sizec){
	int h=0;
	for(h=0;h<sizea;h++){
		printf("%c",a[h]);
	}
	
	int carry=0,i=sizea-1,j=sizeb-1,temp;
	if(*c==NULL){
		*c=(char *)malloc(sizeof(char)*(max(sizea,sizeb)+1));
	}
	*sizec=max(sizea,sizeb)+1;
	charSet(*c,'0',*sizec);
	int k=*sizec-1;
	while(i>=0 && j>=0){
		temp=(a[i]+b[j]+carry-96);
		carry=temp/10;
		temp=temp-carry*10;
		(*c)[k]=(temp+48);
		i--;j--;k--;
	}
	if(i<0){
		while(j>=0){
			temp=b[j]+carry-48;
			carry=temp/10;
			temp=temp-carry*10;
			(*c)[k]=(temp+48);
			k--;j--;
		}
	}else if(j<0){
		while(i>=0){
			temp=a[i]+carry-48;
			carry=temp/10;
			temp=temp-carry*10;
			(*c)[k]=(temp+48);
			k--;i--;
		}
	}
	(*c)[k]=carry+48;
}

void stringSub(char *a,int sizea,char *b,int sizeb,char **c,int *sizec){
	int h=0;
	for(h=0;h<sizea;h++){
		printf("%c",a[h]);
	}

	int carry=0,i=sizea-1,j=sizeb-1,temp;
	if(*c==NULL){
		*c=(char *)malloc(sizeof(char)*(max(sizea,sizeb)+1));
		*sizec=max(sizea,sizeb)+1;
	}
	
	charSet(*c,'0',*sizec);
	int k=*sizec-1;
	while(i>=0 && j>=0){
		temp=(a[i]-b[j]-carry);
		if(temp<0){
			carry=1;
			temp=10+temp;
		}else{
			carry=0;
		}
		(*c)[k]=(temp+48);
		i--;j--;k--;
	}
	if(i<0){
		while(j>=0){
			temp=b[j]-carry-48;
			if(temp<0){
				carry=1;
				temp=10+temp;
			}else{
				carry=0;
			}
			(*c)[k]=(temp+48);
			k--;j--;
		}
	}else if(j<0){
		while(i>=0){
			temp=a[i]-carry-48;
			if(temp<0){
				carry=1;
				temp=10+temp;
			}else{
				carry=0;
			}
			(*c)[k]=(temp+48);
			k--;i--;
		}
	}
	(*c)[k]=carry+48;
}

void stringMul(char *a,int sizea,char *b,int sizeb,char **c,int *sizec){
	int carry=0,i=sizea-1,j=sizeb-1,temp;
	char *zero=(char *)malloc(sizeof(char));
	*zero='0';
	char *one=(char *)malloc(sizeof(char));
	*one='1';
	*c=(char *)malloc(sizeof(char)*(sizea+sizeb));
	*sizec=sizea+sizeb;
	charSet(*c,'0',*sizec);
	int *k;
	*k=sizea+sizeb;
//	while(!stringIsEmpty(b,sizeb)){
		stringAdd(a,sizea,zero,sizeof(zero)-1,c,k);
		stringSub(b,sizeb,one,sizeof(one)-1,&b,&sizeb);
		printf("%s\n",*c);
		printf("%s\n",b);
//	}
}

void stringAddAll(char *a, int sizea, char *b, int sizeb, char **c, int *sizec){
	char *tok;
	tok = strtok(a, ".");
	printf("%s\n",tok);
	if (tok == NULL) {
		printf("here\n");
	} else {
		printf("else here\n");
	}
}

int main() {
	char a[]="5123";
	char b[]="4123";
	char *c;
	printf("main\n");
	int p,q,r;
	if(c==NULL){
		printf("here");
	}
	stringAddAll(a,sizeof(a) - 1,b,sizeof(b) - 1,&c,&r);
//	printf("%s\n",c);
}
