struct List_0026E830;
struct Queue_0026E830;

extern "C" void* func_001046B0(unsigned int size);
extern "C" List_0026E830* func_0026E388(void* mem, int n);
extern "C" Queue_0026E830* func_0026DF98(void* mem);
extern "C" void func_0026E050(Queue_0026E830* q, int a);

struct Obj_0026E830 {
    int m_0;
    List_0026E830* m_listA;
    List_0026E830* m_listB;
    Queue_0026E830* m_qC;
    Queue_0026E830* m_q10;
    Queue_0026E830* m_q14;
    Queue_0026E830* m_q18;
};

Obj_0026E830* func_0026E830(Obj_0026E830* self)
{
    self->m_listA = func_0026E388(func_001046B0(0xC), 5);
    self->m_listB = func_0026E388(func_001046B0(0xC), 5);
    self->m_q18 = func_0026DF98(func_001046B0(0x14));
    func_0026E050(self->m_q18, 0);
    self->m_qC = func_0026DF98(func_001046B0(0x14));
    func_0026E050(self->m_qC, 0);
    self->m_q14 = func_0026DF98(func_001046B0(0x14));
    func_0026E050(self->m_q14, 0);
    self->m_q10 = func_0026DF98(func_001046B0(0x14));
    func_0026E050(self->m_q10, 0);
    return self;
}
