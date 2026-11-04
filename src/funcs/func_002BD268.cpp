struct Obj_002BD268 {
    char pad[0x3528];
    int m3528;
};
extern "C" void func_002C3330(Obj_002BD268* o);

extern "C" void func_002BD268(Obj_002BD268* o, int v)
{
    o->m3528 = v;
    func_002C3330(o);
}
