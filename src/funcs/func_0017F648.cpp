struct Obj_0017F648 {
    int m0;
    char pad4[0x40 - 0x4];
    void* m40;
    void Fn(bool on);
};

extern "C" void func_0017F128(Obj_0017F648* self, bool on);
extern "C" void func_0017EC48(void* p, bool on);

void Obj_0017F648::Fn(bool on)
{
    int old = m0;
    func_0017F128(this, on);
    if (m40 && old != on)
        func_0017EC48(m40, !on);
}
