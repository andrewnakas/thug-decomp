extern char D_00366D08[];
struct Obj_00202E60 {
    int m0;
    char m4[8];
    void* mC;
    Obj_00202E60();
};
extern "C" void func_001E6978(void* p);

Obj_00202E60::Obj_00202E60()
{
    mC = D_00366D08;
    func_001E6978(m4);
}
