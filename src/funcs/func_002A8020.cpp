extern char D_00378BD8[];

struct Base_002A8020 {
    char pad[0x14];
    virtual ~Base_002A8020();
};

struct Node_002A8020 {
    int m0;
    Base_002A8020* data;
    int m8;
    Node_002A8020* next;
    Base_002A8020* GetData() { return data; }
    Node_002A8020* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002A8020 {
    int m0;
    Node_002A8020* cur;
    void* vt;
    It_002A8020() { vt = D_00378BD8; cur = 0; }
    ~It_002A8020() { vt = D_00378BD8; }
    Base_002A8020* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002A8020* Advance(Node_002A8020* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002A8020* First(Node_002A8020* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002A8020 {
    char pad[0x10C];
    Node_002A8020 m10C;
    void Clear();
};

void Obj_002A8020::Clear()
{
    It_002A8020 it;
    Base_002A8020* d = it.First(&m10C);
    if (d) {
        It_002A8020* p = &it;
        do {
            Base_002A8020* nx = p->Advance(it.cur);
            delete d;
            d = nx;
        } while (d);
    }
}
