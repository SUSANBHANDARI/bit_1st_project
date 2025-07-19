//#include<stdio.h>
//char *str(char []);
//int main()
//{
//	char a[20],*c;
//	c=str(a);
//	printf("str is %s",c);
//	return 0;
//}
//char *str(char x[])
//{
//	printf("Enter str\n");
//	scanf("%s",x);
//	return x;
//}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct email_password
{
	char email[31];
	char password[16];
	char file[25];
};
struct file_store
{
	char mem_file[25];
	char bk_file[25];
	char bkgv_file[25];
	char bkname_file[25];
};
char *ret_file(int);
int em_pw_block_num();
int main()
{
//	struct file_store v;
//	FILE *ptr;
//	char *fl;
//	int n=1;
//	fl=ret_file(n);
//	printf("\ncar is %s",fl);
//	ptr=fopen(fl,"r");
//	fread(&v,sizeof(v),1,ptr);
//	printf("\n%s %s %s %s\n",v.mem_file,v.bk_file,v.bkgv_file,v.bkname_file);
//	return 0;
	struct file_store *v;
	FILE *ptr;
	char *fl;
	int n=1;
	v=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(n);
	printf("\ncar is %s",fl);
	ptr=fopen(fl,"r");
	fread(v,sizeof(*v),1,ptr);
	printf("\n%s %s %s %s\n",v->mem_file,v->bk_file,v->bkgv_file,v->bkname_file);
	return 0;
	
}
char *ret_file(int num)
{
	FILE *ptr;
	struct email_password *v;
	static char fl[25];
	int n=0;
	n=em_pw_block_num();
	v=(struct email_password *)calloc(n,sizeof(struct email_password));
	ptr=fopen("registration.txt","r");
	fread(v,sizeof(*v),n,ptr);
	fclose(ptr);
	strcpy(fl,v[num].file);
	free(v);
	return &fl[0];
}
//char *ret_file(int num) {
//    FILE *ptr;
//    struct email_password *v;
//    static char fl[25];  // static: persists after function returns
//    int n;
//
//    n = em_pw_block_num();
//    v = (struct email_password *)calloc(n, sizeof(struct email_password));
//
//    ptr = fopen("registration.txt", "r");  // corrected file name
//    if (!ptr) {
//        perror("File open failed");
//        free(v);
//        return NULL;
//    }
//
//    fread(v, sizeof(*v), n, ptr);
//    fclose(ptr);
//
//    if (num < 0 || num >= n) {
//        fprintf(stderr, "Invalid index\n");
//        free(v);
//        return NULL;
//    }
//
//    strcpy(fl, v[num].file);
//    free(v);  // free allocated memory
//
//    return fl;
//}

int em_pw_block_num()
{
	struct email_password *v;
	int n=0;
	FILE *ptr;
	ptr=fopen("registration.txt","r");
	v=(struct email_password *)calloc(1,sizeof(struct email_password));
	while(fread(v,sizeof(*v),1,ptr)==1)
	{
		n++;
	}
	fclose(ptr);
	free(v);
	return n;
}
