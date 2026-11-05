extern char D_004647C8[];
extern char D_310000F[];
extern char D_50FFC00[];
extern "C" void* func_001047C0(int size, void* place);
extern "C" void* func_0010C158(void* p, unsigned int start, unsigned int end);

struct Obj_0010B6F0;
extern char D_00388AC0[];
extern "C" void* func_0010AF60(Obj_0010B6F0* self, void* heap, int a, char* name);

struct Obj_0010B6F0 {
    char pad[0x118];
    void* m118;
    void* m11C;
    void Init();
};

void Obj_0010B6F0::Init()
{
    m118 = func_0010C158(func_001047C0(0x1C, D_004647C8), (unsigned int)D_310000F & 0xFFFFFFF0, (unsigned int)D_50FFC00 & 0xFFFFFFF0);
    m11C = func_0010AF60(this, m118, 1, D_00388AC0);
}
