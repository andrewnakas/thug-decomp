struct Sub_001AA518 { char pad[0x18]; int m_18; };
extern "C" int func_001E8A30(void* params, unsigned int id, int* out, int assert_);
extern "C" void* func_00185578(void* self, unsigned int id);
extern "C" void func_001A2610(void* p, int a, int flag, int b, int c);
extern "C" void func_001A0F10(void* p, int v, float f);
extern "C" float func_001A0AB0(void* p, int v);
struct Obj_001AA518 { char pad[0xC]; Sub_001AA518* m_C; char pad2[0xC]; float m_1C; void Go(void* params, float angle); };
void Obj_001AA518::Go(void* params, float angle)
{
    int v;
    angle += 0.7853981853f;
    if (angle < 0.0f) angle += 6.283185482f;
    switch ((int)(angle * 0.6366197467f)) {
    case 0:
    case 4:
        func_001E8A30(params, 0x4DE2C9E8, &v, 1);
        break;
    case 1: {
        int flag;
        if (func_001E8A30(params, 0x733DA756, &v, 0)) {
            flag = 0;
        } else {
            func_001E8A30(params, 0xA7A0DD72, &v, 1);
            flag = 1;
        }
        void* p = func_00185578(m_C, 0x72AD7B23);
        if (p) func_001A2610(p, m_C->m_18, flag, 0, 1);
        break;
    }
    case 2:
        func_001E8A30(params, 0x64948109, &v, 1);
        break;
    case 3: {
        int flag;
        if (func_001E8A30(params, 0xA7A0DD72, &v, 0)) {
            flag = 0;
        } else {
            func_001E8A30(params, 0x733DA756, &v, 1);
            flag = 1;
        }
        void* p = func_00185578(m_C, 0x72AD7B23);
        if (p) func_001A2610(p, m_C->m_18, flag, 0, 1);
        break;
    }
    default:
        return;
    }
    void* q = func_00185578(m_C, 0x72AD7B23);
    if (q) {
        func_001A0F10(q, v, 0.0f);
        m_1C = func_001A0AB0(q, v);
    }
}
