struct Ctx_00112378 {
    int m0[3];
    volatile int m_done;
};

extern "C" Ctx_00112378* func_00112128();

void Wait_00112378()
{
    Ctx_00112378* c = func_00112128();
    do {
    } while (!c->m_done);
}
