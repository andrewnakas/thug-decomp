struct Obj_002392B8 {
    short m0;
    short m_2;
    int m_4;
};

extern void* D_0038FC78;
extern void* D_00392068;
extern char D_00373570[];
extern char D_00373580[];
extern "C" bool func_002A1A38(void* a);
extern "C" void* func_0022E358(void* self);
extern "C" void* func_0022E048(void* self);
extern "C" bool func_001E5400(char* name, int a);
extern "C" bool func_0024F8D8(void* a, char* name);
extern "C" int func_00266190(void* a, int b);

int Get_002392B8(Obj_002392B8* o)
{
    if (!func_002A1A38(D_00392068)) {
        return o->m_4;
    }
    void* mgr = D_0038FC78;
    void* x = func_0022E358(mgr);
    if (func_001E5400(D_00373570, 0) || func_0024F8D8(x, D_00373580)) {
        return func_00266190(func_0022E048(mgr), o->m_2);
    }
    return o->m_4;
}
