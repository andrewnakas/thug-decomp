extern "C" void func_0010D280(void* p, int f);

struct Obj_002B6780 {
    char pad0[0x10];
    void* m10;
    void* m14;
    void Release();
};

void Obj_002B6780::Release()
{
    if (m14) {
        func_0010D280(m14, 3);
        m14 = 0;
    }
    if (m10) {
        func_0010D280(m10, 3);
        m10 = 0;
    }
}
