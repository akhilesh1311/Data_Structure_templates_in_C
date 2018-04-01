#include<stdio.h>

char* stringAdd(char *a, char*b){
	int lena,lenb,i=0;
	
	int pointa=-1,pointb=-1;
	while(i < lena){
		if(a[i] == '.'){
			pointa = i;
			break;
		}
		i++;
	}
	i = 0;
	while(i < lenb){
		if(b[i] == '.'){
			pointb = i;
			break;
		}
		i++;
	}
	
}

void stringAdd(char *a,char *b,char **c,int *sizec){
	int h=0;
	for(h=0;h<sizea;h++){
		printf("%c",a[h]);
	}
	
	while(a[i] != '\0'){
		i++;
	}
	sizea = i;
	i = 0;
	while(b[i] != '\0'){
		i++;
	}
	sizeb = i;
	i=0;

	
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

int main(){
	
}
