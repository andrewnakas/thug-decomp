struct Obj_002B22B8 {
    char pad[0x14C];
    int m14C;
};

extern "C" bool func_002B22B8(Obj_002B22B8* o) { return (o->m14C & 0x7800) != 0; }
