struct Obj_002A80F0 {
    char pad0[0x16C];
    int m16C;
    void SetM16C(signed char v);
};

static inline int Get_002A80F0(const int& v) { return v; }

void Obj_002A80F0::SetM16C(signed char v) {
    m16C = Get_002A80F0(v);
}
