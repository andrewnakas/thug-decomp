struct Bytes138150 {
    unsigned char b[4];
};

extern Bytes138150 D_00393EF0;
extern "C" void func_0014BF48();

void func_00138150(const Bytes138150* p)
{
    D_00393EF0 = *p;
    func_0014BF48();
}
