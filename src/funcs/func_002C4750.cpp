struct Obj_002C4750 {
    char pad0[0x10];
    int m10;
};

extern Obj_002C4750* D_003929B8[2];
extern int D_003929C8;

int func_002C4750() {
    return D_003929B8[D_003929C8]->m10;
}
