extern char D_00378BD8[];
extern char D_00378D58[];

struct Heap_002A7EE8 {
    char pad0[0xF4];
    int mF4;
};
extern Heap_002A7EE8* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(unsigned int size);

struct Item_002A7EE8;

struct Node_002A7EE8 {
    int m0;
    Item_002A7EE8* m4;
    int m8;
    Node_002A7EE8* mC;
    Node_002A7EE8* m10;
    Item_002A7EE8* GetData() { return m4; }
    Node_002A7EE8* Valid() { return (int)m4 != -1 ? this : 0; }
};

struct Item_002A7EE8 : Node_002A7EE8 {
    void* m14;
    int m18;
    int m1C;
    int m20;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Item_002A7EE8(int a, int b, int key) {
        m4 = this;
        m8 = 0;
        mC = this;
        m10 = this;
        m14 = D_00378D58;
        m18 = a;
        m1C = b;
        m20 = key;
    }
    void InsertBefore(Node_002A7EE8* head) {
        m10 = head->m10;
        mC = head;
        head->m10->mC = this;
        head->m10 = this;
    }
};

struct Iter_002A7EE8 {
    int m0;
    Node_002A7EE8* m4;
    void* m8;
    Iter_002A7EE8() { m8 = D_00378BD8; m4 = 0; }
    ~Iter_002A7EE8() { m8 = D_00378BD8; }
    Item_002A7EE8* Next() {
        m4 = m4->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Item_002A7EE8* First(Node_002A7EE8* head) {
        m4 = head;
        return Next();
    }
};

struct Obj_002A7EE8 {
    char pad[0x10C];
    Node_002A7EE8 m10C;
    void Add(int a, int b, int key);
};

void Obj_002A7EE8::Add(int a, int b, int key)
{
    Iter_002A7EE8 it;
    for (Item_002A7EE8* d = it.First(&m10C); d; d = it.Next()) {
        if (d->m20 == key) return;
    }
    func_0010A950(D_00388A70, D_00388A70->mF4);
    Item_002A7EE8* n = new Item_002A7EE8(a, b, key);
    n->InsertBefore(&m10C);
    func_0010A9B0(D_00388A70);
}
