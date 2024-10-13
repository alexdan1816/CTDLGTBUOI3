#include <stdio.h>
#include <stdbool.h>

// CÀI ĐẶT DANH SÁCH NỐI ĐƠN THẲNG
struct Node
{
    int data;
    Node *next;
};
// typedef Node *LinkedList;

void InitList(Node *&H) // khởi tạo danh sách
{
    H = NULL;
}

bool isEmpty(Node *H) // Kiểm tra trạng thái hiện tại của danh sách
{
    return (H== NULL);
}

void InsertBegin(Node *&H, int K) // BỔ SUNG PHẦN TỬ MỚI VÀO ĐÀU DANH SÁCH H
{
    Node *Q=new Node;
    Q->data = K;
    if (isEmpty(H))
    {
        Q->next = NULL;
        H = Q;
    }
    else
    {
        Q->next = H;
        H = Q;
    }
}


Node* SearchNode(Node *& H, int K) //TÌM PHẦN TỬ 
{
	Node *P=H;
	while (P!=0){
		if (P->data==K)
		return P;
		else P=P->next;
	}
	return 0;
}
void InsertAfter(Node *&H, int k, int x)
{
    Node *temp = SearchNode(H,x);
    if(temp==0) InsertBegin(H,x);
    else
    {
        Node *q=new Node;
        q->data=k;
        q->next=temp->next;
        temp->next=q;

    }
}

void DeleteNode(Node *&H) //hàm xóa phần tử đầu danh sách
{
    if(isEmpty(H)) 
    {
        printf("Danh sach rong");
    }
    else 
    {
        Node *P=H;
        H=H->next;
    }

}
void InsertBefore(Node *&H, int k, int x) 
{
    Node *temp = SearchNode(H,x);
    if(temp==0) InsertBegin(H,x);
    else 
    {
       Node *q= new Node;
       q->data=k;
       if(temp->next==NULL)
       {
        q->next=NULL;
        q->data=temp->data;
        temp->next=q;
        temp->data=k;
        
       }


    }

}
void display(Node *head)
{
    Node *temp = head;
    printf("Danh sach: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *H;
    InitList(H);
    InsertBegin(H,11);
    InsertBegin(H,12);
    InsertAfter(H,13,12);
    InsertBefore(H,14,11);
    DeleteNode(H);


    display(H);
    
}