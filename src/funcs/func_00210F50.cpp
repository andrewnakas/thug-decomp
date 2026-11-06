struct Obj_00210F50 {
    char m_pad0[0x84];
    void* m84;
};

extern char D_0038F468[];
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" Obj_00210F50* func_00131E20(char* name);
extern "C" Obj_00210F50* func_00131E48();
extern "C" void func_00131CD8(Obj_00210F50* o);
extern "C" void func_00139D10(void* p);

bool Cmd_00210F50(void* params, void* script)
{
    bool r = false;
    char* name = 0;
    func_001E8890(params, D_0038F468, &name, 0);
    if (name) {
        Obj_00210F50* o = func_00131E20(name);
        if (o)
            r = true;
        else
            o = func_00131E48();
        if (o) {
            void* sub = o->m84;
            func_00131CD8(o);
            if (sub)
                func_00139D10(sub);
        }
    }
    return r;
}
