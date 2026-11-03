extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F328(void* p);

extern void* D_0038FC78;

struct Obj_002A7820 {
    char pad0[0x44];
    bool m44;
    bool m48;
    bool m4C;
    int ToggleM48();
};

int Obj_002A7820::ToggleM48() {
    int r = func_0024F328(func_0022E358(D_0038FC78));
    m48 ^= true;
    return r;
}
