#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct email_password
{
	char email[31];
	char password[16];
	char file[25];
};
struct str_num_inc
{
	char num[10];
	char file[25];
};
struct file_store
{
	char mem_file[25];
	char bk_file[25];
	char bkgv_file[25];
	char bkname_file[25];
};
struct upd_mem
{
    int id;
    char name[15];
    char phone[11];
};
struct book_info
{
    int book_num;
    char book_name[15];
    char book_author[20];
};
struct book_provide
{
    int bor_id;
    int bor_bknum;
    char bor_name[15];
    char bor_phone[11];
};
struct book_name
{
    int id_rep;
    char bor_bkname[15];
};
void sign_up();
int fun_em(char []);
int fun_em_com(char []);
int fun_pw(char []);
void fun_reg(char [],char []);
char *string_add_by_num(char []);
void strfile_cr(char [],char []);
void file_cr(char []);
int block_pr_or_not(struct str_num_inc *);
void sign_in();
int em_check(char []);
int pw_check(char [],char []);
void sign_in_success(char [],char []);
int reg_pos(char [],char []);
void member(int);
void mem_upd(int);
void mem_list(int);
void mem_del(int);//MAYBE MEMBERSEARCH WILL ALSO BE LISTED
void book(int);
void book_upd(int);
void book_list(int);
void book_del(int);
void book_gv(int);//MAYBE ONE MORE FOR LIST OF BOOK PROVIDED OR NOT
void book_return(int);
void book_search(int);
char *ret_file(int);
int em_pw_block_num(struct email_password *);
int mem_block_num(char []);
int bk_block_num(char []);
int bkgv_block_num(char []);
int bkname_block_num(char []);

int main() 
{
    int ch;
	printf("\n\t\t__________________________LIBRARY MANAGEMENT SYSTEM__________________________\n\n\n\n\n\n");
	printf("\n\t\t=========================PRESS ENTER KEY TO CONTINUE=========================\n\n");
	printf("\n\n\n\n\n\n\t\t");
    getch();
    while (1)
	{
		system("CLS");
        printf("\nEnter choice\n1. Sign up\n2. Sign in\n3. Exit\n");
        printf("\nYour choice:");
        fflush(stdin);
        scanf("%d",&ch);
        switch(ch)
		{
            case 1:
            	system("CLS");
                sign_up();
                printf("\nPress Enter to return to menu...");
                getch();
                break;
            case 2:
            	system("CLS");
                sign_in();
                printf("\nPress Enter to return to menu...");
                getch();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
            	system("CLS");
                printf("Enter a number between 1 and 3.\n");
                printf("\nPress Enter to return to menu...");
                getch();
        }
    }
    return 0;
}

void sign_up()
{
	char email[31],pass[16];
	int res_em,res_pw,res_emcom;
	char con1,con2,con3;
	ekey1:
	ekey:
	printf("\nEmail:\t");
	fflush(stdin);
	scanf("%s",email);
	res_em=fun_em(email);
	if(res_em==1)
	{
		res_emcom=fun_em_com(email);
		if(res_emcom==1)
		{
			pkey:
			printf("\nPassword:");
			fflush(stdin);
			scanf("%s",pass);
			res_pw=fun_pw(pass);
			if(res_pw==1)
			{
				system("CLS");
				printf("\nYour Sign up was successful\n");
				printf("\nNow you can use your new account\n");
				fun_reg(email,pass);
			}
			else
			{
				printf("\nPress y to continue or others to stop:");
				con3=getch();
				if(con3=='y')
				{
					system("CLS");
					printf("\nEmail:%s\t\n",email);
					goto pkey;
				}
			}
		}
		else
		{
		   	printf("\nPress y to continue or others to stop:");
			con2=getch();
			if(con2=='y')
			{
				system("CLS");
				goto ekey1;
			}
		}
	}
	else
	{
		printf("\nPress y to continue or others to stop:");
		con2=getch();
		if(con2=='y')
		{
			system("CLS");
			goto ekey;
		}
		
	}
}

int fun_em(char email[])
{
	
	int l=0,i=0;
	l=strlen(email);
	for(i=0;email[i]!='\0';i++)
	{
		if(i==l-1)
		{
			if(email[l-1]=='m'&&email[l-2]=='o'&&email[l-3]=='c'&&email[l-4]=='.'&&email[l-5]=='l'&&email[l-6]=='i'&&email[l-7]=='a'&&email[l-8]=='m'&&email[l-9]=='g'&&email[l-10]=='@')
			{
				return 1;
			}
			else
			{
				printf("\nRequired name numbers @gmail.com at end\n");//adding for number still is incomplete
				return 0;
			}			
		}
    }
}

int fun_em_com(char email[])
{
	struct email_password *v;
	FILE *ptr;
	int num=0,i,c=0;
	num=em_pw_block_num(v);
	v=(struct email_password *)calloc(num,sizeof(struct email_password));
	ptr=fopen("registration.txt","r");
	fread(v,sizeof(*v),num,ptr);
	fclose(ptr);
	for(i=0;i<=num-1;i++)
	{
		if(strcmp(v[i].email,email)==0)
		{
			c++;
		}
	}
	if(c==0)
	{
		return 1;
	}
	else
	{
		printf("\nThis user is already available\n");
		printf("\nPlease use different email\n");
		return 0;
	}
}

