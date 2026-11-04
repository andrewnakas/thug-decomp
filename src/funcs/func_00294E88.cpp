extern "C" void func_00331A9C(char* d, char* s);

struct Obj_00294E88 {
    char pad[0xAF];
    char mAF[1];
};

extern "C" void func_00294E88(Obj_00294E88* o, char* s) { func_00331A9C(o->mAF, s); }
