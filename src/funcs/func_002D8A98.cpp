extern char D_00392E60[];
extern char D_00392E58[];

struct Node_002D8A98 {
    int m0;
    int m4;
    int m8;
    Node_002D8A98* mC;
    Node_002D8A98* m10;
    void Link(Node_002D8A98* n) {
        m10 = n->m10;
        mC = n;
        n->m10->mC = this;
        n->m10 = this;
    }
};

struct Item_002D8A98 : Node_002D8A98 {
    char pad14[4];
    char m18[0x38 - 0x18];
    int m38;
    int m3C;
};

struct Pool_002D8A98 {
    char pad[0x104];
    int m104;
};

extern Pool_002D8A98* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" char* func_00336558(char* s, char* delim);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_00334120(char* s);
extern "C" void* func_001046B0(int size);
extern "C" Item_002D8A98* func_002DA5C8(void* p);

struct Obj_002D8A98 {
    char pad[0x1D4];
    Node_002D8A98 m1D4;
    void Parse(char* str);
};

void Obj_002D8A98::Parse(char* str)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    char* tok = func_00336558(str, D_00392E58);
    while (tok) {
        Item_002D8A98* it = func_002DA5C8(func_001046B0(0x40));
        it->Link(&m1D4);
        it->m3C = func_00334120(tok);
        tok = func_00336558(0, D_00392E58);
        if (!tok)
            goto fail;
        it->m38 = func_00334120(tok);
        tok = func_00336558(0, D_00392E60);
        if (!tok) {
        fail:
            func_0010A9B0(D_00388A70);
            return;
        }
        func_00331A9C(it->m18, tok);
        tok = func_00336558(0, D_00392E58);
    }
    func_0010A9B0(D_00388A70);
}