int fun_pw(char pass[])
{
	int j,lp,cw=0,cn=0;
	wkey:
	nkey:
	lkey:
	lp=strlen(pass);
	for(j=0;pass[j]!='\0';j++)
	{
		if(lp>=8&&lp<=15)
		{
			if(pass[j]>=65&&pass[j]<=90||pass[j]>=97&&pass[j]<=123)
			{
				cw++;
			}
			if(pass[j]>=48&&pass[j]<=57)
			{
				cn++;
			}
			if(j==lp-1)
			{
				if(cw==0)
				{
					printf("\nLetters must be included\n");
					return 0;
				}
				else if(cn==0)
				{
					printf("\nNumbers must be included\n");
					return 0;
				}
				else
				{
					// printf("\nSign up successful:\n");
					return 1;
				}
			}
		}
		else
		{
			printf("\npassword should be 8-15 word\n");
			return 0;
		}
	}
}

void fun_reg(char email[],char pass[])
{
	FILE *ptr;
	struct email_password *v;
	char *fl,x[25]="reg";
	int i=0,num=0,c=0;
	fl=string_add_by_num(x);
	num=em_pw_block_num(v);//function call to know block size of file
	v=(struct email_password *)calloc(num,sizeof(struct email_password));
	ptr=fopen("registration.txt","r");
	fread(v,sizeof(*v),num,ptr);
	fclose(ptr);
	v=(struct email_password *)realloc(v,(num+1)*sizeof(struct email_password));
	for(i=num;i<=(num+1)-1;i++)
	{
		strcpy(v[i].email,email);
		strcpy(v[i].password,pass);
		strcpy(v[i].file,fl);
	}
	ptr=fopen("registration.txt","w");
	fwrite(v,sizeof(*v),num+1,ptr);
	fclose(ptr);
	free(v);
}

