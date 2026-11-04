extern char D_003773C8[];
struct Obj_00293830;
extern "C" int func_00293998(Obj_00293830* o, unsigned char c);
extern "C" void func_00103F28(void* p);

struct Obj_00293830 {
    char pad[0x30C];
    unsigned char m30C[10];
    unsigned char m316;
    void Add(unsigned char c);
};

void Obj_00293830::Add(unsigned char c)
{
    if (func_00293998(this, c))
        return;
    if (m316 >= 10)
        func_00103F28(D_003773C8);
    else
        m30C[m316++] = c;
}
