struct Reg_001F90D0 {
    int m0;
    int m4;
    char m8[4];
};
extern Reg_001F90D0* D_0038C308;

struct Conn_001F90D0;
extern "C" int func_001FEAD0(Conn_001F90D0*);
extern "C" int func_001FEAC8(Conn_001F90D0*);
extern "C" int func_001FEAD8(Conn_001F90D0*);
extern "C" int func_001FEAE0(Conn_001F90D0*);
extern "C" void func_00105260(char*, int);

void func_001F90D0(void* mgr, Conn_001F90D0* c)
{
    Reg_001F90D0* r = D_0038C308;
    int v = func_001FEAD0(c);
    func_00105260(r->m8, v);
    v = func_001FEAC8(c);
    func_00105260(r->m8, v);
    v = func_001FEAD8(c);
    func_00105260(r->m8, v);
    v = func_001FEAE0(c);
    func_00105260(r->m8, v);
}
