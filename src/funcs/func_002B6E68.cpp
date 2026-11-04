extern char D_0037A3E0[];

struct Base_002B6E68 {
    int m0;
    int m4;
    int m8;
    void* mC;
    ~Base_002B6E68();
};

struct Obj_002B6E68 : public Base_002B6E68 {
    ~Obj_002B6E68();
};

Obj_002B6E68::~Obj_002B6E68() {
    mC = D_0037A3E0;
}
