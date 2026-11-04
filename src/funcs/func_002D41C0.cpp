struct Out_002D41C0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

int func_002D41C0(void* a, int flag, void* c, void* d, Out_002D41C0* out) {
    out->m8 = 100;
    if (!flag) {
        out->mC = 1;
    } else {
        out->mC = 2;
    }
    return 1;
}
