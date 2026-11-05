extern "C" void func_001FA9B0(void* self, int chrg);
extern char D_00366AA8[];

struct Base_00201C58 {
    char pad[0x14];
    virtual ~Base_00201C58();
};

struct Item_00201C58 : Base_00201C58 {
    char pad18[0x2C - 0x18];
    void* m_2C;
};

struct Node_00201C58 {
    int m0;
    Item_00201C58* data;
    int m8;
    Node_00201C58* next;
    int m10;
    int m14;
    Item_00201C58* GetData() { return data; }
    Node_00201C58* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_00201C58 {
    int m0;
    Node_00201C58* cur;
    void* vt;
    It_00201C58() { vt = D_00366AA8; cur = 0; }
    ~It_00201C58() { vt = D_00366AA8; }
    Item_00201C58* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_00201C58* Advance(Node_00201C58* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_00201C58* First(Node_00201C58* h, It_00201C58* self) {
        cur = h;
        return self->Advance(h);
    }
};

struct Obj_00201C58 {
    char pad[0x884];
    Node_00201C58 m_lists[256];
    void Clear();
};

void Obj_00201C58::Clear()
{
    It_00201C58 it;
    It_00201C58* q = &it;
    for (int i = 0; i < 256; i++) {
        Item_00201C58* d = it.First(&m_lists[i], q);
        if (d) {
            It_00201C58* p = &it;
            do {
                Item_00201C58* nx = p->Advance(it.cur);
                if (d->m_2C) {
                    func_001FA9B0(d->m_2C, 3);
                }
                delete d;
                d = nx;
            } while (d);
        }
    }
}
