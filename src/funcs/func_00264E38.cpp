struct RGBA_00264E38 {
    unsigned char r, g, b, a;
};

extern char D_00375F08[];
extern "C" void* func_001317D0(int id);
extern "C" void* func_001E55F8(const char* name, int a);
extern "C" void* func_001E93A0(void* p, void* key);
extern "C" int func_001E9270(void* arr, int i);
extern "C" void func_00134F28(void* m, RGBA_00264E38* c);

static inline void SetColor_00264E38(void* mesh, RGBA_00264E38 c)
{
    func_00134F28(mesh, &c);
}

struct Obj_00264E38 {
    char pad[0x18];
    int m18;
    bool Apply(void* key);
};

bool Obj_00264E38::Apply(void* key)
{
    void* mesh = func_001317D0(m18);
    void* arr = func_001E93A0(func_001E55F8(D_00375F08, 0), key);
    RGBA_00264E38 color;
    color.r = func_001E9270(arr, 0);
    color.g = func_001E9270(arr, 1);
    color.b = func_001E9270(arr, 2);
    color.a = 0x80;
    SetColor_00264E38(mesh, color);
    return true;
}
