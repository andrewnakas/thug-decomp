struct Vec_0011C108 {
    float x, y, z;
};

struct Bone_0011C108 {
    char pad[0x60];
    float x, y, z;
};

extern "C" void* func_0011AC30(void* self);
extern "C" void* func_00185578(void* p, unsigned int name);
extern "C" Bone_0011C108* func_001A2C98(void* skel, unsigned int name);

extern "C" void func_0011C108(void* self, unsigned int name, const Vec_0011C108* v)
{
    Bone_0011C108* b = func_001A2C98(func_00185578(func_0011AC30(self), 0x72AD7B23), name);
    if (b) {
        b->x = (v->x + v->x) * 0.0007669904153f;
        b->y = (v->y + v->y) * 0.0007669904153f;
        b->z = (v->z + v->z) * 0.0007669904153f;
    }
}
