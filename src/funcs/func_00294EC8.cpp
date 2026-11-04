extern "C" void func_00331A9C(char* d, char* s);

struct Obj_00294EC8 {
    char pad[0x36];
    char m36[1];
};

extern "C" void func_00294EC8(Obj_00294EC8* o, char* s) { func_00331A9C(o->m36, s); }
