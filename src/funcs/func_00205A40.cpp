struct Skater_00205A40 {
    char pad[0x14];
    void* m_script;
    char pad18[0x31C - 0x18];
    int m_local;
};

extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001EE8C8(void* script, unsigned int name, void* params, Skater_00205A40* obj);
extern "C" void func_001EFDC0(void* script);
extern "C" void func_001E6AE8(void* p, int flags);

void func_00205A40(Skater_00205A40* self, bool a, bool b)
{
    if (!self->m_script)
        self->m_script = func_001EE428(func_00121960(0xF4));
    void* params = 0;
    if (a || b) {
        params = func_001E6978(func_001190D0(8));
        if (a)
            func_001E7360(params, 0, 0x726E85AA);
        if (b)
            func_001E7360(params, 0, 0x7B738580);
    }
    func_001EE8C8(self->m_script, 0xE740F458, params, self);
    if (self->m_local)
        func_001EFDC0(self->m_script);
    if (params)
        func_001E6AE8(params, 3);
}