char *string_add_by_num(char x[25])
{
	FILE *ptr;
	struct str_num_inc v;
	char a[10]="0",b[10];
	char y[5]=".txt";
	char add='1',car=0;
	int n=0,cou=0,i;
	n=block_pr_or_not(&v);
	if(n!=0)
	{
		ptr=fopen("num1.txt","r");
		fread(&v,sizeof(v),1,ptr);
		fclose(ptr);
		strrev(v.num);
		strcpy(a,v.num);
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
		strcpy(x,"reg");
		strcat(x,b);
		strcat(x,y);
		strcpy(v.file,x);
		ptr=fopen("num1.txt","w");
		fwrite(&v,sizeof(v),1,ptr);
		fclose(ptr);
		strfile_cr(x,b);
		return x;
}

void strfile_cr(char x[25],char b[10])
{
	struct file_store *v;//or without pointer
	char a1[25]="member",a2[25]="book",a3[25]="bkgv",a4[25]="bkname";
	char y[5]=".txt";
	FILE *ptr;
	ptr=fopen(x,"w");
	v=(struct file_store *)calloc(1,sizeof(struct file_store));
	strcat(a1,b);
	strcat(a1,y);
	strcpy(v->mem_file,a1);
	file_cr(a1);
	strcat(a2,b);
	strcat(a2,y);
	strcpy(v->bk_file,a2);
	file_cr(a2);
	strcat(a3,b);
	strcat(a3,y);
	strcpy(v->bkgv_file,a3);
	file_cr(a3);
	strcat(a4,b);
	strcat(a4,y);
	strcpy(v->bkname_file,a4);
	file_cr(a4);
	fwrite(v,sizeof(*v),1,ptr);
	fclose(ptr);
	free(v);
}

void file_cr(char fl[])
{
	FILE *ptr;
	ptr=fopen(fl,"w");
	fclose(ptr);
}

int block_pr_or_not(struct str_num_inc *v)
{
	int n=0;
	FILE *ptr;
	ptr=fopen("num1.txt","r");
	v=(struct str_num_inc *)calloc(1,sizeof(struct str_num_inc));
	while(fread(v,sizeof(*v),1,ptr)==1)
	{
		n++;
	}
	fclose(ptr);
	free(v);
	return n;
}

void sign_in()
{
	struct email_password *v;
	char emlog[31],passlog[16];
	char con1,con2;
	int em_res,pw_res;
	em1:
	printf("\nEnter email:");
	scanf("%s",emlog);
	em_res=em_check(emlog);
	if(em_res==1)
	{
		pw1:
		printf("\nEnter password:");
		scanf("%s",passlog);
		pw_res=pw_check(emlog,passlog);
		if(pw_res==1)
		{
			system("CLS");
			printf("______________WELCOME %s______________\n\n\n",emlog);
			printf("You have successfully logged in to your account\n");
			printf("\nPress Enter to look into the record..........");
            getch();
			sign_in_success(emlog,passlog);
		}
		else
		{
			printf("\nPress y to continue or others to stop:");
			con2=getch();
			if(con2=='y')
			{
				system("CLS");
				printf("\nEnter email:%s\n",emlog);
				goto pw1;
			}
		}
	}
	else
	{
		printf("\nPress y to continue or others to stop:");
		con1=getch();
		if(con1=='y')
		{
			system("CLS");
			goto em1;
		}
	}
}

int em_check(char email[])
{
	struct email_password *v;
	FILE *ptr;
	int num=0,i,c=0;
	num=em_pw_block_num(v);
	v=(struct email_password *)calloc(num,sizeof(struct email_password));
	ptr=fopen("registration.txt","r");
	fread(v,sizeof(*v),num,ptr);
	fclose(ptr);
	for(i=0;i<=num-1;i++)
	{
		if(strcmp(v[i].email,email)==0)
		{
			return 1;
			c++;
		}
	}
	if(c==0)
	{
		printf("\nWRONG EMAIL\n");
		return 0;
	}
}

int pw_check(char email[],char pass[])
{
	struct email_password *v;
	FILE *ptr;
	int num=0,i,c=0;
	num=em_pw_block_num(v);
	v=(struct email_password *)calloc(num,sizeof(struct email_password));
	ptr=fopen("registration.txt","r");
	fread(v,sizeof(*v),num,ptr);
	fclose(ptr);
	for(i=0;i<=num-1;i++)
	{
		if(strcmp(v[i].email,email)==0&&strcmp(v[i].password,pass)==0)
		{
			return 1;
			c++;
		}
	}
	if(c==0)
	{
		printf("\nWRONG PASSWORD\n");
		return 0;
	}
}

void sign_in_success(char email[],char pass[])
{
	int n=0,ck=0;
	n=reg_pos(email,pass);
	int lib_ch;
    while(1)
	{
		system("CLS");
        printf("\nEnter choice\n1. MEMBER\n2. BOOK\n3. EXIT MENU\n");
        printf("\nYour choice:");
        fflush(stdin);
        scanf("%d",&lib_ch);
        switch(lib_ch)
		{
            case 1:
                //MEMBERS OPTION
                system("CLS");
                member(n);
                printf("\nPress Enter to exit member menu...");
                getch();
                break;
            case 2:
            	system("CLS");
                //BOOK OPTION
                book(n);
                printf("\nPress Enter to exit book menu...");
                getch();
                break;
            case 3:
                ck=1;
                break;
            default:
            	system("CLS");
                printf("Enter a number between 1 and 3.\n");
                printf("\nPress Enter to return to menu...");
                getch();
        }
        if(ck==1)
        {
        	break;
		}
    }
}

int reg_pos(char email[],char pass[])
{
	FILE *ptr;
	struct email_password *v;
	int i,n,num=0;
	n=em_pw_block_num(v);
	v=(struct email_password *)calloc(n,sizeof(struct email_password));
	ptr=fopen("registration.txt","r");
	fread(v,sizeof(*v),n,ptr);
	fclose(ptr);
	for(i=0;i<=n-1;i++)
	{
		if(strcmp(v[i].email,email)==0&&strcmp(v[i].password,pass)==0)
		{
			num=i;
		}
	}
	free(v);
	return num;
}

void member(int n)
{
	int mem_ch,ck=0;
    while(1)
	{
		system("CLS");
        printf("\nEnter choice\n1. MEMBER UPDATE\n2. MEMBER LIST\n3. MEMBER DELETE\n4. EXIT MEMBER MENU\n");
        //MEMBER SEARCH REMAINING
        printf("\nYour choice:");
		fflush(stdin);
        scanf("%d",&mem_ch);
		
        switch(mem_ch)
		{
            case 1:
            	system("CLS");
            	mem_upd(n);
            	printf("\nPress Enter to return to member menu...");
            	getch();
                break;
            case 2:
            	system("CLS");
            	mem_list(n);
            	printf("\nPress Enter to return to member menu...");
            	getch();
                break;
            case 3:
            	system("CLS");
            	mem_del(n);
            	printf("\nPress Enter to return to member menu...");
                getch();
                break;
            case 4:
            	system("CLS");
            	ck=1;
                break;
            default:
            	system("CLS");
                printf("Enter a number between 1 and 4.\n");
                printf("\nPress Enter to return to member menu...");
                getch();
        }
        if(ck==1)
        {
        	break;
		}
    }
}
void mem_upd(int reg_pos)
{
	FILE *ptr;
	struct file_store *v1;
	struct upd_mem *v,*t;
	char *fl,memfl[25];
	int i,j,new=0,c=0,n=0,tem=0;
    int phl=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(memfl,v1->mem_file);
	fclose(ptr);
	free(v1);
	
	n=mem_block_num(memfl);
	v=(struct upd_mem *)calloc(n,sizeof(struct upd_mem));
    if(v==NULL)
    {
        printf("Memory wasn't allocated\n");
        exit(0);
    }
    ptr=fopen(memfl,"r");
    if(ptr==NULL)
    {
        printf("The file wasn't found\n");
        exit(0);
    }
    fread(v,sizeof(*v),n,ptr);
    fclose(ptr);
    printf("no of members to be update:");
    scanf("%d",&new);
    v=(struct upd_mem *)realloc(v,(n+new)*sizeof(struct upd_mem));
    t=(struct upd_mem *)calloc(new,sizeof(struct upd_mem));
    if(v==NULL)
    {
        printf("Memory wasn't allocated\n");
        exit(0);
    }
    for(i=n;i<=(n+new)-1;i++)
    {
        idkey:
        printf("Enter id   :");
        scanf("%d",&v[i].id);
        t[tem].id=v[i].id;
        for(j=0;j<=i-1;j++)
        {
            if(v[i].id==v[j].id)
            {
                printf("\n-----------------------------ID REPEATED-----------------------------\n");
                printf("\n------------------------------TRY AGAIN------------------------------\n");
                goto idkey;
            }
        }
        fflush(stdin);
        printf("Enter name :");
        gets(v[i].name);
        strcpy(t[tem].name,v[i].name);
        fflush(stdin);
        phk1:
        phk2:
        phk3:
        printf("Enter phone:");
        scanf("%s",v[i].phone);
        strcpy(t[tem].phone,v[i].phone);
        phl=strlen(v[i].phone);
        fflush(stdin);
            if(v[i].phone[0]=='9'&&v[i].phone[1]=='8')
            {
                if(v[i].phone[10]=='\0'&&phl==10)
                {
                    for(j=0;v[i].phone[j]!='\0';j++)
                    {
                        if(v[i].phone[j]>=48&&v[i].phone[j]<=57)
                        {
                            if(v[i].phone[j+1]=='\0')
                            {
                                printf("\n-----------------------MEMBER UPDATED SUCCESSFULLY-----------------------\n");
                            }
                        }
                        else
                        {
                            printf("\nENTER NUMBERS ONLY\n");
                            goto phk1;
                        }
                    }
                }
                else
                {
                    printf("Phone no. is required to have 10 digits\n");
                    goto phk2;
                }
            }
            else
            {
                printf("Sorry the beginning number should start with 98-------");
                printf("\nPlease Redial again correctly\n");
                goto phk3;
            }
    	tem++;
    }
    ptr=fopen(memfl,"a");
    if(ptr==NULL)
    {
        printf("The file wasn't found\n");
        exit(0);
    }
    fwrite(t,sizeof(*t),new,ptr);
    fclose(ptr);
    free(t);
    free(v);

}

void mem_list(int reg_pos)
{
	FILE *ptr;
    struct upd_mem *v;
	struct file_store *v1;
	char *fl,memfl[25];
	int i=0,j,n=0,c=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(memfl,v1->mem_file);
	fclose(ptr);
	free(v1);
	
	n=mem_block_num(memfl);
	v=(struct upd_mem *)calloc(n,sizeof(*v));
    if(v==NULL)
    {
        printf("Memory wasn't allocated\n");
        exit(0);
    }
    ptr=fopen(memfl,"r");
    if(ptr==NULL)
    {
        printf("The file wasn't found\n");
        exit(0);
    }
    fread(v,sizeof(*v),n,ptr);
    printf("\n%-10s %-20s %-15s\n", "ID_NUM", "MEMBER_NAME", "MEMBER_PH.NO.");
    printf("----------------------------------------------------------\n");
    for(i=0;i<=n-1;i++)
    {
        printf("\n%-10d name=%-20s phone=%-15s\n",v[i].id,v[i].name,v[i].phone);
    }
    fclose(ptr);
    free(v);
}

void mem_del(int reg_pos)
{
	FILE *ptr;
	struct file_store *v1;
	struct upd_mem *v,*t;
	char *fl,memfl[25];
	int i=0,j=0,n=0,c=0,c1=0;
    int size,*src,red=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(memfl,v1->mem_file);
	fclose(ptr);
	free(v1);
	
	n=mem_block_num(memfl);
	t=(struct upd_mem *)calloc(1,sizeof(*t));
	if(t==NULL)
    {
        printf("Memory wasn't allocated\n");
        exit(0);
    }
    v=(struct upd_mem *)calloc(n,sizeof(*v));
    if(v==NULL)
    {
        printf("Memory wasn't allocated\n");
        exit(0);
    }
    ptr=fopen(memfl,"r");
    if(ptr==NULL)
    {
        printf("The file wasn't found\n");
        exit(0);
    }
    fread(v,sizeof(*v),n,ptr);
    printf("\nEnter the no of record you want to delete:");
    scanf("%d",&size);
    src=(int *)calloc(size,sizeof(int));
    for(i=0;i<=size-1;i++)
    {
        printf("Enter the search value\n");
        scanf("%d",src+i);
    }
    for(i=0;i<=size-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if(v[j].id==*(src+i))
            {
                if(j>=0&&j<=n-2)
                {
                    *t=*(v+j+1);
                    *(v+j+1)=*(v+j);
                    *(v+j)=*t;
                }
                c++;
                if(c1==0)
                {
                    printf("\n------------------ID %d RECORDS DELETED SUCCESSFULLY------------------\n",*(src+i));//need for fix
                    c1=1;
                }
                
            }
        }
        if(c==0)
        {
            printf("\n------------------ID %d ISN'T PRESENT IN THE RECORDS------------------\n",*(src+i));
            red++;
        }
        c=0;
        c1=0;
    }
    size=size-red;
    fclose(ptr);
    free(src);
    free(t);
    ptr=fopen(memfl,"w");
    if(ptr==NULL)
    {
        printf("File wasn't found\n");
        exit(0);
    }
    fwrite(v,sizeof(*v),n-size,ptr);
    fclose(ptr);
    free(v);
}

