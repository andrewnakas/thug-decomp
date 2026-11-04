extern char D_00391ED0[];

struct Scene_002978F8 {
    char pad0[0x18];
    void* m18;
};

struct Park_002978F8 {
    Scene_002978F8* m0;
};

extern "C" void* func_00131E20(char* name);
extern "C" Park_002978F8* func_002C0368();
extern "C" void* func_00133300(void* a, void* b, void* c, int d, int e);
extern "C" void func_00133D48(void* p, int v);
extern "C" void* func_001317D0(void* p);

extern "C" void* func_002978F8(void* obj)
{
    void* src = func_00131E20(D_00391ED0);
    if (!src)
        return 0;
    void* scene = func_002C0368()->m0->m18;
    if (!scene)
        return 0;
    void* inst = func_00133300(src, obj, scene, 0, 1);
    func_00133D48(scene, 0);
    return func_001317D0(inst);
}
