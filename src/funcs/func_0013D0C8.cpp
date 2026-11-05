extern "C" int func_0011D9E8(void* src);
extern "C" int func_0011D9E0(void* src);
extern "C" void func_0013C768(void* e, int a, int b);

struct Mesh_0013D0C8;
extern "C" int func_0013E9D8(Mesh_0013D0C8* m);
extern "C" void* func_0013E9B8(Mesh_0013D0C8* m, int i);

struct Mesh_0013D0C8 {
    int m0;
    bool Load(void* src);
};

bool Mesh_0013D0C8::Load(void* src)
{
    int n = func_0013E9D8(this);
    for (int i = 0; i < n; i++) {
        void* e = func_0013E9B8(this, i);
        int a = func_0011D9E0(src);
        int b = func_0011D9E8(src);
        func_0013C768(e, a, b);
    }
    return true;
}
