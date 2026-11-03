struct Bytes1380D0 {
    unsigned char b[4];
};

extern Bytes1380D0 D_00393EE0;
extern "C" void func_0014BF48();

void func_001380D0(const Bytes1380D0* p)
{
    D_00393EE0 = *p;
    func_0014BF48();
}
