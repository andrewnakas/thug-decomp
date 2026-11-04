extern void* D_0038EB78;
extern char D_003783B8[];
extern "C" void func_002B38E0();
extern "C" void* func_001FA640(void* m);
extern "C" int func_00326E30(void* p);
extern "C" char* func_001F92B8(void* m, int a, char* name, int b, int c, int flags);
extern "C" int func_001FBF60(void* p, int a, void (*cb)(), int b, void* data, int c);

struct Obj_002A2BD0 {
    char pad[0x20];
    char* m20;
    char* Create();
};

char* Obj_002A2BD0::Create()
{
    void* m = D_0038EB78;
    m20 = func_001F92B8(m, 0, D_003783B8, 0x141F, func_00326E30(func_001FA640(m)), 0x35);
    func_001FBF60(m20 + 4, 0x10, func_002B38E0, 3, this, 0x80);
    return m20;
}
