struct Obj_002D9340 {
    int m0;
    int m4;
};

extern "C" int func_002F1D88(Obj_002D9340* o);

extern "C" void func_002D9340(Obj_002D9340* o)
{
    o->m4 = func_002F1D88(o) == 1;
}
