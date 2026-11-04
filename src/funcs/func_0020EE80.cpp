struct Sound_0020EE80 {
    float m_volL;
    float m_volR;
    char m_pad[0x18];
};

extern char D_0038F3C0[];
extern char D_0038F3C8[];
extern char D_0038F3D0[];
extern char D_0038F3D8[];
extern void* D_0038E0A0;

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" void func_001DC540(Sound_0020EE80* s);
extern "C" void func_001DC6D0(Sound_0020EE80* s);
extern "C" void func_001DC578(Sound_0020EE80* s, int flags);
extern "C" void func_001DD290(void* mgr, unsigned int id, Sound_0020EE80* s, unsigned int b, float pitch, int c,
                              int d);

bool func_0020EE80(void* params)
{
    unsigned int id = 0;
    float vol_l;
    float vol_r;
    float vol;
    float pitch;
    unsigned int b = 0;
    vol = 100.0f;
    vol_l = 100.0f;
    vol_r = 100.0f;
    pitch = 100.0f;
    func_001E8398(params, 0, &id, 0);
    func_001E7F50(params, D_0038F3C0, &vol_l, 0);
    func_001E7F50(params, D_0038F3C8, &vol_r, 0);
    if (func_001E7F50(params, D_0038F3D0, &vol, 0)) {
        vol_l = vol;
        vol_r = vol;
    }
    func_001E7F50(params, D_0038F3D8, &pitch, 0);
    func_001E8398(params, 0x40C698AF, &b, 0);
    Sound_0020EE80 s;
    func_001DC540(&s);
    func_001DC6D0(&s);
    s.m_volL = vol_l;
    s.m_volR = vol_r;
    func_001DD290(D_0038E0A0, id, &s, b, pitch, 0, 0);
    func_001DC578(&s, 2);
    return true;
}
