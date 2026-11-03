extern void* D_0038FC78;
extern char D_00378918[];
extern char D_00378328[];

struct Obj_002A7668;
extern "C" int func_002A19A8(Obj_002A7668* o);
extern "C" void* func_002A6070(Obj_002A7668* o);
extern "C" void* func_0022E058(void* g);
extern "C" char* func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, char* s);
extern "C" int func_001E8A50(void* s, char* name, int* out, int f);

struct Obj_002A7668 {
    int GetId();
};

int Obj_002A7668::GetId()
{
    void* g = D_0038FC78;
    void* p;
    if (func_002A19A8(this))
        p = func_002A6070(this);
    else
        p = func_0022E058(g);
    int id;
    func_001E8A50(func_00202EF8(p, func_001F0D78(D_00378918)), D_00378328, &id, 1);
    return id;
}
