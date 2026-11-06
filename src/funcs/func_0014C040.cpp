class Obj_0014C040 {
public:
    int m0;
    int m4;
    virtual ~Obj_0014C040();
};

extern void* D_00393F1C;
extern Obj_0014C040* D_00393F18;
extern "C" void func_00131F68(void* p);
extern "C" void func_0016C2B0();

extern "C" void func_0014C040()
{
    if (D_00393F1C) {
        func_00131F68(D_00393F1C);
        D_00393F1C = 0;
    }
    if (D_00393F18) {
        delete D_00393F18;
        D_00393F18 = 0;
    }
    func_0016C2B0();
}