void book(int n)
{
	int bk_ch,ck=0;
    while(1)
	{
		system("CLS");
        printf("\nEnter choice\n1. BOOK UPDATE\n2. BOOK LIST\n3. BOOK DELETE\n4. BOOK PROVIDE\n5. BOOK RETURN\n6. EXIT BOOK MENU\n");
        printf("\nYour choice:");
		fflush(stdin);
        scanf("%d",&bk_ch);
        switch(bk_ch)
		{
            case 1:
            	system("CLS");
            	book_upd(n);
            	printf("\nPress Enter to return to book menu...");
                getch();
                break;
            case 2:
            	system("CLS");
            	book_list(n);
            	printf("\nPress Enter to return to book menu...");
            	getch();
                break;
            case 3:
            	system("CLS");
            	book_del(n);
            	printf("\nPress Enter to return to book menu...");
                getch();
                break;
            case 4:
            	system("CLS");
            	book_gv(n);
            	printf("\nPress Enter to return to book menu...");
                getch();
                break;
            case 5:
            	system("CLS");
            	book_return(n);
            	printf("\nPress Enter to return to book menu...");
                getch();
                break;
            case 6:
            	system("CLS");
                ck=1;
                break;
            default:
            	system("CLS");
                printf("Enter a number between 1 and 4.\n");
                printf("\nPress Enter to return to book menu...");
                getch();
        }
        if(ck==1)
        {
        	break;
		}
    }
}

