typedef int qword __attribute__((mode(TI)));

struct Vec_0014AC98 {
    qword q;
};

extern Vec_0014AC98 D_003BEB10[];
extern Vec_0014AC98 D_003DD9F0[];

bool Copy_0014AC98(int i)
{
    D_003DD9F0[i] = D_003BEB10[i];
    return true;
}
