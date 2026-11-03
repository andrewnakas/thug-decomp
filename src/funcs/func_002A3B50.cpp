extern char D_00371C78[];
extern char D_003714C0[];

struct IterA_002A3B50 {
    int m0;
    int m4;
    void* m8;
    IterA_002A3B50() { m8 = D_00371C78; m4 = 0; }
    ~IterA_002A3B50() { m8 = D_00371C78; }
};

struct Item_002A3B50 {
    char pad[0x20];
    unsigned int m20;
    int m24;
    int m28;
};

struct Node_002A3B50 {
    int m0;
    Item_002A3B50* m4;
    int m8;
    Node_002A3B50* mC;
    Item_002A3B50* GetData() { return m4; }
    Node_002A3B50* Valid() { return (int)m4 != -1 ? this : 0; }
};

struct IterB_002A3B50 {
    int m0;
    Node_002A3B50* m4;
    void* m8;
    IterB_002A3B50() { m8 = D_003714C0; m4 = 0; }
    ~IterB_002A3B50() { m8 = D_003714C0; }
    Item_002A3B50* Next() {
        m4 = m4->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Item_002A3B50* First(Node_002A3B50* head) {
        m4 = head;
        return Next();
    }
};

struct Elem_002A3B50 {
    char pad[0x14C];
    unsigned int m14C;
};
extern "C" int func_002B1FE8(Elem_002A3B50* e);
extern "C" int func_002B30F0(Elem_002A3B50* e);
extern "C" int func_002B1FC8(Elem_002A3B50* e);
struct Obj_002A3B50;
extern "C" int func_002A1968(Obj_002A3B50* o);

extern "C" Elem_002A3B50* func_002A53F8(void* self, IterA_002A3B50* it, int a);
extern "C" Elem_002A3B50* func_002A5490(void* self, IterA_002A3B50* it, int a);

struct Obj_002A3B50 {
    char pad[0xF4];
    Node_002A3B50 mF4;
    int Count();
};

int Obj_002A3B50::Count()
{
    IterA_002A3B50 a;
    IterB_002A3B50 b;
    int n = 0;
    for (Elem_002A3B50* e = func_002A53F8(this, &a, 1); e; e = func_002A5490(this, &a, 1)) {
        if (func_002B1FE8(e) && !func_002B30F0(e) && (!func_002B1FC8(e) || !func_002A1968(this)))
            n++;
    }
    for (Item_002A3B50* it = b.First(&mF4); it; it = b.Next()) {
        if ((it->m20 & 0xC) == 4)
            n++;
    }
    return n;
}
