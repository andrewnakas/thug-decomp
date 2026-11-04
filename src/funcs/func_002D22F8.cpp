extern char D_0037BB88[];
extern char D_0037BB98[];
extern char D_0037BBA8[];
extern char D_0037BBB8[];

struct Node_002D22F8 {
    int m0;
    int m4;
    int m8;
    Node_002D22F8* mC;
    Node_002D22F8* m10;
    Node_002D22F8* Valid() { return m4 != -1 ? this : 0; }
    void Link(Node_002D22F8* n) {
        m10 = n->m10;
        mC = n;
        n->m10->mC = this;
        n->m10 = this;
    }
};

struct Entry_002D22F8 : Node_002D22F8 {
    char pad14[4];
    char m18[0x3F];
    char m57;
    int m58;
    int m5C;
    int m60;
    int m64;
    int m68;
    int m6C;
    int m70;
    int m74;
};

struct Mgr_002D22F8 {
    char pad[0x10];
    void* m10;
};

struct Pool_002D22F8 {
    char pad[0x108];
    int m108;
};

extern Mgr_002D22F8* D_00392068;
extern Pool_002D22F8* D_00388A70;
extern "C" void func_002B5608(void* self, int mode);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int size);
extern "C" Entry_002D22F8* func_002B60E8(void* p);
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" int func_002DF4E0(void* params, char* name, int def);
extern "C" void* func_002DA188(void* p);
extern "C" int func_002DA2A8(void* p);

void func_002D22F8(void* self, int ok, int score, void* params, char* name, int a5, int a6, int a7, int a8, Node_002D22F8* head)
{
    Mgr_002D22F8* mgr = D_00392068;
    Entry_002D22F8* e;
    if (!ok)
        goto fail;
    if (score == 0) {
        func_002B5608(mgr, 12);
        return;
    }
    func_0010A950(D_00388A70, D_00388A70->m108);
    e = func_002B60E8(func_001046B0(0x78));
    func_00332088(e->m18, name, 0x3F);
    e->m5C = a7;
    e->m60 = a6;
    e->m57 = 0;
    e->m58 = score;
    if (!(a5 < func_002DF4E0(params, D_0037BB88, 0)))
        e->m6C = 1;
    e->m68 = func_002DF4E0(params, D_0037BB98, 100000);
    e->m64 = func_002DF4E0(params, D_0037BBA8, 0);
    if (e->m68 < func_002DA2A8(func_002DA188(mgr->m10)))
        e->m70 = 1;
    if (func_002DA2A8(func_002DA188(mgr->m10)) < e->m64)
        e->m70 = 1;
    if (func_002DF4E0(params, D_0037BBB8, 0))
        e->m74 = 1;
    if (e->m5C > e->m60)
        e->m60 = e->m5C;
    e->m8 = -score;
    for (Node_002D22F8* n = head->mC->Valid(); n; n = n->mC->Valid()) {
        if (!(e->m8 < n->m8)) {
            e->Link(n);
            goto done;
        }
    }
    e->Link(head);
done:
    func_0010A9B0(D_00388A70);
    return;
fail:
    func_002B5608(mgr, 13);
}
