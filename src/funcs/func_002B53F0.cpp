struct Heap_002B53F0 {
    char pad0[0xF4];
    int mF4;
    char pad1[0x108 - 0xF8];
    int m108;
};

struct Node_002B53F0 {
    char pad[0xC];
    Node_002B53F0* m_next;
    Node_002B53F0* m_prev;
    void Append(Node_002B53F0* n) {
        n->m_prev = m_prev;
        n->m_next = this;
        m_prev->m_next = n;
        m_prev = n;
    }
};

struct Item_002B53F0 : Node_002B53F0 {
    char pad2[0x2C - 0x14];
    int m2C;
    int m30;
    char m34[0x10];
};

extern Heap_002B53F0* D_00388A70;
extern void* D_00392068;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_002A1A28(void* s);
extern "C" void* func_001046B0(int size);
extern "C" Item_002B53F0* func_002B1BD8(void* p, int v);
extern "C" char* func_00332088(char* dst, const char* src, int n);

struct Obj_002B53F0 {
    char pad[0xB0];
    Node_002B53F0 m_list;
    void Add(const char* name, int v);
};

void Obj_002B53F0::Add(const char* name, int v)
{
    if (func_002A1A28(D_00392068))
        func_0010A950(D_00388A70, D_00388A70->m108);
    else
        func_0010A950(D_00388A70, D_00388A70->mF4);
    Item_002B53F0* it = func_002B1BD8(func_001046B0(0x16C), 0);
    it->m2C = v;
    func_00332088(it->m34, name, 15);
    it->m34[15] = 0;
    m_list.Append(it);
    func_0010A9B0(D_00388A70);
}
