struct Obj_002C8FA0;
extern "C" void func_002BB7A0(void* p);
extern "C" void func_002CE490(void* p);

struct Obj_002C8FA0 {
    char pad[0x50];
    void* m50;
    char pad54[0x64 - 0x54];
    int m64;
    char pad68[0x6C - 0x68];
    void* m6C;
    void Release(int keep);
};

void Obj_002C8FA0::Release(int keep)
{
    if (m50)
        func_002BB7A0(m50);
    if (!keep && m6C)
        func_002CE490(m6C);
    m64 = 0;
}
