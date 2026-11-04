/* cflags: -fopt-stack */
struct Obj105260 {
    char pad[0x40];
    void* m40;
    void Forward40();
};

extern "C" void func_00104BC8(void* self);

void Obj105260::Forward40()
{
    func_00104BC8(m40);
}
