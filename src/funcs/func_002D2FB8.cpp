extern char D_0037BD78[];

struct Data_002D2FB8;

struct Node_002D2FB8 {
    int m0;
    Data_002D2FB8* data;
    int m8;
    Node_002D2FB8* next;
    Data_002D2FB8* GetData() { return data; }
    Node_002D2FB8* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D2FB8 {
    int m0;
    Node_002D2FB8* cur;
    void* vt;
    It_002D2FB8() { vt = D_0037BD78; cur = 0; }
    ~It_002D2FB8() { vt = D_0037BD78; }
    Data_002D2FB8* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D2FB8* First(Node_002D2FB8* h) {
        cur = h;
        return Next();
    }
};

struct List_002D2FB8 : Node_002D2FB8 {
    Data_002D2FB8* Get(int i);
};

Data_002D2FB8* List_002D2FB8::Get(int i)
{
    It_002D2FB8 it;
    for (Data_002D2FB8* d = it.First(this); d; d = it.Next()) {
        if (!i) return d;
        i--;
    }
    return 0;
}
