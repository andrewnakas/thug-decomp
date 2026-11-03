struct Array_00240630 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Mgr_00240630 {
    char m_pad[0x48];
    int m_level;
    int m_group;
};

extern void* D_0038FC78;

extern "C" Array_00240630* func_001E55B8(unsigned int name, int assert_);
extern "C" Array_00240630* func_001E93A0(Array_00240630* self, int index);
extern "C" void* func_001E9378(Array_00240630* self, int index);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void* func_0022E358(void* self);
extern "C" bool func_0024F908(void* self, unsigned int flag);
extern "C" void* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);

void func_00240630(Mgr_00240630* self)
{
    if (self->m_level < func_001E55B8(0xB892776F, 1)->m_size && !func_0024F908(func_0022E358(D_0038FC78), 0x353961D7)) {
        Array_00240630* groups = func_001E55B8(0x9F00892D, 1);
        int group = self->m_group;
        int level = self->m_level;
        if (group == 0) {
            if (level == 0) {
                return;
            }
            level--;
            group = func_001E93A0(groups, level)->m_size - 1;
        } else {
            group--;
        }
        unsigned int script;
        if (func_001E8398(func_001E9378(func_001E93A0(groups, level), group), 0x6166F3AD, &script, 0)) {
            func_001F0750(script, 0, 0, 0, -1, 0, 0, 0, 0, 0);
        }
    }
}
