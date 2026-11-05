struct Obj_002BEFC8;
extern "C" int func_002BEF38(Obj_002BEFC8* o);

struct Obj_002BEFC8 {
    char pad0[0x8C];
    int m8C;
    int m90;
    int m94;
    void Pop();
};

void Obj_002BEFC8::Pop()
{
    m8C--;
    m94 -= func_002BEF38(this);
}
