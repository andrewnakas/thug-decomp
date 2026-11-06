struct Bone_0011C2D8 {
    char pad[0x50];
    int m_val;
};

extern "C" void* func_0011AC30(void* self);
extern "C" void* func_00185578(void* p, unsigned int name);
extern "C" Bone_0011C2D8* func_001A2C98(void* skel, unsigned int name);

extern "C" void func_0011C2D8(void* self, unsigned int name, int val)
{
    Bone_0011C2D8* b = func_001A2C98(func_00185578(func_0011AC30(self), 0x72AD7B23), name);
    if (b) {
        b->m_val = val;
    }
}