void book_upd(int reg_pos)
{
	FILE *ptr;
	struct file_store *v1;
	struct book_info *v;
	char *fl,bkfl[25];
	int new,i=0,j=0;
    int n=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(bkfl,v1->bk_file);
	fclose(ptr);
	free(v1);
	
	n=bk_block_num(bkfl);
	v=(struct book_info *)calloc(n,sizeof(struct book_info));
    if(v==NULL)
    {
        printf("Sorry!The memory wasn't allocated\n");
        exit(0);
    }
    ptr=fopen(bkfl,"r");
    if(ptr==NULL)
    {
        printf("Sorry the file wasn't found");
        exit(0);
    }
    fread(v,sizeof(*v),n,ptr);
    fclose(ptr);

    printf("\nEnter how many new books you want to add:");
    scanf("%d",&new);
    v=(struct book_info *)realloc(v,(n+new)*sizeof(struct book_info));
    if(v==NULL)
    {
        printf("Sorry!The memory wasn't allocated\n");
        exit(0);
    }
    ptr=fopen(bkfl,"w");
    if(ptr==NULL)
    {
        printf("Sorry the file wasn't found");
        exit(0);
    }
    for(i=n;i<=(n+new)-1;i++)
    {
        bnamekey:
        printf("Enter book_name:");
        fflush(stdin);
        gets(v[i].book_name);
        for(j=0;j<=i-1;j++)
        {
            if(strcmp(v[i].book_name,v[j].book_name)==0)
            {
                printf("YOU CAN'T MAKE MULTIPLE SECTION OF SAME BOOK");
                goto bnamekey;
            }
        }
        printf("Enter book_author:");
        fflush(stdin);
        gets(v[i].book_author);
        fflush(stdin);
        bkey:
        printf("Enter book_num:");
        fflush(stdin);
        scanf("%d",&v[i].book_num);
        if(v[i].book_num<0)
        {
            printf("ERROR\n");
            goto bkey;
        }
    }
    fwrite(v,sizeof(*v),(n+new),ptr);
    fclose(ptr);
    free(v);
}

void book_list(int reg_pos)
{
	FILE *ptr;
	struct file_store *v1;
	struct book_info *v;
	char *fl,bkfl[25];
	int n=0,i=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(bkfl,v1->bk_file);
	fclose(ptr);
	free(v1);
	
	n=bk_block_num(bkfl);
	v=(struct book_info *)calloc(n,sizeof(struct book_info));
    if(v==NULL)
    {
        printf("Sorry!The memory wasn't allocated\n");
        exit(0);
    }
    ptr=fopen(bkfl,"r");
    if(ptr==NULL)
    {
        printf("Sorry the file wasn't found");
        exit(0);
    }
    fread(v,sizeof(*v),n,ptr);
    printf("\n%-15s %-20s %-10s\n", "Book_NAME", "BOOK_AUTHOR", "BOOK_NUM");
    printf("----------------------------------------------------------\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%-15s %-20s %-10d\n",v[i].book_name,v[i].book_author,v[i].book_num);
    }
    fclose(ptr);
    free(v);
}

