struct Row_002BFA58 {
    int v[0xE8 / 4];
};
struct Obj_002BFA58 {
    char pad[0x98];
    Row_002BFA58 rows[1];
};

extern "C" int func_002BFA58(Obj_002BFA58* o, int a, int b) { return o->rows[a].v[b]; }
