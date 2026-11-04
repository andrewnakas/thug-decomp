struct Node_002B4A80 {
    int m0;
    void* data;
    int m8;
    Node_002B4A80* next;
    Node_002B4A80* Valid() { return (int)data != -1 ? this : 0; }
};

struct Sub_002B4A80 {
    char pad[0x24];
    Node_002B4A80* m24;
};

struct Net_002B4A80 {
    int m0;
    Sub_002B4A80* m4;
    char pad8[0x130 - 0x8];
    Node_002B4A80* m130;
};

struct Script_002B4A80 {
    char pad[0x18];
    void* m18;
};

extern Net_002B4A80* D_00392068;
extern char D_00379C20[];
extern "C" void func_001E7268(void* p, char* name, int v);

extern "C" bool func_002B4A80(void* params, Script_002B4A80* s)
{
    char* name = D_00379C20;
    int n = 0;
    void* dst = s->m18;
    for (Node_002B4A80* p = D_00392068->m130->Valid(); p; p = p->next->Valid())
        n++;
    func_001E7268(dst, name, n);
    return true;
}
