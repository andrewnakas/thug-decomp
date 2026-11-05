struct Node_0029B468 {
    int m0;
    Node_0029B468* m4;
};

struct Obj_0029B468 {
    char pad[0x24];
    Node_0029B468* m24;
};

extern "C" int func_0029B468(Obj_0029B468* o)
{
    int n = 0;
    for (Node_0029B468* x = o->m24; x; x = x->m4)
        n++;
    return n;
}
