#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	struct n * prev;
	int data;
	struct n * next;
}node;

	node * s=NULL;
	
node * create(node * root,int value){
	root=(node *)malloc(sizeof(node));
	root->prev=NULL;
	root->next=NULL;
	root->data=value;
	printf("%d sayisi listeye eklendi...\n",value);
	return root;
}

void getList(node * root){
	node * iter=root;
	printf("---------\n");
	if(root==NULL)
	{
		printf("Liste bos!");
	}
	else
	{
		printf("%d",iter->data);
		while(iter->next!=NULL){
			iter=iter->next;
			printf("|%d",iter->data);
		}
	}
	printf("\n---------\n");
}

node * insert_begin(node * root,int value){
	if(root==NULL){
		root=create(root,value);
	}
	else{
		node * temp=(node *)malloc(sizeof(node));
		temp->prev=NULL;
		temp->next=root;
		temp->data=value;
		root=temp;
		printf("%d sayisi listenin basina eklendi...\n",root->data);
	}
	return root;
}

node * insert_end(node * root,int value){
	if(root==NULL){
		create(root,value);
	}
	else{
		node * iter=root;
		while(iter->next!=NULL){
			iter=iter->next;
		}
		node * temp=(node *)malloc(sizeof(node));
		temp->prev=iter;
		temp->data=value;
		temp->next=NULL;
		iter->next=temp;
		printf("%d sayisi listenin sonuna eklendi...\n",temp->data);
	}
	return root;
}

node * insert_pos(node * root,int value){
	
	int pos;
	getList(root);
	printf("eklenecek konum = ");
	scanf("%d",&pos);
	system("cls");
	if(root==NULL){
		root=create(root,value);
	}
	else if(pos<0){
		printf("Hatali giris!");
	}
	else if(pos==0)
	{
	 	root=insert_begin(root,value);
	}
	else
	{
		int i,c=1;
		node * iter=root;
		for(i=1;i<pos;i++){
			iter=iter->next;
			if(iter==NULL){
				printf("liste sinirlarinda bir konum giriniz!\n");
				c=0;
				break;
			}
		}
		if(c){
			if(iter->next==NULL){
				root=insert_end(root,value);
			}
			else{
				node * temp =(node*)malloc(sizeof(node));
				temp->data=value;
				temp->prev=iter;
				temp->next=iter->next;
				iter->next=temp;
				iter->next->prev=temp;	
				printf("%d konumuna(%d-%d arasina) \"%d\" degeri eklendi...\n",pos,iter->data,temp->next->data,value);
			}
		}
	}
	return root;
}

node * delete_begin(node * root){
	if(root==NULL)
	{
		printf("Liste bos!\n");
	}
	else if(root->next==NULL){
		printf("%d sayisi listenin basindan silindi...\n",root->data);
		root=NULL;
	}
	else
	{
		printf("%d sayisi listenin basindan silindi...\n",root->data);
		node * temp=root->next;
		temp->prev=NULL;
		root=temp;
	}
	return root;
}

node * delete_end(node * root){
	if(root==NULL)
	{
		printf("Liste bos!\n");
	}
	else if(root->next==NULL){
		printf("%d sayisi listenin sonundan silindi...\n",root->data);
		root=NULL;
	}
	else
	{
		node * iter = root;
		while(iter->next->next!=NULL)
		{
			iter=iter->next;
		}
		printf("%d sayisi listenin sonundan silindi...\n",iter->next->data);
		iter->next=NULL;
	}
	return root;
}

node * delete_pos(node * root){
	int pos;
	getList(root);
	printf("silinecek konum = ");
	scanf("%d",&pos);
	system("cls");
	if(root==NULL){
		printf("Liste Bos!\n");
	}
	else if(pos<0){
		printf("Hatali giris!\n");
	}
	else if(pos==0)
	{
	 	root=delete_begin(root);
	}
	else
	{
		int i,c=1;
		node * iter=root;
		node * temp=(node *)malloc(sizeof(node));
		for(i=0;i<pos;i++){
			temp=iter;
			iter=iter->next;
			if(iter==NULL){
				printf("liste sinirlarinda bir konum giriniz!\n");
				c=0;
				break;
			}
		}
		if(c){
			if(iter->next==NULL){
				root=delete_end(root);
			}
			else{	
				temp->next=iter->next;
				iter->next->prev=temp;
				printf("%d konumundan \"%d\" degeri silindi...\n",pos,iter->data);
			}
		}
	}
	return root;
}

int main(int argc, char *argv[]) {
	int choice,value,c=1;
	while(c){
		printf("1-Basa Ekle\n2-Sona Ekle\n3-Bastan Sil\n4-Sondan Sil\n5-Araya Ekle\n6-Aradan Sil\n7-Cikis\nSecim=");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				system("cls");
				printf("Deger=");
				scanf("%d",&value);
				system("cls");
				s=insert_begin(s,value);
				break;
			}
			case 2:{
				system("cls");
				printf("Deger=");
				scanf("%d",&value);
				system("cls");
				s=insert_end(s,value);
				break;
			}
			case 3:{
				system("cls");
				s=delete_begin(s);
				break;
			}
			case 4:{
				system("cls");
				s=delete_end(s);
				break;
			}
			case 5:{
				system("cls");
				printf("Deger=");
				scanf("%d",&value);
				system("cls");
				s=insert_pos(s,value);
				break;
			}
			case 6:{
				system("cls");
				s=delete_pos(s);
				break;
			}
			case 7:{
				c=0;
				break;
			}
			default :{
				system("cls");
				printf("hata!\n");
				break;
			}
		}
		if(c==1)
			getList(s);
	}
	return 0;
}
