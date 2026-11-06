/* fuzzy: 99.4 */
typedef int qword_00232898 __attribute__((mode(TI)));

struct Row_00232898 {
    union {
        qword_00232898 q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    void operator+=(const Row_00232898& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
struct Vec_00232898 : Row_00232898 {
    Vec_00232898() {}
    Vec_00232898(const Row_00232898& o) { q = o.q; }
    Vec_00232898(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};
extern "C" void func_003233B8(Row_00232898* dst, Row_00232898* src);
inline Vec_00232898 operator*(const Row_00232898& a, float k) { return Vec_00232898(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }

extern char D_00366B58[];
struct It_00232898 {
    int m0;
    int m4;
    void* m8;
    It_00232898() { m8 = D_00366B58; m4 = 0; }
    ~It_00232898() { m8 = D_00366B58; }
};

struct Conn_00232898 {
    char pad0[0x20B4];
    unsigned int m20B4;
};

struct Data_00232898 {
    unsigned int m0;
    char pad4[0xC];
    Row_00232898 m10;
    Row_00232898 m20;
    char pad30[4];
    int m34;
    float m38;
    signed char m3C;
};

struct Msg_00232898 {
    Data_00232898* m0;
    char pad4[0xC];
    void* m10;
    char pad14[0x1C - 0x14];
    void* m1C;
};

extern void* D_00392068;
extern "C" void* func_0022DF08(void* self, int id);
extern "C" bool func_002A1A38(void* net);
extern "C" Conn_00232898* func_00200EC0(void* net, It_00232898* it);
extern "C" bool func_00202768(Conn_00232898* c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* s, unsigned int name, int v);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" void func_001E6AE8(void* s, int flags);

int Handle_00232898(Msg_00232898* msg)
{
    Data_00232898* d = msg->m0;
    void* net = D_00392068;
    void* obj = func_0022DF08(msg->m1C, d->m3C);
    if (!obj)
        return 3;
    Vec_00232898 vel = d->m20;
    Vec_00232898 dir = vel;
    Vec_00232898 pos = d->m10;
    func_003233B8(&dir, &dir);
    unsigned int t = d->m0;
    if (!func_002A1A38(net)) {
        It_00232898 it;
        Conn_00232898* c = func_00200EC0(msg->m10, &it);
        unsigned int lat = func_00202768(c) ? 0 : c->m20B4;
        t += lat;
    }
    pos += dir * ((float)t * 0.001f);
    void* s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0x81C39E06, d->m3C);
    func_001E7200(s, 0x7323E97C, (int)pos[0]);
    func_001E7200(s, 0x0424D9EA, (int)pos[1]);
    func_001E7200(s, 0x9D2D8850, (int)pos[2]);
    func_001E7200(s, 0xBDED7A76, (int)d->m20[0]);
    func_001E7200(s, 0xCAEA4AE0, (int)d->m20[1]);
    func_001E7200(s, 0x53E31B5A, (int)d->m20[2]);
    func_001E7200(s, 0xC48391A5, d->m34);
    func_001E72B0(s, 0x13B9DA7B, d->m38);
    func_001F0210(0xAA2B5552, s, obj, 0, 0);
    if (s)
        func_001E6AE8(s, 3);
    return 1;
}
