struct Sub_002B3080 {
    char pad[0x48];
    int m48;
};
struct Obj_002B3080 {
    char pad[0x1C];
    Sub_002B3080* m1C;
};

extern "C" int func_002B3080(Obj_002B3080* o)
{
    Sub_002B3080* s = o->m1C;
    if (s) return s->m48;
    return 0;
}
