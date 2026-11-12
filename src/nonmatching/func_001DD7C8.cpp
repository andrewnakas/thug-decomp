/* cflags: -fno-rerun-loop-opt */
/* fuzzy: 90.6 */
struct Sub_001DD7C8 {
    char m_pad[0x1C];
    float m_vol;
};

struct Entry_001DD7C8 {
    unsigned int m_id;
    int m4;
    Sub_001DD7C8* m_sub;
    char m_padC[0x14 - 0xC];
    float m_vol;
    float m_pitch;
    char m_pad1C[0x3C - 0x1C];
};

extern Entry_001DD7C8 D_003EC2F8[];
extern int D_0038881C;

extern "C" bool func_001DC418(void* mgr, unsigned int id, void* params, float vol);
extern "C" bool func_001E21C0(int i);
extern "C" bool func_001DC658(void* params);
extern "C" void func_001DC5A8(void* params, float pitch);
extern "C" void func_001DD1E8(void* mgr, void* params, float* vol, Sub_001DD7C8* sub);
extern "C" void func_001E1B38(int i, void* params, float vol);
extern "C" int func_001E53A0(unsigned int name, int a);

extern "C" bool func_001DD7C8(void* mgr, unsigned int id, void* params, float vol)
{
    if (func_001DC418(mgr, id, params, vol))
        return true;
    int i = 0;
    do {
        if (D_003EC2F8[i].m_id == id) {
            if (!func_001E21C0(i))
                break;
            if (!func_001DC658(params)) {
                if (D_003EC2F8[i].m_pitch != 100.0f)
                    func_001DC5A8(params, D_003EC2F8[i].m_pitch);
                if (D_003EC2F8[i].m_vol != 100.0f)
                    vol = vol * D_003EC2F8[i].m_vol * 0.01f;
            }
            Sub_001DD7C8* s = D_003EC2F8[i].m_sub;
            if (!s)
                return false;
            if (!func_001DC658(params))
                func_001DD1E8(mgr, params, &vol, s);
            vol = vol * s->m_vol * 0.01f;
            func_001E1B38(i, params, vol);
            return true;
        }
        i++;
    } while (i < 42);
    if (!D_0038881C)
        func_001E53A0(0x6D2E270E, 0);
    return false;
}
