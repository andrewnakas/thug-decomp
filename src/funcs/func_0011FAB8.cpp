struct Obj_0011FAB8;
extern "C" int func_0011FA48(Obj_0011FAB8* self);
extern "C" void func_001E6EA8(void* src, void* dst, int a);
extern "C" void func_0011F578(Obj_0011FAB8* self);

struct Obj_0011FAB8 {
    char pad[0x48];
    int m48[2];
    int Set(void* src, int apply);
};

int Obj_0011FAB8::Set(void* src, int apply)
{
    func_0011FA48(this);
    func_001E6EA8(src, m48, 0);
    if (apply) {
        func_0011F578(this);
    }
    return 1;
}
