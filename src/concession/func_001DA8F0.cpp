/* cflags: -fno-schedule-insns */
/* force: {"kind": "lfr", "block": 0, "reg": 120, "hard": 3} */
typedef int qword_001DA8F0 __attribute__((mode(TI)));
union Vec_001DA8F0 {
    qword_001DA8F0 q;
    struct {
        float x, y, z, w;
    } f;
    void Set(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};
struct Obj_001DA8F0 {
    Vec_001DA8F0 m0;
    Vec_001DA8F0 m10;
    char pad[0xFC0 - 0x20];
    int mFC0;
    int mFC4;
    int mFC8;
    void Reset();
};

void Obj_001DA8F0::Reset()
{
    Vec_001DA8F0 v;
    v.f.y = v.f.x = v.f.z = 10000000.0f;
    v.f.w = 1.0f;
    m0 = v;
    v.f.y = v.f.x = v.f.z = -10000000.0f;
    m10 = v;
    mFC8 = 0;
    mFC0 = 0;
    mFC4 = 0;
}
