#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/*
0+1=1
1+1=2
2+1=3
3+1=4
4+1=5
5+1=6
6+1=7,
7+1=8,
8+1=9,19-10=9
9+1=10,99+1=001
*/
struct str_num_inc
{
	char num[10];
	char file[25];
};
struct file_store
{
	char meme[25];
	char beme[25];
};

void string_add_by_num();
int em_pw_block_num(struct str_num_inc *);
void file_cr(char [],char []);
int str_inc_block_num(struct str_num_inc *);
int main() 
{
//	char a[10]="0",b[10];
//	char add='1',car=0;
//	int i,j=0,cou=0;
//	for(i=0;i<=199;i++)
//	{
//		top:
//		if(a[cou]!='9')
//		{
//			a[cou]=a[cou]+add-48+car;
//			car='0'-'0';
//			add='1';
//		}
//		else if(a[cou]=='9')
//		{
//			car='1';
//			a[cou]='0';
//			cou++;
//			if(a[cou]=='\0')
//			{
//				a[cou]='0';
//				a[cou+1]='\0';
//			}
//			add='0'-'0';
//			goto top;
//		}	
//		cou=0;
//		strcpy(b,a);
//		strrev(b);	
//		printf("\n%s",b);
//	}
	string_add_by_num();
	return 0;
}

void string_add_by_num()
{
	FILE *ptr;
	struct str_num_inc v;
	char a[10]="0",b[10];
	char x[25]="regi",y[5]=".txt";
	char add='1',car=0;
	int n=0,cou=0,i;
	for(i=0;i<=4;i++)
	{
//	n=0,cou=0;
//	add='1',car=0;
	n=str_inc_block_num(&v);
	if(n!=0)
	{
		ptr=fopen("num.txt","r");
		fread(&v,sizeof(v),1,ptr);
		fclose(ptr);
		strrev(v.num);
		strcpy(a,v.num);
		printf("a=%s vnum=%s",a,v.num);
	}
		top:
		if(a[cou]!='9')
		{
			a[cou]=a[cou]+add-48+car;
			car='0'-'0';
			add='1';
		}
		else if(a[cou]=='9')
		{
			car='1';
			a[cou]='0';
			cou++;
			if(a[cou]=='\0')
			{
				a[cou]='0';
				a[cou+1]='\0';
			}
			add='0'-'0';
			goto top;
		}	
		cou=0;
		strcpy(b,a);
		strrev(b);
		strcpy(v.num,b);
		strcpy(x,"regi");
		strcat(x,b);
		strcat(x,y);
		strcpy(v.file,x);
		ptr=fopen("num.txt","w");
		fwrite(&v,sizeof(v),1,ptr);
		file_cr(x,b);
		fclose(ptr);
		printf("\nnum:%s\n",b);
//		printf("\nnum:%s\tfile:%s\n",v.num,v.file);
	}
}

int str_inc_block_num(struct str_num_inc *v)
{
	int n=0;
	FILE *ptr;
	ptr=fopen("num.txt","r");
	v=(struct str_num_inc *)calloc(1,sizeof(struct str_num_inc));
	while(fread(v,sizeof(*v),1,ptr)==1)
	{
		n++;
	}
	fclose(ptr);
	free(v);
	return n;
}
void file_cr(char x[25],char b[10])
{
	struct file_store *v;//or without pointer
	char a1[25]="meme",a2[25]="beme";
	char y[5]=".txt";
	FILE *ptr;
	ptr=fopen(x,"w");
	v=(struct file_store *)calloc(1,sizeof(struct file_store));
	strcat(a1,b);
	strcat(a1,y);
	strcpy(v->meme,a1);
	strcat(a2,b);
	strcat(a2,y);
	strcpy(v->beme,a2);
	fwrite(v,sizeof(*v),1,ptr);
	fclose(ptr);
	free(v);
}
//change

