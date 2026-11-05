extern "C" int func_002A19A8(void* p);
extern void* D_00392068;

struct Obj_00246CB8 {
    char pad0[0x38];
    int m38;
    int m3C;
    char pad40[0x78 - 0x40];
    int m78;
    int m7C;
    bool Fn();
};

bool Obj_00246CB8::Fn()
{
    if (func_002A19A8(D_00392068)) {
        m38 = 0;
        m3C = 0;
        if (m7C) {
            m7C = 0;
            return true;
        }
    } else {
        if (m78) {
            m78 = 0;
            return true;
        }
    }
    return false;
}
