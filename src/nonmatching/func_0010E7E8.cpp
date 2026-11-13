/* fuzzy: 76.5 */
struct Req_0010E7E8 {
    int m_result;
    int m_async;
};

// volatile: set by a callback/another thread; func_0010ED38 busy-waits on it (lw/beqz loop at 0x0010ED90).
// (Matched func_001124B8 only stores to it and matches with or without volatile.)
extern volatile int D_00388C94;
extern "C" int func_0010EFE0(Req_0010E7E8* r);
extern "C" int func_0010E830(Req_0010E7E8* r);

extern "C" void func_0010E7E8(Req_0010E7E8* r, int cmd, int result)
{
    r->m_result = result;
    D_00388C94 = 1;
    if (r->m_async) {
        func_0010EFE0(r);
    } else {
        func_0010E830(r);
    }
}
