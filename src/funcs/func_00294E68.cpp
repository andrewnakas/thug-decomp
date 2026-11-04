extern "C" void func_00331A9C(char* d, char* s);

struct Obj_00294E68 {
    char pad[0x4B];
    char m4B[1];
};

extern "C" void func_00294E68(Obj_00294E68* o, char* s) { func_00331A9C(o->m4B, s); }
