extern char D_00390128[];
extern "C" int func_001E86D0(void* p, char* name);

struct Obj_0024A1F8 {
    char pad0[0x20];
    void* m20;
    int Get();
};

int Obj_0024A1F8::Get()
{
    return func_001E86D0(m20, D_00390128);
}
