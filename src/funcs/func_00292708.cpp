/* cflags: -fopt-stack */
extern char D_00377320[];
extern char D_00453050[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Obj_00292708 {
    char pad[0x2A8];
    int m2A8;
    char* GetName();
};

char* Obj_00292708::GetName() {
    func_003331D0(D_00453050, D_00377320, m2A8);
    return D_00453050;
}
