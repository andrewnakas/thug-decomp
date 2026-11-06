struct Req_0010F050;
typedef void (*Callback_0010F050)(Req_0010F050*, int, int, int, int);

struct Req_0010F050 {
    int m0;
    Callback_0010F050 m_callback;
    int m_arg0;
    int m_arg1;
};

struct Done_0010F050 {
    Req_0010F050* m_req;
    int m_op;
    int m_result;
};

extern "C" void func_001124B8();
extern "C" void func_0010E830(Req_0010F050*);
extern volatile int D_00388CA0;
extern volatile int D_00388C98[2];
extern volatile Done_0010F050 D_00464C38[2][16];

extern "C" void func_0010F050()
{
    func_001124B8();
    int buf = D_00388CA0 ^ 1;
    int n = D_00388C98[buf];
    for (int i = 0; i < n; i++) {
        volatile Done_0010F050* d = &D_00464C38[buf][i];
        Req_0010F050* r = d->m_req;
        r->m_callback(r, d->m_op, d->m_result, r->m_arg0, r->m_arg1);
        func_0010E830(r);
    }
    D_00388C98[buf] = 0;
}
