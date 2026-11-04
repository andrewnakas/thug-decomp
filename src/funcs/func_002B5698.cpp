struct Heap_002B5698 {
    char pad0[0x104];
    int m104;
};

struct S_002B5698 {
    int m0;
    int m4;
};

struct Item_002B5698 {
    char pad[0xA8];
    int mA8;
    int mAC;
};

extern Heap_002B5698* D_00388A70;
extern S_002B5698* D_00392068;
extern char D_00392460[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_002A1A18(S_002B5698* s);
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E8398(void* params, int name, int* out, int req);
extern "C" Item_002B5698* func_002B5098(S_002B5698* s, int id);
extern "C" void func_002B3BB0(S_002B5698* s, Item_002B5698* it);
extern "C" void* func_002D3D30(int id);
extern "C" void func_003067E0(void* p, int v, int w);

bool func_002B5698(void* params)
{
    S_002B5698* s = D_00392068;
    if (func_002A1A18(s))
        return true;
    int id;
    func_001E8398(params, func_001F0D78(D_00392460), &id, 0);
    Item_002B5698* it = func_002B5098(s, id);
    func_002B3BB0(s, it);
    if (it->mA8)
        return true;
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_003067E0(func_002D3D30(s->m4), it->mAC, 1);
    func_0010A9B0(D_00388A70);
    return false;
}