void book_del(int reg_pos)
{
	FILE *ptr;
	struct file_store *v1;
	struct book_info *v,*t;
	char *fl,bkfl[25];
	int i=0,j=0,n=0,c=0,c1=0;
	int size=0,red=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(bkfl,v1->bk_file);
	fclose(ptr);
	free(v1);
	
	n=bk_block_num(bkfl);
	t=(struct book_info *)calloc(1,sizeof(*t));
    if(t==NULL)
    {
        printf("Memory wasn't allocated\n");
        exit(0);
    }
    v=(struct book_info *)calloc(n,sizeof(struct book_info));
    if(v==NULL)
    {
        printf("Memory wasn't allocated\n");
        exit(0);
    }
    ptr=fopen(bkfl,"r");
    if(ptr==NULL)
    {
        printf("The file wasn't found\n");
        exit(0);
    }
    fread(v,sizeof(*v),n,ptr);
    printf("\nEnter the no of record you want to delete:");
    scanf("%d",&size);
    char src[size][15];
    for(i=0;i<=size-1;i++)
    {
        printf("\nEnter the search value:");
        scanf("%s",src[i]);
    }
    for(i=0;i<=size-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if(strcmp(v[j].book_name,src[i])==0)
            {
                if(j>=0&&j<=n-2)
                {
                    *t=*(v+j+1);
                    *(v+j+1)=*(v+j);
                    *(v+j)=*t;
                }
                c++;
                if(c1==0)
                {
                    printf("\n------------------BOOK %s's RECORDS DELETED SUCCESSFULLY------------------\n",src[i]);//need for fix
                    c1=1;
                }
                
            }
        }
        if(c==0)
        {
            printf("\n------------------BOOK %s's ISN'T PRESENT IN THE RECORDS------------------\n",src[i]);
            red++;
        }
        c=0;
        c1=0;
    }
    size=size-red;
    fclose(ptr);
    free(t);
    ptr=fopen(bkfl,"w");
    if(ptr==NULL)
    {
        printf("File wasn't found\n");
        exit(0);
    }
    fwrite(v,sizeof(*v),n-size,ptr);
    fclose(ptr);
    free(v);
}

