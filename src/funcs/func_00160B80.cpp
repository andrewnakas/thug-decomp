extern int* D_0038B53C;
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_0010BF90(int a, int b);
extern "C" void* func_0015F938();
extern "C" void func_0015F900(void* p);

struct Obj_00160B80 {
    void* m0;
    void* m4;
    void* m8;
    bool Fn();
};

bool Obj_00160B80::Fn()
{
    D_0038B53C = (int*)func_0010BDE0(0x400);
    for (int i = 0; i < 32; i++) {
        int v = 0;
        for (int j = 0; j < 5; j++) {
            if ((i >> j) & 1)
                v |= 1 << (16 - j * 4);
        }
        D_0038B53C[i] = v;
    }
    m0 = func_0010BF90(8, 0x100);
    m4 = func_0010BF90(4, 0x100);
    m8 = func_0015F938();
    func_0015F900(m8);
    return true;
}
