extern "C" int func_0025D770(void* p);
extern "C" int func_0025DB50(void* p);

struct Obj_0025EC98 {
    char pad[0x1C];
    int m1C;
    char pad20[4];
    int m24;
    char pad28[0x14];
    void* m3C;
    bool Fn();
};

bool Obj_0025EC98::Fn()
{
    if (m24) return true;
    if (m1C) return false;
    if (m3C) {
        bool r = false;
        if (func_0025D770(m3C)) r = func_0025DB50(m3C) != 0;
        return r;
    }
    return false;
}