void book_gv(int reg_pos)
{
	FILE *ptr;
	struct file_store *v1;
	struct upd_mem *mem;
    struct book_info *b;
    struct book_provide *bkgv,tbkgv;
    struct book_name *bname,tbname;
	char *fl,bkfl[25],memfl[25],bkgvfl[25],bknamefl[25];
	char pbkname[15];
	int i,j,k,l,m,p;//p mayn't be used
    int pid,pbn;
    int mn=0,bn=0,bgn=0,bnn=0;
    int mc=0,bc=0,c=0,c1=0,c2=0,c3=0,br=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(bkfl,v1->bk_file);
	strcpy(memfl,v1->mem_file);
	strcpy(bkgvfl,v1->bkgv_file);
	strcpy(bknamefl,v1->bkname_file);
	fclose(ptr);
	free(v1);
	mn=mem_block_num(memfl);
	bn=bk_block_num(bkfl);
	bgn=bkgv_block_num(bkgvfl);
	bnn=bkname_block_num(bknamefl);
	
	mem=(struct upd_mem *)calloc(mn,sizeof(struct upd_mem));
    b=(struct book_info *)calloc(bn,sizeof(struct book_info));
    bkgv=(struct book_provide *)calloc(bgn,sizeof(struct book_provide));
    bname=(struct book_name *)calloc(bnn,sizeof(struct book_name));
    ptr=fopen(memfl,"r");
    fread(mem,sizeof(*mem),mn,ptr);
    fclose(ptr);
    ptr=fopen(bkfl,"r");
    fread(b,sizeof(*b),bn,ptr);
    fclose(ptr);
    ptr=fopen(bkgvfl,"r");
    fread(bkgv,sizeof(*bkgv),bgn,ptr);
    fclose(ptr);
    ptr=fopen(bknamefl,"r");
    fread(bname,sizeof(*bname),bnn,ptr);
    fclose(ptr);
    printf("\nEnter id:");
    fflush(stdin);
    scanf("%d",&pid);
    mc=0;
    bc=0;
    c=0;
    for(i=0;i<=mn-1;i++)
    {
        if(pid==mem[i].id)
        {
            for(j=0;j<=bgn-1;j++)
            {
                if(pid==bkgv[j].bor_id)
                {
                    c++;
                    printf("Enter no of books:");
                    fflush(stdin);
                    scanf("%d",&pbn);
                    for(k=0;k<=pbn-1;k++)
                    {
                        printf("Enter book name:");
                        fflush(stdin);
                        gets(pbkname);
                        for(l=0;l<=bn-1;l++)
                        {
                            if(strcmp(pbkname,b[l].book_name)==0)
                            {
                                for(m=0;m<=bnn+bc-1;m++)
                                {
                                    if(pid==bname[m].id_rep)
                                    {
                                        if(strcmp(pbkname,bname[m].bor_bkname)==0)
                                        {
                                            br++;
                                        }                                 
                                    }
                                }
                                if(br==0)
                                {
                                    bc++;
                                    bname=(struct book_name *)realloc(bname,(bnn+bc)*sizeof(struct book_name));
                                    bname[bnn+bc-1].id_rep=pid;
                                    strcpy(bname[bnn+bc-1].bor_bkname,pbkname);
                                    b[l].book_num=b[l].book_num-1;
                                    bkgv[j].bor_bknum=bkgv[j].bor_bknum+1;
                                }
                                else
                                {
                                    printf("\nOne person can't take more than one same book\n");
                                }
                                br=0;
                            }
                        }
                    }
                }
            }
            if(c==0)
            {
                mc++;
                bkgv=(struct book_provide *)realloc(bkgv,(bgn+mc)*sizeof(struct book_provide));
                bkgv[bgn+mc-1].bor_id=mem[i].id;
                strcpy(bkgv[bgn+mc-1].bor_name,mem[i].name);
                strcpy(bkgv[bgn+mc-1].bor_phone,mem[i].phone);
                bkgv[bgn+mc-1].bor_bknum=0;
                printf("Enter the no of books you want\n");
                fflush(stdin);
                scanf("%d",&pbn);
                for(k=0;k<=pbn-1;k++)
                {
                    printf("Enter book name:");
                    fflush(stdin);
                    gets(pbkname);
                    //
                    for(l=0;l<=bn-1;l++)
                    {
                        if(strcmp(pbkname,b[l].book_name)==0)
                        {
                            bc++;
                            bname=(struct book_name *)realloc(bname,(bnn+bc)*sizeof(struct book_name));
                            bname[bnn+bc-1].id_rep=pid;
                            strcpy(bname[bnn+bc-1].bor_bkname,pbkname);
                            for(p=bnn;p<=bnn+bc-2;p++)
                            {
                                if(strcmp(pbkname,bname[p].bor_bkname)==0)
                                {
                                    c1++;
                                    printf("One person can't two books of same name\n");
                                    k--;
                                    bc--;
                                    bname=(struct book_name *)realloc(bname,(bnn+bc)*sizeof(struct book_name));
                                    pbn--;
                                }
                            }
                            if(c1==0)
                            {
                                b[l].book_num=b[l].book_num-1;
                                bkgv[bgn+mc-1].bor_bknum=bkgv[bgn+mc-1].bor_bknum+1;
                            }
                            c1=0;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<=(bgn+mc)-1;i++)
    {
        for(j=i+1;j<=(bgn+mc)-1;j++)
        {
            if(bkgv[i].bor_id>bkgv[j].bor_id)
            {
                tbkgv=bkgv[i];
                bkgv[i]=bkgv[j];
                bkgv[j]=tbkgv;
            }
        }
    }
    for(i=0;i<=(bnn+bc)-1;i++)
    {
        for(j=i+1;j<=(bnn+bc)-1;j++)
        {
            if(bname[i].id_rep>bname[j].id_rep)
            {
                tbname=bname[i];
                bname[i]=bname[j];
                bname[j]=tbname;
            }
        }
    }
    ptr=fopen(bkfl,"w");
    fwrite(b,sizeof(*b),bn,ptr);
    fclose(ptr);
    free(b);
    ptr=fopen(bkgvfl,"w");
    fwrite(bkgv,sizeof(*bkgv),(bgn+mc),ptr);
    fclose(ptr);
    free(bkgv);
    ptr=fopen(bknamefl,"w");
    fwrite(bname,sizeof(*bname),(bnn+bc),ptr);
    fclose(ptr);
    free(bname);
	free(mem);
}

void book_return(int reg_pos)
{
	FILE *ptr;
	struct file_store *v1;
	struct book_info *b;
    struct book_provide *bkgv,tbkgv;
    struct book_name *bname,tbname;
	char *fl,bkfl[25],bkgvfl[25],bknamefl[25];
	char pbkname[15];
	char rbook[15];
	int i,j,k,l,m,p,q;
    int mn=0,bn=0,bgn=0,bnn=0,c=0,c1=0,red=0,inc=0,c2=0,num1=0,num2=0;
    int str=0;
    int rid=0,rn=0,curbknum=0,booknum=0;
	v1=(struct file_store *)calloc(1,sizeof(struct file_store));
	fl=ret_file(reg_pos);
	ptr=fopen(fl,"r");
	fread(v1,sizeof(*v1),1,ptr);
	strcpy(bkfl,v1->bk_file);
	strcpy(bkgvfl,v1->bkgv_file);
	strcpy(bknamefl,v1->bkname_file);
	fclose(ptr);
	free(v1);
	
	bn=bk_block_num(bkfl);
	bgn=bkgv_block_num(bkgvfl);
	bnn=bkname_block_num(bknamefl);
	
    b=(struct book_info *)calloc(bn,sizeof(struct book_info));
    bkgv=(struct book_provide *)calloc(bgn,sizeof(struct book_provide));
    bname=(struct book_name *)calloc(bnn,sizeof(struct book_name));
    ptr=fopen(bkfl,"r");
    fread(b,sizeof(*b),bn,ptr);
    fclose(ptr);
    ptr=fopen(bkgvfl,"r");
    fread(bkgv,sizeof(*bkgv),bgn,ptr);
    fclose(ptr);
    ptr=fopen(bknamefl,"r");
    fread(bname,sizeof(*bname),bnn,ptr);
    fclose(ptr);
    printf("\nEnter id for return:");
    scanf("%d",&rid);
    c2=0;
    for(i=0;i<=bgn-1;i++)
    {
    	if(rid==bkgv[i].bor_id)
    	{
            //Enter if id correct
    		printf("\nEnter no of books you want to return:");
    		fflush(stdin);
    		scanf("%d",&rn);
    		for(j=0;j<=rn-1;j++)
    		{
                for(p=0;p<=bgn-1;p++)
                {
                    if(c2==0)
                    {
                        booknum=booknum+bkgv[p].bor_bknum;
    	                curbknum=bkgv[p].bor_bknum;
                    }
                    if(rid==bkgv[p].bor_id)
                    {
                        c2=1;
                    }
                }
    			printf("\nEnter the book name:");
    			fflush(stdin);
    			gets(rbook);
    			for(k=booknum-curbknum;k<=booknum-1;k++)
    			{
    				if(strcmp(rbook,bname[k].bor_bkname)==0&&rid==bname[k].id_rep)
    				{
                        str=k;
    					printf("id=%d\tbook_name=%s\n",bname[k].id_rep,bname[k].bor_bkname);
                        for(m=str;m<=bnn-inc-1;m++)
                        {
                            if(m>=booknum-curbknum&&m<=bnn-2)
                            {
                                tbname=bname[m+1];
                                bname[m+1]=bname[m];
                                bname[m]=tbname;
                            }
                            c++;
                            if(c1==0)
                            {
                                inc++;
                                printf("\n------------------%s BOOK'S RECORDS DELETED SUCCESSFULLY------------------\n",rbook);//need for fix
                                bkgv[i].bor_bknum=bkgv[i].bor_bknum-1;
                                for(q=0;q<=bn-1;q++)
                                {
                                    if(strcmp(rbook,b[q].book_name)==0)
                                    {
                                        b[q].book_num=b[q].book_num+1;
                                    }
                                }
                                c1=1;
                            }
                        }
                        
					}
				}

                if(c==0)
                {
                    printf("\n------------------%s BOOK ISN'T PRESENT IN THE RECORDS------------------\n",rbook);
                    red++;
                }
                c=0;
                c1=0;
			}
            booknum=0;
    	    curbknum=0;
		}
	}
    rn=rn-red;
	for(i=0;i<=bgn-1;i++)
    {
        if(bkgv[i].bor_bknum==0)
        {
        	num1++;
		}
    }
    if(num1!=0)
    {
    	for(i=0;i<=bgn-2;i++)
    	{
    	    if(bkgv[i].bor_bknum==0)
    	    {
    	    	tbkgv=bkgv[i];
    	    	bkgv[i]=bkgv[i+1];
    	    	bkgv[i+1]=tbkgv;
			}
    	}
	}
    ptr=fopen(bkgvfl,"w");
    fwrite(bkgv,sizeof(*bkgv),bgn-num1,ptr);
    fclose(ptr);
    free(bkgv);

    ptr=fopen(bknamefl,"w");
    fwrite(bname,sizeof(*bname),bnn-rn,ptr);
    fclose(ptr);
    free(bname);

    ptr=fopen(bkfl,"w");
    fwrite(b,sizeof(*b),bn,ptr);
    fclose(ptr);
    free(b);
}

char *ret_file(int num)
{
	FILE *ptr;
	struct email_password *v;
	static char fl[25];
	int n=0;
	n=em_pw_block_num(v);
	v=(struct email_password *)calloc(n,sizeof(struct email_password));
	ptr=fopen("registration.txt","r");
	fread(v,sizeof(*v),n,ptr);
	fclose(ptr);
	strcpy(fl,v[num].file);
	free(v);
	return &fl[0];
}

int em_pw_block_num(struct email_password *v)
{
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

int mem_block_num(char memfl[])
{
	FILE *ptr;
	struct upd_mem *mem;
    int mn=0;
    ptr=fopen(memfl,"r");
    if(ptr==NULL)
    {
    	printf("\nFile wasn't found\n");
    	exit(0);
	}
    mem=(struct upd_mem *)calloc(1,sizeof(struct upd_mem));
    if(mem==NULL)
    {
        printf("\nMemory wasn't allocated\n");
        exit(0);
    }
    while(fread(mem,sizeof(*mem),1,ptr)==1)
    {
        mn++;
    }
    free(mem);
    fclose(ptr);
    return mn;
}
int bk_block_num(char bkfl[])
{
	FILE *ptr;
	struct book_info *b;
	int bn=0;
	ptr=fopen(bkfl,"r");
    b=(struct book_info *)calloc(1,sizeof(struct book_info));
    while(fread(b,sizeof(*b),1,ptr)==1)
    {
        bn++;
    }
    free(b);
    fclose(ptr);
    return bn;
}

int bkgv_block_num(char bkgvfl[])
{
	FILE *ptr;
	struct book_provide *bkgv;
	int bgn=0;
	ptr=fopen(bkgvfl,"r");
    bkgv=(struct book_provide *)calloc(1,sizeof(struct book_provide));
    while(fread(bkgv,sizeof(*bkgv),1,ptr)==1)
    {
        bgn++;
    }
    free(bkgv);
    fclose(ptr);
    return bgn;
}

int bkname_block_num(char bknamefl[])
{
	FILE *ptr;
	struct book_name *bname;
	int bnn=0;
	ptr=fopen(bknamefl,"r");
    bname=(struct book_name *)calloc(1,sizeof(struct book_name));
    while(fread(bname,sizeof(*bname),1,ptr)==1)
    {
        bnn++;
    }
    free(bname);
    fclose(ptr);
    return bnn;
}

