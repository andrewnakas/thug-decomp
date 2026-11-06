struct Obj_00132418 {
    int m0;
    void* m_tex;
};

extern "C" int func_001463E8(Obj_00132418* o);
extern "C" void func_00139D10(void* tex);

extern "C" int func_00132418(Obj_00132418* o)
{
    void* tex = o->m_tex;
    int r = func_001463E8(o);
    func_00139D10(tex);
    return r;
}
