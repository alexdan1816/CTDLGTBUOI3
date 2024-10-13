    #include <iostream>
    using namespace std;
    #define MAX 10

    struct Node
    {
        int data;
        Node *next;
    };
    typedef Node* LinkedList;
    void InitList(LinkedList &H) //TẠO DANH SÁCH RỖNG
    {
        H=NULL;    
    }
    bool isEmpty(LinkedList H)  //KIỂM TRA DANH SÁCH RỖNG
    {
        return(H==NULL);
    }
    void InsertBegin(LinkedList &H, int k)  //BỔ SUNG PHẦN TỬ VÀO ĐẦU DANH SÁCH
    {
        Node *Q = new Node;
        Q->data=k;
        if(isEmpty(H))
        {
            Q->next=NULL;
            H=Q;
        }
        else
        {
            Q->next=H;
            H=Q;
        }
    }

    Node *Searchbyvalue(LinkedList &H, int x)   //TÌM KIẾM PHẦN TỬ CÓ GIÁ TRỊ X
    {  
        Node *temp=H;
        while(temp!=0)
        {
            if(temp->data==x)
            return temp;
            else
            temp=temp->next;
        }
        return nullptr;
    }

    void InsertAfter(LinkedList &H,int k,int x) //BỔ SUNG PHẦN TỬ CÓ GIÁ TRỊ k VÀO SAU X
    {
        Node* temp=Searchbyvalue(H,x);
        if(temp==0)
        {
            printf("Khong tim duoc vi tri thich hop");
        }
        else
        {
            LinkedList Q=new Node;
            Q->data=k;
            Q->next=temp->next;
            temp->next=Q;
        }
            
    }

    void InsertBefore(LinkedList &H,int k,int x)    //BỔ SUNG PHẦN TỬ GIÁ TRỊ k VÀO TRƯỚC X
    {
        Node *temp=Searchbyvalue(H,x);
        if(temp==0)
        {
            InsertBegin(H,k);
        }
        else
        {
            Node *Q = new Node;
            Q->next=temp->next;
            temp->next=Q;
            Q->data=temp->data;
            temp->data=k;
            
        }
    }

    void Headdelete(LinkedList &H) //XÓA PHẦN TỬ Ở ĐẦU DANH SÁCH
    {
        if(H == NULL)
        {
            printf("danh sach rong");
        }
        else
        {
            LinkedList P=H;
            H=H->next;
            delete P;
        }
    }

    void PointPdelete(LinkedList &H, LinkedList &nodeToDelete)  //XÓA PHẦN TỬ ĐANG ĐƯỢC P TRỎ ĐẾN
    {
        if(H==NULL || nodeToDelete==NULL)   //NẾU DANH SÁCH RỖNG
        {
            return;
        }
        else if(H==nodeToDelete && nodeToDelete->next==NULL)    //NẾU DANH SÁCH CẦN XÓA LÀ NODE DUY NHẤT
        {
            H==NULL;
            delete nodeToDelete;
        }
        else
        {
            if(H==nodeToDelete)// NẾU NODE CẦN XÓA NGAY ĐẦU DANH SÁCH
            {
                H=nodeToDelete->next;
                delete nodeToDelete;
            }
            else 
            {
                LinkedList PreviousNode = H;
                while(PreviousNode->next!=nodeToDelete)//TÌM NODE NGAY TRƯỚC NODE CẦN XÓA
                {
                    PreviousNode=PreviousNode->next;
                }
                PreviousNode->next=nodeToDelete->next;//CHO NODE TRƯỚC NODE CẦN XÓA CHỈ VỀ PHÍA SAU NODE CẦN XÓA
                delete nodeToDelete;
            }
        }

    }

    void ValueKNodeDelete(LinkedList &H, int k) //xóa các phần tử có giá trị bằng k
    {
    
        Node*temp=Searchbyvalue(H,k);
        if(temp==nullptr)
        {
            return;
        }
        else if(H->data==k)
        {
            Node*nodetodelete = H;
            H=H->next;
            delete nodetodelete;
        }
        else
        {
            Node*Previous = H;
            while(Previous->next!=temp)
            {
                Previous=Previous->next;
            }
            if(temp->next==nullptr)
            {
                delete temp;
            }
            else
            {
                Previous->next=temp->next;
                delete temp;
            }
        }
    }

        void allDelete(LinkedList &H)
        {
            Node*Current = H;
            Node*Nextnode;
            while (Current!=NULL)
            {
                Nextnode=Current->next;
                delete Current;
                Current=Nextnode;
            }
            H=NULL;
        }
    float AvarageValue(LinkedList H)    //HÀM TÍNH GIÁ TRỊ TRUNG BÌNH CỦA DANH SÁCH
    {
        float count=1;
        float sum;
        if(isEmpty(H))
        {
            cout<<"Danh sach rong";
            return 0;
        }
        else 
        {
            Node*temp=H;
            sum=temp->data;
            while(temp->next!=nullptr)
            {

                temp=temp->next;
                sum+=temp->data;
                count++;
            }
            return sum/count;
        }
    }

    int Nodecounts(LinkedList H) // HÀM ĐẾM SỐ PHẦN TỬ
    {
        if(isEmpty(H))
        {
            cout<<"Danh sach rong";
            return 0;
        }
        else
        {
        Node*temp=H;
        int count=1;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
            count++;
        }
        return count;
        }
    }
    void display(LinkedList &H) //HIỂN THỊ DANH SÁCH    
    {
        Node* temp=H;
        if(isEmpty(H))
        {
            printf("danh sach rong");
            return ;
        }
        else
        {
            while(temp!=0)
            {
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            printf("NULL");
        }
    }

    int main()
    {
        LinkedList H;
        InitList(H);
        InsertBegin(H,10);
        InsertBegin(H,9);
        InsertBegin(H,8);
        InsertAfter(H,20,8);
        InsertBefore(H,21,9);
        ValueKNodeDelete(H,9);
        int count=Nodecounts(H);
        cout<<"So phan tu "<<count<<endl;
        float avarage=AvarageValue(H);
        cout<<"Gia tri trung binh "<<avarage<<endl;
        
        display(H);

    }