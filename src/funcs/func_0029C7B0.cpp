extern int D_00391F40;
extern unsigned int D_00354E60[];
extern "C" int func_00229668(void* p, int a);
extern "C" void* func_001E55B8(unsigned int id, int v);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int a);
extern "C" bool func_001EDFB8(unsigned int v, unsigned int* list, int n);

struct Obj_0029C7B0 {
    char pad[0x74];
    void* m74;
    char pad2[0x89 - 0x78];
    char m89;
};

extern "C" void func_0029C7B0(Obj_0029C7B0* o)
{
    if (!o->m89)
        return;
    if (!o->m74)
        return;
    int i = func_00229668(o->m74, 0);
    if (i < 0)
        return;
    void* s = func_001E9378(func_001E55B8(0xC472ECC5, 0), i);
    unsigned int v = 0;
    func_001E8398(s, 0x2CA8A299, &v, 0);
    if (v && func_001EDFB8(v, D_00354E60, 11))
        D_00391F40 = 1;
}
