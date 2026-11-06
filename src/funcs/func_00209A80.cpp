struct Obj_00209A80;

extern "C" void func_00101F58(Obj_00209A80* self);
extern "C" void func_00209B38(Obj_00209A80* self);

static inline void Wait_00209A80()
{
    int i = 32;
    while (i--) {
        int j = 2;
        while (j--) {
        }
    }
}

struct Obj_00209A80 {
    int m0;
    Obj_00209A80* Init();
};

Obj_00209A80* Obj_00209A80::Init()
{
    func_00101F58(this);
    Wait_00209A80();
    Wait_00209A80();
    func_00209B38(this);
    return this;
}
