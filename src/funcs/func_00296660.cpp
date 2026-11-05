struct Elem_00296660 {
    char pad[0x2A5];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
};

struct Obj_00296660 {
    char pad[0x20];
    Elem_00296660 m20[50];
};

extern "C" int func_00294888(Elem_00296660* e);
extern "C" void func_00292630(Elem_00296660* e);

extern "C" void func_00296660(Obj_00296660* o)
{
    for (int i = 0; i < 50; i++) {
        Elem_00296660* e = &o->m20[i];
        if (e->m2A5 && !func_00294888(e))
            func_00292630(e);
    }
}
