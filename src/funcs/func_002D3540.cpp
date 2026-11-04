struct Node_002D3540 {
    int m0;
    void* data;
    int m8;
    Node_002D3540* next;
    Node_002D3540* Valid() { return (int)data != -1 ? this : 0; }
};

struct Sub_002D3540 {
    char pad[0x24];
    Node_002D3540* m24;
};

struct Net_002D3540 {
    int m0;
    Sub_002D3540* m4;
    char pad8[0x130 - 0x8];
    Node_002D3540* m130;
};

struct Script_002D3540 {
    char pad[0x18];
    void* m18;
};

extern Net_002D3540* D_00392068;
extern char D_0037BCF0[];
extern "C" void func_001E7268(void* p, char* name, int v);

extern "C" bool func_002D3540(void* params, Script_002D3540* s)
{
    char* name = D_0037BCF0;
    int n = 0;
    void* dst = s->m18;
    for (Node_002D3540* p = D_00392068->m4->m24->Valid(); p; p = p->next->Valid())
        n++;
    func_001E7268(dst, name, n);
    return true;
}
