#include<stdio.h>
#include<string.h>

typedef struct voz{
	int brVoza;
	char gradP[30], gradD[30];
	int satP, minP;
	int satD, minD;
	int direkt;
}Voz;
Voz vozovi[50];
int br_vozova = 0;
	
	//UcitavanjeFIELA
	int ucitajFile(FILE *f, Voz *v){
		return fscanf(f, "%d%s%s%d%d%d%d%d",
		&(v->brVoza),
		v->gradP,
		v->gradD,
		&(v->satP),
		&(v->minP),
		&(v->satD),
		&(v->minD),
		&(v->direkt));
	}
	//DASDADADSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
	void nadjiGrad(){
		char p[30];
		char d[30];
			printf("Unesite grad polaska:");
			scanf("%s", p);
			printf("Unesite grad dolaska:");
			scanf("%s", d);
		for(int i=0;i<br_vozova;i++){
			if(strcmp(p,vozovi[i].gradP)==0 && strcmp(d, vozovi[i].gradD)==0){
				printf("Voz %d, polazak: %02d:%02d, dolazak: %02d:%02d\n",
				vozovi[i].brVoza,
				vozovi[i].satP, vozovi[i].minP,
				vozovi[i].satD, vozovi[i].minD);
			}
		}
	}
	
	
int main()
{
	FILE *f = fopen("vozovi.txt","r");
	if(f==NULL){
		printf("Greska prilikom ucitavanja fajla.");
		return 1;
	}
	while(ucitajFile(f, &vozovi[br_vozova])==8){
		br_vozova++;
	}
	fclose(f);
	
	nadjiGrad();
	
}

