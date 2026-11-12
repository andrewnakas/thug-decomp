struct Obj_002D7950_A {
    char pad0[0x108];
    int m108;
};

struct Link_002D7950 {
    char pad0[0xC];
    Link_002D7950* mC;
    Link_002D7950* m10;
    void Insert(Link_002D7950* n)
    {
        n->m10 = m10;
        n->mC = this;
        m10->mC = n;
        m10 = n;
    }
};

struct Node_002D7950 : Link_002D7950 {
    char pad14[0x18 - 0x14];
    char m18[0x20];
    int m38;
    int m3C;
    int m40;
};

struct Obj_002D7950 {
    char pad0[0x14];
    Link_002D7950 m14;
};

extern Obj_002D7950_A* D_00388A70;
extern char D_00392DD8[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int size);
extern "C" Node_002D7950* func_002D88A8(void* p);
extern "C" char* func_00331A9C(char* dst, char* src);
extern "C" void func_002E8A58(Obj_002D7950* p, int v, char* s);

extern "C" void func_002D7950(Obj_002D7950* owner, char* name, int value)
{
    func_0010A950(D_00388A70, D_00388A70->m108);
    Node_002D7950* node = func_002D88A8(func_001046B0(0x250));
    func_00331A9C(node->m18, name);
    node->m38 = value;
    node->m40 = 1;
    node->m3C = 0;
    owner->m14.Insert(node);
    func_002E8A58(owner, value, D_00392DD8);
    func_0010A9B0(D_00388A70);
}
