extern char D_00379E70[];

struct Data_002B3C88 {
    char pad[0x9C];
    int m9C;
};

struct Node_002B3C88 {
    int m0;
    Data_002B3C88* data;
    int m8;
    Node_002B3C88* next;
    Data_002B3C88* GetData() { return data; }
    Node_002B3C88* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002B3C88 {
    int m0;
    Node_002B3C88* cur;
    void* vt;
    It_002B3C88() { vt = D_00379E70; cur = 0; }
    ~It_002B3C88() { vt = D_00379E70; }
    Data_002B3C88* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002B3C88* Advance(Node_002B3C88* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002B3C88* First(Node_002B3C88* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002B3C88 {
    char pad[0x124];
    Node_002B3C88 m124;
    int Count();
};

int Obj_002B3C88::Count()
{
    It_002B3C88 it;
    int n = 0;
    Data_002B3C88* d = it.First(&m124);
    if (d) {
        It_002B3C88* p = &it;
        do {
            if (d->m9C) n++;
            d = p->Advance(it.cur);
        } while (d);
    }
    return n;
}
