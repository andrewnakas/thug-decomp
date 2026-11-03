extern "C" float fabsf(float x);
typedef unsigned int u128 __attribute__((mode(TI)));

union Vec_001C0E30 {
    struct {
        float x, y, z, w;
    } f;
    u128 q;
};

struct Obj_001C0E30 {
    char m_pad[0x60];
    float m60;
    float m64;
    float m68;
    char m_pad6C[0xA50 - 0x6C];
    Vec_001C0E30 mA50;
};

extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_003233B8(Vec_001C0E30* dst, Vec_001C0E30* src);

extern "C" float func_001C0E30(Obj_001C0E30* self, float v)
{
    if (self->mA50.f.y > 0.95f)
        return v;
    float limit;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0x79D182AD, &limit, 1);
    if (v <= limit)
        return v;
    Vec_001C0E30 dir;
    dir.q = self->mA50.q;
    dir.f.y = 0.0f;
    func_003233B8(&dir, &dir);
    float d = fabsf(self->m60 * dir.f.x + self->m64 * dir.f.y + self->m68 * dir.f.z);
    return (1.0f - d) * v + d * self->mA50.f.y * v;
}
