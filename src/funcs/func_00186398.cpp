extern "C" void func_00185238(void* p);
struct Obj_00186398 {
    char pad[0x104];
    int m104;
    void Run(int b);
};

void Obj_00186398::Run(int b)
{
    m104 |= 8;
    if (b) {
        func_00185238(this);
    }
}
