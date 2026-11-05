extern "C" void func_00326E30(void* p);

struct Obj_001FA618 {
    char pad0[0x13C];
    char m13C[0x10];
    int m14C;
    void Check();
};

void Obj_001FA618::Check()
{
    if (!m14C) func_00326E30(m13C);
}
