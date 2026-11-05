typedef int qword __attribute__((mode(TI)));

struct Vec_001464C8 {
    qword q;
};

extern "C" Vec_001464C8* func_00114E18(void* o);
extern "C" void func_0017AD80(Vec_001464C8* dst, Vec_001464C8* src);

void Cb_001464C8(void*, void* o)
{
    Vec_001464C8 v = *func_00114E18(o);
    func_0017AD80(&v, &v);
}
