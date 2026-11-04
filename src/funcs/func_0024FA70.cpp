struct Array_0024FA70 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

struct GameMode_0024FA70 {
    int m0;
    char m_params[4];
};

extern void* D_00392068;

extern "C" bool func_002A19A8(void* self);
extern "C" int func_0024F750(GameMode_0024FA70* self);
extern "C" void func_001E6B30(void* params);
extern "C" Array_0024FA70* func_001E55B8(unsigned int name, int assert_);
extern "C" void* func_001E9378(Array_0024FA70* self, unsigned int index);
extern "C" bool func_001E8A30(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" bool func_001E8870(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void* func_001E5588(unsigned int name, int assert_);
extern "C" void func_001E6AC8(void* params, void* src);
extern "C" void func_0024EC78(GameMode_0024FA70* self);
extern "C" void func_0024ED30(GameMode_0024FA70* self);
extern "C" void func_0024F728(GameMode_0024FA70* self, int value);

bool func_0024FA70(GameMode_0024FA70* self, unsigned int type)
{
    void* mgr = D_00392068;
    int value = 8;
    if (mgr && func_002A19A8(mgr)) {
        value = func_0024F750(self);
    }
    func_001E6B30(self->m_params);
    Array_0024FA70* modes = func_001E55B8(0xCA5F7FFB, 1);
    for (unsigned int i = 0; i < modes->m_size; i++) {
        void* mode = func_001E9378(modes, i);
        unsigned int name;
        func_001E8A30(mode, 0x21902065, &name, 1);
        if (name == type) {
            unsigned int info;
            func_001E8870(mode, 0x97CFD027, &info, 1);
            func_001E6AC8(self->m_params, func_001E5588(info, 1));
            func_0024EC78(self);
            func_0024ED30(self);
            if (mgr && func_002A19A8(mgr)) {
                func_0024F728(self, value);
            }
            return true;
        }
    }
    return false;
}
