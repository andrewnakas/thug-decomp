struct Obj_001BAD28;
extern "C" void func_001BAC68(Obj_001BAD28* o);
extern "C" void func_001BACC8(Obj_001BAD28* o);

struct Obj_001BAD28 {
    char pad[0x1C];
    int m1C;
    void Method(int on);
};

void Obj_001BAD28::Method(int on)
{
    if (on != m1C) {
        if (on)
            func_001BAC68(this);
        else
            func_001BACC8(this);
    }
}
