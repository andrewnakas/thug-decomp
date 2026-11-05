extern void* D_0038FC78;
extern void* D_00392068;
extern "C" void* func_0022DF08(void* g, int id);
extern "C" void* func_002A52F0(void* net, unsigned short id);

struct Obj_00265978 {
    char pad[0x18];
    unsigned short m18;
};

struct Conn_00265978 {
    char pad[0x1C];
    int m1C;
};

int Find_00265978(int id)
{
    void* net = D_00392068;
    Obj_00265978* o = (Obj_00265978*)func_0022DF08(D_0038FC78, id);
    if (!o)
        return 0;
    Conn_00265978* c = (Conn_00265978*)func_002A52F0(net, o->m18);
    if (!c)
        return 0;
    return c->m1C;
}
