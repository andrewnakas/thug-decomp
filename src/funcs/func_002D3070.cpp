struct Obj_002D3058 {
    char pad0[0x30];
    int m30;
    int m34;
    int m38;
    char m3C[0x80];
    char mBC[0x84];
    int m140;
    int GetM38() const;
};

int Obj_002D3058::GetM38() const {
    return m38;
}
