typedef unsigned int u128 __attribute__((mode(TI)));

union Vec_001C6458 {
    struct {
        float x, y, z, w;
    } f;
    u128 q;
};

struct Feeler_001C6458 {
    Vec_001C6458 m_start;
    Vec_001C6458 m_end;
    char m_pad[0xA0 - 0x20];
    Vec_001C6458 m_point;
};

struct Obj_001C6458 {
    int m0;
    bool Probe(Vec_001C6458* pos, Vec_001C6458* out, Feeler_001C6458* f);
};

extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_002093E8(Feeler_001C6458* f, int a, int b);

bool Obj_001C6458::Probe(Vec_001C6458* pos, Vec_001C6458* out, Feeler_001C6458* f)
{
    float up;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0x6DA7F696, &up, 1);
    f->m_start.q = pos->q;
    f->m_start.f.y += 2.0f * up;
    f->m_end.q = pos->q;
    float down;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xAEBFA9CD, &down, 1);
    f->m_end.f.y -= down;
    if (func_002093E8(f, 1, 0)) {
        out->q = f->m_point.q;
        return true;
    }
    out->q = pos->q;
    return false;
}
