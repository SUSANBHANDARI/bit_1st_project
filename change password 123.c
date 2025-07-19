//change password
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct email_password
{
	char email[31];
	char password[16];
};
int main()
{
	FILE *ptr;
	struct email_password *v;
	char em[31],pw[16],sem[31],spw[16],npw[16];
	int n=0,i=0,j=0;
	printf("\nEnter how many sign ups you want to make:");
	scanf("%d",&n);
	v=(struct email_password *)calloc(n,sizeof(struct email_password));
	if(v==NULL)
	{
		printf("Memory wasn't allocated\n");
		exit(0);
	}
	for(i=0;i<=n-1;i++)
	{
		printf("\nEnter email:");
		fflush(stdin);
		scanf("%s",em);
		strcpy(v[i].email,em);
		printf("\nEnter password:");
		fflush(stdin);
		scanf("%s",pw);
		strcpy(v[i].password,pw);
	}
	ptr=fopen("em.txt","w");
	if(ptr==NULL)
	{
		printf("File wasn't found\n");
		exit(0);
	}
	fwrite(v,sizeof(*v),n,ptr);
	fclose(ptr);
	free(v);
	v=(struct email_password *)calloc(n,sizeof(struct email_password));
	if(v==NULL)
	{
		printf("Memory wasn't allocated\n");
		exit(0);
	}
	ptr=fopen("em.txt","r");
	if(ptr==NULL)
	{
		printf("File wasn't found\n");
		exit(0);
	}
	fread(v,sizeof(*v),n,ptr);
	fclose(ptr);
	printf("\nEnter email:");
	fflush(stdin);
	scanf("%s",sem);
	for(i=0;i<=n-1;i++)
	{
		if(strcmp(sem,v[i].email)==0)
		{
			printf("\nEnter password:");
			fflush(stdin);
			scanf("%s",spw);
			if(strcmp(spw,v[i].password)==0)
			{
				printf("Enter new password\n");
				fflush(stdin);
				scanf("%s",npw);
				strcpy(v[i].password,npw);
			}
		}
	}
	ptr=fopen("em.txt","w");
	if(ptr==NULL)
	{
		printf("File wasn't found\n");
		exit(0);
	}
	fwrite(v,sizeof(*v),n,ptr);
	free(v);
}
