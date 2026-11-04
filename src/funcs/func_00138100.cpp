struct Bytes138100 {
    unsigned char b[4];
};

extern Bytes138100 D_00393EE8;
extern "C" void func_0014BF48();

void func_00138100(const Bytes138100* p)
{
    D_00393EE8 = *p;
    func_0014BF48();
}
