extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int required);

struct Obj_00290058 {
    char pad0[0x1C];
    float m1C;
    float m20;
    float m24;
    float m28;
    int SetParam(unsigned int id, void* params);
};

int Obj_00290058::SetParam(unsigned int id, void* params)
{
    switch (id) {
    case 0x82A0A873:
        if (func_001E7EB0(params, 0, &m1C, 0)) {
            float t = m1C * 12.0f;
            m1C = t * t;
        }
        return 1;
    case 0x8CB5D0C0:
        if (func_001E7EB0(params, 0, &m20, 0)) {
            float t = m20 * 12.0f;
            m20 = t * t;
        }
        return 1;
    case 0x50F28D36:
        if (func_001E7EB0(params, 0, &m24, 0)) {
            float t = m24 * 12.0f;
            m24 = t * t;
        }
        return 1;
    case 0x2D703B94:
        if (func_001E7EB0(params, 0, &m28, 0)) {
            float t = m28 * 12.0f;
            m28 = t * t;
        }
        return 1;
    }
    return 2;
}
