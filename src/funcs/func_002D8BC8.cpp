extern char D_00392E60[];
extern char D_00392E58[];
extern char D_00392E68[];

struct Node_002D8BC8 {
    int m0;
    int m4;
    int m8;
    Node_002D8BC8* mC;
    Node_002D8BC8* m10;
    void Link(Node_002D8BC8* n) {
        m10 = n->m10;
        mC = n;
        n->m10->mC = this;
        n->m10 = this;
    }
};

struct Group_002D8BC8 : Node_002D8BC8 {
    char pad14[4];
    int m18;
    Node_002D8BC8 m1C;
};

struct Item_002D8BC8 : Node_002D8BC8 {
    char pad14[4];
    char m18[0x38 - 0x18];
    int m38;
    int m3C;
};

struct Slot_002D8BC8 {
    int m0;
    Node_002D8BC8 m4;
    char pad18[0x34 - 0x18];
    char m34[0x1C];
};

struct Pool_002D8BC8 {
    char pad[0x104];
    int m104;
};

extern Pool_002D8BC8* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" char* func_00336558(char* s, char* delim);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_00334120(char* s);
extern "C" void* func_001046B0(int size);
extern "C" Group_002D8BC8* func_002DA5F0(void* p);
extern "C" Item_002D8BC8* func_002DA5C8(void* p);
extern "C" int func_00336228(char* a, char* b);

struct Obj_002D8BC8 {
    char pad[0x78];
    Slot_002D8BC8 m78[1];
    void Parse(int idx, char* str, int named);
};

void Obj_002D8BC8::Parse(int idx, char* str, int named)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    char* tok;
    if (!named)
        goto unnamed;
    {
        char* t = func_00336558(str, D_00392E60);
        func_00331A9C(m78[idx].m34, t);
    }
    tok = func_00336558(0, D_00392E58);
    goto common;
fail:
    func_0010A9B0(D_00388A70);
    return;
unnamed:
    tok = func_00336558(str, D_00392E58);
common:
    while (tok && !func_00336228(tok, D_00392E68)) {
        tok = func_00336558(0, D_00392E60);
        if (!tok)
            goto fail;
        int v = func_00334120(tok);
        Group_002D8BC8* g = func_002DA5F0(func_001046B0(0x34));
        g->m18 = v;
        g->Link(&m78[idx].m4);
        tok = func_00336558(0, D_00392E58);
        if (!tok)
            goto fail;
        while (tok && func_00336228(tok, D_00392E68)) {
            Item_002D8BC8* it = func_002DA5C8(func_001046B0(0x40));
            it->Link(&g->m1C);
            it->m3C = func_00334120(tok);
            tok = func_00336558(0, D_00392E58);
            if (!tok)
                goto fail;
            it->m38 = func_00334120(tok);
            tok = func_00336558(0, D_00392E60);
            if (!tok)
                goto fail;
            func_00331A9C(it->m18, tok);
            tok = func_00336558(0, D_00392E58);
        }
    }
    func_0010A9B0(D_00388A70);
}
