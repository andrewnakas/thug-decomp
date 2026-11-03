/* cflags: -fopt-stack */
extern "C" void func_001D0BD8(void* self);

struct Triple {
    int m0;
    int m4;
    int m8;
    Triple();
};

Triple::Triple()
{
    func_001D0BD8(this);
}
