extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);

struct Obj_0024E0C0 {
    char pad[0x20];
    void* m20;
    bool Fn();
};

bool Obj_0024E0C0::Fn()
{
    bool r = false;
    int v = 0;
    func_001E7DE8(m20, 0xEA7BA666, &v, 0);
    if (v || func_001E8708(m20, 0xEA7BA666)) r = true;
    return r;
}
