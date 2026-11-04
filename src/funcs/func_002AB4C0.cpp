struct Obj_002AB4C0 {
    char pad0[0x1B4];
    int m1B4;
    int* GetM1B4Ptr();
};

int* Obj_002AB4C0::GetM1B4Ptr() {
    return &m1B4;
}
