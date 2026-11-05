struct Obj_002BEF88;
extern "C" int func_002BEF38(Obj_002BEF88* o);

struct Obj_002BEF88 {
    char pad0[0x8C];
    int m8C;
    int m90;
    int m94;
    void Step();
};

void Obj_002BEF88::Step()
{
    m8C++;
    m94 += func_002BEF38(this);
}
