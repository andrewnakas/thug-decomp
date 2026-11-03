struct Obj_00294888 {
    char pad[0x2A0];
    unsigned char m2A0;
    unsigned char m2A1;
};

extern "C" bool func_00294888(Obj_00294888* o) { return o->m2A1 == o->m2A0; }
