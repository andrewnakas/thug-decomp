struct Obj_002A6070 {
    char pad0[0xBC];
    int mBC[4];
    int mCC[4];
    int* GetCC();
};

int* Obj_002A6070::GetCC() {
    return mCC;
}
