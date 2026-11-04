struct Range_0021ADF0 {
    float m_min;
    float m_max;
};

extern void* D_00388A70;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" Range_0021ADF0* func_001DC540(void* mem);
extern "C" void func_001DC578(Range_0021ADF0* r, int flags);
extern "C" int func_001DF940(unsigned int id, Range_0021ADF0* r, float dist);

static inline void Delete_0021ADF0(Range_0021ADF0* r)
{
    if (r)
        func_001DC578(r, 3);
}

int func_0021ADF0(void* params)
{
    float dist = 100.0f;
    unsigned int id;
    func_001E8398(params, 0x8A68AB90, &id, 1);
    float radius = dist;
    func_001E7EB0(params, 0x46653221, &radius, 0);
    Range_0021ADF0* r = func_001DC540(func_0010A638(D_00388A70, 0x18, 1, 0));
    r->m_min = radius;
    r->m_max = radius;
    int result = func_001DF940(id, r, dist);
    Delete_0021ADF0(r);
    return result;
}
