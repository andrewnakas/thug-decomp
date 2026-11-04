struct Obj_002D3058 {
    char pad0[0x30];
    int m30;
    int m34;
    int m38;
    char m3C[0x80];
    char mBC[0x84];
    int m140;
    void SetM140(int v);
};

void Obj_002D3058::SetM140(int v) {
    m140 = v;
}
