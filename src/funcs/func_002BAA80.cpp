extern char D_0037A430[];
extern "C" void func_00103F28(const char* fmt, ...);

struct Obj_002BAA80 {
    unsigned char m0;
    signed char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    void Print() const;
};

void Obj_002BAA80::Print() const {
    func_00103F28(D_0037A430, m0, m1, m2, m3, m4, m5);
}
