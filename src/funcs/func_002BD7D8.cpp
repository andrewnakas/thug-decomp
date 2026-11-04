struct Obj_002BD7D8;
extern "C" int func_002C2288(Obj_002BD7D8* o, int a, int b);
extern "C" void func_002B7DB0(void* p, int v);

struct Obj_002BD7D8 {
    void* m0;
    bool Apply(int check);
};

bool Obj_002BD7D8::Apply(int check)
{
    if (check && !func_002C2288(this, 0, 1))
        return false;
    func_002C2288(this, 0, 0);
    func_002B7DB0(m0, 1);
    return true;
}
