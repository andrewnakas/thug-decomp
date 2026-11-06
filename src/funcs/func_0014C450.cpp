extern "C" void func_003312D8(int a, int b);
extern "C" void func_00170BF0(void* p);
extern "C" void func_0010DCD0(char* name);

struct Scrn_0014C450 {
    char pad[0x164];
    char m164[0x134];
    void* m298;
    int Unload();
};

int Scrn_0014C450::Unload()
{
    if (m298) {
        func_003312D8(0, 0);
        func_00170BF0(m298);
        func_0010DCD0(m164);
        m164[0] = 0;
        return 1;
    }
    return 0;
}
