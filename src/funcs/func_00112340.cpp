struct Ctx_00112340 {
    int m0[2];
    int m_sema;
};

extern "C" Ctx_00112340* func_00112128();
extern "C" int func_0031C040(int sema);

void Drain_00112340()
{
    Ctx_00112340* c = func_00112128();
    while (func_0031C040(c->m_sema) >= 0)
        ;
}
