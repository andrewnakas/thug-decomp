struct Obj_0025D770;
extern "C" int func_0010F400(void* p);
extern "C" void func_0025C988(Obj_0025D770* self, int a);

struct Obj_0025D770 {
    int m0;
    void* m4;
    int m8;
    bool Fn();
};

bool Obj_0025D770::Fn()
{
    if (m8) return true;
    if (!func_0010F400(m4)) return false;
    func_0025C988(this, 1);
    m8 = 1;
    return true;
}
