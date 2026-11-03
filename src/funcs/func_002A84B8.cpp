struct Obj_002A84B8 {
    char pad0[0x1930];
    int m1930;
    int* GetM1930Ptr();
};

int* Obj_002A84B8::GetM1930Ptr() {
    return &m1930;
}
