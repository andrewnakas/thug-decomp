typedef int qword __attribute__((mode(TI)));

union Vec_001CB670 {
    qword q;
    struct { float x, y, z, w; } v;
};

struct Body_001CB670 {
    char m_pad0[0xF0];
    Vec_001CB670 m_F0;
    char m_pad1[0x1B0 - 0x100];
    unsigned long m_1B0;
};

struct Owner_001CB670 {
    char m_pad[0x260];
    Body_001CB670* m_260;
};

struct Obj_001CB670 {
    char m_pad[0xA30];
    Owner_001CB670* m_A30;
    float Get();
};

extern "C" void* func_001E5548(unsigned int key, int a);
extern "C" void func_001E7EB0(void* s, unsigned int key, float* out, int flag);

float Obj_001CB670::Get()
{
    Body_001CB670* b = m_A30->m_260;
    if ((int)(b->m_1B0 >> 3) & 1) {
        Vec_001CB670 v = b->m_F0;
        float f;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0xA8C13E74, &f, 1);
        return (1.0f - v.v.y) * f;
    }
    return 0.0f;
}
