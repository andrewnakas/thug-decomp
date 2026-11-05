extern "C" void* func_00105520(void* p);

struct Obj_0026FDD8 {
    char pad[0x1C];
    void* m1C;
    void Set(void* p);
};

void Obj_0026FDD8::Set(void* p)
{
    m1C = func_00105520(p);
}
