extern char D_0037C690[];

struct Base_002D7A08 {
    char pad[0x14];
    virtual ~Base_002D7A08();
};

struct Data_002D7A08 : Base_002D7A08 {
    char pad18[0x40 - 0x18];
    int m40;
};

struct Node_002D7A08 {
    int m0;
    Data_002D7A08* data;
    int m8;
    Node_002D7A08* next;
    Data_002D7A08* GetData() { return data; }
    Node_002D7A08* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_002D7A08 {
    int m0;
    Node_002D7A08* cur;
    void* vt;
    It_002D7A08() { vt = D_0037C690; }
    ~It_002D7A08() { vt = D_0037C690; }
    Data_002D7A08* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D7A08* First(Node_002D7A08* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D7A08 {
    char pad[0x14];
    Node_002D7A08 m14;
    void RemoveFirst();
};

void Obj_002D7A08::RemoveFirst()
{
    It_002D7A08 it;
    for (Data_002D7A08* d = it.First(&m14); d; d = it.Next()) {
        if (d->m40) {
            delete d;
            return;
        }
    }
}
