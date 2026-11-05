struct Obj_00206828 {
    char pad[0x23C];
    int m23C;
    void Stop();
};

extern "C" void func_001F0210(unsigned int name, int a, Obj_00206828* p, int b, int c);

void Obj_00206828::Stop()
{
    if (m23C) {
        func_001F0210(0x430EFC31, 0, this, 0, 0);
        m23C = 0;
    }
}
