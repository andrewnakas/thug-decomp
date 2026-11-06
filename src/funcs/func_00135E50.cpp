typedef int qword __attribute__((mode(TI)));

struct Vec_00135E50 {
    qword q;
};

extern Vec_00135E50 D_003BEB10[];
extern "C" bool func_0014AC98(int i);

extern "C" bool func_00135E50(int i, Vec_00135E50* v)
{
    D_003BEB10[i] = *v;
    return func_0014AC98(i);
}
