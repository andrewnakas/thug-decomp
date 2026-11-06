typedef int qword __attribute__((mode(TI)));

struct Vec_0011C0A8 {
    qword q;
};

struct Bone_0011C0A8 {
    char pad[0x40];
    Vec_0011C0A8 m_v;
};

extern "C" void* func_0011AC30(void* self);
extern "C" void* func_00185578(void* p, unsigned int name);
extern "C" Bone_0011C0A8* func_001A2C98(void* skel, unsigned int name);

extern "C" void func_0011C0A8(void* self, unsigned int name, const Vec_0011C0A8* v)
{
    Bone_0011C0A8* b = func_001A2C98(func_00185578(func_0011AC30(self), 0x72AD7B23), name);
    if (b) {
        b->m_v = *v;
    }
}
