struct Obj_0020EB70 {
    float m_x;
    float m_y;
    char pad8[0x18];
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001DC540(Obj_0020EB70* o);
extern "C" void func_001DC6D0(Obj_0020EB70* o);
extern "C" void func_001DC578(Obj_0020EB70* o, int flags);
extern "C" bool func_001DF040(unsigned int id, Obj_0020EB70* o);
extern "C" bool func_001DF0A8(unsigned int id, float t);

bool Cmd_0020EB70(void* params, void* script)
{
    Obj_0020EB70 o;
    unsigned int id = 0;
    if (func_001E8398(params, 0, &id, 0)) {
        float x;
        float y;
        bool scale = func_001E7EB0(params, 0x5E285A66, &x, 0);
        scale = func_001E7EB0(params, 0xA4276705, &y, 0) || scale;
        float both;
        if (func_001E7EB0(params, 0xF6A36814, &both, 0)) {
            scale = true;
            x = both;
            y = both;
        }
        bool r = true;
        if (scale) {
            func_001DC540(&o);
            func_001DC6D0(&o);
            o.m_x = x;
            o.m_y = y;
            r = func_001DF040(id, &o);
            func_001DC578(&o, 2);
        }
        float t;
        if (func_001E7EB0(params, 0xD8604126, &t, 0))
            r = func_001DF0A8(id, t) && r;
        return r;
    }
    return false;
}
