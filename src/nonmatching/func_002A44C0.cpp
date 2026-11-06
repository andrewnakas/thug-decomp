/* fuzzy: 94.2 */
/* nonmatch func_002A44C0: best earlier draft (thug-claude-lane3/work/w53/p2/func_002A44C0.fail), 13 of 190 words differ. */
extern char D_003714C0[];
extern char D_00378C80[];

struct Item_002A44C0 {
    char m0;
    char m1[0x10];
    char m11;
    char pad12[2];
    int m14;
    int m18;
    void* m1C;
    unsigned int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
};

struct Node_002A44C0 {
    int m0;
    Item_002A44C0* data;
    int m8;
    Node_002A44C0* next;
    Node_002A44C0* prev;
    void* vt;
    Item_002A44C0* GetData() { return data; }
    void AddBefore(Node_002A44C0* n) {
        n->prev = prev;
        n->next = this;
        prev->next = n;
        prev = n;
    }
    Node_002A44C0* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002A44C0 {
    int m0;
    Node_002A44C0* cur;
    void* vt;
    It_002A44C0(Node_002A44C0* h) { cur = h; vt = D_003714C0; }
    ~It_002A44C0() { vt = D_003714C0; }
    Item_002A44C0* Advance(Node_002A44C0* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002A44C0* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002A44C0* Begin() {
        Node_002A44C0* n = cur->next->Valid();
        Item_002A44C0* r = n ? n->GetData() : 0;
        cur = n;
        return r;
    }
};

struct Conn_002A44C0 {
    char pad[0x1804];
    int m1804;
};

struct Pool_002A44C0 {
    char pad[0xF4];
    int mF4;
};

struct Obj_002A44C0;
extern Pool_002A44C0* D_00388A70;
extern char D_00378430[];
extern char D_00378450[];
extern char D_00378468[];
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int n);
extern "C" Item_002A44C0* func_002B3100(void* p);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002A1A38(Obj_002A44C0* o);
extern "C" void* func_0010A638(void* p, int n, int a, int b);
extern "C" void func_002616E0(void* s, void* buf, int n, int a);
extern "C" void func_002617C8(void* s, void* buf);
extern "C" void func_0010A8D8(void* p, void* q);
extern "C" int func_001F0D78(char* s);
extern "C" void func_002A7B50(Obj_002A44C0* s, int a, int b, char* c, int d, int e, int f, int g, int h);

struct Obj_002A44C0 {
    char pad[0x14];
    Conn_002A44C0* m14;
    Conn_002A44C0* m18;
    char pad1C[0xF4 - 0x1C];
    Node_002A44C0 mF4;
    void Add(Item_002A44C0* src, int t);
};

void Obj_002A44C0::Add(Item_002A44C0* src, int t)
{
    It_002A44C0 it(&mF4);
    Item_002A44C0* d = it.Begin();
    if (d) {
        It_002A44C0* q = &it;
        do {
            if (d->m11 == src->m11) return;
            d = it.Advance(q->cur);
        } while (d);
    }
    func_0010A950(D_00388A70, D_00388A70->mF4);
    d = func_002B3100(func_001046B0(0x3C));
    func_00331A9C(d->m1, src->m1);
    d->m14 = src->m14;
    d->m11 = src->m11;
    d->m20 = src->m20;
    d->m28 = src->m28;
    d->m2C = src->m2C;
    d->m30 = src->m30;
    d->m34 = src->m34;
    d->m38 = src->m38;
    if (d->m20 & 0x10) {
        if (func_002A1A38(this))
            d->m24 = m14->m1804;
    }
    if ((d->m20 & 0xC) != 4) {
        void* buf = func_0010A638(D_00388A70, 0x1000, 1, 0);
        func_002616E0(src->m1C, buf, 0x1000, 0);
        func_002617C8(d->m1C, buf);
        if (buf) func_0010A8D8(D_00388A70, buf);
    }
    if (func_002A1A38(this)) {
        d->m18 = m14->m1804 + t;
        unsigned int f = d->m20;
        if (!(f & 1)) {
            if (f & 4)
                func_002A7B50(this, 1, (f & 8) ? func_001F0D78(D_00378430) : func_001F0D78(D_00378450), src->m1, 0, 0, 0, 0, 2000);
            else
                func_002A7B50(this, 0, func_001F0D78(D_00378468), src->m1, 0, 0, 0, 0, 2000);
        }
    } else {
        d->m18 = m18->m1804 + t;
    }
    Node_002A44C0* node = (Node_002A44C0*)func_001046B0(0x18);
    node->next = node;
    node->prev = node;
    node->data = d;
    node->vt = D_00378C80;
    node->m8 = 0;
    mF4.AddBefore(node);
    func_0010A9B0(D_00388A70);
}
