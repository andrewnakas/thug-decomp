struct Elem_002C0370 {
    char pad[0x150];
    signed char m150;
    char pad151[3];
};

struct Obj_002C0370 {
    char pad[0x353C];
    Elem_002C0370 m353C[1];
};

extern "C" Elem_002C0370* func_002C0370(Obj_002C0370* o, int n, int* out)
{
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (o->m353C[i].m150)
            c++;
    }
    if (out)
        *out = c;
    return &o->m353C[n];
}
