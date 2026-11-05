typedef int (*Fn_002DA118)(void* conn, char* name, void* handler, void* arg, void* data);

extern char D_00392EC0[];
extern Fn_002DA118 D_00355E00[];
extern void* D_00355DC0[];
extern "C" int func_003331D0(char* buf, char* fmt, ...);

struct Obj_002DA118 {
    char pad[0xC];
    void* mC;
    void Register(void* data, void* arg);
};

void Obj_002DA118::Register(void* data, void* arg)
{
    char buf[64];
    func_003331D0(buf, D_00392EC0);
    D_00355E00[0](mC, buf, D_00355DC0[0], arg, data);
}
