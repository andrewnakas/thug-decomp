struct Goal_0024E550 {
    char m_pad[0x20];
    void* m_params;
};

struct Tricks_0024E550 {
    char m_pad[0x58];
    int m_numTricks;
};

extern void* D_0038FC78;

extern "C" void* func_0022DD38(void* self);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int assert_);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" Tricks_0024E550* func_00203360(void* skater);
extern "C" bool func_0023AC08(Tricks_0024E550* self, int index);
extern "C" unsigned int func_00236DE0(Tricks_0024E550* self, int index);
extern "C" bool func_001E8618(void* params, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" unsigned int func_00246258(Goal_0024E550* goal);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* self, int flags);

void func_0024E550(Goal_0024E550* self)
{
    int got_new = 0;
    void* skater = func_0022DD38(D_0038FC78);
    void* found;
    func_001E8180(self->m_params, 0x735AF2DD, &found, 1);
    int count;
    func_001E7DE8(self->m_params, 0xF1E59083, &count, 1);
    Tricks_0024E550* tricks = func_00203360(skater);
    int n = tricks->m_numTricks;
    for (int i = 0; i < n; i++) {
        if (func_0023AC08(tricks, i)) {
            unsigned int name = func_00236DE0(tricks, i);
            if (!func_001E8618(found, name)) {
                got_new = 1;
                func_001E7200(found, name, 1);
                count++;
            }
        }
    }
    func_001E7200(self->m_params, 0xF1E59083, count);
    func_001E7200(self->m_params, 0x129DAA10, count);
    if (got_new) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E7360(p, 0x9982E501, func_00246258(self));
        func_001F0210(0x851AA6B8, p, 0, 0, 0);
        if (p) {
            func_001E6AE8(p, 3);
        }
    }
}
