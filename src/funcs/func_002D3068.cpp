struct Obj_002D3058 {
    char pad0[0x30];
    int m30;
    int m34;
    int m38;
    char m3C[0x80];
    char mBC[0x84];
    int m140;
    void SetM38(int v);
};

void Obj_002D3058::SetM38(int v) {
    m38 = v;
}
