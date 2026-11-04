struct Info_002B76D0 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x30 - 0x10];
};

struct Obj_002B76D0;
extern "C" void func_002B74F0(Info_002B76D0* out, Obj_002B76D0* o, int a);

struct Obj_002B76D0 {
    char pad0[0x28];
    int m28;
    int Count();
};

int Obj_002B76D0::Count()
{
    Info_002B76D0 t;
    func_002B74F0(&t, this, 0);
    t.mC += (m28 - 1) * 0xB5658;
    return t.mC / 0xB5658 + 1;
}
