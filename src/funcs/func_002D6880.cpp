struct Msg_002D6880 {
    int m0;
    int m4;
};

struct Obj_002D6880 {
    int m0;
    int m4;
    int m8;
};

extern char D_0037C270[];
extern char D_0037C298[];
extern char D_0037C2B8[];
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002D8070(Obj_002D6880* o);

void Handle_002D6880(void* a0, Msg_002D6880* msg, Obj_002D6880* o)
{
    switch (msg->m4) {
    case 0x202:
        func_001F0370(D_0037C270, 0, 0, 0);
        func_002D8070(o);
        break;
    case 0x201:
        o->m8 = 3;
        break;
    case 0x603:
        func_001F0370(D_0037C298, 0, 0, 0);
        break;
    case 0x107:
        func_002D8070(o);
        func_001F0370(D_0037C2B8, 0, 0, 0);
        break;
    }
}
